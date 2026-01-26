#pragma once
#include <iostream>
#include <string>

using namespace std;

class APlayer
{
public:
    APlayer();
    ~APlayer();

protected:
  
    string Name;

    int Hp;

    int Atk;

public:

    void Attack();

    void TakeDamage(int DamageAmount);

};