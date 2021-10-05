#pragma once
#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
    Msg_HiHoneyImHome,
    Msg_StewReady,
    Msg_Hee_haw  // ����� �޼��� �߰�
};


inline std::string MsgToStr(int msg)
{
    switch (msg)
    {
    case Msg_HiHoneyImHome:

        return "HiHoneyImHome";

    case Msg_StewReady:

        return "StewReady";

    case Msg_Hee_haw:

        return "Hee-haw!";

    default:

        return "Not recognized!";
    }
}

#endif