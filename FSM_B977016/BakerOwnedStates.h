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

