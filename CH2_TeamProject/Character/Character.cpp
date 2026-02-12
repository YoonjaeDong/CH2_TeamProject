#include "Character.h"


ACharacter::ACharacter(const string& NewName, const FUnitStat& UnitStat)
{
	Name = NewName;
	Stat = UnitStat;

	Stat.Hp = Stat.MaxHp;
	Stat.Mp = Stat.MaxMp;

	cout << "[생성]" << Name << "가 전장에 나타났습니다! (HP : " << Stat.Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
	cout << "ACharacter 소멸됨" << endl;
}

void FDamageResult::PrintMessage(const string& AttackMessage)
{
	cout << "---------------------------------------------------" << endl;
	Attacker->PrintName();
	cout << AttackMessage << "\n";

	Target->PrintName();
	cout << "받은 데미지 : " << Damage << " -> '남은 HP' : " << Target->GetHp() << "/" << Target->GetMaxHp() << endl;
	cout << "---------------------------------------------------" << endl;
}

void ACharacter::PrintName()
{
	cout << "[" << Name << "] ";
}

FDamageResult ACharacter::Attack(ACharacter* Target)
{
	int Damage = Stat.Atk;
	int Random = GetRandomInt();
	bool bCritical = Random < Stat.Critical;
	
	if (bCritical)
	{
		Damage = static_cast<int>(Damage * 1.5f);
	}

	int FinalDamage = Target->TakeDamage(Damage);
	FDamageResult result;
	result.Attacker = this;
	result.Target = Target;
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

void ACharacter::DoAction(ACharacter* Target)
{
	const int AttackRate = 70;
	const int SkillMp = 10;
		
	if (GetRandomInt() < AttackRate)
	{
		Attack(Target);

		return;
	}
	if (Stat.Mp < SkillMp)
	{
		cout << "마나가 부족합니다." << endl;
		Attack(Target);
	
		return;
	}
	UseSkill(Target);
}

void ACharacter::ShowStat(ACharacter* Target)
{
	cout << "[" << Name << "]" << "HP : " << Stat.Hp << " / " << Stat.MaxHp << "|" << "MP : " << Stat.Mp << " / " << Stat.MaxMp << endl;
}