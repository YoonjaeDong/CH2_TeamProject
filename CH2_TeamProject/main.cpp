// 파일명: Main.cpp
#include "Character.h"

int main()
{
    // 1. 캐릭터 생성
    ACharacter* MyChar = new ACharacter();

    // 2. 공격 테스트
    MyChar->Attack();

    // 3. 피격 테스트 (데미지 30을 줘봅시다)
    MyChar->TakeDamage(30);

    // 4. 삭제
    delete MyChar;

    return 0;
}