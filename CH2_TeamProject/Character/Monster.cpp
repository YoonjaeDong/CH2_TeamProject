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
    
    result.PrintMessage(AttackMessage);
    return result;
}

void AMonster::UseSkill(ACharacter* Target)
{
    
    if (Stat.Mp < 10)
    {
        return;
    }
    int Damage = Stat.Atk;
    cout << "---------------------------------------------------" << endl;
    Stat.Mp -= 10;
    string AttackMessage = "이(가) 흡혈을 사용했습니다!";

    TakeDamage(Damage);
    Stat.Hp += Damage;

    Stat.Hp = min(Stat.Hp, Stat.MaxHp);

    cout << Name << AttackMessage << "데미지 : " << Damage << endl;
    cout << Damage << "만큼 체력을 회복했습니다!!" << endl;
    cout << "---------------------------------------------------" << endl;
}