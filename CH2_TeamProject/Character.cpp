// 파일명: Character.cpp
#include "Character.h"

// ---------------------------------------------------------
// [Mission 4] 생성자에서 기본값 설정하기
// ---------------------------------------------------------
ACharacter::ACharacter()
{
    // Q1. Name 변수에 "Unknown"을 넣어주세요. (문자열은 큰따옴표 "")
    // (여기에 작성)

    // Q2. Hp는 100, Atk는 10으로 설정해주세요.
    // (여기에 작성)

    // (여기에 작성)


    cout << "ACharacter 생성됨: " << Name << " (HP: " << Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    cout << "ACharacter 소멸됨" << endl;
}

// ---------------------------------------------------------
// [Mission 5] 행동 구현하기
// ---------------------------------------------------------

void ACharacter::Attack()
{
    // Q3. "OOO가 공격합니다! (공격력: XX)" 형식으로 로그를 출력해보세요.
    // 힌트: cout << Name << "가 공격... " << Atk << ... ;
    // (여기에 작성)

}

void ACharacter::TakeDamage(int DamageAmount)
{
    // Q4. 현재 체력(Hp)에서 들어온 데미지(DamageAmount)만큼 빼주세요.
    // (여기에 작성)


    cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
}