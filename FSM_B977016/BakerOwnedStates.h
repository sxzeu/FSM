#pragma once
#ifndef BAKER_OWNED_STATES_H
#define BAKER_OWNED_STATES_H

//------------------------------------------------------------------------
//
//  Name:   CatOwnedStates.h
//
//  ����̴� ��� ���� ��ϴ�.�׷��� ���� ������ ���� �� ���� ���ʴϴ�.
//  ���� ����, ���翡�� �λ縦 �մϴ�. 
//  ���� ���� ������ �ؼҵǾ��ٸ�, �ٽ� ���翡 ���� ���� ��ϴ�.
//
//------------------------------------------------------------------------
#include "State.h"


class Cat;
struct Telegram;


class SleepAllDay : public State<Cat>
{
private:

	SleepAllDay() {}

	//copy ctor and assignment should be private
	SleepAllDay(const SleepAllDay&);
	SleepAllDay& operator=(const SleepAllDay&);

public:

	//this is a singleton
	static SleepAllDay* Instance();

	virtual void Enter(Cat* miner);

	virtual void Execute(Cat* miner);

	virtual void Exit(Cat* miner);

	virtual bool OnMessage(Cat* agent, const Telegram& msg);

};

//------------------------------------------------------------------------

class VisitHomeGetWater : public State<Cat>
{
private:

	VisitHomeGetWater() {}

	//copy ctor and assignment should be private
	VisitHomeGetWater(const VisitHomeGetWater&);
	VisitHomeGetWater& operator=(const VisitHomeGetWater&);

public:

	//this is a singleton
	static VisitHomeGetWater* Instance();

	virtual void Enter(Cat* miner);

	virtual void Execute(Cat* miner);

	virtual void Exit(Cat* miner);

	virtual bool OnMessage(Cat* agent, const Telegram& msg);
};



