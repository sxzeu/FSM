#pragma once
#ifndef OWNER_H
#define OWNER_H


#include <string>
#include <cassert>
#include <iostream>

#include "BaseGameEntity.h"
#include "Locations.h"
#include "ConsoleUtils.h"
#include "OwnerOwnedStates.h"    
#include "StateMachine.h"

template <class entity_type> class State; //pre-fixed with "template <class entity_type> " for vs8 compatibility

struct Telegram;

// 돈통에 돈이 차는지 체크 하는 변수
const int	MoneyCheck = 10;
// 피로도
const int	FeelTired = 6;


class Owner : public BaseGameEntity
{
private:

	//an instance of the state machine class
	StateMachine<Owner>* m_pStateMachine;

	location_type         m_Location;

	bool o_isMoneyFull;
	bool o_isTired;

public:

	Owner(int id) :m_Location(bakery),
		o_isMoneyFull(0),
		o_isTired(0),
		BaseGameEntity(id)
	{
		//set up state machine
		m_pStateMachine = new StateMachine<Owner>(this);

		m_pStateMachine->SetCurrentState(WantToGoHome::Instance());

		/* NOTE, A GLOBAL STATE HAS NOT BEEN IMPLEMENTED FOR THE MINER */
	}

	~Owner() { delete m_pStateMachine; }

	//this must be implemented
	void Update();

	//so must this
	virtual bool  HandleMessage(const Telegram& msg);


	StateMachine<Owner>* GetFSM()const { return m_pStateMachine; }

	//-------------------------------------------------------------accessors
	location_type Location()const { return m_Location; }
	void          ChangeLocation(location_type loc) { m_Location = loc; }

	bool          IsMoneyFull()const { return o_isMoneyFull; }
	bool		  IsTired()const { return o_isTired; }

};



#endif

