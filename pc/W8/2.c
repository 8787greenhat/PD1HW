#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int totalRolls = 20000; // you could modify the totalRolls
double expectedValue = 0;
int sum;
int r;
// Using rand() to generate a random number between 1 and 6.
int rollDice() {
    
    r = (rand()%6) + 1;
}

int main() {
    srand((unsigned)time(NULL));
    for(int i =0;i<=totalRolls;i++){
        rollDice();
        sum = sum + r;
    }
    expectedValue = (double)sum/totalRolls;
    printf("The Expected Value is %lf\n", expectedValue);

    return 0;
}