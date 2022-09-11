#include <bits/stdc++.h>
using namespace std;

// create function that will print all subsets
void printSubsets(int *arr, int length)
{
    // no of subsets
    int subsetCount = pow(2, length);

    // print all the subsets
    for (int subsetNumber = 0; subsetNumber < subsetCount; subsetNumber++)
    {
        for (int kthBit = length - 1; kthBit >= 0; kthBit--)
        {
            if ((1 << kthBit) & subsetNumber)
            {
                cout << arr[length - kthBit - 1] << "\t";
            }
            else
            {
                cout << "-\t";
            }
        }
        cout << endl;
    }
}

int main()
{
    // take size of array
    int size;
    
    cin >> size;

    // create an array
    int *arr = new int[size];

    // take input of array
    for (int idx = 0; idx < size; idx++)
    {
        cin >> arr[idx];
    }

    // print all the subsets
    printSubsets(arr, size);

    return 0;
}