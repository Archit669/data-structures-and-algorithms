#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &persons, int k, int index = 0)
    {

        // base condition
        if (persons.size() == 1)
        {
            return persons[0];
        }

        // deleting (index+k) person from the persons
        // use modulus size of persons to keep index in array
        index = (index + k) % persons.size();

        // remove person at index
        persons.erase(persons.begin() + index);

        // recursive condition
        int ans = solve(persons, k, index);

        // return last person
        return ans;
    }

public:
    int findTheWinner(int n, int k)
    {

        // create a vector persons which will store all persons
        vector<int> persons(n);

        // insert persons in vector
        for (int i = 0; i < n; i++)
        {
            persons[i] = i + 1;
        }

        // calling recursive function
        int last_person = solve(persons, k - 1);

        // return last_person
        return last_person;
    }
};