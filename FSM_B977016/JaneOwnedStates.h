#pragma once
#ifndef JANE_OWNED_STATES_H
#define JANE_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   MinerOwnedStates.h
//
//  Desc:   All the states that can be assigned to the Miner class.
//          Note that a global state has not been implemented.
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "State.h"

class Jane;
struct Telegram;



//------------------------------------------------------------------------
//  매장의 청결을 관리하는 변수가 5가 되면 알바생 제인은 매장을 청소하기 시작한다
//------------------------------------------------------------------------
class EnterCleanBakeryAndClean : public State<Jane>
{
private:

    EnterCleanBakeryAndClean() {}

    //copy ctor and assignment should be private
    EnterCleanBakeryAndClean(const EnterCleanBakeryAndClean&);
    EnterCleanBakeryAndClean& operator=(const EnterCleanBakeryAndClean&);

public:

    //this is a singleton
    static EnterCleanBakeryAndClean* Instance();

    virtual void Enter(Jane* jane);

    virtual void Execute(Jane* jane);

    virtual void Exit(Jane* jane);

    virtual bool OnMessage(Jane* agent, const Telegram& msg);

};

// 제인은 베이커리의 알바생입니다. 제인은 베이커리에서 근무시간동안 근무합니다. 
//------------------------------------------------------------------------
class WorkingAtBakery : public State<Jane>
{
private:

    WorkingAtBakery() {}

    //copy ctor and assignment should be private
    WorkingAtBakery(const WorkingAtBakery&);
    WorkingAtBakery& operator=(const WorkingAtBakery&);

public:

    //this is a singleton
    static WorkingAtBakery* Instance();

    virtual void Enter(Jane* jane);

    virtual void Execute(Jane* jane);

    virtual void Exit(Jane* jane);

    virtual bool OnMessage(Jane* agent, const Telegram& msg);
};

//  빵이 다 구워졌다는 메시지를 받으면 제인은 빵을 정리합니다 
//------------------------------------------------------------------------
class DisplayBread : public State<Jane>
{
private:

    DisplayBread() {}

    //copy ctor and assignment should be private
    DisplayBread(const DisplayBread&);
    DisplayBread& operator=(const DisplayBread&);

public:

    //this is a singleton
    static DisplayBread* Instance();

    virtual void Enter(Jane* jane);

    virtual void Execute(Jane* jane);

    virtual void Exit(Jane* jane);

    virtual bool OnMessage(Jane* agent, const Telegram& msg);
};

// 제인은 매장이 더러워지면 청소를 합니다.
class  Cleaning : public State<Jane>
{
private:

    Cleaning() {}

    //copy ctor and assignment should be private
    Cleaning(const Cleaning&);
    Cleaning& operator=(const Cleaning&);

public:

    //this is a singleton
    static Cleaning* Instance();

    virtual void Enter(Jane* jane);

    virtual void Execute(Jane* jane);

    virtual void Exit(Jane* jane);

    virtual bool OnMessage(Jane* agent, const Telegram& msg);
};



#endif