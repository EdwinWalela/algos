/*
    Performing Set Union Using Vectors

    example:
    
    setA = [ 3 , 5 , 1 , 3 ]
    setB = [ 7 , 1 , 2 , 4]

    Output = [ 1 , 2 , 3 , 4 , 5 , 7 ]
*/
#include <iostream>

using namespace std;

int MAX = 20;

void bubbleSort(int arr[],int size){
    for(int p = 0; p < size; p++){
        for(int i = 0; i < size - 1; i++){
            if(arr[i] > arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp; 
            }
        }
    }
}

bool exists(int value,int arr[],int size){
    for(int i = 0; i < size; i++){
        if(value == arr[i]){
            return true;
        }
    }
    return false;
}

int* shrinkArray(int arr[],int targetSize){
    int* res = new int[targetSize];
    for(int i = 0; i < targetSize; i++){
        res[i] = arr[i];
    }
    // mark end of array
    res[targetSize] = -999;
    // delete original array
    delete[] arr;
    // return pointer to new array
    return res;
}

int* setUnion(int setA[],int sizeA,int setB[],int sizeB){
    int* set_union = new int[MAX];
    int unionIndex = 0;
    // sort sets
    bubbleSort(setA,sizeA);
    bubbleSort(setB,sizeB);
    // perform union    
     for(int i = 0; i < sizeA; i++){
        if(!exists(setA[i],set_union,MAX)){
            set_union[unionIndex] = setA[i];
            unionIndex++;
        }
    }
    for(int i = 0; i < sizeB; i++){
        if(!exists(setB[i],set_union,MAX)){
            set_union[unionIndex] = setB[i];
            unionIndex++;
        }
    }
    // sort union
    bubbleSort(set_union,unionIndex);
    //shrink array ( get rid of empty indices )
    set_union = shrinkArray(set_union,unionIndex);
    // return pointer to setUnion
    return set_union;
}


int main(){

    int setA[] = {1,1,1,1,1,1,2};
    int setB[] = {3,3,3,4,4,5,5,6};

    size_t sizeA = sizeof(setA) / sizeof(setA[0]);
    size_t sizeB = sizeof(setB) / sizeof(setB[0]);

    int* setunion = setUnion(setA,sizeA,setB,sizeB);

    int i = 0;
    while(setunion[i] != -999){
        cout<<setunion[i]<<",";
        i++;
    }
    cout<<endl;
   
    return 1;
}