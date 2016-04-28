#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 6
bool right(int maze[N][N],int r,int c,int sol[N][N]);
bool left(int maze[N][N],int r,int c,int sol[N][N]);
bool up(int maze[N][N],int r,int c,int sol[N][N]);
bool down(int maze[N][N],int r,int c,int sol[N][N]);
bool isSafe(int maze[N][N],int r,int c,int sol[N][N]);
bool findSol(int maze[N][N],int r,int c,int sol[N][N]);

void printSol(int sol[N][N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d ",sol[i][j]);
        printf("\n");
    }
}

int main()
{
    int sol[N][N] = { {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0}
                    };

    int maze[N][N]  = { {1, 1, 1, 1, 1, 1},
                        {1, 0, 0, 0, 0, 1},
                        {1, 0, 0, 0, 0, 1},
                        {1, 0, 0, 0, 0, 1},
                        {1, 0, 0, 0, 0, 1},
                        {1, 1, 1, 1, 1, 1}
                      };

    if(!isSafe(maze,0,0,sol))
    {
        printf("\nSolution does not exist!!");
        getchar();
        exit(0);
    }
    sol[0][0]=1;

    if(maze[1][0]==1)
        down(maze,1,0,sol);
    else
        right(maze,0,1,sol);


    if(sol[N-1][N-1]==1)
    printSol(sol);
    else
        printf("\nSolution does not exist!!");
    getchar();
    return 0;
}

bool isSafe(int maze[N][N],int r,int c,int sol[N][N])
{
    if(r>=0 && r<N && c>=0 && c<N && maze[r][c]==1 &&sol[r][c]!=1)
        return true;
    return false;
}

bool right(int maze[N][N],int r,int c,int sol[N][N])
{
    if(r == N-1 && c == N-1 && maze[N-1][N-1]==1)
    {
        sol[r][c] = 1;
        return true;
    }

    if(isSafe(maze,r,c,sol)==true)
    {
        sol[r][c]=1;

        if(down(maze,r+1,c,sol)==true)return true;
        if(right(maze,r,c+1,sol)==true)return true;
        if(up(maze,r-1,c,sol)==true)return true;

        sol[r][c]=0;
        return false;
    }
    return false;
}

bool left(int maze[N][N],int r,int c,int sol[N][N])
{
    if(r == N-1 && c == N-1 && maze[N-1][N-1]==1)
    {
        sol[r][c] = 1;
        return true;
    }

    if(isSafe(maze,r,c,sol)==true)
    {
        sol[r][c]=1;

        if(down(maze,r+1,c,sol)==true)return true;
        if(up(maze,r-1,c,sol)==true)return true;
        if(left(maze,r,c-1,sol)==true)return true;

        sol[r][c]=0;
        return false;
    }
    return false;
}
bool up(int maze[N][N],int r,int c,int sol[N][N])
{
    if(r == N-1 && c == N-1 && maze[N-1][N-1]==1)
    {
        sol[r][c] = 1;
        return true;
    }

    if(isSafe(maze,r,c,sol)==true)
    {
        sol[r][c]=1;

        if(right(maze,r,c+1,sol)==true)return true;
        if(up(maze,r-1,c,sol)==true)return true;
        if(left(maze,r,c-1,sol)==true)return true;

        sol[r][c]=0;
        return false;
    }
    return false;
}

bool down(int maze[N][N],int r,int c,int sol[N][N])
{
    if(r == N-1 && c == N-1 && maze[N-1][N-1]==1)
    {
        sol[r][c] = 1;
        return true;
    }

    if(isSafe(maze,r,c,sol)==true)
    {
        sol[r][c]=1;

        if(down(maze,r+1,c,sol)==true)return true;
        if(right(maze,r,c+1,sol)==true)return true;
        if(left(maze,r,c-1,sol)==true)return true;

        sol[r][c]=0;
        return false;
    }
    return false;
}
