#pragma once
#include <iostream>
#include <string>

using namespace std;

class ACharacter
{
public:
	ACharacter(const string& Name, int Hp, int Atk);
	//가상 소멸자-
	virtual ~ACharacter();

protected:
	string Name;
	int Hp;
	int Atk;

public:
	void Attack(ACharacter* target);
	void TakeDamage(int DamageAmount);

	int GetHp() { return Hp; }
	bool IsDead() { return Hp <= 0; }
};
