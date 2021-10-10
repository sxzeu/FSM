#include <fstream>
#include <time.h>

#include "Locations.h"
#include "Jane.h"
#include "Baker.h"
#include "Owner.h"   // 고양이 추가
#include "EntityManager.h"
#include "MessageDispatcher.h"
#include "ConsoleUtils.h"
#include "EntityNames.h"


std::ofstream os;

int main()
{
    //define this to send output to a text file (see locations.h)
#ifdef TEXTOUTPUT
    os.open("output.txt");
#endif

    //seed random number generator
    srand((unsigned)time(NULL));

    //create Jane
    Jane* mJane = new Jane(ent_Jane);

    //create Baker
    Baker* mBaker = new Baker(ent_Baker);

    Owner* mOwner = new Owner(ent_Owner);  // 고양이 추가

    //register them with the entity manager
    EntityMgr->RegisterEntity(mJane);
    EntityMgr->RegisterEntity(mBaker);
    EntityMgr->RegisterEntity(mOwner);

    //run Bob and Elsa through a few Update calls
    for (int i = 0; i < 30; ++i)
    {
        mJane->Update();
        mBaker->Update();
        mOwner->Update();

        //dispatch any delayed messages
        Dispatch->DispatchDelayedMessages();

        //Sleep(800);
    }

    //tidy up
    delete mJane;
    delete mBaker;
    delete mOwner;

    //wait for a keypress before exiting
    PressAnyKeyToContinue();


    return 0;
}


