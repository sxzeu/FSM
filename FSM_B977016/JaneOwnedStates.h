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

//  ���� �� �������ٴ� �޽����� ������ ������ ���� �����մϴ� 
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

// ������ ������ ���������� û�Ҹ� �մϴ�.
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