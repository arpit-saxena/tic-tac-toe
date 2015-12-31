#include <iostream>
#include <cmath>
#include "tic.h"

using namespace std;

int tic(int board[BOARD_SIZE][BOARD_SIZE],int id)
{
    //Checking if the move is first
    int coun = 0;
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] == 0)
            {
                coun++;
            }
        }
    }
    if(coun == 9)
    {
        return 0;
    }

    int cell;

    //Making
    cell = check_me(board,id);
    if(cell != 255)
    {
        int row, col;
        col = cell % 10;
        row = cell / 10;
        if(board[row][col] == 0)
        {
            return row * 10 + col;
        }
    }

    //Blocking
    cell = check_opp(board,id);
    if(cell != 255)
    {
        int row, col;
        col = cell % 10;
        row = cell / 10;
        if(board[row][col] == 0)
        {
            return row * 10 + col;
        }
    }

    //Playing the first move if id == 2
    if(id == 2 && coun == 8 && board[1][1] != 1)
    {
        return 11;
    }
    else if(id == 2 && board[0][0] == 0)
    {
        return 0;
    }

    //Tackling other players double moves
    if(coun == 6)
    {
        if(board[2][0] == 0)
            return 20;
        else if(board[0][2] == 0)
            return 2;
        else if(board[2][2] == 0)
            return 22;
    }

    //Playing the move if id == 1
    if(coun == 7)
    {
        if(board[0][1] == 0 && board[0][2] == 0)
        {
            return 2;
        }
        else if(board[1][0] == 0 && board[2][0] == 0)
        {
            return 20;
        }
        else if(board[1][1] == 0 && board[2][2] == 0)
        {
            return 22;
        }
    }
    else if(coun == 5)
    {
        if(board[0][2] == 1)
        {
            if(board[2][0] == 0 && board[1][0] == 0)
                return 20;
            else if(board[1][2] == 0 && board[2][2] == 0)
                return 22;
        }
        else if(board[2][0] == 1)
        {
            if(board[2][2] == 0 && board[2][1] == 0)
                return 22;
            else if(board[0][2] == 0 && board[1][1] == 0)
                return 2;
        }
        else if(board[2][2] == 1)
        {
            if(board[0][2] == 0 && board[1][2] == 0)
                return 2;
            else if(board[2][1] == 0 && board[2][0] == 0)
                return 20;
        }

    }

    //If any other scenario is there with 2 other empty spaces
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            int other = other_scenario(board,i,j);
            if(board[i][j] == 0 && (other == 2 || other == 1))
            {
                return i*10 + j;
            }
        }
    }

    //Other scenario
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] == 0)
            {
                return i * 10 + j;
            }
        }
    }

    return 33;
}

int check_me(int board[BOARD_SIZE][BOARD_SIZE], int id)
{
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        int sum_columns = 0, sum_rows = 0;
        int first_diagonal = board[0][0] + board[1][1] + board[2][2];
        int second_diagonal = board[0][2] + board[1][1] + board[2][0];
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            sum_rows += board[i][j];
            sum_columns += board[j][i];
        }

        // Checking if I can win

        //Checking Rows
        if(sum_rows / id == 2 && sum_rows % id == 0 && check_row(board,i))
        {
            int ret = 3, k = 0;

            while(ret == 3)
            {
                if(board[i][k] == 0)
                {
                    ret = k;
                }
                k++;
            }
            if (ret < 3)
                return i * 10 + ret;
        }

        // Checking Columns
        else if(sum_columns / id == 2 && sum_columns % id == 0 && check_column(board,i))
        {
            int ret = 3, k = 0;

            while(ret == 3)
            {
                if(board[k][i] == 0)
                {
                    ret = k;
                }
                k++;
            }
            if (ret < 3)
                return ret * 10 + i;
        }

        //Checking Diagonals
        else if(first_diagonal / id == 2 && first_diagonal % id == 0 && check_diagonal(board,1))
        {
            if(board[0][0] == 0)
            {
                return 0;
            }
            else if(board[1][1] == 0)
            {
                return 11;
            }
            else if(board[2][2] == 0)
            {
                return 22;
            }
        }

        else if(second_diagonal / id == 2 && second_diagonal % id == 0 && check_diagonal(board,2))
        {
            if(board[0][2] == 0)
            {
                return 2;
            }
            else if(board[1][1] == 0)
            {
                return 11;
            }
            else if(board[2][0] == 0)
            {
                return 20;
            }
        }
    }
    return 255;
}

