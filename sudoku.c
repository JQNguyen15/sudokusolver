#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int grid[9][9]={{7,0,4,0,3,8,2,0,0},
                {8,6,0,7,0,0,0,0,9},
                {0,3,0,0,2,1,0,8,0},
                {0,4,8,2,0,0,6,0,0},
                {0,0,5,0,0,0,9,0,0},
                {0,0,3,0,0,7,5,1,0},
                {0,5,0,8,6,0,0,2,0},
                {4,0,0,0,0,3,0,9,6},
                {0,0,6,1,9,0,7,0,4}};

void print()
{
    int i,j;
    int numlines=0,numrows=0;
    for (i=0;i<9;i++)
    {
        for (j=0;j<9;j++)
        {
            printf("%d  ",grid[i][j]);
            numrows++;
            if (numrows%3==0)
                printf("  ");
        }
        printf("\n");
        numlines++;
        if (numlines%3==0)
            printf("\n");
    }
}

bool checkrow(int row,int n)
{
    int i;
    for (i=0;i<9;i++)
    {
        if (grid[row][i]==n)
            return false;
    }
    return true;
}

bool checkcol(int col,int n)
{
    int i;
    for (i=0;i<9;i++)
    {
        if (grid[i][col]==n)
            return false;
    }
    return true;
}

bool checkbox(int row,int col,int n)
{
    int i,j;
    if (row<3 && col<3) // top left box
    {
        for (i=0;i<3;i++)
        {
            for (j=0;j<3;j++)
            {
                if (grid[i][j]==n)
                    return false;
            }
        }
    }
    if (row<3 && col>2 && col<6) // mid left box
    {
        for (i=0;i<3;i++)
        {
            for (j=3;j<6;j++)
            {
                if (grid[i][j]==n)
                    return false;
            }
        }
    }
    if (row<3 && col>5) // top left box
    {
        for (i=0;i<3;i++)
        {
            for (j=6;j<9;j++)
            {
                if (grid[i][j]==n)
                    return false;
            }
        }
    }

    if (row>2 && row<6) // checks middle rows
    {
        if (col<3)
        {
            for (i=3;i<6;i++)
            {
                for (j=0;j<3;j++)
                {
                    if (grid[i][j]==n)
                        return false;
                }
            }
        }
        if (col>2 && col<6)
        {
            for (i=3;i<6;i++)
            {
                for (j=3;j<6;j++)
                {
                    if (grid[i][j]==n)
                        return false;
                }
            }
        }
        if (col>5)
        {
            for (i=3;i<6;i++)
            {
                for (j=6;j<9;j++)
                {
                    if (grid[i][j]==n)
                        return false;
                }
            }
        }
    }

    if (row>5) // checks bottom rows
    {
        if (col<3)
        {
            for (i=6;i<9;i++)
            {
                for (j=0;j<3;j++)
                {
                    if (grid[i][j]==n)
                        return false;
                }
            }
        }
        if (col>2 && col<6)
        {
            for (i=6;i<9;i++)
            {
                for (j=3;j<6;j++)
                {
                    if (grid[i][j]==n)
                        return false;
                }
            }
        }
        if (col>5)
        {
            for (i=6;i<9;i++)
            {
                for (j=6;j<9;j++)
                {
                    if (grid[i][j]==n)
                        return false;
                }
            }
        }
    }

    return true;
}

bool checkunassign()
{
    int r,c;
    for (r=0;r<9;r++)
    {
        for (c=0;c<9;c++)
        {
            if (grid[r][c]==0)
            {
                return true;
            }
        }
    }
    return false;
}

int findrow()
{
    int r,c;
    for (r=0;r<9;r++)
    {
        for (c=0;c<9;c++)
        {
            if (grid[r][c]==0)
            {
                return r;
            }
        }
    }
}

int findcol()
{
    int r,c;
    for (r=0;r<9;r++)
    {
        for (c=0;c<9;c++)
        {
            if (grid[r][c]==0)
            {
                return c;
            }
        }
    }
}

bool issafe(int r,int c,int n)
{
    if ((checkrow(r,n)) && (checkcol(c,n)) && (checkbox(r,c,n)))
        return true;
    else
        return false;
}
/*
first checks if there are 0s in the grid
if there are 0s then it finds the first 0 available
for loop starts from 1, goes till 9 and attempts to place it in the grid position
calls itself again until grid is filled.
if a value cannot be placed in a spot it returns false
this triggers backtracking and will revert the number before that to 0
and the program will attempt to put in another number into that previous number
*/
bool solve()
{
    int num,row,col;
    if (checkunassign()==false) // checks if there are 0s in the grid
        return true;
    row=findrow(); // first row value that has a 0
    col=findcol(); // first col value that has a 0
    for (num=1;num<10;num++)
    {
        if (issafe(row,col,num))//checks if num will fit in that position
        {
            grid[row][col]=num; // tentatively assigns num to grid position
            if (solve())
                return true;
            grid[row][col]=0; // if that value doesnt work, revert back to 0
        }
    }
    return false; // backtracking
}

int main()
{
    if (solve())
        print();
    return 0;
}
