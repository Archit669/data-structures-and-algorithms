#include <iostream>
using namespace std;


double sqrt(double x){
    double r = x;
    int tmp = -1;
    while (r*r > x){
        double temp = r;
        r = (r + x/r)/2;
        if (temp == r){
            break;
        }
    }
    return r;
}
 
int main(){
    double n;
    cout << "enter your number: ";
    cin >> n;
    int precision;
    cout << "enter precision: ";
    cin >> precision;

    double res = sqrt(n);
    cout.precision(precision+1);
    cout << "square root of " << n << ": ";
    cout << res << endl;
    return 0;
}