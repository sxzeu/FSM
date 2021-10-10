#pragma once
#ifndef OWNER_OWNED_STATES_H
#define OWNER_OWNED_STATES_H

#include "State.h"


class Owner;
struct Telegram;


//돈통에 돈이 얼마나 찼는지 확인함
class CheckMoney : public State<Owner>
{
private:

	CheckMoney() {}

	//copy ctor and assignment should be private
	CheckMoney(const CheckMoney&);
	CheckMoney& operator=(const CheckMoney&);

public:

	//this is a singleton
	static CheckMoney* Instance();

	virtual void Enter(Owner* owner);

	virtual void Execute(Owner* owner);

	virtual void Exit(Owner* owner);

	virtual bool OnMessage(Owner* agent, const Telegram& msg);

};

// 재료 주문하기
class OrderIngredients : public State<Owner>
{
private:

	OrderIngredients() {}

	//copy ctor and assignment should be private
	OrderIngredients(const OrderIngredients&);
	OrderIngredients& operator=(const OrderIngredients&);

public:

	//this is a singleton
	static OrderIngredients* Instance();

	virtual void Enter(Owner* owner);

	virtual void Execute(Owner* owner);

	virtual void Exit(Owner* owner);

	virtual bool OnMessage(Owner* agent, const Telegram& msg);
};

// 돈이 쌓이면 은행에 가서 저금함
class GotoBank: public State<Owner>
{
private:

	GotoBank() {}

	//copy ctor and assignment should be private
	GotoBank(const GotoBank&);
	GotoBank& operator=(const GotoBank&);

public:

	//this is a singleton
	static GotoBank* Instance();

	virtual void Enter(Owner* owner);

	virtual void Execute(Owner* owner);

	virtual void Exit(Owner* owner);

	virtual bool OnMessage(Owner* agent, const Telegram& msg);

};
#pragma once
#endif
