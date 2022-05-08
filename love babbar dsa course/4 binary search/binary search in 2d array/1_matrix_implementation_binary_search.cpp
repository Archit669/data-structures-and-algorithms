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

    bool binarySearch(int target){
        int start = 0;
        int end = row - 1;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (m[mid][0] <= target && m[mid][col-1]>=target){
                int low = 0;
                int high = col - 1;
                while (low <= high){
                    int mid2 = low + (high - low)/2;
                    if (m[mid][mid2] == target){
                        return 1;
                    }else if (m[mid][mid2] < target){
                        low = mid2 + 1;
                    }else{
                        high = mid2 - 1;
                    }
                }
                return 0;
            }else if (m[mid][0] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return 0;
    }

};
 
int main(){
    matrix m(3,3);
    m.input();
    m.print();
    cout << "result is:" << endl;
    cout << m.binarySearch(9) << endl;

    return 0;
}