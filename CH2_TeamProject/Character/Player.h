#pragma once
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class APlayer: public ACharacter
{
public:
    APlayer(string Name, int Hp, int Atk);
};