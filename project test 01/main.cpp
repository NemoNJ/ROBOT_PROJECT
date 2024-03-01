#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include "Unit.cpp"
#include <windows.h>

using namespace std;
char *Heroname;
string Hero;
void GameStart();

void GetEnter();
// void CreateBoss();
void AskPlayerName();
void ShowHowToplay();
void ShowMap();
string toUpperStr(string);
void FightBoss(Player &, Boss &);
void ShowFightPhase();
Boss Dummy1("Dummy1", rand() % 5 + 100, rand() % 2 + 3, rand() % 2 + 1, 200);
Boss Dummy2("Dummy2", rand() % 5 + 100, rand() % 2 + 3, rand() % 2 + 1, 400);
Boss Dummy3("Dummy3", rand() % 5 + 100, rand() % 2 + 3, rand() % 2 + 1, 600);
Boss Dummy4("Dummy4", rand() % 5 + 100, rand() % 2 + 3, rand() % 2 + 1, 800);
string name;

int levelStage = 1;
Player Player1("");

int main()
{
    srand(time(0));

    GameStart();

    if (Player1.getname() == "")
        AskPlayerName();
    cout << setw(62) << "Hi Player : " << Hero << endl;
    Player1.setname(name);
    GetEnter();
    ShowHowToplay();
    while(levelStage < 5){
    Player1.GobuyPhase();
    // Modify to read file to save current in future
    ShowMap();
    GetEnter();
    system("cls");
    if (levelStage == 1)
        FightBoss(Player1, Dummy1);
    else if (levelStage == 2)
        FightBoss(Player1, Dummy2);
    else if (levelStage == 2)
        FightBoss(Player1, Dummy2);
    else if (levelStage == 3)
        FightBoss(Player1, Dummy3);
    else if (levelStage == 4)
        FightBoss(Player1, Dummy4);
   if (Player1.isDead)
    {
        Player1.hp = Player1.hpmax;
        if (levelStage == 1) Dummy1.hp = Dummy1.hpmax;
        if (levelStage == 2) Dummy2.hp = Dummy2.hpmax;
        if (levelStage == 3) Dummy3.hp = Dummy3.hpmax;
        if (levelStage == 4) Dummy4.hp = Dummy4.hpmax;
        main();
    }
    }
}

