#include <bits/stdc++.h>
using namespace std;

class matrix{
    public:
        int row;
        int col;
        int** m;

    matrix(int row , int col){
        this->row = row;
        this->col = col;
        m = new int*[row];
        for (int i = 0 ;  i < row ; i++){
            m[i] = new int[col];
        }
    }

    // methods
    void input(){
        cout << "enter elements of matrix: " << endl;
        for (int i = 0 ; i < row ; i++){
            for (int j = 0 ; j < col ; j++){
                cin >> m[i][j];
            }
        }
        return;
    }

    void print(){
        cout << "elements of matrix: " << endl;
        for (int i=0 ; i< row ; i++){
            for (int j = 0 ; j < col ; j++){
                cout << m[i][j] << " ";
            }cout << endl;
        }cout << endl;
    }

};
 
int main(){
    matrix m(3,3);
    m.input();
    m.print();
    return 0;
}