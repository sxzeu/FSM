#pragma once
#ifndef MINER_H
#define MINER_H

#include <string>
#include <cassert>
#include <iostream>

#include "BaseGameEntity.h"
#include "Locations.h"
#include "misc/ConsoleUtils.h"
#include "JaneOwnedStates.h"
#include "StateMachine.h"

template <class entity_type> class State; //pre-fixed with "template <class entity_type> " for vs8 compatibility

struct Telegram;

//the amount of gold a miner must have before he feels he can go home
const int ComfortLevel = 5;
//the amount of nuggets a miner can carry
const int MaxNuggets = 3;
//above this value a miner is thirsty
const int ThirstLevel = 5;
//above this value a miner is sleepy
const int TirednessThreshold = 5;

// the state of uncleanliness in bakery
const int BakeryUnclean = 5;
// the time which jane work at bakery
const int WorkingTime = 7;


class Jane : public BaseGameEntity
{
private:

    //an instance of the state machine class
    StateMachine<Jane>* m_pStateMachine;

    location_type         m_Location;



    // the higher the value, the more tired Jane
    int                 j_WorkTime;
    // the higher the value, the uncleaner bakery
    int                 j_Unclean;

public:

    Jane (int id) :m_Location(bakery),

        j_WorkTime(0),
        j_Unclean(0)
        BaseGameEntity(id)

    {
        //set up state machine
        m_pStateMachine = new StateMachine<Jane>(this);

        m_pStateMachine->SetCurrentState(WorkAtBakery::Instance());

        /* NOTE, A GLOBAL STATE HAS NOT BEEN IMPLEMENTED FOR THE MINER */
    }

    ~Jane() { delete m_pStateMachine; }

    //this must be implemented
    void Update();

    //so must this
    virtual bool  HandleMessage(const Telegram& msg);


    StateMachine<Jane>* GetFSM()const { return m_pStateMachine; }



    //-------------------------------------------------------------accessors
    location_type Location()const { return m_Location; }
    void          ChangeLocation(location_type loc) { m_Location = loc; }

    int           WorkAtBakery()const { return j_WorkTime; }
    int           IncreaseWorkTime() { j_WorkTime += 1; }
    int           DecreseWorkTime() { j_WorkTime -= 1; }

    int           Unclean()const { return j_Unclean; }
    int           IncreaseUnclean() { j_Unclean += 1; }
    int           DecreaseUnclean() { j_Unclean -= 2; }


};



#endif
