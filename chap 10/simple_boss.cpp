//Simple Boss
//Demonstrates inheritance
#include <iostream>

class Enemy {
public:
    int m_Damage;

    Enemy();
    void Attack() const;
};

Enemy::Enemy():
    m_Damage(10)
{}

void Enemy::Attack() const {
    std::cout << "Attack inflicts " << m_Damage << " damage points!\n";
}

class Boss : public Enemy {
public:
    int m_DamageMultiplier;

    Boss();
    void SpecialAttack() const;
};

Boss::Boss():
    m_DamageMultiplier(3)
{}

void Boss::SpecialAttack() const {
    std::cout << "Special Attack inflicts " << (m_DamageMultiplier * m_Damage);
    std::cout << " damage points!";
}

int main(){
    std::cout << "Creating an enemy.\n";
    Enemy Enemy1;
    Enemy1.Attack();

    std::cout << "\nCreating a boss.\n";
    Boss Boss1;
    Boss1.Attack();
    Boss1.SpecialAttack();

    return 0;
}