int check_opp(int board[BOARD_SIZE][BOARD_SIZE], int id)
{
    int opp_id;

    if(id == 1)
        opp_id = 2;
    else
        opp_id = 1;

    for(int i = 0; i < BOARD_SIZE; i++)
    {
        int sum_columns = 0, sum_rows = 0;
        int first_diagonal = board[0][0] + board[1][1] + board[2][2];
        int second_diagonal = board[0][2] + board[1][1] + board[2][0];
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            sum_rows += board[i][j];
            sum_columns += board[j][i];
        }

        //Blocking the opponent

        //Checking Rows
        if(sum_rows / opp_id == 2 && sum_rows % opp_id == 0 && check_row(board,i))
        {
            int ret = 3, k = 0;

            while(ret == 3)
            {
                if(board[i][k] == 0)
                {
                    ret = k;
                }
                k++;
            }
            if (ret < 3)
                return i * 10 + ret;
        }

        // Checking Columns
        else if(sum_columns / opp_id == 2 && sum_columns % opp_id == 0 && check_column(board,i))
        {
            int ret = 3, k = 0;

            while(ret == 3)
            {
                if(board[k][i] == 0)
                {
                    ret = k;
                }
                k++;
            }
            if (ret < 3)
                return ret * 10 + i;
        }

        //Checking Diagonals
        else if(first_diagonal / opp_id == 2 && first_diagonal % opp_id == 0 && check_diagonal(board,1))
        {
            if(board[0][0] == 0)
            {
                return 0;
            }
            else if(board[1][1] == 0)
            {
                return 11;
            }
            else if(board[2][2] == 0)
            {
                return 22;
            }
        }

        else if(second_diagonal / opp_id == 2 && second_diagonal % opp_id == 0 && check_diagonal(board,2))
        {
            if(board[0][2] == 0)
            {
                return 2;
            }
            else if(board[1][1] == 0)
            {
                return 11;
            }
            else if(board[2][0] == 0)
            {
                return 20;
            }
        }
    }
    return 255;
}

bool check_row(int board[BOARD_SIZE][BOARD_SIZE], int row)
{
    int sum = 0;
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        if(board[row][i] == 0)
        {
            sum += 1;
        }
    }
    if(sum == 1)
    {
        return true;
    }

    return false;
}

bool check_column(int board[BOARD_SIZE][BOARD_SIZE], int column)
{
    int sum = 0;
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        if(board[i][column] == 0)
        {
            sum += 1;
        }
    }
    if(sum == 1)
    {
        return true;
    }
    return false;
}

bool check_diagonal(int board[BOARD_SIZE][BOARD_SIZE], int n)
{
    int sum = 0;
    if(n == 1)
    {
        for(int i = 0; i < BOARD_SIZE; i++)
        {
            if(board[i][i] == 0)
                sum += 1;
        }

        if(sum == 1)
        {
            return true;
        }
    }
    else if(n == 2)
    {
        for(int i = 0; i < BOARD_SIZE; i++)
        {
            if(board[i][2-i] == 0)
                sum += 1;
        }

        if(sum == 1)
        {
            return true;
        }
    }
    return false;
}

int other_scenario(int board[BOARD_SIZE][BOARD_SIZE], int i, int j)
{
    int check_row = 0, check_column = 0;
    for(int k = 0; k < BOARD_SIZE; k++)
    {
        if(board[i][k] == 0)
        {
            check_row++;
        }
    }
    for(int k = 0; k < BOARD_SIZE; k++)
    {
        if(board[k][j] == 0)
        {
            check_column++;
        }
    }
    if(check_row > 1)
    {
        return 2;
    }
    else if(check_row > 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
