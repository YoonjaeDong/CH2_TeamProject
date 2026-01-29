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

FDamageResult ACharacter::Attack(ACharacter* target)
{
	int Damage = Stat.Atk;
	int Random = GetRandomInt();
	bool bCritical = Random < Stat.Critical;
	
	if (bCritical)
	{
		Damage = static_cast<int>(Damage * 1.5f);
	}

	int FinalDamage = target->TakeDamage(Damage);
	FDamageResult result;
	result.Damage = FinalDamage;
	result.bCritical = bCritical;
	return result;
}

int ACharacter::TakeDamage(int DamageAmount)
{
	int NewDamage = DamageAmount - Stat.Def;
	NewDamage = max(NewDamage, 0);

	Stat.Hp = Stat.Hp - NewDamage;
	Stat.Hp = max(Stat.Hp, 0);

	return NewDamage;
}

int ACharacter::GetRandomInt()
{
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 100);

	return dis(gen);
}
