#include <iostream>
#include <iomanip>
#include <cstdlib> // Include for using rand()
#include <ctime>   // Include for using time()
#include <string>
using namespace std;

int PistolPrice = 150;
int ArmourPrice = 300;
int MedkitPrice = 100;
int AKPrice = 1000;
int grenadePrice = 200;
int grenadeDamage = 120;
int medkitHeal = 25+rand()%16;
class Player;
class Boss; // Forward declaration

class Player
{
public:
    Player(string name);
    string getname();
    void setname(string);
    void buyPistol();
    void buyArmour();
    void buyMedkit();
    void buyAK();
    void showshop();
    void buyGrenade();
    void GobuyPhase();
    void GetEnter();
    void attack(Boss &);
    void PlayerbeAttacked(int);
    void useGrenade(Boss &);
    void useMedkit();
    bool CheckDead();
    void addmoney(int);
    void playerWin(int);
    void playerLose();

    string name;
    int hpmax;
    int hp;
    int atk;
    int def;
    int super_atk;
    bool changeturn;
    int money;
    int med;
    int grenade;
    int level;
    bool armor;
    bool isPistol;
    bool isAK;
    bool buyphase;
    bool isDead;
    int medkit;
};
class Boss
{
public:
    Boss(string Name, int Hpmax, int Attack, int Def, int money);
    bool bossisDead();
    bool bossnewturn();
    void bossbeAttacked(int);
    int bossattack(Player &);
    void attack(Player &);
    int money;
    string name;
    int hpmax;
    int hp;
    int atk;
    int def;
    int super_atk;
    bool changeturn;
    bool isDead;
    bool CheckDead();
};

Player::Player(string name)
{
    this->name = name;
    money = 100;
    hpmax = 120;
    hp = 100;
    // hp = 10;
    atk = 5;
    def = rand() % 3 + 1;
    armor = false;
    isPistol = false;
    isAK = false;
    med = 0;
    grenade = 0;
    level = 1;
    changeturn = false;
    buyphase = false;
    isDead = false;
    cout << setw(62) << "Hello Player " << name << endl;

}
string Player::getname()
{
    return name;
}

