#pragma once
#ifndef BAKER_H
#define BAKER_H


#include <string>
#include <cassert>
#include <iostream>

#include "BaseGameEntity.h"
#include "Locations.h"
#include "ConsoleUtils.h"
#include "BakerOwnedStates.h"
#include "StateMachine.h"

template <class entity_type> class State; //pre-fixed with "template <class entity_type> " for vs8 compatibility

struct Telegram;

// 제빵사가 빵을 몇개나 만드는 지에 대해 체크
const int MaxBread = 6;
// 주방에 재료가 얼마나 있는지 체크 
const int Ingredients = 7;
// 지루하면 노래 바꿔야됨
const int FeelBored = 4;
// 피로하면 퇴근해야함
const int FeelTired = 6;


class Baker : public BaseGameEntity
{
private:

    //an instance of the state machine class
    StateMachine<Baker>* m_pStateMachine;

    location_type         m_Location;

    // 빵 갯수 체크
    int                  b_BreadCount;
    // 현재 재료 체크
    int                  b_Ingredients;
    // 지루함 체크
    int                  b_FeelBored;

public:

    Baker(int id) :m_Location(bakery),
        b_BreadCount(0),
        b_Ingredients(0),
        b_FeelBored(0),
        BaseGameEntity(id)

    {
        //set up state machine
        m_pStateMachine = new StateMachine<Baker>(this);

        m_pStateMachine->SetCurrentState(BakeBread::Instance());

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

 
    bool         IsBreadFull()const;
    void         MadeBread() { b_BreadCount += 1; }

    void         IncreaseFeelBored(){ b_FeelBored += 1; }
    bool         IsFeelBoredFull()const;
    void         PlaySong() { b_FeelBored = 0; }

    bool        IsIngredientsEmpty()const;
    void        DecreaseIngredients() { b_Ingredients -= 1; }
    void        ResetIngredients() { b_Ingredients = 7; }
};



#endif
