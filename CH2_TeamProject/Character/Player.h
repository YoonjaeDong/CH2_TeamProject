#pragma once
#include "Character.h"
#include <string>

using namespace std;

class APlayer: public ACharacter
{
public:
    APlayer(const string& Name, const FUnitStat& Stat);
    
    //멤버 변수: Level, Exp

    int Level;
    int Exp;

    void UseItem();
    void LevelUp();
    //멤버 함수: UseItem(), LevelUp() // 구현은 CPP에는 작성하되, 빈 구현으로 만들어주세요.
};