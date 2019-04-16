#include <iostream>

using namespace std;

bool isPrime(int n){
    if(n == 0){
        return false;
    }
    for(int i = 2; i <= n/2; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
int linearSearch(int x,int arr[]){
    int loops = 0;
    for(int i = 0; i<38;i++){
        if(arr[i] == x){
            cout<<"loops: ("<<loops<<") , ";
            return i;
        }
        loops++;
    }
    cout<<"loops: ("<<loops<<") , ";
    return -1;
}
int binarySearch(int q,int arr[]){
    int left = 0;
    int right = 37;
    int loops = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] == q){
            cout<<"loops: ("<<loops<<") , ";
            return mid;
        } else if(q > arr[mid]){
            left = mid + 1;
        }else if( q < arr[mid]){
            right = mid - 1;
        }
        loops++;
    }
    cout<<"loops: ("<<loops<<") , ";
    return -1;
}

int main(void){
    
    int SIZE = 0;
    int LIMIT,val1,val2,val3;
    cout<<"\nEnter Limit: ";
    cin>>LIMIT;
    cout<<endl;

    // Count prime numbers
    for(int i = 0; i<= LIMIT;i++){
        if(isPrime(i)){
            SIZE++;
        }
    }
    // Create array using prime number count
    int primes[SIZE];
    int x = 0;
    // Insert prime numbers into array
    while(x<SIZE){
        for(int i = 0; i<=LIMIT;i++){
            if(isPrime(i)){
                primes[x] = i;
                x++;
            }
        } 
    }
    // Print prime numbers 
    cout<<"Prime Numbers\n"<<endl;
    for(int i =0;i<SIZE;i++){
        cout<<primes[i]<<",";
    }
    
    cout<<"\n\nEnter 3 values to search: ";
    cin>>val1>>val2>>val3;

    // Output
    cout<<"\n"<<endl;
    cout<<"Linear Search:\n\n";
    cout<<"element = "<<val1<<", index = "<<linearSearch(val1,primes)<<endl;
    cout<<"element = "<<val2<<", index = "<<linearSearch(val2,primes)<<endl;
    cout<<"element = "<<val3<<", index = "<<linearSearch(val3,primes)<<endl;
    cout<<"\nBinary Search:\n\n";
    cout<<"element = "<<val1<<", index = "<<binarySearch(val1,primes)<<endl;
    cout<<"element = "<<val2<<", index = "<<binarySearch(val2,primes)<<endl;
    cout<<"element = "<<val3<<", index = "<<binarySearch(val3,primes)<<endl;

    cout<<"\n------------------------------------------\n index -1 indicates element was not found\n------------------------------------------\n";
    return 1;
}