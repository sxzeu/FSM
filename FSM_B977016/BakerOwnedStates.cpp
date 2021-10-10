#include "BakerOwnedStates.h"
#include "Baker.h"
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

BakeBread* BakeBread::Instance()
{
    static BakeBread instance;

    return &instance;
}

void BakeBread::Enter(Baker* pBaker)
{
}

void BakeBread::Execute(Baker* pBaker)
{
    //if the miner is at the goldmine he digs for gold until he
    //is carrying in excess of MaxNuggets. If he gets thirsty during
    //his digging he packs up work for a while and changes state to
    //gp to the saloon for a whiskey.
    pBaker->MadeBread();
    pBaker->IncreaseFeelBored();
    pBaker->DecreaseIngredients();

    cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "Baking some bread";

    //if enough gold mined, go and put it in the bank
    if (pBaker->IsIngredientsEmpty())
    {
        pBaker->GetFSM()->ChangeState(RequestIngredients::Instance());
    }

    if (pBaker->IsFeelBoredFull())
    {
        pBaker->GetFSM()->ChangeState(PlaySong::Instance());
    }
}

void BakeBread::Exit(Baker* pBaker)
{
    Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
        pBaker->ID(),        //ID of sender      : 제빵사가 
        ent_Jane,            //ID of recipient : 제인에게 
        Msg_BreadOut,   //the message           : 빵이 나왔음을 알린다
        (void*)NO_ADDITIONAL_INFO);
}

bool BakeBread::OnMessage(Baker* pBaker, const Telegram& msg)
{
    SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    switch (msg.Msg)
    {
    case  Msg_OrderIngerdient:

        cout << "\nMessage handled by " << GetNameOfEntity(pBaker->ID())
            << " at time: " << Clock->GetCurrentTime();

        SetTextColor(0x000f);

        cout << "\n" << GetNameOfEntity(pBaker->ID())
            << ":Thank you I check it!";

        pBaker->GetFSM()->ChangeState(BakeBread::Instance());

        return true;

    }//end switch

    return false; //send message to global message handler
}
//----------------------------------------methods for VisitBankAndDepositGold

RequestIngredients* RequestIngredients::Instance()
{
    static RequestIngredients instance;

    return &instance;
}

void RequestIngredients::Enter(Baker* pBaker)
{
    SetTextColor(0x000f);
    cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "Oh, I have to tell owner to order ingredients";
}
void RequestIngredients::Execute(Baker* pBaker)
{
    Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
        pBaker->ID(),        //ID of sender      : 제빵사가
        ent_Owner,            //ID of recipient : 사장에게
        Msg_RequestIngredient,   //the message           : 재료가 떨어졌음을 이야기한다
        (void*)NO_ADDITIONAL_INFO);
    pBaker->ResetIngredients();
}
void RequestIngredients::Exit(Baker* pBaker)
{
    
}

bool RequestIngredients::OnMessage(Baker* pBaker, const Telegram& msg)
{
    SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    switch (msg.Msg)
    {
    case  Msg_OrderIngerdient:

        cout << "\nMessage handled by " << GetNameOfEntity(pBaker->ID())
            << " at time: " << Clock->GetCurrentTime();
        SetTextColor(0x000f);

        cout << "\n" << GetNameOfEntity(pBaker->ID())
            << ":Thank you I check it!";

        pBaker->GetFSM()->ChangeState(BakeBread::Instance());

        return true;

    }//end switch

    return false; //send message to global message handler
}
//----------------------------------------methods for GoHomeAndSleepTilRested

PlaySong* PlaySong::Instance()
{
    static PlaySong instance;

    return &instance;
}

void PlaySong::Enter(Baker* pBaker)
{
    SetTextColor(0x000f);
    cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "Wow, It's too boring. I need new music.";
}

void PlaySong::Execute(Baker* pBaker)
{
    SetTextColor(0x000f);
    cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": "<< "I played new music.";
    pBaker->PlaySong(); 
    pBaker->GetFSM()->ChangeState(BakeBread::Instance());
}

void PlaySong::Exit(Baker* pBaker)
{
    SetTextColor(0x000f);
    cout << "\n" << GetNameOfEntity(pBaker->ID()) << ": " << "New music is so good.";
}

bool PlaySong::OnMessage(Baker* pBaker, const Telegram& msg)
{
    SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    switch (msg.Msg)
    {
    case  Msg_OrderIngerdient:

        cout << "\nMessage handled by " << GetNameOfEntity(pBaker->ID())
            << " at time: " << Clock->GetCurrentTime();

        SetTextColor(0x000f);

        cout << "\n" << GetNameOfEntity(pBaker->ID())
            << ":Thank you I check it!";

        pBaker->GetFSM()->ChangeState(BakeBread::Instance());

        return true;

    }//end switch

    return false; //send message to global message handler
}