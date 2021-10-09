#pragma once
#ifndef JANE_H
#define JANE_H

#include <string>
#include <cassert>
#include <iostream>

#include "BaseGameEntity.h"
#include "Locations.h"
#include "ConsoleUtils.h"
#include "JaneOwnedStates.h"
#include "StateMachine.h"

template <class entity_type> class State; //pre-fixed with "template <class entity_type> " for vs8 compatibility

struct Telegram;

// the state of uncleanliness in bakery
const int BakeryUnclean = 4;
// the time which jane work at bakery
const int WorkingTime = 7;
// 제인이 정리해야할 빵의 갯수
const int BreadDisplay = 6;
// 제인이 퇴근하고 없애는 스트레스
const int StressOfJane = 7;


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
    // 제인이 정리한 빵의 개수 
    int                 j_DisplayBread;
    // 제인이 퇴근 후 출근까지의 시간
    int                 j_Stress;

public:

    Jane (int id) :m_Location(bakery),

        j_WorkTime(0),
        j_Unclean(0),
        j_DisplayBread(0),
        j_Stress(0),
        BaseGameEntity(id)

    {
        //set up state machine
        m_pStateMachine = new StateMachine<Jane>(this);

        m_pStateMachine->SetCurrentState(WorkingAtBakery::Instance());

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
    //void          SetWorkTime(int val) { j_WorkTime = val;  }
    int           AddToWorkTime() { j_WorkTime += 1; }
    bool          MaxWorkTime() const { return WorkingTime <= j_WorkTime; }
    void          ResetWorkTime(){ j_WorkTime = 0; }

    int           Unclean()const { return j_Unclean; }
    int           IncreaseUnclean() { j_Unclean += 1; }
    int           DecreaseUnclean() { j_Unclean -= 1; }
    bool          MaxUnclean() const { return BakeryUnclean <= j_Unclean; }

    int           Display()const { return j_DisplayBread; }
    int           IncreaseDisplay() { j_DisplayBread += 1; }
    int           DecreaseDisplay() { j_DisplayBread -= 2; }
    bool          MaxDisplay() const { return BreadDisplay <= j_DisplayBread; }
    void          ClearDisplay() { j_DisplayBread = 0; }

};



#endif
