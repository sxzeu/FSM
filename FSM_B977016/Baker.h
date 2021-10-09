#pragma once
#ifndef BAKER_H
#define BAKER_H
//------------------------------------------------------------------------
//
//  Name:   Miner.h
//
//  Desc:   A class defining a goldminer.
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include <string>
#include <cassert>
#include <iostream>

#include "BaseGameEntity.h"
#include "Locations.h"
#include "misc/ConsoleUtils.h"
#include "BakerOwnedStates.h"
#include "StateMachine.h"

template <class entity_type> class State; //pre-fixed with "template <class entity_type> " for vs8 compatibility

struct Telegram;

// 제빵사가 빵을 몇개나 만드는 지에 대해 체크
const int BreadCount = 6;
// 주방에 재료가 얼마나 있는지 체크 
const int Ingredients = 5;


class Baker : public BaseGameEntity
{
private:

    //an instance of the state machine class
    StateMachine<Baker>* m_pStateMachine;

    location_type         m_Location;

    //how many nuggets the miner has in his pockets
    int                   m_iGoldCarried;

    int                   m_iMoneyInBank;

    //the higher the value, the thirstier the miner
    int                   m_iThirst;

    //the higher the value, the more tired the miner
    int                   m_iFatigue;

public:

    Baker(int id) :m_Location(shack),
        m_iGoldCarried(0),
        m_iMoneyInBank(0),
        m_iThirst(0),
        m_iFatigue(0),
        BaseGameEntity(id)

    {
        //set up state machine
        m_pStateMachine = new StateMachine<Baker>(this);

        m_pStateMachine->SetCurrentState(GoHomeAndSleepTilRested::Instance());

        /* NOTE, A GLOBAL STATE HAS NOT BEEN IMPLEMENTED FOR THE MINER */
    }

    ~Baker() { delete m_pStateMachine; }

    //this must be implemented
    void Update();

    //so must this
    virtual bool  HandleMessage(const Telegram& msg);


    StateMachine<Baker>* GetFSM()const { return m_pStateMachine; }



    //-------------------------------------------------------------accessors
    location_type Location()const { return m_Location; }
    void          ChangeLocation(location_type loc) { m_Location = loc; }

    int           GoldCarried()const { return m_iGoldCarried; }
    void          SetGoldCarried(int val) { m_iGoldCarried = val; }
    void          AddToGoldCarried(int val);
    bool          PocketsFull()const { return m_iGoldCarried >= MaxNuggets; }

    bool          Fatigued()const;
    void          DecreaseFatigue() { m_iFatigue -= 1; }
    void          IncreaseFatigue() { m_iFatigue += 1; }

    int           Wealth()const { return m_iMoneyInBank; }
    void          SetWealth(int val) { m_iMoneyInBank = val; }
    void          AddToWealth(int val);

    bool          Thirsty()const;
    void          BuyAndDrinkAWhiskey() { m_iThirst = 0; m_iMoneyInBank -= 2; }

};



#endif
