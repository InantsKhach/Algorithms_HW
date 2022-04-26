#include <iostream>
#include <string>
#include <vector>
#include <cmath>


int count_of_str = 0;

void Solve(int start_index, int count, std::string& s, std::vector<std::size_t>& indeces)
{
    if(indeces.size() == count)
    {
        std::cout << s << std::endl;
        ++count_of_str;
        if(count_of_str == pow(2, indeces.size()))
          exit(0);
        return;
    }

        s[indeces[start_index]] = '0';
        ++count;
        Solve(start_index + 1, count, s, indeces);
        s[indeces[start_index]] = '1';
        Solve(start_index + 1, count, s,  indeces);
    
}

int main()
{
    std::string s;
    std::cin >> s;
    std::vector<std::size_t> indeces;
    int count = 0;
    for(std::size_t i = 0; i < s.size(); ++i)
    {
        if(s[i] == '?')
        {
         ++count;
         indeces.push_back(i);
        }
    }


    Solve(0, 0, s, indeces);
}