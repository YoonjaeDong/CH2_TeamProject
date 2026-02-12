#include "Character/Character.h"
#include "Character/Player.h"
#include "Character/Monster.h"

#include <Windows.h>

void WaitForPlayerInput()
{
    system ( "pause");
    cout << endl;
}

bool BattleTurn(ACharacter* Attacker, ACharacter* Defender)
{
    Attacker->DoAction(Defender);
    
    Attacker->ShowStat(Defender);
    Defender->ShowStat(Attacker);
   
    WaitForPlayerInput();    

    return Defender->IsDead();
}

int main()
{
    ACharacter* Player = new APlayer("용사", FUnitStat(200, 50, 30, 10, 30));
    ACharacter* Monster = new AMonster("트롤", FUnitStat(100, 30, 20, 5, 10));

    cout << "=== 데스매치 시작! === " << endl;

    WaitForPlayerInput();

    while (true)
    {
        if (BattleTurn(Player, Monster) == true)
        {
            break;
        }

        if (BattleTurn(Monster, Player) == true)
        {
            break;
        }
    }

    delete Player;
    delete Monster;

    WaitForPlayerInput();

    return 0;
}