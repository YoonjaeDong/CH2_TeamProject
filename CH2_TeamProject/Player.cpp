#include "Player.h"

APlayer::APlayer(string NewName, int NewHp, int NewAtk)
    : ACharacter(NewName, NewHp, NewAtk)
{
    cout << "[생성]" << Name << "가 전장에 나타났습니다! (HP : " << Hp << ")" << endl;
}

APlayer::~APlayer()
{
    cout << "APlayer 소멸됨" << endl;
}



void APlayer::Attack()
{
    cout << Name << "가 공격합니다! (공격력 : " << Atk << ")" << endl;
}

void APlayer::TakeDamage(int DamageAmount)
{
    Hp = Hp - DamageAmount;

    cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
    cout << "   -> 남은 체력: " << Hp << endl;
}