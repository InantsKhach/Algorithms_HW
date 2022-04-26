#include <iostream>
#include <vector>

int solve(std::vector<int>& arr, int value)
{
    int sum = 0;
    int l = 0;
    int r = arr.size() - 1;
    while(l <= r)
    {
        int m = l +  ( (r - l) / 2);
        if(arr[m] > value)
        {
            r = m - 1;
        }
        else if(arr[m] <= value)
        {
            l = m + 1; 
        }
    }
    sum = l;
    return sum;
}
