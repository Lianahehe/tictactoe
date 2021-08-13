#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>

char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
void drawBoard();
void marking_board(int,char);
int checkWin();

int main(){
    int choice,player=1, i;
    // X or O
    char mark;
    
    do {
        drawBoard();
        player = (player % 2)? 1: 2;
        
        printf("Player %d, enter a number : ", player );
        scanf("%d", &choice);

        // if player == 1 then it'll mark with X
        mark = (player==1) ? 'X' : 'O';
        marking_board(choice,mark);
        i = checkWin();
        player++;

    }while (i == -1); 

    drawBoard();

    if(i==1){
        printf("Player %d has won the game", --player);
    }
    else{
        printf("The game is drawn");
    }
    return 0;
}

void drawBoard(){

    clear_screen;
    printf("\n\n\t Tic Tac Toe \n\n");
    printf("Player 1(X) -- Player 2(O)\n\n");
    printf("       |       |       \n");
    printf("   %c   |    %c  |   %c   \n", square[1],square[2],square[3]);
    printf("_______|_______|_______\n");
    printf("       |       |       \n");
    printf("   %c   |    %c  |   %c   \n", square[4],square[5],square[6]);
    printf("_______|_______|_______\n");
    printf("       |       |       \n");
    printf("   %c   |    %c  |   %c   \n", square[7],square[8],square[9]);


}

void marking_board(int choice, char mark){
    if (choice == 1 && square[1]=='1')
        square[1] = mark;
    else if (choice==2 && square[2]=='2')
        square[2] = mark;
    else if (choice==3 && square[3]=='3')
        square[3] = mark;
    else if (choice==4 && square[4]=='4')
        square[4] = mark;
    else if (choice==5 && square[5]=='5')
        square[5] = mark;
    else if (choice==6 && square[6]=='6')
        square[6] = mark;
    else if (choice==7 && square[7]=='7')
        square[7] = mark;
    else if (choice==8 && square[8]=='8')
        square[8] = mark;
    else if (choice==9 && square[9]=='9')
        square[9] = mark;
    else{
        printf("Invalid choice");
    }
}

int checkWin(){
    // horizontal
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    // vertical
    if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    //diagonal
    if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    
    // no match
    else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' &&square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;

    else
        return -1;
}

