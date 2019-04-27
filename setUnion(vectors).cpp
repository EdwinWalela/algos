/*
    Performing Set Union Using Vectors

    example:
    
    setA = [ 3 , 5 , 1 , 3 ]
    setB = [ 7 , 1 , 2 , 4]

    Output = [ 1 , 2 , 3 , 4 , 5 , 7 ]
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool exists(int value,vector<int> arr,int size){
    for(int i = 0; i < size; i++){
        if(value == arr[i]){
            return true;
        }
    }
    return false;
}

vector<int> setUnion(vector<int> setA,vector<int> setB){
    vector<int> setUnion;
    // sort vectors
    sort(setA.begin(),setA.end());
    sort(setB.begin(),setB.end());

    // perform union    
     for(int i = 0; i < setA.size(); i++){
        if(!exists(setA[i],setUnion,setUnion.size())){
            setUnion.push_back(setA[i]);
        }
    }

    for(int i = 0; i < setB.size(); i++){
        if(!exists(setB[i],setUnion,setUnion.size())){
            setUnion.push_back(setB[i]);
        }
    }
    // sort union
    sort(setUnion.begin(),setUnion.end());
    // return resulting set union
    return setUnion;
}

void printUnion(vector<int> setUnion){
    cout<<"\nSet Union : [ ";

    for(int i = 0; i < setUnion.size(); i++){
        cout<<setUnion[i]<<" ";
    }

     cout<<"]"<<endl;
}

void printVector(vector<int> vector){
    cout<<"[ ";
    for(int i = 0; i < vector.size(); i++){
        cout<<vector[i]<<" ";
    }
    cout<<"]"<<endl;

}

int main(){

    vector<int> setA {1,1,1,1,1,1,2};
    vector<int> setB {3,3,3,4,4,5,5,6};

    cout<<"Set A: ";
    printVector(setA);
    cout<<"Set B: ";
    printVector(setB);

    vector<int> set_union = setUnion(setA,setB);

    printUnion(set_union);
   
    return 1;
}