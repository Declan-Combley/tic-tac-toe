#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Board {
    char top_left; 
    char top_middle; 
    char top_right; 
    char middle_left; 
    char middle_middle; 
    char middle_right; 
    char bottom_left; 
    char bottom_middle; 
    char bottom_right; 
} Board;

void populate_board(Board *Board)
{
    Board->top_left = ' ';  
    Board->top_middle = ' ';  
    Board->top_right = ' ';  
    Board->middle_left = ' ';  
    Board->middle_middle = ' ';  
    Board->middle_right = ' ';  
    Board->bottom_left = ' ';  
    Board->bottom_middle = ' ';  
    Board->bottom_right = ' ';  
}

void display_board(const Board Board)
{
    printf(" -----------  \n");
    printf("| %c | %c | %c |\n", Board.top_left, Board.top_middle, Board.top_right);
    printf(" ----- ----- \n");
    printf("| %c | %c | %c |\n", Board.middle_left, Board.middle_middle, Board.middle_right);
    printf(" ----- ----- \n");
    printf("| %c | %c | %c |\n", Board.bottom_left, Board.bottom_middle, Board.bottom_right);
    printf(" -----------\n");
}


void update_board(char i, int itter, Board *board)
{
    int pos = i - '0';
    char c;
    
    if (itter % 2 != 0) {
        c = 'o';
        
        if      (pos == 1) { board->top_left = c; }
        else if (pos == 2) { board->top_middle = c; }
        else if (pos == 3) { board->top_right = c; }
        else if (pos == 4) { board->middle_left = c; }
        else if (pos == 5) { board->middle_middle = c; }
        else if (pos == 6) { board->middle_right = c; }
        else if (pos == 7) { board->top_left = c; }
        else if (pos == 8) { board->top_middle = c; }
        else if (pos == 9) { board->top_right = c; }
        else {
            fprintf(stderr, "Something went very wrong\n");
            exit(1);
        }
    } else {
        c = 'x';
        
        if      (pos == 1) { board->top_left = c; }
        else if (pos == 2) { board->top_middle = c; }
        else if (pos == 3) { board->top_right = c; }
        else if (pos == 4) { board->middle_left = c; }
        else if (pos == 5) { board->middle_middle = c; }
        else if (pos == 6) { board->middle_right = c; }
        else if (pos == 7) { board->top_left = c; }
        else if (pos == 8) { board->top_middle = c; }
        else if (pos == 9) { board->top_right = c; }
        else {
            fprintf(stderr, "Something went very wrong\n");
            exit(1);
        }
    }
}

void handle_input(char i, int itter, Board *Board_pointer)
{
    if (i >= '0' && i <= '9') {
        update_board(i, itter, Board_pointer);
    } else {
        printf("%c is invalid expected a co-ordinate between 1 and 9\n", i);
        exit(1);
    }}

int main()
{
    Board board;
    Board *board_pointer = &board;
    populate_board(board_pointer);

    system("clear");

    int itter = 1;
    
    while (itter <= 18) {
        display_board(board);
        
        int i = getchar();
        getchar();
        
        handle_input(i, itter, board_pointer);
        system("clear");
        itter++;
    }
    
    return 0;
}
