#include "Monster.h"


AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
    : ACharacter(NewName, NewStat)
{
}

FDamageResult AMonster::Attack(ACharacter* Target)
{
    FDamageResult result = ACharacter::Attack(Target);
    string AttackMessage = "이(가) 몽둥이를 휘두릅니다!";
    if (result.bCritical)
    {
        AttackMessage = "이(가) 강하게 내리쳤습니다!!";
    }
    cout << Name << AttackMessage << "데미지 : " << result.Damage << endl;
    cout << Target->GetName() << "HP : " << Target->GetHp() << endl;
    return result;
}