#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    Board->top_left      = ' ';  
    Board->top_middle    = ' ';  
    Board->top_right     = ' ';  
    Board->middle_left   = ' ';  
    Board->middle_middle = ' ';  
    Board->middle_right  = ' ';  
    Board->bottom_left   = ' ';  
    Board->bottom_middle = ' ';  
    Board->bottom_right  = ' ';  
}

void display_board(const Board board)
{
    system("clear");
    printf("                          ..cuod8B8bou,,.          \n");
    printf("                 ..,uod8BBBBBBBBBBBBBBBBRPFT?l8_   \n");
    printf("            ,=m8BBBBBBBBBBBBBBBRPFT?!|||||||||||   \n");
    printf("            !...:!TVBBBRPFT||||||||||!!^^^   *|||  \n");
    printf("            !.......:!?|||||!!^^            %c ||| \n",    board.top_right);
    printf("            !.........||||            %c       ||| \n",   board.top_middle);
    printf("            !.........||||   %c                ||| \n",     board.top_left);
    printf("            !.........||||                  %c ||| \n",  board.middle_right);
    printf("            !.........||||            %c       ||| \n", board.middle_middle);
    printf("            !.........||||   %c                ||| \n",   board.middle_left);
    printf("            !.........||||                  %c ||| \n",  board.bottom_right);
    printf("            `.........||||            %c      ,||| \n", board.bottom_middle);
    printf("             .;.......||||   %c         _.-!!||||: \n",   board.bottom_left);
    printf("      .,uodWBBBBb.....||||        _.-!!|||||||BB!:                      \n");
    printf("   !YBBBBBBBBBBBBBBb..!|||:..-!!|||||||!iof68BBBBBb....                 \n");
    printf("   !..YBBBBBBBBBBBBBBb!!||||||||!iof68BBBBBBRPFT?!::   `.               \n");
    printf("   !....YBBBBBBBBBBBBBBbaaitf68BBBBBBRPFT?!:::::::::     `.             \n");
    printf("   !......YBBBBBBBBBBBBBBBBBBBRPFT?!::::::;:!^ `;:::       `.           \n");
    printf("   !........YBBBBBBBBBBRPFT?!::::::::::.......::::::;         iBBbo.    \n");
    printf("   `..........YBRPFT?!::::::::::::::::::::::::;iof68bo.      WBBBBbo.   \n");
    printf("     `..........:::::::::::::::::::::::;iof688888888888b.     `YBBBP^   \n");
    printf("       `........::::::::::::::::;iof688888888888888888888b.             \n");
    printf("         `......:::::::::;iof688888888888888888888888888888b.           \n");
    printf("           `....:::;iof688888888888888888888888888888888899fT!          \n");
}

void update_board(char i, int *itter, Board *board)
{
    int pos = i - '0';
    char c;
    
    if (*itter % 2 != 0) {
        c = 'O';
        
        if      (pos == 1 && board->top_left      != 'X') { board->top_left      = c; }
        else if (pos == 2 && board->top_middle    != 'X') { board->top_middle    = c; }
        else if (pos == 3 && board->top_right     != 'X') { board->top_right     = c; }
        else if (pos == 4 && board->middle_left   != 'X') { board->middle_left   = c; }
        else if (pos == 5 && board->middle_middle != 'X') { board->middle_middle = c; }
        else if (pos == 6 && board->middle_right  != 'X') { board->middle_right  = c; }
        else if (pos == 7 && board->bottom_left   != 'X') { board->bottom_left   = c; }
        else if (pos == 8 && board->bottom_middle != 'X') { board->bottom_middle = c; }
        else if (pos == 9 && board->bottom_right  != 'X') { board->bottom_right  = c; }
        else {
            printf("\nCannot Place A Character There\nTry Again\n");
            system("sleep 1.5");
            *itter -= 1;
        }
    } else {
        c = 'X';

        if      (pos == 1 && board->top_left      != 'O') { board->top_left      = c; }
        else if (pos == 2 && board->top_middle    != 'O') { board->top_middle    = c; }
        else if (pos == 3 && board->top_right     != 'O') { board->top_right     = c; }
        else if (pos == 4 && board->middle_left   != 'O') { board->middle_left   = c; }
        else if (pos == 5 && board->middle_middle != 'O') { board->middle_middle = c; }
        else if (pos == 6 && board->middle_right  != 'O') { board->middle_right  = c; }
        else if (pos == 7 && board->bottom_left   != 'O') { board->bottom_left   = c; }
        else if (pos == 8 && board->bottom_middle != 'O') { board->bottom_middle = c; }
        else if (pos == 9 && board->bottom_right  != 'O') { board->bottom_right  = c; }

        else {
            printf("\nCannot Place A Character There\nTry Again\n");
            system("sleep 1.5");
            *itter -= 1;
        }
    }
}

void handle_input(char i, int *itter, Board *Board_pointer)
{
    if (i >= '0' && i <= '9') {
        update_board(i, itter, Board_pointer);
    } else {
        // TODO: Fix This Bug
        printf("%c is invalid \n expected a co-ordinate between 1 and 9\n", i);
        *itter -= 1;
    }
}

void winner(char player, Board board)
{
    display_board(board);
    printf("%c won \n", player);
    exit(0);
}

char calculate(const Board board)
{
    char o = 'O';
    char x = 'X';
    
    if      (board.top_left    == o && board.top_middle    == o && board.top_right     == o ) { winner(o, board); }
    else if (board.middle_left == o && board.middle_middle == o && board.middle_right  == o ) { winner(o, board); }
    else if (board.bottom_left == o && board.bottom_middle == o && board.bottom_right  == o ) { winner(o, board); }
    else if (board.top_left    == o && board.middle_left   == o && board.bottom_left   == o ) { winner(o, board); }
    else if (board.top_middle  == o && board.middle_middle == o && board.bottom_middle == o ) { winner(o, board); }
    else if (board.top_right   == o && board.middle_right  == o && board.bottom_right  == o ) { winner(o, board); }
    else if (board.top_left    == o && board.middle_middle == o && board.bottom_right  == o ) { winner(o, board); }
    else if (board.top_right   == o && board.middle_middle == o && board.bottom_left   == o ) { winner(o, board); }

    if      (board.top_left    == x && board.top_middle    == x && board.top_right     == x ) { winner(x, board); }
    else if (board.middle_left == x && board.middle_middle == x && board.middle_right  == x ) { winner(x, board); }
    else if (board.bottom_left == x && board.bottom_middle == x && board.bottom_right  == x ) { winner(x, board); }
    else if (board.top_left    == x && board.middle_left   == x && board.bottom_left   == x ) { winner(x, board); }
    else if (board.top_middle  == x && board.middle_middle == x && board.bottom_middle == x ) { winner(x, board); }
    else if (board.top_right   == x && board.middle_right  == x && board.bottom_right  == x ) { winner(x, board); }
    else if (board.top_left    == x && board.middle_middle == x && board.bottom_right  == x ) { winner(x, board); }
    else if (board.top_right   == x && board.middle_middle == x && board.bottom_left   == x ) { winner(x, board); }

    return ' ';
}

int main()
{
    Board board;
    Board *board_pointer = &board;
    populate_board(board_pointer);

    system("clear");

    int itter = 1;
    int *itter_pointer = &itter;

    while (1) {
        calculate(board);
        display_board(board);
        if (itter == 10) { break; }
        
        int i = getchar();
        getchar();
        
        handle_input(i, itter_pointer, board_pointer);
        system("clear");
        itter++;
    }

    printf("Draw\n");
    
    return 0;
}
