#include "Player.h"

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
    : ACharacter(NewName, NewStat)
{
    Level = 1;
    Exp = 0;
}

void APlayer::UseItem()
{

}

void APlayer::LevelUp()
{

}

void APlayer::Attack(ACharacter* Target)
{
    cout << Name << "이(가) 검을 휘둘러 공격합니다!" << endl;

    ACharacter::Attack(Target);
}