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
//  ������ û���� �����ϴ� ������ 5�� �Ǹ� �˹ٻ� ������ ������ û���ϱ� �����Ѵ�
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


//------------------------------------------------------------------------
// ������ ����Ŀ���� �˹ٻ��Դϴ�. ������ ����Ŀ������ �ٹ��ð����� �ٹ��մϴ�. 
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



//------------------------------------------------------------------------
//
//  ���� �� �������ٴ� �޽����� ������ ������ ���� �����մϴ� 
//------------------------------------------------------------------------
class DisplayBreads : public State<Jane>
{
private:

    DisplayBreads() {}

    //copy ctor and assignment should be private
    DisplayBreads(const DisplayBreads&);
    DisplayBreads& operator=(const DisplayBreads&);

public:

    //this is a singleton
    static DisplayBreads* Instance();

    virtual void Enter(Jane* jane);

    virtual void Execute(Jane* jane);

    virtual void Exit(Jane* jane);

    virtual bool OnMessage(Jane* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//  �ٹ��ð��� �� ä��� ������ ������ ���ư� �޽��� ���մϴ�.
//------------------------------------------------------------------------
class GoToHomeAndTakeARest : public State<Jane>
{
private:

    GoToHomeAndTakeARest() {}

    //copy ctor and assignment should be private
    GoToHomeAndTakeARest(const GoToHomeAndTakeARest&);
    GoToHomeAndTakeARest& operator=(const GoToHomeAndTakeARest&);

public:

    //this is a singleton
    static GoToHomeAndTakeARest* Instance();

    virtual void Enter(Jane* jane);

    virtual void Execute(Jane* jane);

    virtual void Exit(Jane* jane);

    virtual bool OnMessage(Jane* agent, const Telegram& msg);
};



#endif