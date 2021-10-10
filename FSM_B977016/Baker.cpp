#include "Baker.h"

bool Baker::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}


void Baker::Update()
{
	SetTextColor(0x000f);  // го╬А╩Ж ╠ш╬╬
	//SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

	b_FeelBored += 1;

	m_pStateMachine->Update();
}

bool Baker::IsBreadFull()const
{
	if (b_BreadCount >= MaxBread) return true; 

	return false;
}

bool Baker::IsFeelBoredFull()const
{
	if (b_FeelBored >= FeelBored) return true;
	return false;
}

bool Baker::IsIngredientsEmpty()const
{
	if (b_Ingredients <= 0) return true;
	return false;
}