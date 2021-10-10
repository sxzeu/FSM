#pragma once
#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
    Msg_BreadOut,
    Msg_RequestIngredient,
    Msg_BreadShowcase,
    Msg_OrderIngerdient
};


inline std::string MsgToStr(int msg)
{
    switch (msg)
    {
    case Msg_BreadOut:

        return "Bread is out!";

    case Msg_RequestIngredient:

        return "We need more ingredient!";

    case Msg_OrderIngerdient:
        return "I order it don't worry!";

    default:
        return "Not recognized!";
    }
}

#endif