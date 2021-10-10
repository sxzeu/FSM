#include "Jane.h"

bool Jane::HandleMessage(const Telegram& msg)
{
    return m_pStateMachine->HandleMessage(msg);
}


void Jane::Update()
{
    //set text color to green
    SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    m_pStateMachine->Update();
}
