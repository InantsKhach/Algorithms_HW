#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


long long solution(std::vector<int> v)
{
    std::vector<std::string> str_vec;
    for(int i = 0; i < v.size(); ++i)
    {
        str_vec.push_back(std::to_string(v[i]));
    }

    for(int i = 0; i < str_vec.size(); ++i)
    {
        std::sort(str_vec[i].begin(), str_vec[i].end());
    }
    std::sort(str_vec.begin(), str_vec.end());
    
    long long count_pairs = 0, j = 1;
    for(int i = 0; i < v.size(); ++i)
    {
        int count = 0;
        while(str_vec[i] == str_vec[i + 1])
        {
            ++count;
            ++i;
        }
        count_pairs += (count + 1) * count / 2;
    }
    return count_pairs;   
}



