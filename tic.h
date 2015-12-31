#ifndef TIC
#define TIC

#define BOARD_SIZE 3

int check_me(int board[BOARD_SIZE][BOARD_SIZE], int id);
int check_opp(int board[BOARD_SIZE][BOARD_SIZE], int id);
bool check_row(int board[BOARD_SIZE][BOARD_SIZE], int row);
bool check_column(int board[BOARD_SIZE][BOARD_SIZE], int column);
bool check_diagonal(int board[BOARD_SIZE][BOARD_SIZE], int n);
int other_scenario(int board[BOARD_SIZE][BOARD_SIZE], int i, int j);

int tic(int board[BOARD_SIZE][BOARD_SIZE], int id);

extern int man_id;
extern int bot_id;

#endif // TIC

