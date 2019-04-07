#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int diagDiff(vector<vector<int>> arr){
    int length = arr.size();
    for(int i = 0; i < length;i++){
        for(int k = 0; k < length; k++){
            cout<<arr[i][k];
        }
    }
}

int main(void){
    int n;
    cin>>n;

   vector<vector<int>> arr(n);
   for(int i = 0 ; i < n; i++){
       arr[i].resize(n);
       for(int j = 0; j < n; j++){
           cin>>arr[i][j];
       }
   }

    diagDiff(arr);
    return 1;
}