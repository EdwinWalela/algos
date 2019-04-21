// Run Length Encoding  (String compression Algorithim)
/*
    Example:
        Input  : aaabbbcccc
        Output : a3b4c4

*/

#include <iostream>
#include <string>

using namespace std;

string compressor(string input){
    string output;
    for(int i = 0; i < input.length(); i++){
        int counter = 1;
        int k = i;
        // compare adjacent charachters
        while(input[i] == input[k + 1]){
            counter++;
            k++;
        }
        // append charachter count to output string
        if(counter == 1){
            output = output + input[i];
        }else{
            output = output + input[i] + to_string(counter);
        }
      // skip the counted repeated charachters
      i += counter- 1;
    }
    return output;
}

int main(void){
    string input;
    cout<<"\nEnter string to compress : ";
    // input string
    getline(cin,input);

    // compress string
    string output = compressor(input);
    // calculate compression percentage
    float percent;
    float inital = input.length();
    float result = output.length();
    percent = (result / inital) * 100;
    percent = 100 - percent;
    // output
    cout<<"Compressed string : ";
    cout<<output<<endl;
    cout<<"Initial length : "<<inital<<endl;
    cout<<"Final length : "<<result<<endl;
    cout<<"Compression : "<< percent<<"%"<<endl;

    return 1;
}