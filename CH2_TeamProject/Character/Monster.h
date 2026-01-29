#pragma once
#include "Character.h"

#include <iostream>
#include <string> 

using namespace std;

class AMonster : public ACharacter
{
public:
    AMonster(const string& NewName, const FUnitStat& NewStat);

    void Attack(ACharacter* Target) override;
};
