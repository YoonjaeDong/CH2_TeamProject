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
	int Damage = Stat.Atk;
	int Random = GetRandomInt();
	bool bCritical = Random < Stat.Critical;
	
	if (bCritical)
	{
		Damage = static_cast<int>(Damage * 1.5f);
	}

	cout << Name << "가 공격합니다! (데미지 : " << Damage << ")" << endl;
	if (bCritical)
	{
		cout << "크리티컬 공격!!" << endl;
	}

	target->TakeDamage(Damage);
}

void ACharacter::TakeDamage(int DamageAmount)
{
	int NewDamage = DamageAmount - Stat.Def;
	NewDamage = max(NewDamage, 0);

	Stat.Hp = Stat.Hp - NewDamage;

	cout << Name << "가 " << NewDamage << "의 피해를 입었습니다." << endl;
	cout << "   ->" << Name << "의 남은 체력 : " << Stat.Hp << endl;
}

int ACharacter::GetRandomInt()
{
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 100);

	return dis(gen);
}
