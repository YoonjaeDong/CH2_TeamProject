#include "Character/Character.h"
#include "Character/Player.h"
#include "Character/Monster.h"
#include "BattleManager.h"

#include <Windows.h>
#include <iostream>
#include <memory>

int main()
{
    auto BattleManager = std::make_unique<ABattleManager>();

    FUnitStat PlayerStat(200, 50, 30, 10, 30);
    FUnitStat MonsterStat(100, 30, 20, 5, 10);

    unique_ptr<ACharacter> Player = make_unique<APlayer>("용사", PlayerStat);
    unique_ptr<ACharacter> Monster = make_unique<AMonster>("트롤", MonsterStat);

    cout << "=== 데스매치 시작! === " << endl;

    BattleManager->WaitForPlayerInput();
    BattleManager->RunBattle(Player.get(), Monster.get());
    BattleManager->WaitForPlayerInput();

    cout << "=== 데스매치 종료! === " << endl;

    return 0;
}