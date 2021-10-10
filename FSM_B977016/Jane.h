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
// 제인이 정리해야할 빵의 갯수
const int BreadDisplay = 6;


class Jane : public BaseGameEntity
{
private:

    //an instance of the state machine class
    StateMachine<Jane>* m_pStateMachine;

    location_type         m_Location;



    // the higher the value, the uncleaner bakery
    int                 j_Unclean;
    // 제인이 정리한 빵의 개수 
    int                 j_DisplayBread;

public:

    Jane (int id) :m_Location(bakery),

        j_Unclean(0),
        j_DisplayBread(0),
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

    int           Unclean()const { return j_Unclean; }
    void           IncreaseUnclean() { j_Unclean += 1; }
    void          DecreaseUnclean() { j_Unclean -= 4; }
    bool          MaxUnclean() const { return BakeryUnclean <= j_Unclean; }
    bool          ClearCleaning(){ return j_Unclean == 0; }

    int           Display()const { return j_DisplayBread; }
    //void           IncreaseDisplay() { j_DisplayBread += 1; }
    void          DecreaseDisplay() { j_DisplayBread -= 6; }
    void          MaxDisplay() { j_DisplayBread = 6; }
    bool          ClearDisplay() { return j_DisplayBread = 0; }
    void          ResetDisplay() { j_DisplayBread = 0; }

};



#endif
