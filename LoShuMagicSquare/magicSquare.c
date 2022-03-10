#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// TODO list of properties
// TODO The grid contains the numbers 1 through 9 exactly
// TODO The sum of each row, each column, and each diagonal all add up to the same number
int magicSquatTest(int magicSquare[3][3]) {
    int count = 0;
    int row[3] = {0,0,0};
    int col[3] = {0,0,0};
    int diagonal[2] = {0,0};
    int testResult = 0;

    //makes sure that array contains numbers 1 - 9
    //sets the row and col arrays
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            count += pow(10, magicSquare[i][j]-1);
            row[i] += magicSquare[i][j];
            col[i] += magicSquare[j][i];
        }
    }

    //sets the diagonal arrays
    diagonal[0] = magicSquare[0][0] + magicSquare[1][1] + magicSquare[2][2];
    diagonal[1] = magicSquare[0][2] + magicSquare[1][1] + magicSquare[2][0];

    if (row[0] == row[1] && row[0] == row[2]) {
        testResult += 1;
    } else {
        testResult = 0;
    }

    if (col[0] == col[1] && col[0] == col[2]) {
        testResult += 1;
    } else {
        testResult = 0;
    }

    if (diagonal[0] == diagonal[1]) {
        testResult += 1;
    } else {
        testResult = 0;
    }

    if (count != 111111111) {
        testResult = 0;
    } else {
        testResult += 1;
    }

    if (testResult == 4) {
        return 1;
    } else {
        return 0;
    }
}

//random number generation function
int rando(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

//
void randoSquare(int magicSquare[3][3]) {
    int numPool[9] = {1,2,3,4,5,6,7,8,9};
    int index = 0;
    for (int num = 0; num < 9; num++) {
        int temp = numPool[num];
        int rand = rando(0,8);
        numPool[num] = numPool[rand];
        numPool[rand] = temp;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            magicSquare[i][j] = numPool[index];
            index++;
        }
    }
}

//testing
int main () {
    char *result;
    int magicSquare[3][3] = {{4,9,2},{3,5,7},{8,1,6}};
    printf("testing confirmed magic square...\n");
    for (int i = 0; i < 3; i++) {
        printf("[ ");
        for (int j = 0; j < 3; j++) {
            printf("%d ", magicSquare[i][j]);
        }
        printf("]\n");
    }
    if (magicSquatTest(magicSquare)) {
        result = "TRUE";
    } else {
        result = "FALSE";
    }
    printf("test results: %s\n\n", result);

    int count = 0;
    int test = 0;
    srand(time(0));
    printf("testing randomly generated squares...\n");
    while (test == 0) {
        randoSquare(magicSquare);
        test = magicSquatTest(magicSquare);
        count++;
    }
    printf("Success after %d random squares!\n", count);
    for (int i = 0; i < 3; i++) {
        printf("[ ");
        for (int j = 0; j < 3; j++) {
            printf("%d ", magicSquare[i][j]);
        }
        printf("]\n");
    }


    return 0;
}