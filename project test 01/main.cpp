#include "game03.h"
#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include <cmath>
#include <algorithm>
#include <conio.h>
#include <stdio.h>
#include <fstream>
using namespace std;
string hero_name;
void condition(){
     printf("Press button A to ATTACK\n");
     printf("Press button Q to USE MEDKIT\n");
     printf("Press button G to USE GRENADE\n");
     printf("Press button S to SAVE GAME\n");
     printf("Press button L to BLOAD GAME\n");
     printf("Press button E to EXIT GAME\n");
}
void terminal(string &hero_name){
     string name;
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                            ____________________________________________                                                               |\n");
printf("|                                                           [                                            ]                                                              |\n");
printf("|                            *******************************[      WELCOME TO BATTLE BOSS GAME 03        ]*********************************                             |\n");
printf("|                            *                              [____________________________________________]                                *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                          [1] PLAY GAME                                                     *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                          [2] HOW TO PLAY                                                   *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                          [E] EXIT                                                          *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                                                                                            *                             |\n");
printf("|                            *                                              ....                                                          *                             |\n");
printf("|                            *                                            .'    '.                                                        *                             |\n");
printf("|                            *                                           .   ......  ___       _                                          *                             |\n");
printf("|                            *                                           . .' I_I_;./___|_____/-|____                                     *                             |\n");
printf("|                            *                                         .'     |     ____.--;;;;;;;'                                       *                             |\n");
printf("|                            *                                        .  ...  |____/||  [ ]'''                                            *                             |\n");
printf("|                            *                                        :     ...   ...'   [_]                                              *                             |\n");
printf("|                            *                                       .    .     :                                                         *                             |\n");
printf("|                            *                                       . :  . :  : .                                                        *                             |\n");
printf("|                            *                                       : : .  :  : :                                                        *                             |\n");
printf("|                            *                                       :...........:                                                        *                             |\n");
printf("|                            *                                       :           :                                                        *                             |\n");
printf("|                            **************************************************************************************************************                             |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
cout << "                                           Enter Your Name : ";
getline(cin,name);
 hero_name = name;
}
string choose_mon(int count){ //เลือก mons ที่จะบวก
    string boss;
    if(count == 1) boss = "BOSS01";
    else if(count == 2) boss = "BOSS02";
    else if(count == 3) boss = "BOSS03";
    else if(count == 4) boss = "BOSS04";
    return boss;
}
char atkboss(char BOSS_action){//เช็ค monster action
   int ranAtkboss = rand()%10;
        if(ranAtkboss <= 8) BOSS_action == 'a';
        if(ranAtkboss > 8) BOSS_action == 'b';
    return BOSS_action;
}

void starterbotton(int money,char player_action){
     char click = getch();
     printf("%c\n",click);
     if(click == '1') money = 0;
     else if(click == '2') condition();
     else if(click == 'e') player_action = 'e';
     else cout << "Invalid input\n";
}
void showshop(int money,Unit &type,char player_action,char BOSS_action,Unit soilder101){
        button(player_action,BOSS_action);
    int grenadeshop = soilder101.grenade;
    int armorshop =  soilder101.weararmor;
    int medkitshop = soilder101.medkit;
    int gunshop;
    int rifleshop;
    if(soilder101.havegun == true) gunshop = 1;
    else gunshop = 0;
    if(soilder101.haverifle == true) rifleshop = 1;
    else rifleshop = 0;
// while(true){
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
printf("|            Amount : %d                                               Amount : %d                                      Amount : %d                                     |\n",gunshop,armorshop,medkitshop);
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
printf("|            Amount : %d                                               Amount : %d / 2                                                                                  |\n",rifleshop,grenadeshop);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|     YOUR MONEY : %d              PRESS [T] To continue                                                                                                                |\n",money);
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
//  if(player_action == 't') break;
// }
}

int main(){
    // unit 1 =new UNIT("Player") ;
    // Unit Boss1 = new Unit("boos1",15,150,2) ;
    // Unit Boss2 =
    Unit soilder101,boss;
    int money = 100;
    char player_action = '\0',BOSS_action = '\0'; //กำหนดค่าเริ่มต้น monster action
    terminal(hero_name);
    starterbotton(money,player_action);
    srand(time(0));
   int i = 1;
   string boss_id;

   while(i < 5){
    showmap(soilder101);//show stage
    boss_id = choose_mon(i);
	soilder101.createchar("Soilder");
	boss.createchar(boss_id);
	int p = 0, m = 0;//กำหนดค่าเริ่มต้น
             showshop(money,soilder101,player_action,BOSS_action,soilder101);
        soilder101.buy_item(money);//ซื้อของก่อนเข้ารอบถัดไป        
        
	while(true){
		boss.newturn();	
		soilder101.newturn();			
		drawScene(soilder101,boss,hero_name);		
        //player
        button(player_action,BOSS_action);
        if(player_action == 'a') p = soilder101.attack(boss,"Soilder"); 
        
        if(player_action == 'q'){
            if(soilder101.medkit > 0) p = soilder101.heal();
            else cout << "Emtry\n";
        } 
        if(player_action == 'g'){
            if(i > 1 && soilder101.grenade > 0) p = soilder101.usegrenade(boss,boss_id);
            else if(i > 1 && soilder101.grenade < 0) cout << "Emtry\n";
            else cout << "Your level is too low\n";
        }
        if(player_action == 'e') break;
        //mons
		if(i > 0){
        if(i == 4){
              BOSS_action = atkboss(BOSS_action);
        }
        else{
              BOSS_action = 'a';
        }
        }
        if(BOSS_action == 'a') m = boss.attack(soilder101,boss_id); 
        if(BOSS_action == 'b') m = boss.superattack(soilder101,boss_id);
        
		if(soilder101.isDead()){
			drawScene(soilder101,boss,hero_name);
            money += 10000;
			playerLose();
			break; 
		}
		
		if(boss.isDead()){
			drawScene(soilder101,boss,hero_name);//อาจแก้เป็นฉากตาย
            soilder101.level_up();
			playerWin();
            getmoney(boss_id,money);
            i++;
            break;
        }
    }
}
}