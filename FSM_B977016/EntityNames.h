#pragma once
#ifndef NAMES_H
#define NAMES_H

#include <string>

enum
{
    ent_Jane,

    ent_Baker,

    ent_Owner 
};

inline std::string GetNameOfEntity(int n)
{
    switch (n)
    {
    case ent_Jane:

        return "Jane";

    case ent_Baker:

        return "Baker";

    case ent_Owner:

        return "Owner";

    default:

        return "UNKNOWN!";
    }
}

#endif