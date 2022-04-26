#include <iostream>
#include <algorithm>
#include <vector>

bool flag = false;

void print(std::vector<int> v, std::vector<char> c, int s)
{
    for(int i = 0; i < c.size(); ++i)
    {
       std::cout << c[i] << v[i];
    }
    std::cout << '=' << s << '\n';
}

void solution(int start_index, int currSum, std::vector<char> currComb, std::vector<int> v, int sum)
{
    if(currComb.size() == v.size() && currSum == sum)
    {
        print(v, currComb, sum);
        flag  = true;
        return;
    }

    if(currComb.size() == v.size())
    {
        return;
    }

    currComb.push_back('+');
    solution(start_index + 1, currSum + v[start_index], currComb, v, sum);
    currComb.pop_back();
    currComb.push_back('-');
    solution(start_index + 1, currSum - v[start_index], currComb, v, sum);
}

int main()
{
    int n, s;
    std::cin >> n >> s;
    std::vector<int> v(n);
    for(auto& elem : v)
      std::cin >> elem;

    std::vector<char> dummy;
    solution(0, 0, dummy, v, s);
    if(!flag)
      std::cout << "No solution\n";
    
}