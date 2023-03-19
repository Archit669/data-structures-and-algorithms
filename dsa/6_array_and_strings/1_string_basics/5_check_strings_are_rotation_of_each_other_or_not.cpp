// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int checkrotation(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        if (checkrotation(a,b) == -1){
            cout << "strings are not rotation of each other\n" << endl;
        }else{
            cout << "strings are rotation of each other\n" << endl;
        }
    }
}
// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int checkrotation(string s, string x)
{
    if (s.length() != x.length()){
        return -1;
    }
     s+= x;
     if (s.find(x) == string::npos)
         return -1;  
         return s.find(x);
}