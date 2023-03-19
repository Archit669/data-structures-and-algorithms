// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        int max = 0;
        char res;
        map<char,int> m;
        for (int i = 0 ; i < str.size() ; i++){
            m[str[i]]++;
        }
        
        for (auto i : m){
            if (max < i.second){
                max = i.second;
                res = i.first;
            }
        }
        
        return res;
    }

};

// { Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}  // } Driver Code Ends