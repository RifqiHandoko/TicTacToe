#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int sq[10] = {2,2,2,2,2,2,2,2,2,2};
void calibrateArray();
void singlePlayer();
int easyPlayer();
int hardPlayer();
int hardCom();
int twoPlayer();
int checkWin();
void board();
void reset();

int main(){

    char choice;
    system("cls");
    reset();

    printf("\n----------------MENU----------------\n");
    printf("\n\t1 : Single Player");
    printf("\n\t2 : Two Player");
    printf("\n\n\t0 : Exit");
    printf("\n\n\tEnter your choice: ");
    scanf("%c",&choice);

    switch (choice){
    case '1':
        singlePlayer();
        break;
    case '2':
        twoPlayer();
        break;
    case '0':
        exit(1);
    default:
        main();
    }

    return 0;
}

void calibrateArray(){
    for(int n=0;n<10;++n){
        if(square[n]=='X')
            sq[n]=3;
        else if(square[n]=='O')
            sq[n]=5;
        else
            sq[n]=2;
        }
}

void singlePlayer(){
    int choice;
    system("cls");
    reset();

    printf("\n----------------MENU----------------\n");
    printf("\n\t1 : Easy");
    printf("\n\t2 : Hard");
    printf("\n\n\t0 : Back");
    printf("\n\n\tEnter your choice: ");
    scanf("%d",&choice);

    switch (choice){
    case 1:
        easyPlayer();
        break;
    case 2:
        hardPlayer();
        break;
    case 0:
        main();
    }
}

int hardCom(int count){
    int i,num, n = 0;
    
    calibrateArray();
    
    while(n<2){
        if(n == 0)
            num = 50;
        else if(n == 1)
            num = 18;
        for(i=1; i<=7; i+=3){
            if(sq[i] * sq[i+1] * sq[i+2] == num){
                if(sq[i] == 2)
                    return i;
                if(sq[i+1] == 2)
                    return i+1;
                if(sq[i+2] == 2)
                    return i+2;
            }
        }

        for(i=1; i<=3; i++){
            if(sq[i] * sq[i+3] * sq[i+6] == num){
                if(sq[i] == 2)
                    return i;
                if(sq[i+3] == 2)
                    return i+3;
                if(sq[i+6] == 2)
                    return i+6;
            }
        }

        if(sq[1] * sq[5] * sq[9] == num){
            if(sq[1] == 2)
                return 1;
            if(sq[5] == 2)
                return 5;
            if(sq[9] == 2)
                return 9;
        }

        if(sq[3] * sq[5] * sq[7] == num){
            if(sq[3] == 2)
                return 3;
            if(sq[5] == 2)
                return 5;
            if(sq[7] == 2)
                return 7;
        }
        
        n++;
    }

    if(sq[5] == 2)
        return 5;
    if(sq[2] == 2)
        return 2;
    if(sq[4] == 2)
        return 4;
    if(sq[6] == 2)
        return 6;
    if(sq[8] == 2)
        return 8;
    if(sq[1] == 2)
        return 1;
    if(sq[3] == 2)
        return 3;
    if(sq[7] == 2)
        return 7;
    if(sq[9] == 2)
        return 9;
    else
        return 0;
}

int hardPlayer(){

    int player = 1, i, choice;
    system("cls");

    char mark;
    int count=0;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        if (player == 2){
            choice=hardCom(count);
            }
        if (player == 1){
            printf("\tPlayer, enter a number:  ");
            scanf("%d", &choice);
        }

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else {
            if(player == 1){
                printf("\t\tInvalid Move!");

                player--;
                getch();
            }
            else if (player == 2){
                printf("\t\tLoading....");
                player--;
            }

        }
        i = checkWin();
        player++;
        count++;
    }
    while (i ==  -1);
    board();

    if (i == 1 && player == 2){
        printf("\t\tPlayer Win ");
        getch();
        main();
    }
    else if (i == 1 && player != 2){
        printf("\t\tComputer Win ");
        getch();
        main();
    }
    else{
        printf("\t\t  Game Draw");
        getch();
        main();
    }

    return 0;
}

int easyPlayer(){

    int player = 1, i, choice;
    system("cls");

    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        if (player == 2){
            srand(time(0));
            choice=rand()%10;
        }
        if (player == 1){
            printf("\tPlayer, enter a number:  ");
            scanf("%d", &choice);
        }

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else {
            if(player == 1){
                printf("\t\tInvalid Move!");

                player--;
                getch();
            }
            else if (player == 2){
                printf("\t\tLoading....");
                player--;
            }

        }
        i = checkWin();
        player++;
    }
    while (i ==  -1);
    board();

    if (i == 1 && player == 2){
        printf("\t\tPlayer Win ");
        getch();
        main();
    }
    else if (i == 1 && player != 2){
        printf("\t\tComputer Win ");
        getch();
        main();
    }
    else{
        printf("\t\t  Game Draw");
        getch();
        main();
    }

    return 0;
}

int twoPlayer(){

    int player = 1, i, choice;
    system("cls");

    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        printf("\tPlayer %d, enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else{
            printf("\tInvalid Move!");

            player--;
            getch();
        }
        i = checkWin();
        player++;
    }
    while (i ==  - 1);
    board();

    if (i == 1){
        printf("\t\tPlayer %d Win ", --player);
        getch();
        main();
    }
    else{
        printf("\t\t  Game Draw");
        getch();
        main();
    }

    return 0;
}

int checkWin(){

    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else{
        return  - 1;
    }

}

void board(){

    system("cls");

    printf("\n");
    printf("\t         |         |         \n");
    printf("\t         |         |         \n");
    printf("\t    %c    |    %c    |    %c   \n", square[1], square[2], square[3]);
    printf("\t         |         |         \n");
    printf("\t_________|_________|_________\n");
    printf("\t         |         |         \n");
    printf("\t         |         |         \n");
    printf("\t    %c    |    %c    |    %c   \n", square[4], square[5], square[6]);
    printf("\t         |         |         \n");
    printf("\t_________|_________|_________\n");
    printf("\t         |         |         \n");
    printf("\t         |         |         \n");
    printf("\t    %c    |    %c    |    %c   \n", square[7], square[8], square[9]);
    printf("\t         |         |         \n");
    printf("\t         |         |         \n\n");
}

void reset(){

    square[1]='1';
    square[2]='2';
    square[3]='3';
    square[4]='4';
    square[5]='5';
    square[6]='6';
    square[7]='7';
    square[8]='8';
    square[9]='9';
    calibrateArray();

}

/**
Coded by:
Juan Felix Aldo                 <1706022520>
Muhammad Rifqi Handokoputra     <1706985312>

Compiled by Code::Blocks 17.12 GNU GCC Compiler

Reference:
http://www.cprogrammingnotes.com/question/tic-tac-toe-game.html
https://www.codewithc.com/c-projects-with-source-code/
*/
