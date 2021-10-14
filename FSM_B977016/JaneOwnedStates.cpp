#include "JaneOwnedStates.h"
#include "Jane.h"
#include "Locations.h"
#include "EntityNames.h"

#include "State.h"
#include "Telegram.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "CrudeTimer.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;

#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

//--------------------------------------methods for BakeBread

WorkingAtBakery* WorkingAtBakery::Instance()
{
    static WorkingAtBakery instance;

    return &instance;
}

void WorkingAtBakery::Enter(Jane* pJane)
{
}

void WorkingAtBakery::Execute(Jane* pJane)
{
    pJane->IncreaseUnclean();

    cout << "\n" << GetNameOfEntity(pJane->ID()) << ": " << "Working at bakery";

    if (pJane->MaxUnclean())
    {
        pJane ->GetFSM()->ChangeState(Cleaning::Instance());
    }

}

void WorkingAtBakery::Exit(Jane* pJane)
{
    cout << "\n" << GetNameOfEntity(pJane->ID()) << ": " << "I have to do other work!";
}

bool WorkingAtBakery::OnMessage(Jane* pJane, const Telegram& msg)
{
    SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    switch (msg.Msg)
    {
    case Msg_BreadOut:
    {
        cout << "\nMessage handled by " << GetNameOfEntity(pJane->ID()) << " at time: "
            << Clock->GetCurrentTime();

        SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);

        cout << "\n" << GetNameOfEntity(pJane->ID()) <<
            ": Okay I see. I will display it";

        pJane->GetFSM()->ChangeState(DisplayBread::Instance());
    }


    return true;
    }
}
//----------------------------------------methods for VisitBankAndDepositGold

DisplayBread* DisplayBread::Instance()
{
    static DisplayBread instance;

    return &instance;
}

void DisplayBread::Enter(Jane* pJane)
{
    cout << "\n" << GetNameOfEntity(pJane->ID()) << ": " << "Oh, I can display bread now!";
    pJane->MaxDisplay();
}
void DisplayBread::Execute(Jane* pJane)
{
    pJane->ResetDisplay();
    pJane->GetFSM()->ChangeState(WorkingAtBakery::Instance());
}
void DisplayBread::Exit(Jane* pJane)
{
    cout << "\n" << GetNameOfEntity(pJane->ID()) << ": " << "I'm done! if bread is out call me again.";
}
bool DisplayBread::OnMessage(Jane* pJane, const Telegram& msg)
{
    //send msg to global message handler
    return false;
}

//----------------------------------------methods for GoHomeAndSleepTilRested

Cleaning* Cleaning::Instance()
{
    static Cleaning instance;

    return &instance;
}

void Cleaning::Enter(Jane* pJane)
{
    cout << "\n" << GetNameOfEntity(pJane->ID()) << ": " << "too dirty, Let's clean bakery.";
}

void Cleaning::Execute(Jane* pJane)
{
    pJane->ClearClean();

}

void Cleaning::Exit(Jane* pJane)
{
    pJane->GetFSM()->ChangeState(WorkingAtBakery::Instance());
    cout << "\n" << GetNameOfEntity(pJane->ID()) << ": " << "Wow! so clean.";
}

bool Cleaning::OnMessage(Jane* pJane, const Telegram& msg)
{
    //send msg to global message handler
    return false;
}