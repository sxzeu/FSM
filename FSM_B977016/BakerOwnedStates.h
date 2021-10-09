#pragma once
#ifndef BAKER_OWNED_STATES_H
#define BAKER_OWNED_STATES_H

//------------------------------------------------------------------------
//
//  Name:   CatOwnedStates.h
//
//  고양이는 계속 잠을 잡니다.그러다 목이 마르면 집에 들어가 물을 마십니다.
//  집에 들어갈때, 엘사에게 인사를 합니다. 
//  물을 마셔 갈증이 해소되었다면, 다시 마당에 나가 잠을 잡니다.
//
//------------------------------------------------------------------------
#include "State.h"


class Baker;
struct Telegram;


class BakeBreads : public State<Baker>
{
private:

	BakeBreads() {}

	//copy ctor and assignment should be private
	BakeBreads(const BakeBreads&);
	BakeBreads& operator=(const BakeBreads&);

public:

	//this is a singleton
	static BakeBreads* Instance();

	virtual void Enter(Baker* baker);

	virtual void Execute(Baker* baker);

	virtual void Exit(Baker* baker);

	virtual bool OnMessage(Baker* agent, const Telegram& msg);

};

class CheckIngredients : public State<Baker>
{
private:

	CheckIngredients() {}

	//copy ctor and assignment should be private
	CheckIngredients(const CheckIngredients&);
	CheckIngredients& operator=(const CheckIngredients&);

public:

	//this is a singleton
	static CheckIngredients* Instance();

	virtual void Enter(Baker* baker);

	virtual void Execute(Baker* baker);

	virtual void Exit(Baker* baker);

	virtual bool OnMessage(Baker* agent, const Telegram& msg);
};

class CheckBored : public State<Baker>
{
private:

	CheckBored() {}

	//copy ctor and assignment should be private
	CheckBored(const CheckBored&);
	CheckBored& operator=(const CheckBored&);

public:

	//this is a singleton
	static CheckBored* Instance();

	virtual void Enter(Baker* baker);

	virtual void Execute(Baker* baker);

	virtual void Exit(Baker* baker);

	virtual bool OnMessage(Baker* agent, const Telegram& msg);
};

