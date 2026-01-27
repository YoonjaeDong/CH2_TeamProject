#include "Character.h"


ACharacter::ACharacter(const string& NewName, const FUnitStat& NewStat)
{
    Name = NewName;

    Stat = NewStat;

    cout << "[생성]" << Name << "가 전장에 나타났습니다! (HP : " << Stat.Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    cout << "ACharacter 소멸됨" << endl;
}

void ACharacter::Attack(ACharacter* target)
{
    int damage = Stat.Atk;
    int random = getRandomInt();
    
    if (random < Stat.Critical)
    {
        damage = damage * 1.5f;
        cout << "크리티컬 공격!!" << endl;
    }

    cout << Name << "가 공격합니다! (데미지 : " << damage << ")" << endl;
    target->TakeDamage(damage);

}

void ACharacter::TakeDamage(int DamageAmount)
{
    int NewDamage = DamageAmount - Stat.Def;

    if (NewDamage < 0)
        NewDamage = 0;

    Stat.Hp = Stat.Hp - NewDamage;

    cout << Name << "가 " << NewDamage << "의 피해를 입었습니다." << endl;
    cout << "   ->" << Name << "의 남은 체력 : " << Stat.Hp << endl;
}
