 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include <string>

using namespace std;
 
// Binary Search Recursively

// x  == 5
//  [ 1 , 2 , 3 , 4 , 5 ]
//  l(0)             R(4)
//           M 


int binarySearchRecursive(vector<int> arr,int x,int left,int right){
     if(left>right){
         return -1;
     }
    int mid = (left + right ) / 2;
    if(arr[mid]==x){
        return mid;
    }else if(x < arr[mid]){
        binarySearchRecursive(arr,x,left,mid-1);
    }else if(x > arr[mid]){
        binarySearchRecursive(arr,x,mid+1,right);
    }
}

int binarySearchIterative(vector<int>arr,int x){
     int left = 0;;
     int right = arr.size() - 1;

    while(left <= right){
        int mid = (left + right ) / 2;
        if(arr[mid]==x){
            return mid;
        }else if(x < arr[mid]){
            right = mid -1;
        }else if(x > arr[mid]){
            left = mid +1;
        }
    }
    return -1;
}

void printArray(vector<int> arr){
    cout<<"array : [ ";
     for (int i = 0; i < arr.size(); i++){
         i != arr.size()-1 ? cout<<arr[i]<<" , " : cout<<arr[i]; 
     } 
     cout<<" ] "<<endl;
      cin.ignore(255,'\n');
}

vector<int> populateArray(){
    cout<<"Enter elements (Ctrl + Z to signal end of input) : \n";
    vector<int> arr;
    while(!cin.eof()){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    arr.pop_back();
    return arr;
}

 int main(void){
     int x = 7;int index;
     vector<int>arr = populateArray();
     sort(arr.begin(),arr.end());
     printArray(arr);

     index = binarySearchIterative(arr,x);

     if(index != -1){
         cout<<"Element ("<<x<<")"<<" found at index : [ "<<index<<" ]"<<endl;
     }else{
         cout<<"Element ("<<x<<")"<<" not found"<<endl;
     }
     return 1;
 }