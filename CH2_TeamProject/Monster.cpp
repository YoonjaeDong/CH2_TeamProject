#include "Monster.h"


AMonster::AMonster(string NewName, int NewHp, int NewAtk)
    : ACharacter(NewName, NewHp, NewAtk)
{
}

AMonster::~AMonster()
{
    cout << "AMonster 소멸됨" << endl;
}

void AMonster::Attack()
{
    cout << Name << "가 공격합니다! (공격력 : " << Atk << ")" << endl;
}

void AMonster::TakeDamage(int DamageAmount)
{
   
}