string toUpperStr(string x)
{
    string y = x;
    for (unsigned i = 0; i < x.size(); i++)
        y[i] = toupper(x[i]);
    return y;
}
void AskPlayerName()
{
    cout << setw(62) << "Enter Your Name : ";
    getline(cin,Hero);
    const char* Heroname = Hero.c_str();
    
    name = Hero;
    system("cls");//clear terminal
}
void GameStart()
{
   HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(color , 15);	
printf("|");SetConsoleTextAttribute(color , 12);printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");SetConsoleTextAttribute(color , 15);printf("|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                           ");SetConsoleTextAttribute(color , 9);printf(" ____________________________________________");SetConsoleTextAttribute(color , 15);printf("                                                               |\n");
printf("|                                                           ");SetConsoleTextAttribute(color , 9);printf("[                                            ]");SetConsoleTextAttribute(color , 15);printf("                                                              |\n");
printf("|                            ");SetConsoleTextAttribute(color , 3);printf("*******************************");SetConsoleTextAttribute(color , 9);printf("[      ");SetConsoleTextAttribute(color , 14);printf("WELCOME TO BATTLE BOSS GAME 03");SetConsoleTextAttribute(color , 9);printf("        ]");SetConsoleTextAttribute(color , 3);printf("*********************************");SetConsoleTextAttribute(color , 15);printf("                             |\n");
printf("|                            *                              ");SetConsoleTextAttribute(color , 9);printf("[____________________________________________]");SetConsoleTextAttribute(color , 15);printf("                                *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                       ");SetConsoleTextAttribute(color , 2);printf("       ....   ");SetConsoleTextAttribute(color , 15);printf("                                                       *                             |\n");
printf("|                            *                                       ");SetConsoleTextAttribute(color , 2);printf("     .'    '.   ");SetConsoleTextAttribute(color , 15);printf("                                                     *                             |\n");
printf("|                            *                                       ");SetConsoleTextAttribute(color , 2);printf("    .   ......  ___       _   ");SetConsoleTextAttribute(color , 15);printf("                                       *                             |\n");
printf("|                            *                                       ");SetConsoleTextAttribute(color , 2);printf("    . .' I_I_;./___|_____/-|____    ");SetConsoleTextAttribute(color , 15);printf("                                 *                             |\n");
printf("|                            *                                       ");SetConsoleTextAttribute(color , 2);printf("  .'     |     ____.--;;;;;;;'      ");SetConsoleTextAttribute(color , 15);printf("                                 *                             |\n");
printf("|                            *                                       ");SetConsoleTextAttribute(color , 2);printf(" .  ...  |____/||  [ ]'''           ");SetConsoleTextAttribute(color , 15);printf("                                 *                             |\n");
printf("|                            *                                       ");SetConsoleTextAttribute(color , 2);printf(" :     ...   ...'   [_]             ");SetConsoleTextAttribute(color , 15);printf("                                 *                             |\n");
printf("|                            *                                       ");SetConsoleTextAttribute(color , 2);printf(".    .     :                        ");SetConsoleTextAttribute(color , 15);printf("                                 *                             |\n");
printf("|                            *                                       ");SetConsoleTextAttribute(color , 2);printf(". :  . :  : .                       ");SetConsoleTextAttribute(color , 15);printf("                                 *                             |\n");
printf("|                            *                                       ");SetConsoleTextAttribute(color , 2);printf(": : .  :  : :                       ");SetConsoleTextAttribute(color , 15);printf("                                 *                             |\n");
printf("|                            *                                       ");SetConsoleTextAttribute(color , 2);printf(":...........:                       ");SetConsoleTextAttribute(color , 15);printf("                                 *                             |\n");
printf("|                            *                                       ");SetConsoleTextAttribute(color , 2);printf(":           :                       ");SetConsoleTextAttribute(color , 15);printf("                                 *                             |\n");
printf("|                            ");SetConsoleTextAttribute(color , 3);printf("**************************************************************************************************************");SetConsoleTextAttribute(color , 15);printf("                             |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|");SetConsoleTextAttribute(color , 12);printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");SetConsoleTextAttribute(color , 15);printf("|\n");
}
void GetEnter()
{
    cout << setw(70) << "Press Enter To go next";
    cin.get();
    system("cls");
}

