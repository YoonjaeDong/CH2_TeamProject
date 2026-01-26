#pragma once
#include <iostream>
#include <string> 

using namespace std;

class ACharacter
{
public:
    ACharacter(string Name, int Hp, int Atk);
    ~ACharacter();

protected:   
    string Name;
    int Hp;
    int Atk;


public:
    void Attack(ACharacter* target)
    {
        target->TakeDamage(Atk);
    }
    void TakeDamage(int DamageAmount);
    int GetHp()
    {
        return Hp;
    }
    bool IsDead()
    {
        if (Hp <= 0)
            return true;
        else
            return false;
    }
};