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

// ���� ���̸� ���࿡ ���� ������
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
