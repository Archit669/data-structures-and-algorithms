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

    void wavePrint(){
        cout << "wave print of matrix is: " << endl;
        for (int i = 0 ; i < row ; i++){
            if (i%2==0){
                for (int j = 0; j < col ; j++){
                    cout << m[i][j] << " ";
                }
            }else{
                for (int j = col-1 ; j >=0 ; j--){
                    cout << m[i][j] << " ";
                }
            }
        }cout << endl;
    }

};
 
int main(){
    matrix m(4,3);
    m.input();
    m.print();
    m.wavePrint();
    return 0;
}