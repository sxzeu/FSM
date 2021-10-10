#include "OwnerOwnedStates.h"
#include "Owner.h"
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


//----------------------------------
CheckMoney* CheckMoney::Instance()
{
    static CheckMoney instance;

    return &instance;
}

void CheckMoney::Enter(Owner* pOwner)
{
    if (pOwner->Location() != bakery)
    {
        cout << "\n" << GetNameOfEntity(pOwner->ID()) << ": " << "[The owner in the bakery.]";

        pOwner->ChangeLocation(bakery);
    }
}

void CheckMoney::Execute(Owner* pOwner)
{
    pOwner->IncreaseMoney();

    cout << "\n" << GetNameOfEntity(pOwner->ID()) << ": " << "Working at bakery";

    if (pOwner->IsMoneyFull())
    {
        pOwner->GetFSM()->ChangeState(GotoBank::Instance());
    }

}
bool CheckMoney::OnMessage(Owner* pOwner, const Telegram& msg)
{
    SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    switch (msg.Msg)
    {
    case Msg_RequestIngredient:

        cout << "\nMessage handled by " << GetNameOfEntity(pOwner->ID())
            << " at time: " << Clock->GetCurrentTime();

        SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

        cout << "\n" << GetNameOfEntity(pOwner->ID())
            << ": Okay I see. I will order ingredients";

        pOwner->GetFSM()->ChangeState(OrderIngredients::Instance());

        return true;

    }//end switch

    return false; //send message to global message handler
}

void CheckMoney::Exit(Owner* pOwner)
{
    cout << "\n" << GetNameOfEntity(pOwner->ID()) << ": " << "I have to go bank!";
}

//----------------------------------------methods for GoHomeAndSleepTilRested

GotoBank* GotoBank::Instance()
{
    static GotoBank instance;

    return &instance;
}

void GotoBank::Enter(Owner* pOwner)
{
    if (pOwner->Location() != bank)
    {
        cout << "\n" << GetNameOfEntity(pOwner->ID()) << ": " << "[The owner in the bank.]";

        pOwner->ChangeLocation(bank);
    }
}

void GotoBank::Execute(Owner* pOwner)
{
    pOwner->ResetMoney();
    cout << "\n" << GetNameOfEntity(pOwner->ID()) << ": " << "[I input my cash to my account.]";
    pOwner->GetFSM()->ChangeState(CheckMoney::Instance());
}

bool GotoBank::OnMessage(Owner* pOwner, const Telegram& msg)
{
    /*
    SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    switch (msg.Msg)
    {
    case Msg_RequestIngredient:

        cout << "\nMessage handled by " << GetNameOfEntity(pOwner->ID())
            << " at time: " << Clock->GetCurrentTime();

        SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

        cout << "\n" << GetNameOfEntity(pOwner->ID())
            << ": Okay I see. I will order ingredients";

        pOwner->GetFSM()->ChangeState(OrderIngredients::Instance());

        return true;

    }//end switch
    */
    return false; //send message to global message handler
    
}
void GotoBank::Exit(Owner* pOwner)
{
    cout << "\n" << GetNameOfEntity(pOwner->ID()) << ": " << "I'm back to bakery";
    if (pOwner->Location() != bakery)
    {
        cout << "\n" << GetNameOfEntity(pOwner->ID()) << ": " << "[Owner is back to the bakery.]";

        pOwner->ChangeLocation(bakery);
        //pOwner->GetFSM()->ChangeState(CheckMoney::Instance());
    }
}

//-----------------------------------------------

OrderIngredients* OrderIngredients::Instance()
{
    static OrderIngredients instance;

    return &instance;
}
void OrderIngredients::Enter(Owner* pOwner)
{
  
}

void OrderIngredients::Execute(Owner* pOwner)
{
    Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
        pOwner->ID(),        //ID of sender      :사장이
        ent_Baker,            //ID of recipient : 제빵사에게 
        Msg_OrderIngerdient,   //the message           : 재료주문했음을 이야기한다
        (void*)NO_ADDITIONAL_INFO);
    // pOwner->GetFSM()->ChangeState(CheckMoney::Instance());
}


void OrderIngredients::Exit(Owner* pOwner)
{
    pOwner->GetFSM()->ChangeState(CheckMoney::Instance());
    if (pOwner->Location() != bakery)
    {
        cout << "\n" << GetNameOfEntity(pOwner->ID()) << ": " << "[Owner is back to the bakery.]";

        pOwner->ChangeLocation(bakery);
        //pOwner->GetFSM()->ChangeState(CheckMoney::Instance());
    }
}

bool OrderIngredients::OnMessage(Owner* pOwner, const Telegram& msg)
{
    //send msg to global message handler
    return false;
}