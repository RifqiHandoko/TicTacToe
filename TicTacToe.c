#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

char square[10] = {'o'};
int count=0;
int sq[10];

struct node{
    int data;
    struct node *next;
} *current = NULL, *previous = NULL,*head = NULL;

void menuExit();
void singlePlayer();
int Player();
int easyCom();
int hardCom();
int twoPlayer();
int checkWin();
void board();
void reset();
void calibrateArray();
void insert();
void display();
int deleteData();
void bubbleSort();
void swap();
int countWin();

int main(){ //Start point and also menu for the program

    char choice;
    reset();

    printf("\n--------------TIC TAC TOE--------------\n");
    printf("\n\t1 : Single Player");
    printf("\n\t2 : Dual Player");
    printf("\n\t3 : Help");
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
    case '3':
        system("cls");
        printf("\n--------------------HELP--------------------\n");
        printf("\n\t\tSingle Player\n");
        printf("\n\t1. You will play against\n\t   a computer");
        printf("\n\t2. Press number based on\n\t   the boxes to make a move");
        printf("\n\t3. You will play with 'X'\n\t   and the computer will be 'O'");
        printf("\n\n\t\tDual Player\n");
        printf("\n\t1. You will play against\n\t   another player");
        printf("\n\t2. Press number based on\n\t   the boxes to make a move");
        printf("\n\t3. The first player will\n\t   be 'X' and the second\n\t   player will be 'O'");
        getch();
        system("cls");
        main();
        break;
    case '0':
        menuExit();
    default:
        system("cls");
        main();
        break;
    }

    return 0;
}

void menuExit(){ //Exit menu to shows scores
    system("cls");

    printf("\n--------------TIC TAC TOE--------------\n");

    if(count != 0)
        display();

    bubbleSort(head);

    while(deleteData(2) == 0)
        deleteData(2);
        if(count == 0 && deleteData(2) == -1){
            printf("\n\tSorry!\n\tYou never win");
            getch();
            exit(1);
        }


    while(deleteData(3) == 0)
        deleteData(3);
        if(count == 0 && deleteData(3) == -1){
            printf("\n\tSorry!\n\tYou never win");
            getch();
            exit(1);
        }

    printf("\n\tCongratulations!\n\tYou have win %d times", countWin());

    getch();
    exit(1);
}

void singlePlayer(){ //Menu for single player, which consist of 3 modes
    int choice;
    system("cls");
    reset();

    printf("\n--------------TIC TAC TOE--------------\n");
    printf("\n\t1 : Easy");
    printf("\n\t2 : Medium");
    printf("\n\t3 : Hard");
    printf("\n\n\t0 : Back\n");

    if(count != 0)
        display();

    else if(count == 0)
        count++;

    printf("\n\tEnter your choice: ");
    scanf("%d",&choice);

    switch (choice){
    case 1:
        Player(0);
        break;
    case 2:
        Player(1);
        break;
    case 3:
        Player(2);
        break;
    case 0:
        count--;
        main();
    }
}

int hardCom(){ //Algorithm for hard mode, using multiplication
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

int easyCom(){ //Algorithm for easy mode, using randomizer
    int i;

    srand(time(0));
    i = rand()%10;

    return i;
}

int Player(int type){ //Function to execute single player mode, able to deduce which mode selected

    int player = 1, i, choice, n;
    system("cls");

    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        if (player == 2 && type == 0)
            choice = easyCom();

        else if (player == 2 && type == 1){
            n = easyCom();
            if(n%2 == 0)
                choice = hardCom();
            else
                choice = easyCom();
        }

        else if (player == 2 && type == 2)
            choice = hardCom();

        else if (player == 1){
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
        insert(1);
        getch();
        system("cls");
        main();
    }
    else if (i == 1 && player != 2){
        printf("\t\tComputer Win ");
        insert(2);
        getch();
        system("cls");
        main();
    }
    else{
        printf("\t\t  Game Draw");
        insert(3);
        getch();
        system("cls");
        main();
    }

    return 0;
}

int twoPlayer(){ //Function to execute dual player mode

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
        system("cls");
        main();
    }
    else{
        printf("\t\t  Game Draw");
        getch();
        system("cls");
        main();
    }

    return 0;
}

int checkWin(){ //Function to check win (three consecutive mark)

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
    else
        return  - 1;
}

void board(){ //Function to print board for interface in game

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

void reset(){ //Function to reset array into initial condition

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

void calibrateArray(){ //Function for calibrating array to be used in hard mode algorithm

    int n;

    for(n=0;n<10;++n){
        if(square[n]=='X')
            sq[n]=3;
        else if(square[n]=='O')
            sq[n]=5;
        else
            sq[n]=2;
        }
}

void insert(int data){ //Function to add data to result history

    struct node *link = (struct node*) malloc(sizeof(struct node));

    link->data = data;

    if(head == NULL)
        link->next = NULL;

    else
   		link->next = head;

    head = link;
}

void display(){ //Function do display win status in single player mode

    struct node *ptr = head;

    printf("\n\t       WIN STATUS\n\t");

    int i = 0;

    while(ptr != NULL && i != 3) {
        if(ptr->data == 1)
            printf(" => Player");
        else if(ptr->data == 2)
            printf(" => Computer");
        else if(ptr->data == 3)
            printf(" => Draw");

        ptr = ptr->next;
        i++;
    }

    printf("\n");

}

int deleteData(int old){ //Function do delete data on the linked list

    int pos = 0;

    current = head;
    while(current->next!=NULL){
        if(current->data == old){
            if(pos==0)
            head=current->next;
        else
            previous->next=current->next;
        return 0;
        }

        previous = current;
        current = current->next;
        pos++;
    }

   return -1;
}

void bubbleSort(struct node *start){ //Function to sort linked list based on numbers
    int swapped;
    struct node *ptr1;
    struct node *lptr = NULL;

    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

void swap(struct node *a, struct node *b){ //Function to swap position used in linked list
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

int countWin(){ //Function to count the win of player

    struct node *ptr = head;

    int i = 0;

    while(ptr != NULL){
        i++;
        ptr = ptr->next;
    }

    return i;
}


/**
Coded by:
Muhammad Rifqi Handokoputra     <1706985312>

Featuring:
Juan Felix Aldo                 <1706022520>

Compiled using Code::Blocks 17.12 GNU GCC Compiler

Reference:
http://www.cprogrammingnotes.com/question/tic-tac-toe-game.html
https://www.codewithc.com/c-projects-with-source-code/
*/
