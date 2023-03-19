#include <iostream>
using namespace std;


double sqrt(double x){
    long double r = x;
    while (r*r > x){
        r = (r + x/r)/2;
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