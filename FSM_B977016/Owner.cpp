#include "Owner.h"

bool Owner::HandleMessage(const Telegram& msg)
{
    return m_pStateMachine->HandleMessage(msg);
}


void Owner::Update()
{
    //set text color to green
    o_Money += 1;
    SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    m_pStateMachine->Update();
}