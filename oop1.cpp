#include <iostream>
#include <string>

class Queen {
private:
    std::string name;
    int health;
    int attack;
    int defense;
    int maxHealth; // Максимальное здоровье

public:
    Queen(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d), maxHealth(h) {
    }

    int getHealth() const {
        return health;
    }

    void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << std::endl;
    }

    void attackEnemy(Queen& enemy) {
        int damage = attack - enemy.defense;
        if (damage > 0) {
            enemy.health -= damage;
            if (enemy.health < 0) enemy.health = 0; //не опускает его ниже 0
            std::cout << name << " attacks " << enemy.name << " for " << damage << " damage!" << std::endl;
        }
        else {
            std::cout << name << " attacks " << enemy.name << ", but it has no effect!" << std::endl;
        }
    }

    void heal(int amount) {
        health += amount;
        if (health > maxHealth) {
            health = maxHealth; // не превышает максимальное значение
        }
        std::cout << name << " heals for " << amount << " HP. Current HP: " << health << std::endl;
    }

    void takeDamage(int amount) {
        health -= amount;
        if (health < 0) {
            health = 0; //не опускает его ниже 0
        }
        std::cout << name << " takes " << amount << " damage. Current HP: " << health << std::endl;
    }
};

int main() {
    Queen whiteQueen("White Queen", 100, 25, 10);
    Queen blackQueen("Black Queen", 80, 30, 5);

    whiteQueen.displayInfo();
    blackQueen.displayInfo();

    whiteQueen.attackEnemy(blackQueen);
    blackQueen.displayInfo();

    blackQueen.heal(15);
    blackQueen.displayInfo();

    whiteQueen.takeDamage(30);
    whiteQueen.displayInfo();

    whiteQueen.takeDamage(100);
    whiteQueen.displayInfo();

    return 0;
}
