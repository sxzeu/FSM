#pragma once
#ifndef BAKER_OWNED_STATES_H
#define BAKER_OWNED_STATES_H

#include "State.h"


class Baker;
struct Telegram;


class BakeBread : public State<Baker>
{
private:

	BakeBread() {}

	//copy ctor and assignment should be private
	BakeBread(const BakeBread&);
	BakeBread& operator=(const BakeBread&);

public:

	//this is a singleton
	static BakeBread* Instance();

	virtual void Enter(Baker* baker);

	virtual void Execute(Baker* baker);

	virtual void Exit(Baker* baker);

	virtual bool OnMessage(Baker* agent, const Telegram& msg);

};

class RequestIngredients : public State<Baker>
{
private:

	RequestIngredients() {}

	//copy ctor and assignment should be private
	RequestIngredients(const RequestIngredients&);
	RequestIngredients& operator=(const RequestIngredients&);

public:

	//this is a singleton
	static RequestIngredients* Instance();

	virtual void Enter(Baker* baker);

	virtual void Execute(Baker* baker);

	virtual void Exit(Baker* baker);

	virtual bool OnMessage(Baker* agent, const Telegram& msg);

};

class PlaySong : public State<Baker>
{
private:

	PlaySong() {}

	//copy ctor and assignment should be private
	PlaySong(const PlaySong&);
	PlaySong& operator=(const PlaySong&);

public:

	//this is a singleton
	static PlaySong* Instance();

	virtual void Enter(Baker* baker);

	virtual void Execute(Baker* baker);

	virtual void Exit(Baker* baker);

	virtual bool OnMessage(Baker* agent, const Telegram& msg);
};

#endif