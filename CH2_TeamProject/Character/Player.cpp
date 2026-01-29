#include "Player.h"

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
    : ACharacter(NewName, NewStat)
{
    Level = 1;
    Exp = 0;
}

FDamageResult APlayer::Attack(ACharacter* Target)
{
    FDamageResult result = ACharacter::Attack(Target);
    string AttackMessage = "이(가) 검으로 벱니다!";
    if (result.bCritical)
    {
        AttackMessage = "검으로 급소를 베었습니다!!";
    }
    cout << Name << AttackMessage << "데미지 : " << result.Damage << endl;
    cout << Target->GetName() << "HP : " << Target->GetHp() << endl;
    return result;
}

void APlayer::UseItem()
{

}

void APlayer::LevelUp()
{

}
