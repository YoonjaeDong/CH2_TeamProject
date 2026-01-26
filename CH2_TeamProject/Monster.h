#pragma once
#include "Character.h"

#include <iostream>
#include <string> 

using namespace std;

class AMonster : public ACharacter
{
public:
    AMonster(string NewName, int NewHp, int Atk);
    ~AMonster();

protected:
    string Name;
    int Hp;
    int Atk;

public:
    void Attack();
    void TakeDamage(int DamageAmount);
};
