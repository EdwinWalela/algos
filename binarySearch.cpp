 #include <iostream>
using namespace std;
 
// Binary Search Recursively

// x  == 5
//  [ 1 , 2 , 3 , 4 , 5 ]
//  l(0)             R(4)
//           M 


int binarySearchRecursive(int arr[],int x,int left,int right){
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

int binarySearchIterative(int arr[],int x,int n){
     int left = 0;;
     int right = n-1;

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

void printArray(int arr[],int length){
    cout<<"array : [ ";
     for (int i = 0; i < length; i++){
         i != length-1 ? cout<<arr[i]<<" , " : cout<<arr[i]; 
        
     } 
     cout<<" ] "<<endl;
}

 int main(void){
     int arr[]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17}; int x,index;
     size_t arrLength = sizeof(arr) / sizeof(arr[0]);

     printArray(arr,arrLength);

     cout<<"\nEnter number to search for: ";
     cin>>x;
     index =  binarySearchIterative(arr,x,arrLength);
     if(index != -1){
        cout<<"\n"<<x<<" is at index : "<<index<<endl;
     }else{
        cout<<"\n"<<x<<" not found"<<endl;
     }
     return 1;
 }