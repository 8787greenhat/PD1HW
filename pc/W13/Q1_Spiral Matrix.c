#include<stdio.h>

void SpiralMatrix(int n,  int (*matrix)[n]){

	int dircetion[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int d = 0;
    int x = 0, y = 0;

    for(int i = 1 ; i <= n*n ; i++)
    {
        matrix[x][y] = i;

        int x2 = x + dircetion[d][0];
        int y2 = y + dircetion[d][1];

        if(x2 < 0 || x2 >= n || y2 < 0 || y2 >= n || matrix[x2][y2] != -1)
        {
            d = (d + 1) % 4;

            x2 = x + dircetion[d][0];
            y2 = y + dircetion[d][1];
        }

        x = x2;
        y = y2;
    }
}


int main(){
	int n;
	
	scanf("%d", &n);
	
	int matrix[n][n];

	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j < n ; j++)
			matrix[i][j] = -1;
	
	SpiralMatrix(n, matrix);
    
	for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) 
                printf("%3d ", matrix[i][j]);
            printf("\n");
	}
    
	return 0;
}