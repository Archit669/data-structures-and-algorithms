#include <iostream>
using namespace std;

void printSpaceString(string input, int index , string output){
    if (index == input.length()){
        cout << output << endl;
        return;
    }

    //exclude space
    output.push_back(input[index]);
    printSpaceString(input,index+1, output);

    //include space
    output.push_back(' ');
    if (input[index+1] != '\0')
        printSpaceString(input,index+1,output);

}
 
int main(){
    string str;
    cin >> str;

    printSpaceString(str,0,"");
    return 0;
}