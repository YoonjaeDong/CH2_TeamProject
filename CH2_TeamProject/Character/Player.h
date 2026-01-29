#pragma once
#include "Character.h"
#include <string>

using namespace std;

class APlayer: public ACharacter
{
public:
    APlayer(const string& Name, const FUnitStat& Stat);
    
protected:
    int Level;
    int Exp;

public:
    void UseItem();
    void LevelUp();
};