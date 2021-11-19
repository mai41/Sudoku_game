// Course:  CS213 - Programming II  - 2018
// Title:   Task 4 - Problem 2
// Purpose: This Code Solves a Sudoku Game if the solution does exist.
//          if not, shows that no solution is found...
// Author:  Mai Rady Hassan Mohamed   20170302
// Date:    18 Nov 2018
// Version: 3.0

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

#define Empty 0
#define N 9

bool isEmptyLocation(int grid[N][N], int &row, int &col);
bool isGridSafe(int grid[N][N], int row, int col, int num);


//Assigning values to all ZERO-VALUE for solution
bool SolveSudoku(int grid[N][N])
{
    int row, col;
    if (!isEmptyLocation(grid, row, col))
        return true;
    for (int num = 1; num <= N; num++)
    {
        if (isGridSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (SolveSudoku(grid))
                return true;
            grid[row][col] = Empty;
        }
    }
    return false;
}

// Checking if entries don't have a value
bool isEmptyLocation(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == Empty)
                return true;
    return false;
}

//Checking if the assigned entry in a particular row matches a given number
bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

//Checking if the assigned entry in a particular column matches a given number
bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

//Check if the entry is already used in the grid box
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}

//Checks if a number could be assigned to a given row-column location
bool isGridSafe(int grid[N][N], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row % 3, col - col % 3, num);
}

//Printing the result
void printGrid(int finalGrid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout<<finalGrid[row][col]<<"  ";
        cout<<endl;
    }
}


int main()
{
    int grid[N][N] = {{0, 0, 0, 0, 0, 0, 1, 0, 8},
        {0, 0, 0, 0, 0, 0, 9, 0, 0},
        {1, 9, 6, 2, 0, 0, 0, 7, 0},
        {0, 1, 3, 5, 4, 0, 0, 0, 0},
        {0, 5, 7, 8, 0, 0, 0, 0, 0},
        {0, 8, 4, 6, 7, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 6, 0, 0},
        {4, 2, 0, 7, 0, 3, 0, 1, 5},
        {5, 0, 0, 0, 0, 0, 7, 0, 4}
    };

    cout << "Sudoku game before applying the solution: " << endl;
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout<<grid[row][col]<<"  ";
        cout<<endl;
    }
    cout << endl << endl;

    cout << "Sudoku game after applying the solution: " << endl;
    if (SolveSudoku(grid) == true)
        printGrid(grid);

    else
        cout<<"No solution found..."<<endl;

    return 0;
}
