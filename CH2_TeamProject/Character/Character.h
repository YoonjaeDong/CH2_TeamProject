#pragma once
#include <iostream>
#include <string>
#include <random>

using namespace std;

struct FUnitStat
{
	int Hp;
	int Atk;
	int Def;
	int Critical;
};

struct FDamageResult
{
	int Damage;
	bool bCritical;
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
};
