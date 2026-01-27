#pragma once
#include "Character.h"

#include <iostream>
#include <string> 

using namespace std;

class AMonster : public ACharacter
{
public:
    AMonster(string NewName, int NewHp, int Atk, int Def, float Cri);
};
