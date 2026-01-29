#include "Character/Character.h"
#include "Character/Player.h"
#include "Character/Monster.h"

#include <Windows.h>

int main()
{
    FUnitStat PlayerStat{ 200, 30, 10, 30 };
    FUnitStat MonsterStat{ 100, 20, 5, 10 };

    ACharacter* Player = new APlayer("용사", PlayerStat);
    ACharacter* Monster = new AMonster("트롤", MonsterStat);

    cout << "=== 데스매치 시작! === " << endl;

    Sleep(1000);

    while (!Player->IsDead() && !Monster->IsDead())
    {
        Player->Attack(Monster);

        if (Monster->IsDead())
        {
            cout << "몬스터가 쓰러졌습니다! 승리!" << endl;
            break;
        }

        Sleep(500);

        Monster->Attack(Player);

        if (Player->IsDead())
        {
            cout << "플레이어가 쓰러졌습니다... 패배..." << endl;
            break;
        }

        Sleep(1000);
    }

    delete Player;
    delete Monster;

    return 0;
}