#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Class Robot untuk mendefinisikan robot dengan atribut dan metode yang sesuai
class Robot {
private:
    std::string robotName;
    int robotHealth;
    int robotAttackPower;

public:
    // Constructor untuk menginisialisasi atribut robot
    Robot(const std::string& robotName, int robotHealth, int robotAttackPower) {
        this->robotName = robotName;
        this->robotHealth = robotHealth;
        this->robotAttackPower = robotAttackPower;
    }

    // Mendapatkan nama robot
    std::string getRobotName() {
        return robotName;
    }

    // Mendapatkan status darah robot
    int getRobotHealth() {
        return robotHealth;
    }

    // Menyerang robot lain dengan damage acak 
    int attack(Robot& target) {
        int damage;
        damage = rand() % robotAttackPower + 1; // Damage acak antara 1 hingga attackPower
        target.robotHealth -= damage;
        std::cout << robotName << " attacks " << target.getRobotName() << " for " << damage << " damage!\n";
        return damage;
    }

    // Mengecek apakah robot sudah dikalahkan
    bool isDefeated() {
        return robotHealth <= 0;
    }
};

// Class Battle untuk menjalankan pertarungan antara dua robot
class Battle {
public:
    // Metode untuk memulai pertarungan antara dua robot
    void start_fight(Robot &robot1, Robot &robot2) {
        std::cout << "\n*** Battle Start! ***\n";
        while (!robot1.isDefeated() && !robot2.isDefeated()) {
            robot1.attack(robot2);
            if (!robot2.isDefeated()) {
                robot2.attack(robot1);
            }
        }

        // Menentukan pemenang
        if (robot1.isDefeated()) {
            std::cout << robot1.getRobotName() << " is defeated!\n";
            std::cout << robot2.getRobotName() << " wins!\n";
        } else {
            std::cout << robot2.getRobotName() << " is defeated!\n";
            std::cout << robot1.getRobotName() << " wins!\n";
        }
    }
};

// Class Game untuk mengelola daftar robot dan memulai game
class Game {
private:
    std::vector<Robot> robots;

public:
    // Menambahkan robot ke dalam daftar game
    void add_robot(const Robot &robot) {
        robots.push_back(robot);
    }

    // Memulai permainan dengan memilih dua robot untuk bertarung
    void start_game() {
        if (robots.size() < 2) {
            std::cout << "Not enough robots to start a battle.\n";
            return;
        }

        std::cout << "Choose robots for the battle:\n";
        for (int i = 0; i < robots.size(); ++i) {
            std::cout << i + 1 << ". " << robots[i].getRobotName() << "\n";
        }

        int choice1, choice2;
        std::cout << "Select the first robot (1-3): ";
        std::cin >> choice1;
        std::cout << "Select the second robot (1-3): ";
        std::cin >> choice2;

        if (choice1 < 1 || choice1 > robots.size() || choice2 < 1 || choice2 > robots.size() || choice1 == choice2) {
            std::cout << "Invalid robot selection.\n";
            return;
        }

        Robot &robot1 = robots[choice1 - 1];
        Robot &robot2 = robots[choice2 - 1];

        Battle battle;
        battle.start_fight(robot1, robot2);
    }
};

int main() {
    srand(time(0)); // Inisialisasi random seed

    Game game;

    // Menambahkan robot ke dalam game
    game.add_robot(Robot("RoboOne", 300, 100));
    game.add_robot(Robot("RoboTwo", 255, 135));
    game.add_robot(Robot("RoboThree", 200, 200));

    // Memulai permainan
    game.start_game();

    return 0;
}
