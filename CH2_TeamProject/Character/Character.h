#pragma once
#include <iostream>
#include <string>
#include <random>

using namespace std;

class ACharacter
{
public:
	ACharacter(const string& Name, int Hp, int Atk, int NewDef, float NewCri);
	//가상 소멸자-
	virtual ~ACharacter();

protected:
	string Name;
	int Hp;
	int Atk;
	int Def;
	int Critical;

public:
	void Attack(ACharacter* target);
	void TakeDamage(int DamageAmount);

	int GetHp() { return Hp; }
	bool IsDead() { return Hp <= 0; }
	int getRandomInt()
	{
		static random_device rd;
		static mt19937 gen(rd());
		uniform_int_distribution<int> dis(0, 100);

		return dis(gen);
	}
};
