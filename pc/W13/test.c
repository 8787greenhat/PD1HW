#include<stdio.h>

void SpiralMatrix(int n,  int *matrix){
	int num = 1;
	for(int i =0;i<n*n;i++)
    {
        *(matrix+i) = num++;
    }
}


int main(){
	int n;
	
	scanf("%d", &n);
	
	int matrix[n][n];

	for(int i = 0 ; i < n ; i++)
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