void ShowHowToplay()
{
   //อธิบายการเล่น
    GetEnter();
}
void ShowMap()
{
    if (levelStage == 1)
    {
        // map in game stage 1
       HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //Add Color
SetConsoleTextAttribute(color , 15);	
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                             ");SetConsoleTextAttribute(color , 9);printf("[ MAP ]");SetConsoleTextAttribute(color , 15);printf("                                                                                   |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                 _____                                                                 |\n");
printf("|                                                                               _____________O   (     )  ( Stage 4 Final Boss)                                         |\n");
printf("|                                                                              /                ( () () )                                                               |\n");
printf("|                                                                             /                  (  ^  )                                                                |\n");
printf("|                                                                            /                    |||||                                                                 |\n");
printf("|                                                                           /                                                                                           |\n");
printf("|                                                                          /                                                                                            |\n");
printf("|                                                                         /                                                                                             |\n");
printf("|                                                                        /                                                                                              |\n");
printf("|                                                                       /                                                                                               |\n");
printf("|                                                        ______________O ( Stage 3 )                                                                                    |\n");
printf("|                                                       /                                                                                                               |\n");
printf("|                                                      /                                                                                                                |\n");
printf("|                                                     /                                                                                                                 |\n");
printf("|                                                    /                                                                                                                  |\n");
printf("|                                                   /                                                                                                                   |\n");
printf("|                                      ____________O ( Stage 2 )                                                                                                        |\n");
printf("|                                     /                                                                                                                                 |\n");
printf("|                                    /                                                                                                                                  |\n");
printf("|                                   /                                                                                                                                   |\n");
printf("|                                  /                                                                                                                                    |\n");
printf("|                                 ");SetConsoleTextAttribute(color , 12);printf("O");SetConsoleTextAttribute(color , 14);printf(" ( Stage 1 ) ");SetConsoleTextAttribute(color , 15);printf("                                                                                                                        |\n");
printf("|                         ");SetConsoleTextAttribute(color , 14);printf(" [ You Are Here ]  ");SetConsoleTextAttribute(color , 15);printf("                                                                                                                           |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
    if (levelStage == 2)
    {
        // map in game stage 2
       HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //Add Color
SetConsoleTextAttribute(color , 15);	
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                             ");SetConsoleTextAttribute(color , 9);printf("[ MAP ]");SetConsoleTextAttribute(color , 15);printf("                                                                                   |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                 _____                                                                 |\n");
printf("|                                                                               _____________O   (     )  ( Stage 4 Final Boss)                                         |\n");
printf("|                                                                              /                ( () () )                                                               |\n");
printf("|                                                                             /                  (  ^  )                                                                |\n");
printf("|                                                                            /                    |||||                                                                 |\n");
printf("|                                                                           /                                                                                           |\n");
printf("|                                                                          /                                                                                            |\n");
printf("|                                                                         /                                                                                             |\n");
printf("|                                                                        /                                                                                              |\n");
printf("|                                                                       /                                                                                               |\n");
printf("|                                                        ______________O ( Stage 3 )                                                                                    |\n");
printf("|                                                       /                                                                                                               |\n");
printf("|                                                      /                                                                                                                |\n");
printf("|                                                     /                                                                                                                 |\n");
printf("|                                                    /                                                                                                                  |\n");
printf("|                                                   /                                                                                                                   |\n");
printf("|                                      ____________");SetConsoleTextAttribute(color , 12);printf("O ");SetConsoleTextAttribute(color , 14);printf("( Stage 2 )  ");SetConsoleTextAttribute(color , 15);printf("                                                                                                      |\n");
printf("|                                     /            ");SetConsoleTextAttribute(color , 14);printf("[ You Are Here ] ");SetConsoleTextAttribute(color , 15);printf("                                                                                                    |\n");
printf("|                                    /                                                                                                                                  |\n");
printf("|                                   /                                                                                                                                   |\n");
printf("|                                  /                                                                                                                                    |\n");
printf("|                                 O ");SetConsoleTextAttribute(color , 14);printf("( Stage 1 complete) ");SetConsoleTextAttribute(color , 15);printf("                                                                                                                |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
   if (levelStage == 3)
    {
        // map in game stage 3

       HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(color , 15);	
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                             ");SetConsoleTextAttribute(color , 9);printf("[ MAP ]");SetConsoleTextAttribute(color , 15);printf("                                                                                   |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                 _____                                                                 |\n");
printf("|                                                                               _____________O   (     )  ( Stage 4 Final Boss)                                         |\n");
printf("|                                                                              /                ( () () )                                                               |\n");
printf("|                                                                             /                  (  ^  )                                                                |\n");
printf("|                                                                            /                    |||||                                                                 |\n");
printf("|                                                                           /                                                                                           |\n");
printf("|                                                                          /                                                                                            |\n");
printf("|                                                                         /                                                                                             |\n");
printf("|                                                                        /                                                                                              |\n");
printf("|                                                                       /                                                                                               |\n");
printf("|                                                        ______________");SetConsoleTextAttribute(color , 12);printf("O");SetConsoleTextAttribute(color , 14);printf(" ( Stage 3 )");SetConsoleTextAttribute(color , 15);printf("                                                                                    |\n");
printf("|                                                       /               ");SetConsoleTextAttribute(color , 14);printf("[ You Are Here ]");SetConsoleTextAttribute(color , 15);printf("                                                                                |\n");
printf("|                                                      /                                                                                                                |\n");
printf("|                                                     /                                                                                                                 |\n");
printf("|                                                    /                                                                                                                  |\n");
printf("|                                                   /                                                                                                                   |\n");
printf("|                                      ____________O ");SetConsoleTextAttribute(color , 14);printf("( Stage 2 complete )");SetConsoleTextAttribute(color , 15);printf("                                                                                               |\n");
printf("|                                     /                                                                                                                                 |\n");
printf("|                                    /                                                                                                                                  |\n");
printf("|                                   /                                                                                                                                   |\n");
printf("|                                  /                                                                                                                                    |\n");
printf("|                                 O ");SetConsoleTextAttribute(color , 14);printf("( Stage 1 complete)");SetConsoleTextAttribute(color , 15);printf("                                                                                                                 |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
    if (levelStage == 4)
    {
        // map in game stage 4
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(color , 15);
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                             ");SetConsoleTextAttribute(color , 9);printf("[ MAP ]");SetConsoleTextAttribute(color , 15);printf("                                                                                   |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                ");SetConsoleTextAttribute(color , 12);printf(" _____ ");SetConsoleTextAttribute(color , 15);printf("                                                                |\n");
printf("|                                                                               _____________");SetConsoleTextAttribute(color , 12);printf("O   (     )  ");SetConsoleTextAttribute(color , 14);printf("( Stage 4 Final Boss)");SetConsoleTextAttribute(color , 15);printf("                                         |\n");
printf("|                                                                              /              ");SetConsoleTextAttribute(color , 12);printf("  ( () () )    ");SetConsoleTextAttribute(color , 14);printf("[ You Are Here ]");SetConsoleTextAttribute(color , 15);printf("                                           |\n");
printf("|                                                                             /              ");SetConsoleTextAttribute(color , 12);printf("    (  ^  )     ");SetConsoleTextAttribute(color , 15);printf("                                                           |\n");
printf("|                                                                            /               ");SetConsoleTextAttribute(color , 12);printf("     |||||      ");SetConsoleTextAttribute(color , 15);printf("                                                           |\n");
printf("|                                                                           /                                                                                           |\n");
printf("|                                                                          /                                                                                            |\n");
printf("|                                                                         /                                                                                             |\n");
printf("|                                                                        /                                                                                              |\n");
printf("|                                                                       /                                                                                               |\n");
printf("|                                                        ______________O ");SetConsoleTextAttribute(color , 14);printf("( Stage 3 complete )");SetConsoleTextAttribute(color , 15);printf("                                                                           |\n");
printf("|                                                       /                                                                                                               |\n");
printf("|                                                      /                                                                                                                |\n");
printf("|                                                     /                                                                                                                 |\n");
printf("|                                                    /                                                                                                                  |\n");
printf("|                                                   /                                                                                                                   |\n");
printf("|                                      ____________O ");SetConsoleTextAttribute(color , 14);printf("( Stage 2 complete )");SetConsoleTextAttribute(color , 15);printf("                                                                                               |\n");
printf("|                                     /                                                                                                                                 |\n");
printf("|                                    /                                                                                                                                  |\n");
printf("|                                   /                                                                                                                                   |\n");
printf("|                                  /                                                                                                                                    |\n");
printf("|                                 O ");SetConsoleTextAttribute(color , 14);printf("( Stage 1 complete)");SetConsoleTextAttribute(color , 15);printf("                                                                                                                 |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
}
void buttonaction(string &action){
    char click = getch();
    printf("%c\n",click);
    if(click == 'a'){ 
        action = 'A';
        }
    else if(click == 'q'){
        action = 'Q';
    } 
    else if(click == 'g'){ 
        action = 'G';
    }
    else if(click == 'e') action = 'E';
    else action = 't';
}
void FightBoss(Player &Player1, Boss &Boss)
{
    string action;
    bool FightPhase = true;
    Player1.hp = Player1.hpmax;
    while (FightPhase)
    {
        ShowFightPhase();
        //cin >> action;
        //action = toUpperStr(action);
        buttonaction(action);
        if (action == "A")
        {
            Player1.attack(Boss);
            system("cls");
        }
        else if (action == "G")
        {
            Player1.useGrenade(Boss);
            if (Player1.grenade == 0)
                continue;
        }
        else if (action == "Q")
        {
            Player1.useMedkit();
            if (Player1.medkit == 0)
                continue;//ไม่ให้ถูกโจมตี
        }
        else if (action == "E")
        {
            cout << "exiting....";
            main();
        }
        else
        {
            cout << "Wrong input" << endl;
            cin.ignore();
            GetEnter();
            continue; // Continue the loop instead of recursive call
        }

        if (Boss.CheckDead())
        {
            FightPhase = false;
            Player1.playerWin(levelStage);
            levelStage++;
            Player1.addmoney(Boss.money);

            cin.ignore();
            GetEnter();
        }
        Boss.attack(Player1);

        if (Player1.CheckDead())
        {
            FightPhase = false;
            Player1.playerLose();
            cin.ignore();
            GetEnter();
        }
    }
}


void ShowFightPhase(){

    if (levelStage == 1 && !Player1.isAK && !Player1.isPistol)
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy1.hp < 0) Dummy1.hp = 0;
        printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
        printf("|                                                                                                                                                                       \n");
        printf("|                                                                                                                                                           STAGE 1     \n");
        cout  << "|                         "<< Hero <<"                                                                           The Stick Man LV 1                                              \n";
        printf("|                                                                                                                                                                       \n");
        printf("|                                                                                                                                                                       \n");
        printf("|                                                                                                                                                                       \n");
        printf("|                        DAMAGE                                                                              DAMAGE                                                     \n");
        printf("|                                                                                                                                                                       \n");
        printf("|                        ------                                                                       ##                                                                \n");
        printf("|                       /      '               ATK: %d                                                 ##       ------        ATK: %d                                     \n", Player1.atk, Dummy1.atk);
        printf("|                      /--------|      /|      HP:  %d                                               ##     / -  - |        HP:  %d                                    \n", Player1.hp, Dummy1.hp);
        printf("|                      |/   I I |      ||      DEF: %d                                                 ##     | o  o |       DEF: %d                                      \n", Player1.def, Dummy1.def);
        printf("|                      ||    -  /      ||                                                             ##     |  -   |                                                   \n");
        printf("|                        '------'      +++                                                            ##     '-----'                                                    \n");
        printf("|                       /  ------------[]                                                             []----        |                                                   \n");
        printf("|                      /  |      |----/                                                               []------      |                                                   \n");
        printf("|                      |  |      |                                                                    ##    |       |                                                   \n");
        printf("|                      |==|      |                                                                          |       |                                                   \n");
        printf("|                      |==|      |                                                                          |       |                                                   \n");
        printf("|                      '=====[]=='                                                                          --------                                                    \n");
        printf("|                      |         |                                                                          |       |                                                   \n");
        printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                    [A] Attack          [G] USE_Grenade       [Q] USE_MedKit         [E] Exit                                                          |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
    else if (levelStage == 1 && !Player1.isAK && Player1.isPistol)
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy1.hp < 0) Dummy1.hp = 0;
   printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
        printf("|                                                                                                                                                                       \n");
        printf("|                                                                                                                                                           STAGE 1     \n");
        cout  << "|                         "<<Hero <<"                                                                    The Stick Man LV 1                                              \n";
        printf("|                                                                                                                                                                       \n");
        printf("|                                                                                                                                                                       \n");
        printf("|                                                                                                                                                                       \n");
        printf("|                        DAMAGE                                                                              DAMAGE                                                     \n");
        printf("|                                                                                                                                                                       \n");
        printf("|                        ------                                                                        ##                                                               \n");
        printf("|                       /      '               ATK: %d                                                 ##      ------       ATK: %d                                     \n", Player1.atk, Dummy1.atk);
        printf("|                      /--------|              HP:  %d                                                 ##     / -  - |        HP:  %d                                    \n", Player1.hp, Dummy1.hp);
        printf("|                      |/   I I |              DEF: %d                                                 ##     | o  o |      DEF: %d                                    \n", Player1.def, Dummy1.def);
        printf("|                      ||    -  /                                                                      ##     |  -   |                                                  \n");
        printf("|                        '------'       ===='                                                          ##      '-----'                                                  \n");
        printf("|                       /  ------------[]'                                                             []----       |                                                   \n");
        printf("|                      /  |      |----/                                                                []-----      |                                                   \n");
        printf("|                      |  |      |                                                                     ##   |       |                                                   \n");
        printf("|                      |==|      |                                                                          |       |                                                   \n");
        printf("|                      |==|      |                                                                          |       |                                                   \n");
        printf("|                      '=====[]=='                                                                          --------                                                    \n");
        printf("|                      |         |                                                                          |       |                                                   \n");
        printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                    [A] Attack          [G] USE_Grenade       [Q] USE_MedKit         [E] Exit                                                          |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
    else if (levelStage == 1 && Player1.isAK)
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy1.hp < 0) Dummy1.hp = 0;
        printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
        printf("|                                                                                                                                                                       \n");
        printf("|                                                                                                                                                           STAGE 1     \n");
         cout  << "|                         "<<Hero <<"                                                                    The Stick Man LV 1                                              \n";
        printf("|                                                                                                                                                                       \n");
        printf("|                                                                                                                                                                       \n");
        printf("|                                                                                                                                                                       \n");
        printf("|                        DAMAGE                                                                              DAMAGE                                                     \n");
        printf("|                                                                                                                                                                       \n");
        printf("|                        ------                                                                        ##                                                               \n");
        printf("|                       /      '               ATK: %d                                                 ##       ------       ATK: %d                                    \n", Player1.atk, Dummy3.atk);
        printf("|                      /--------|              HP:  %d                                                 ##   / -  - |       HP:  %d                                    \n", Player1.hp, Dummy3.hp);
        printf("|                      |/   I I |              DEF: %d                                                 ##     | o  o |       DEF: %d                                    \n", Player1.def, Dummy3.def);
        printf("|                      ||    -  /                                                                      ##     |  -   |                                                  \n");
        printf("|                        '------'-----_==============='                                                ##     '-----'                                                   \n");
        printf("|                       /  --------___/ |[]'-||---/                                                    []----       |                                                   \n");
        printf("|                      /  |      ||____/     |_|                                                       []-----      |                                                   \n");
        printf("|                      |  |      |                                                                          |       |                                                   \n");
        printf("|                      |==|      |                                                                          |       |                                                   \n");
        printf("|                      |==|      |                                                                          |       |                                                   \n");
        printf("|                      '=====[]=='                                                                          --------                                                    \n");
        printf("|                      |         |                                                                          |       |                                                   \n");
        printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                    [A] Attack          [G] USE_Grenade       [Q] USE_MedKit         [E] Exit                                                          |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
    else if (levelStage == 2 && !Player1.isAK && !Player1.isPistol)
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy2.hp < 0) Dummy2.hp = 0;
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       \n");
printf("|                                                                                                                                                           STAGE 2     \n");
cout  << "|                         "<<Hero <<"                                                                     The 9mm  LV 10                                              \n";
printf("|                                                                                                                                                                       \n");
printf("|                                                                                                                                                                       \n");
printf("|                                                                                                                                                                       \n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     \n");
printf("|                                                                                                                                                                       \n");
printf("|                        ------                                                                                                                                         \n");
printf("|                       /      '               ATK: %d                                                       /------       ATK: %d                                      \n",Player1.atk, Dummy2.atk);
printf("|                      /--------|      /|      HP:  %d                                                    ---------|       HP:  %d                                      \n",Player1.hp, Dummy2.hp);
printf("|                      |/   I I |      ||      DEF: %d                                                      | =  = |       DEF: %d                                      \n", Player1.def, Dummy2.def);
printf("|                      ||    -  /      ||                                                                   |  -   |                                                    \n");
printf("|                        '------'      +++                                                         '====     '-----'                                                    \n");
printf("|                       /  ------------[]                                                             '[]----       |                                                   \n");
printf("|                      /  |      |----/                                                                 ------      |                                                   \n");
printf("|                      |  |      |                                                                          |       |                                                   \n");
printf("|                      |==|      |                                                                          |       |                                                   \n");
printf("|                      |==|      |                                                                          |       |                                                   \n");
printf("|                      '=====[]=='                                                                          --------                                                    \n");
printf("|                      |         |                                                                          |       |                                                   \n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack          [G] USE_Grenade       [Q] USE_MedKit         [E] Exit                                                          |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
     else if (levelStage == 2 && !Player1.isAK && Player1.isPistol)
    {
         if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy2.hp < 0) Dummy2.hp = 0;
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 2     |\n");
printf("|                         %s                              EEE                                                 The 9mm  LV 10                                                |\n",Heroname);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       /------       ATK: %d                                      |\n",Player1.atk, Dummy2.atk);
printf("|                      /--------|              HP:  %d                                                    ---------|       HP:  %d                                      |\n",Player1.hp, Dummy2.hp);
printf("|                      |/   I I |              DEF: %d                                                      | =  = |       DEF: %d                                      |\n", Player1.def, Dummy2.def);
printf("|                      ||    -  /                                                                           |  -   |                                                    |\n");
printf("|                        '------'       ===='                                                      '====     '-----'                                                    |\n");
printf("|                       /  ------------[]'                                                            '[]----       |                                                   |\n");
printf("|                      /  |      |----/                                                                 ------      |                                                   |\n");
printf("|                      |  |      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      '=====[]=='                                                                          --------                                                    |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack          [G] USE_Grenade       [Q] USE_MedKit         [E] Exit                                                          |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}
     else if (levelStage == 2 && Player1.isAK )
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy2.hp < 0) Dummy2.hp = 0;
    //เติม case stage 2 player มี AK
    cout  << "Wait Develop";
}
     else if (levelStage == 3 && !Player1.isAK && !Player1.isPistol)
    {
         if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy3.hp < 0) Dummy3.hp = 0;
   //เติม case stage 3 player ถือ มีด
   cout  << "Wait Develop";
}
else if (levelStage == 3 && !Player1.isAK && Player1.isPistol)
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy3.hp < 0) Dummy3.hp = 0;
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 3     |\n");
printf("|                         %s                                                                             Toxic Timmy LV 25                                              |\n",Heroname);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       /------       ATK: %d                                      |\n",Player1.atk, Dummy3.atk);
printf("|                      /--------|              HP:  %d                                                    ---------|       HP:  %d                                      |\n",Player1.hp, Dummy3.hp);
printf("|                      |/   I I |              DEF: %d                                                      |[]-[] |       DEF: %d                                      |\n", Player1.def, Dummy3.def);
printf("|                      ||    -  /                                                                           |  -   |                                                    |\n");
printf("|                        '------'       ===='                                                  -'=======q    '-----'                                                    |\n");
printf("|                       /  ------------[]'                                                       ||   '[]==---      |                                                   |\n");
printf("|                      /  |      |----/                                                           --    ------      |                                                   |\n");
printf("|                      |  |      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      '=====[]=='                                                                          --------                                                    |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack          [G] USE_Grenade       [Q] USE_MedKit         [E] Exit                                                          |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}
else if (levelStage == 3 && Player1.isAK)
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy3.hp < 0) Dummy3.hp = 0;
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 3     |\n");
printf("|                         %s                                                                             Toxic Timmy LV25                                               |\n",Heroname);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       /------       ATK: %d                                      |\n",Player1.atk, Dummy3.atk);
printf("|                      /--------|              HP:  %d                                                    ---------|       HP:  %d                                      |\n",Player1.hp, Dummy3.hp);
printf("|                      |/   I I |              DEF: %d                                                      |[]-[] |       DEF: %d                                      |\n", Player1.def, Dummy3.def);
printf("|                      ||    -  /                                                                           |  -   |                                                    |\n");
printf("|                        '------'-----_==============='                                       -'=======q    '-----'                                                     |\n");
printf("|                       /  --------___/ |[]'-||---/                                              ||   '[]==---      |                                                   |\n");
printf("|                      /  |      ||____/     |_|                                                  --    ------      |                                                   |\n");
printf("|                      |  |      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      '=====[]=='                                                                          --------                                                    |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack          [G] USE_Grenade       [Q] USE_MedKit         [E] Exit                                                          |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}
else if (levelStage == 4 && !Player1.isAK && !Player1.isPistol)
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy4.hp < 0) Dummy4.hp = 0;
    //เติม case stage 4 player ถือ มีด
    cout  << "Wait Develop";
}
else if (levelStage == 4 && !Player1.isAK && Player1.isPistol)
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy4.hp < 0) Dummy4.hp = 0;
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 4     |\n");
printf("|                         %s                                                                            Just_a_teen LV50                                                |\n",Heroname);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       /------      ATK: %d                                       |\n",Player1.atk, Dummy4.atk);
printf("|                      /--------|              HP:  %d                                                    __|-------|__   HP:  %d                                       |\n",Player1.hp, Dummy4.hp);
printf("|                      |/   I I |              DEF: %d                                                      | U  U |      DEF: %d                                       |\n", Player1.def, Dummy4.def);
printf("|                      ||    -  /                                                                   |_:     |   ^  |                                                    |\n");
printf("|                        '------'       ===='                                                '==-'======'    '-----'                                                    |\n");
printf("|                       /  ------------[]'                                                       [|   '[]==-/  |_| ||                                                   |\n");
printf("|                      /  |      |----/                                                           [|    ------     ||                                                   |\n");
printf("|                      |  |      |                                                                 [|       |      ||                                                   |\n");
printf("|                      |==|      |                                                                          |[][][]||                                                   |\n");
printf("|                      |==|      |                                                                          | | | |||                                                   |\n");
printf("|                      '=====[]=='                                                                          ===[]====                                                   |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack          [G] USE_Grenade       [Q] USE_MedKit         [E] Exit                                                          |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}
else if (levelStage == 4 && Player1.isAK)
    {
        if(Player1.hp < 0) Player1.hp = 0;
        if(Dummy4.hp < 0) Dummy4.hp = 0;
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 4     |\n");
printf("|                         %s                                                                            Just_a_teen LV50                                                |\n",Heroname);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       /------      ATK: %d                                       |\n",Player1.atk, Dummy4.atk);
printf("|                      /--------|              HP:  %d                                                    __|-------|__   HP:  %d                                       |\n",Player1.hp, Dummy4.hp);
printf("|                      |/   I I |              DEF: %d                                                      | U  U |      DEF: %d                                       |\n", Player1.def, Dummy4.def);
printf("|                      ||    -  /                                                                   |_:     |   ^  |                                                    |\n");
printf("|                         '------'-----_==============='                                     '==-'======'    '-----'                                                    |\n");
printf("|                       /  --------___/ |[]'-||---/                                              [|   '[]==-/  |_| ||                                                   |\n");
printf("|                      /  |      ||____/     |_|                                                  [|    ------     ||                                                   |\n");
printf("|                      |  |      |                                                                 [|       |      ||                                                   |\n");
printf("|                      |==|      |                                                                          |[][][]||                                                   |\n");
printf("|                      |==|      |                                                                          | | | |||                                                   |\n");
printf("|                      '=====[]=='                                                                          ===[]====                                                   |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack          [G] USE_Grenade       [Q] USE_MedKit         [E] Exit                                                          |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}

}
