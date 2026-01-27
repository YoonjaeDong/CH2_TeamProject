#include "Player.h"

APlayer::APlayer(string NewName, int NewHp, int NewAtk, int NewDef, float NewCri)
    : ACharacter(NewName, NewHp, NewAtk, NewDef, NewCri)
{
    cout << "[생성]" << Name << "가 전장에 나타났습니다! (HP : " << Hp << ")" << endl;
}