void Player::setname(string Name)
{
    name = Name;
}
void Player::playerWin(int levelStage)
{
    if(levelStage == 1){
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                       |       |       ____                       |             |    _    ___      _                                                   |\n");
    printf("|                                        |     |      |      |    |         |      |             |    |    |  |     |                                                   |\n");
    printf("|                                         |   |      |        |   |         |       |     |     |     |    |   |    |                                                   |\n");
    printf("|                                           |       |          |  |         |        |   | |   |      |    |    |   |                                                   |\n");
    printf("|                                           |        |        |   |         |         | |   | |       |    |     |  |                                                   |\n");
    printf("|                                           |         | ____ |     |_______|           |     |        |    |      |_|                                                   |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                  ***************************************************************************************                                              |\n");
    printf("|                                  *                   YOU GET MONEY : 200 $   Press [ Enter ] To Continue               *                                              |\n");
    printf("|                                  ***************************************************************************************                                              |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                                       ---------                                                                                       |\n");
    printf("|                                                                        -.....-                                                                                        |\n");
    printf("|                                                                         .....                                                                                         |\n");
    printf("|                                                                      ...      ...                                                                                     |\n");
    printf("|                                                                     ...          ..                                                                                   |\n");
    printf("|                                                                    ...    |        ..                                                                                 |\n");
    printf("|                                                                  ...    :|:         ..                                                                                |\n");
    printf("|                                                                 ...     : |  :       ..                                                                               |\n");
    printf("|                                                                ...     :  |   :       ...                                                                             |\n");
    printf("|                                                              ...        : |             ..                                                                            |\n");
    printf("|                                                              ..          :|             ..                                                                            |\n");
    printf("|                                                              ..           |:            ..                                                                            |\n");
    printf("|                                                              ...          |  :         ..                                                                             |\n");
    printf("|                                                               ...     :   |   :       ...                                                                             |\n");
    printf("|                                                                ...     :  |  :       ...                                                                              |\n");
    printf("|                                                                  .....   :|:       ....                                                                               |\n");
    printf("|                                                                     ...   |      ....                                                                                 |\n");
    printf("|                                                                       ............                                                                                    |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
    if(levelStage == 2){
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                       |       |       ____                       |             |    _    ___      _                                                   |\n");
    printf("|                                        |     |      |      |    |         |      |             |    |    |  |     |                                                   |\n");
    printf("|                                         |   |      |        |   |         |       |     |     |     |    |   |    |                                                   |\n");
    printf("|                                           |       |          |  |         |        |   | |   |      |    |    |   |                                                   |\n");
    printf("|                                           |        |        |   |         |         | |   | |       |    |     |  |                                                   |\n");
    printf("|                                           |         | ____ |     |_______|           |     |        |    |      |_|                                                   |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                  ***************************************************************************************                                              |\n");
    printf("|                                  *                   YOU GET MONEY : 400 $   Press [ Enter ] To Continue               *                                              |\n");
    printf("|                                  ***************************************************************************************                                              |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                                       ---------                                                                                       |\n");
    printf("|                                                                        -.....-                                                                                        |\n");
    printf("|                                                                         .....                                                                                         |\n");
    printf("|                                                                      ...      ...                                                                                     |\n");
    printf("|                                                                     ...          ..                                                                                   |\n");
    printf("|                                                                    ...    |        ..                                                                                 |\n");
    printf("|                                                                  ...    :|:         ..                                                                                |\n");
    printf("|                                                                 ...     : |  :       ..                                                                               |\n");
    printf("|                                                                ...     :  |   :       ...                                                                             |\n");
    printf("|                                                              ...        : |             ..                                                                            |\n");
    printf("|                                                              ..          :|             ..                                                                            |\n");
    printf("|                                                              ..           |:            ..                                                                            |\n");
    printf("|                                                              ...          |  :         ..                                                                             |\n");
    printf("|                                                               ...     :   |   :       ...                                                                             |\n");
    printf("|                                                                ...     :  |  :       ...                                                                              |\n");
    printf("|                                                                  .....   :|:       ....                                                                               |\n");
    printf("|                                                                     ...   |      ....                                                                                 |\n");
    printf("|                                                                       ............                                                                                    |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
    if(levelStage == 3){
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                       |       |       ____                       |             |    _    ___      _                                                   |\n");
    printf("|                                        |     |      |      |    |         |      |             |    |    |  |     |                                                   |\n");
    printf("|                                         |   |      |        |   |         |       |     |     |     |    |   |    |                                                   |\n");
    printf("|                                           |       |          |  |         |        |   | |   |      |    |    |   |                                                   |\n");
    printf("|                                           |        |        |   |         |         | |   | |       |    |     |  |                                                   |\n");
    printf("|                                           |         | ____ |     |_______|           |     |        |    |      |_|                                                   |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                  ***************************************************************************************                                              |\n");
    printf("|                                  *                   YOU GET MONEY : 600 $   Press [ Enter ] To Continue               *                                              |\n");
    printf("|                                  ***************************************************************************************                                              |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                                       ---------                                                                                       |\n");
    printf("|                                                                        -.....-                                                                                        |\n");
    printf("|                                                                         .....                                                                                         |\n");
    printf("|                                                                      ...      ...                                                                                     |\n");
    printf("|                                                                     ...          ..                                                                                   |\n");
    printf("|                                                                    ...    |        ..                                                                                 |\n");
    printf("|                                                                  ...    :|:         ..                                                                                |\n");
    printf("|                                                                 ...     : |  :       ..                                                                               |\n");
    printf("|                                                                ...     :  |   :       ...                                                                             |\n");
    printf("|                                                              ...        : |             ..                                                                            |\n");
    printf("|                                                              ..          :|             ..                                                                            |\n");
    printf("|                                                              ..           |:            ..                                                                            |\n");
    printf("|                                                              ...          |  :         ..                                                                             |\n");
    printf("|                                                               ...     :   |   :       ...                                                                             |\n");
    printf("|                                                                ...     :  |  :       ...                                                                              |\n");
    printf("|                                                                  .....   :|:       ....                                                                               |\n");
    printf("|                                                                     ...   |      ....                                                                                 |\n");
    printf("|                                                                       ............                                                                                    |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
    if(levelStage == 4){
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                       |       |       ____                       |             |    _    ___      _                                                   |\n");
    printf("|                                        |     |      |      |    |         |      |             |    |    |  |     |                                                   |\n");
    printf("|                                         |   |      |        |   |         |       |     |     |     |    |   |    |                                                   |\n");
    printf("|                                           |       |          |  |         |        |   | |   |      |    |    |   |                                                   |\n");
    printf("|                                           |        |        |   |         |         | |   | |       |    |     |  |                                                   |\n");
    printf("|                                           |         | ____ |     |_______|           |     |        |    |      |_|                                                   |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                  ***************************************************************************************                                              |\n");
    printf("|                                  *                   YOU GET MONEY : 800 $   Press [ Enter ] To Continue               *                                              |\n");
    printf("|                                  ***************************************************************************************                                              |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                                       ---------                                                                                       |\n");
    printf("|                                                                        -.....-                                                                                        |\n");
    printf("|                                                                         .....                                                                                         |\n");
    printf("|                                                                      ...      ...                                                                                     |\n");
    printf("|                                                                     ...          ..                                                                                   |\n");
    printf("|                                                                    ...    |        ..                                                                                 |\n");
    printf("|                                                                  ...    :|:         ..                                                                                |\n");
    printf("|                                                                 ...     : |  :       ..                                                                               |\n");
    printf("|                                                                ...     :  |   :       ...                                                                             |\n");
    printf("|                                                              ...        : |             ..                                                                            |\n");
    printf("|                                                              ..          :|             ..                                                                            |\n");
    printf("|                                                              ..           |:            ..                                                                            |\n");
    printf("|                                                              ...          |  :         ..                                                                             |\n");
    printf("|                                                               ...     :   |   :       ...                                                                             |\n");
    printf("|                                                                ...     :  |  :       ...                                                                              |\n");
    printf("|                                                                  .....   :|:       ....                                                                               |\n");
    printf("|                                                                     ...   |      ....                                                                                 |\n");
    printf("|                                                                       ............                                                                                    |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
};

void Player::playerLose()
{
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                                                    ____                                                                               |\n");
    printf("|                                         |       |       ____                      |    |      _      _______                                                          |\n");
    printf("|                                          |     |      |      |    |         |     |     |     |      |                                                                |\n");
    printf("|                                           |   |      |        |   |         |     |      |    |      |                                                                |\n");
    printf("|                                             |       |          |  |         |     |      |    |      |_____                                                           |\n");
    printf("|                                             |        |        |   |         |     |     |     |      |                                                                |\n");
    printf("|                                             |         | ____ |     |_______|      |____|      |      |______                                                          |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                  ***************************************************************************************                                              |\n");
    printf("|                                  *                          Press [ T ] To Start Again                                 *                                              |\n");
    printf("|                                  ***************************************************************************************                                              |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                                 ..*.*.*.*.*.*.*.*.*..                                                                                 |\n");
    printf("|                                                               **                     **                                                                               |\n");
    printf("|                                                              *                         *                                                                              |\n");
    printf("|                                                            *                             *                                                                            |\n");
    printf("|                                                           *          *          *         *                                                                           |\n");
    printf("|                                                          *         * x *      * x *        *                                                                          |\n");
    printf("|                                                          *         *   *      *   *        *                                                                          |\n");
    printf("|                                                          *..         *          *        ..*                                                                          |\n");
    printf("|                                                           *..                           ..*                                                                           |\n");
    printf("|                                                             *..                       ..*                                                                             |\n");
    printf("|                                                               *..                   ..*                                                                               |\n");
    printf("|                                                                  *..              ..*                                                                                 |\n");
    printf("|                                                                   *   .   .   .   *                                                                                   |\n");
    printf("|                                                                   *   .   .   .   *                                                                                   |\n");
    printf("|                                                                   *   .   .   .   *                                                                                   |\n");
    printf("|                                                                    ***************                                                                                    |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
};

void Player::showshop()
{
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                         [  SHOP  ]                                                                                    |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                 _______________==                                      ___     ___                                      _______________                               |\n");
    printf("|                q|[[[[ [__]   ___|                                      [ ]_____[ ]]                                    /______________/|                              |\n");
    printf("|                /_____________/_ |                                     |    VEST   ||                                   |      _      | |                              |\n");
    printf("|                |    [|_]'                                             |           ||                                   |   __| |__   | |                              |\n");
    printf("|                | ## |                                                 |___ ___ ___||                                   |  |__   __|  | |                              |\n");
    printf("|                | ## |                                                 |[__][__][__]|                                   |     |_|     | |                              |\n");
    printf("|                |_##_|                                                 |   |   |   ||                                   |  first aid  | |                              |\n");
    printf("|                                                                       |___|___|___|/                                   |_____________|/                               |\n");
    printf("|             Pistol Press[1]                                           Armor1 Press[2]                                  Medkit  Press[3]                               |\n");
    printf("|             PRICE : 150  $                                            PRICE : 300  $                                   PRICE : 100  $                                 |\n");
    printf("|             ATK   : 15 - 35 damage                                    DEF   : +10 def                                  HEAL  :  25 - 40 hp                            |\n");
    printf("|            Amount : %d                                                Amount : %d                                       Amount : %d                                     |\n", isPistol, armor, med);
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                                            __                                                                                         |\n");
    printf("|                                  __:                                     /=||=-o                                                                                      |\n");
    printf("|                         /**********|======.._____    ==                 / [  ]                                                                                        |\n");
    printf("|                --------/  '/-----/ |=[][] !!-----|___/|                / [    ]                                                                                       |\n");
    printf("|               |        __  |_]--|--|=======-----------|               | [______]                                                                                      |\n");
    printf("|               |      _/  |_|     |  |                                    [    ]                                                                                       |\n");
    printf("|               |_____/    ==       |__|                                    [__]                                                                                        |\n");
    printf("|             Rifile  Press[4]                                         Grenade  Press[5]                                                                                |\n");
    printf("|             PRICE : 1000  $                                          PRICE : 200  $ ( 1 used )                                                                        |\n");
    printf("|             ATK   : 50 - 100 damage                                  ATK   : 120 damage                                                                               |\n");
    printf("|             Amount : %d                                               Amount : %d / 2                                                                                  |\n", isAK, grenade);
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|     YOUR MONEY : %d             PRESS [T] To continue                                                                                                                |\n", money);
    printf("|                                                                                                                                                                       |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}

void Player::buyPistol()
{
    if (isPistol)
    {
        cout << setw(62) << "You already have it" << endl;
    }
    else if (money < PistolPrice)
    {
        cout << setw(62) << "You need more " << PistolPrice - money << " $\n";
    }
    else
    {
        money -= PistolPrice;
        isPistol = true;
        atk = 15 + rand()%21;
        cout << setw(62) << "Success Buy Pistol" << endl;
    }
}

void Player::buyArmour()
{
    if (money >= ArmourPrice)
    {
        money -= ArmourPrice;
        cout << setw(62) << "Success Buy Armour" << endl;
    }
    else
    {
        cout << setw(62) << "You need more : " << ArmourPrice - money << " $\n";
    }
}

void Player::buyMedkit()
{
    if (money >= MedkitPrice)
    {
        money -= MedkitPrice;
        medkit++;
        cout << setw(62) << "Success Buy Medkit" << endl;
    }
    else
    {
        cout << setw(62) << "You need more : " << MedkitPrice - money << " $\n";
    }
}

void Player::buyAK()
{
    if (isAK)
    {
        cout << setw(62) << "You already have it" << endl;
    }
    else if (money < AKPrice)
    {
        cout << setw(62) << "You need more " << AKPrice - money << " $\n";
    }
    else
    {
        money -= AKPrice;
        isAK = true;
        atk = 50 + rand()%51;
        cout << setw(62) << "Success Buy AK" << endl;
    }
}

void Player::buyGrenade()
{
    if (grenade >= 2)
    {
        cout << "You Can Have Only 2 grenade" << endl;
    }
    else if (money >= grenadePrice)
    {
        money -= grenadePrice;
        grenade++;
        cout << setw(62) << "Success Buy Grenade" << endl;
    }
    else
    {
        cout << setw(62) << "You need more : " << grenadePrice - money << " $\n";
    }
}

void Player::GobuyPhase()
{
    buyphase = true;
    while (buyphase == true)
    {
        showshop();
        cout << setw(62) << "you choose : ";
        string choice;
        cin >> choice;
        if (choice == "T" || choice == "t")
        {
            buyphase = false;
            cin.ignore();
            GetEnter();
        }
        else if (choice == "1")
        {
            buyPistol();
            cin.ignore();
            GetEnter();
        }
        else if (choice == "2")
        {
            buyArmour();
            cin.ignore();
            GetEnter();
        }
        else if (choice == "3")
        {
            buyMedkit();
            cin.ignore();
            GetEnter();
        }
        else if (choice == "4")
        {
            buyAK();
            cin.ignore();
            GetEnter();
        }
        else if (choice == "5")
        {
            buyGrenade();
            cin.ignore();
            GetEnter();
        }
        else
        {
            cout << "Wrong input" << endl;
            cin.ignore();
            GetEnter();
        }
    }
}

void Player::GetEnter()
{
    cout << setw(62) << "Press Enter To go next";
    cin.get();
    system("cls"); // Assuming you are using Windows. Change to "clear" for Linux.
}

void Player::addmoney(int money)
{

    this->money += money;
}

Boss::Boss(string Name, int Hpmax, int Attack, int Def, int Money)
{
    this->name = Name;
    this->hpmax = Hpmax;
    this->hp = Hpmax;
    this->atk = Attack;
    this->def = Def;
    isDead = false;
    money = Money;
}

void Player::attack(Boss &Boss)
{
    int x = rand() % 100 + 1;
    if (x <= 10)
        Boss.bossbeAttacked(atk * 2);
    else
        Boss.bossbeAttacked(atk);
}

void Boss::bossbeAttacked(int damage)
{
    if (def > damage)
    {
        damage = 0;
    }
    else
    {
        hp -= (damage - def);
    }
    if (hp <= 0)
    {
        isDead = true;
    }
}

void Boss::attack(Player &Player1)
{
    Player1.PlayerbeAttacked(atk);
}

void Player::PlayerbeAttacked(int damage)
{
    if (def > damage)
    {
        damage = 0;
    }
    else
    {
        hp -= (damage - def);
    }
    if (hp <= 0)
    {
        isDead = true;
    }
}

void Player::useGrenade(Boss &Boss)
{
    if (grenade > 0)
    {
        Boss.bossbeAttacked(grenadeDamage);
        grenade--;
    }
    else
    {
        cout << "You Don't have Grenade";
    }
}

void Player::useMedkit()
{
    if (medkit > 0)
    {
        if (medkitHeal + hp >= hpmax)
        {
            hp = hpmax;
            medkit -= 1;
        }
        else
        {
            hp += medkitHeal;
            medkit -= 1;
        }
    }
    else
    {
        cout << "You Don't Have Medkits";
    }
}

bool Player::CheckDead()
{
    if (hp <= 0)
        isDead = true;
    return isDead;
}

bool Boss::CheckDead()
{
    if (hp <= 0)
        isDead = true;
    return isDead;
}