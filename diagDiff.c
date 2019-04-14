#include <stdio.h>
#include <stdlib.h>

/*
    It must return an integer representing
    the absolute diagonal difference.
    The first line contains a single integer, n , the number of rows and columns in the matrix . 
    Each of the next (n) lines describes a row,arr[i], and consists of (n) space-separated integers arr[i][j].

    Print the absolute difference between the sums of the matrix's two diagonals as a single integer.

    Sample input
    3
    11   2    4
    4    5    6
    10   8   -12

    Expected uutput
    15
*/
int diagonalDifference(int arr_rows,int arr_columns,int **arr){
    int mainDiag[arr_rows];
    int subDiag[arr_rows];

    //get primary diagonal
     for(int i = 0; i < arr_rows;i++){
        mainDiag[i] = arr[i][i];
    }

    int i = 0;
    int j = arr_rows-1;
    //get sub diagonal
    while(i<arr_rows){
        subDiag[i] = arr[i][j];
        i++;
        j--;
    }
    int primSum = 0;
    int subSum = 0;
    // sum praimary diagonal
    for(int i = 0; i < arr_rows; i++){
        primSum += mainDiag[i];
    }
    // sum secondrary diagonal
    for(int i = 0; i < arr_rows; i++){
       subSum += subDiag[i];
    }
    int diff = primSum - subSum;
    if(diff < 0){
        diff*=-1;
    }
    return diff;
}

int main(void){
    int x;
    scanf("%d",&x);
    // initialize array of pointers
    int** matrix =(int**) malloc(x*sizeof(int*));
    // populatearray
    for( int i = 0; i < x; i++ ){
        for( int k = 0; k < x; k++ ){
            int input;
            scanf("%d",&input);
            matrix[i][k] = input;
        }
    }
    // get absolute difference
    int result = diagonalDifference(x,x,matrix);
    // print difference
    printf("res = %d\n",result);

    return 1;
}