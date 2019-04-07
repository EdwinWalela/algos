#include <stdio.h>

long aVeryBigSum(int ar_count, long* ar) {
    long long sum = 0;
    for(int i = 0; i < ar_count; i++){
        sum += ar[i];
    }
    return sum;
}

int main(void){
    long arr[] = {1000000001,1000000002,1000000003,1000000004};
    long long result = aVeryBigSum(4,arr);
    printf("%ld\n",result);
    return 1;
}