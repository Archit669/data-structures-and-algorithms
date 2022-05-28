#include <iostream>
using namespace std;

void binarySequences(int leftsum, int rightsum , char* output , int i , int j){
    // base case
    if (i > j){
        if (leftsum == rightsum)
            cout << output << endl;
        return;
    }

    // put 0,0
    output[i]= '0';
    output[j] = '0';
    binarySequences(leftsum,rightsum,output,i+1,j-1);

    // put 0, 1
    output[i]= '0';
    output[j] = '1';
     binarySequences(leftsum,rightsum+1,output,i+1,j-1);

    // put 1, 0
    output[i]= '1';
    output[j] = '0';
     binarySequences(leftsum+1,rightsum,output,i+1,j-1);

    // put 1,1
    output[i]= '1';
    output[j] = '1';
     binarySequences(leftsum+1,rightsum+1,output,i+1,j-1);
}
 
int main(){
    int n;
    cin >> n;

    char output[2*n];

    binarySequences(0,0,output,0,2*n-1);

    return 0;
}