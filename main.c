#include <stdio.h>

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


int main()
{
    Board Board;
    struct Board *Board_pointer = &Board;
    populate_board(Board_pointer);
    display_board(Board);
    
    return 0;
}


