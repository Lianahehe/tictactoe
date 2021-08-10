#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int checkWin();
void drawBoard;

int main(){
    // initialisng the player variable ,i is to keep track of the progress of the game
    int player = 1, i ,choice;
    char mark; // X,O

    // does function while i is -1
    do {
        drawBoard();
        player = (player % 2) ? 1 : 2;
        // %d is the input from the 2nd variable
        printf("Player %d, enter the choice : ", player );
        mark = (player == 1)? 'X' :'O';
        scanf("%d", &choice);

        // improve this with a for loop after uve finished this program
        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square [2] == '2')
            square[2] = mark;
        else if (choice == 3 && square [3] == '3')
            square[3] = mark;
        else if (choice == 4 && square [4] == '4')
            square[4] = mark;
        else if (choice == 5 && square [5] == '5')
            square[5] = mark;
        else if (choice == 6 && square [6] == '6')
            square[6] = mark;
        else if (choice == 7 && square [7] == '7')
            square[7] = mark;
        else if (choice == 8 && square [8] == '8')
            square[8] = mark; 
        else if (choice == 9 && square [9] == '9')
            square[9] = mark;
        
        else{
            printf("Invalid option");
            player--;
            getch();
        }
        // return 1 if theres winner, -1 if game still in progress, 0 if its a draw
        i = checkWin();
        player++;


    }while (i == -1);

    drawBoard();
    if (i==1){
        printf(" ==> Player %d won",--player );
    }
    else {
        printf("==> Game draw");
    }
    getch();
    return 0;
}

int checkWin(){
    // horizontal
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    
}