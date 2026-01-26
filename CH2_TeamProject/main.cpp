#include "Character.h"

#include <Windows.h>

int main()
{
    ACharacter* Player = new ACharacter("Unknown", 200, 30);
    ACharacter* Monster = new ACharacter("트롤", 200, 20);

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

        // [몬스터 턴]
       // 1. 몬스터가 플레이어를 공격,  2. 플레이어가 데미지를 입음

       // 3. 플레이어가 죽었는지 확인

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