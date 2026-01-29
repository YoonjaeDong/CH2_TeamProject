#include "Monster.h"


AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
    : ACharacter(NewName, NewStat)
{
}

void AMonster::Attack(ACharacter* Target)
{
    cout << "크아앙!" << Name << "이(가) 공격합니다!" << endl;

    Target->TakeDamage(Stat.Atk);
}
