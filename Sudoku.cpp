
#include<iostream>
using namespace std;
bool finding_empty_space(char puzzle[9][9], int& row, int& col) {

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (puzzle[i][j] == '.')
            {
                row = i, col = j;
                return true;
            }
        }
    }
    return false;
}
bool puzzle_solve(char(&puzzle)[9][9])
{

    int row = 0;
    int col = 0;
    if (finding_empty_space(puzzle, row, col))
    {
        bool check = false;
        for (int i = 1; i <= 9; i++)
        {
            bool c1 = true;
            bool c2 = true;
            bool c3 = true;
            char number = '0' + i;

            for (int i = 0; i < 9; i++)
            {
                if (puzzle[row][i] == number)
                {
                    c1 = false;
                }
            }
            for (int i = 0; i < 9; i++) 
            {
                if (puzzle[i][col] == number)
                {
                    c2 = false;
                }
            }
            int starting_r = (row / 3) * 3;
            int starting_c = (col / 3) * 3;
            for (int i = starting_r; i < starting_r + 3; i++)
            {
                for (int j = starting_c; j < starting_c + 3; j++) 
                {
                    if (puzzle[i][j] == number)
                    {
                        c3 = false;
                    }
                }
            }
            if (c1 && c2 && c3)
            {
                check = true;
                puzzle[row][col] = number;
                if (puzzle_solve(puzzle))
                {
                    return true;
                }
            }
            puzzle[row][col] = '.';
        }
        if (check == false)
        {
            return false;
        }
    }
    else
    {
        return true;
    }
    return false;
}
int main()
{
    char board[9][9] = { {'5','3','.','.','7','.','.','.','.'},
                     {'6','.','.','1','9','5','.','.','.'},
                     {'.','9','8','.','.','.','.','6','.'},
                     {'8','.','.','.','6','.','.','.','3'},
                     {'4','.','.','8','.','3','.','.','1'},
                     {'7','.','.','.','2','.','.','.','6'},
                     {'.','6','.','.','.','.','2','8','.'},
                     {'.','.','.','4','1','9','.','.','5'},
                     {'.','.','.','.','8','.','.','7','9'} };



    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    puzzle_solve(board);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


}