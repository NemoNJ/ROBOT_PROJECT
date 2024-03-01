#include<iostream>
#include<windows.h>
#include <conio.h>

using namespace std;

int main(){
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
SetConsoleTextAttribute(color , 12);	//Add Color
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
SetConsoleTextAttribute(color , 14);
printf("|                                                                                                                                                                       |\n");
printf("|                                                  ____________________________________________________________________                                                 |\n");
printf("|                                                 |                                                                    |                                                |\n");
printf("|                                                |        I        IIII       III I       I       I I I     I I I I     |                                               |\n");
printf("|                                               |        I I      I    I     I           I I      I    I    I            |                                              |\n");
printf("|                                              |        I   I     I   I     I           I   I     I     I   I             |                                             |\n");
printf("|                                            * |       I ___ I    I    I    I          I ____I    I     I   I I I I       | *                                           |\n");
printf("|                                           *   |     I       I   I     I    I        I       I   I    I    I            |   *                                          |\n");
printf("|                                           *    |   I         I  I      I    III I  I         I  I I I     I I I I     |    *                                          |\n");
printf("|                                           *     |____________________________________________________________________|     *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                       ");SetConsoleTextAttribute(color , 9);printf("Press[1] to enter Game BattleField 03");SetConsoleTextAttribute(color , 14);printf("                    *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                          ");SetConsoleTextAttribute(color , 9);printf("Press[2] to enter  3Card Game");SetConsoleTextAttribute(color , 14);printf("                         *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                          ");SetConsoleTextAttribute(color , 9);printf("Press[3] to enter Quiz Game");SetConsoleTextAttribute(color , 14);printf("                           *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           *                                                                                *                                          |\n");
printf("|                                           **********************************************************************************                                          |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
SetConsoleTextAttribute(color , 12);
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
SetConsoleTextAttribute(color , 15);
  char click = getch();
  printf("%c\n",click);
  if(click == '1')
  {
  system("cls");
  system("main");
  } 
  else if(click == '2'){
    system("cls");
    system("3Card");
  }
  else if(click == '3'){
   system("cls");
  system("quizGame");
  }
  else {
    cout << "Invalid input";
    cout << "Please input again";
    system("cls");
    main();
  }
}