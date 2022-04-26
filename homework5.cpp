#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    int size = *max_element(arr.begin(), arr.end()) + 1;
    vector<int> values(size);
    values[0] = 0;
    values[1] = 1;
    values[2] = 2;
    for(int i = 3; i < size; ++i)
    {
        values[i] = values[i - 1] + (2 * values[i - 2]) - (3 * values[i - 3]);
    }
    vector<int> res(arr.size());
    for(int i = 0; i < arr.size(); ++i)
    {
        res[i] = values[arr[i]];
    }

    return res;
}

