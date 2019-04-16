#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool exists(int arr[],int x,int size){;
    bool is = false;
    for(int i = 0; i < size; i++){
        if(x == arr[i]){
            is = true;
        }
    }
    return is;
}

vector<int> sortArr(int arr[],int size){
    vector<int> x;
    for(int i = 0; i < size;i++){
        x.push_back(arr[i]);
    }
    sort(x.begin(),x.end());
    x.pop_back();
    return x;
}

int main(void){
    int A[5]; 
    int B[4];
    int U[7];
    // sort(A[0],A[4]);
    // sort(B[0],B[3]);
    cout<<"populate set A: ";
    for(int i = 0; i < 5;i++){
        cin>>A[i];
    }
    cout<<"populate set B: ";
    for(int i = 0; i < 4;i++){
        cin>>B[i];
    }
    // poplate union with elemnts in A
    for(int i = 0; i < 5; i++){
        U[i] = A[i];
    }
    // Loop through B
    int d = 5;
    for(int j = 0; j < 4; j++){
        // Loop through Union
        if(!exists(U,B[j],4)){
            U[d] = B[j];
            d++;
        }
    }
    
   vector<int> result = sortArr(U,8);
   cout<<"\nresult: ";
   for(int i = 0; i < result.size(); i++){
       cout<<result[i]<<","<<endl;
   }

    return 1;
}