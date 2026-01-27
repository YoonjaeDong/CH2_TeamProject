#pragma once
#include "Character.h"

#include <iostream>
#include <string> 

using namespace std;

class AMonster : public ACharacter
{
public:
    AMonster(string NewName, FUnitStat);
};
