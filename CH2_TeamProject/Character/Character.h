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

class ACharacter
{
public:
	ACharacter(const string& Name, const FUnitStat& NewStat);
	virtual ~ACharacter();

protected:
	string Name;
	FUnitStat Stat;

public:
	virtual void Attack(ACharacter* target);
	void TakeDamage(int DamageAmount);

	int GetHp() { return Stat.Hp; }
	bool IsDead() { return Stat.Hp <= 0; }
	int GetRandomInt();
};
