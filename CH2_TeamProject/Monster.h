#pragma once
#include "Character.h"

#include <iostream>
#include <string> 

using namespace std;

// [Mission 1] 클래스 선언
// 언리얼 표준: 클래스 이름은 'A'로 시작합니다.
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
