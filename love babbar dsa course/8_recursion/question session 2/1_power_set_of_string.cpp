#include <iostream>
using namespace std;

void powerSet(string input,int index , string output){
    if (index == input.length()){
        cout << output << endl;
        return;
    }
    char ch = input[index];
    //excude ch
    powerSet(input,index+1,output);
    // include ch
    output.push_back(ch);
    powerSet(input,index+1,output);
}
 
int main(){
    string str;
    getline(cin,str);

    string output = "";
    powerSet(str,0,output);
    return 0;
}