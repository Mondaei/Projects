#include <stdio.h>

#define MAX_10 10

typedef char grid10[MAX_10][MAX_10];

void display2DArrayContents(grid10 g,int nRow,int nCol)
{
	int i, j;
	
	for (i = 0;i < nRow;i++)
	{
		for (j = 0;j < nCol;j++)
			printf ("%c",g[i][j]);
		printf ("\n");
	}
}

int intToChar(int n)
{
	if (n >= 0 && n <= 9)
		return n + '0';
	else
		return -1;
}

int inRange(int min,int max,int val)
{
	return val >= min && val <= max;
}

void mineSwept(grid10 g,int nRow,int nCol)
{
	int i, j;
	
	// Complete the code
}

int main()
{
	grid10 g = {{'.','.','*','.','.','.','*','.','.','.'},
			    {'*','*','.','.','.','.','.','*','.','.'},
			    {'.','*','.','*','.','*','.','.','.','*'},
			    {'.','*','*','*','.','.','*','*','*','.'},
			    {'*','.','.','.','*','.','.','.','.','.'},
			    {'.','.','*','.','.','.','.','*','.','.'},
			    {'.','*','.','*','*','.','*','.','*','.'},
			    {'*','.','.','.','.','*','.','.','.','*'},
			    {'.','*','*','*','.','*','*','.','.','.'},
			    {'.','*','.','*','.','*','.','*','.','*'}};
			  
	int nRow = 10;
	int nCol = 10;
	
	printf ("Before: \n");
	display2DArrayContents(g,nRow,nCol);
	
	mineSwept(g,nRow,nCol);
	
	printf ("\n");
	printf ("After: \n");
	
	display2DArrayContents(g,nRow,nCol);
	
	return 0;
}
