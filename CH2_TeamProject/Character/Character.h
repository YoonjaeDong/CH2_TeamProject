#pragma once
#include <iostream>
#include <string>
#include <random>

using namespace std;

struct FUnitStat
{
	int MaxHp;
	int MaxMp;
	int Atk;
	int Def;
	int Critical;

	int Hp = 0;
	int Mp = 0;

	FUnitStat()
	{

	}

	FUnitStat(int MaxHp, int MaxMp, int Atk, int Def, int Critical)
	{
		this->MaxHp = MaxHp;
		this->MaxMp = MaxMp;

		this->Atk = Atk;
		this->Def = Def;
		this->Critical = Critical;
	}
};

class ACharacter;

struct FDamageResult
{
	int Damage;
	bool bCritical;

	ACharacter* Attacker;
	ACharacter* Target;

	void PrintMessage(const string& AttackMessage);
};

class ACharacter
{
public:
	ACharacter(const string& Name, const FUnitStat& NewStat);
	virtual ~ACharacter();

protected:
	string Name;
	FUnitStat Stat;

public:
	string GetName() { return Name; }
	int GetHp() { return Stat.Hp; }
	bool IsDead() { return Stat.Hp <= 0; }
	int GetRandomInt();
	virtual FDamageResult Attack(ACharacter* Target);
	int TakeDamage(int DamageAmount);
	virtual void UseSkill(ACharacter* Target) = 0;
	void PrintName();
	int GetMaxHp() const { return Stat.MaxHp; }

	void DoAction(ACharacter* Target);
	void ShowStat(ACharacter* Target);
};
