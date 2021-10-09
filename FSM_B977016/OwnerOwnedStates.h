#pragma once
#ifndef OWNER_OWNED_STATES_H
#define OWNER_OWNED_STATES_H

#include "State.h"


class Owner;
struct Telegram;


//���뿡 ���� �󸶳� á���� Ȯ����
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

// ��� �ֹ��ϱ�
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

// ������ �Ƿ� ���̸� �����
class WantToGoHome: public State<Owner>
{
private:

	WantToGoHome() {}

	//copy ctor and assignment should be private
	WantToGoHome(const WantToGoHome&);
	WantToGoHome& operator=(const WantToGoHome&);

public:

	//this is a singleton
	static WantToGoHome* Instance();

	virtual void Enter(Owner* owner);

	virtual void Execute(Owner* owner);

	virtual void Exit(Owner* owner);

	virtual bool OnMessage(Owner* agent, const Telegram& msg);

};
#pragma once
