#pragma once
#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
    Msg_BreadOut,
    Msg_BreadPack,
    Msg_BreadShowcase
};


inline std::string MsgToStr(int msg)
{
    switch (msg)
    {
    case Msg_BreadOut:

        return "Bread is out!";

    case Msg_BreadPack:

        return "I packed it!";

    case Msg_BreadShowcase:

        return "I displayed it!";

    default:

        return "Not recognized!";
    }
}

#endif