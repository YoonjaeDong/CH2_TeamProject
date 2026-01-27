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
	//가상 소멸자-
	virtual ~ACharacter();

protected:
	string Name;
	FUnitStat Stat;

public:
	void Attack(ACharacter* target);
	void TakeDamage(int DamageAmount);

	int GetHp() { return Stat.Hp; }
	bool IsDead() { return Stat.Hp <= 0; }
	int getRandomInt()
	{
		static random_device rd;
		static mt19937 gen(rd());
		uniform_int_distribution<int> dis(0, 100);

		return dis(gen);
	}
};
