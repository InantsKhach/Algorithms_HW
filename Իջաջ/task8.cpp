#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

bool check = false;
std::set< std::vector<int> > s;

void print(const std::vector<int>& v)
{
    std::cout << '(' << v[0];
    for(int i = 1; i < v.size(); ++i)
       std::cout << ' ' << v[i];
    std::cout << ')';
    check = true;
}

void checkSum(int sum, int currSum, int start_index, std::vector<int>& v, std::vector<int>& currComb)
{
    if(currSum == sum)
    {
        s.insert(currComb);
        return;
    }

    if(currSum > sum)
      return;

    for(int i = start_index; i < v.size(); ++i)
    {
        currComb.push_back(v[i]);
        checkSum(sum, currSum + v[i], i, v, currComb);
        currComb.pop_back();
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(auto& elem : v)
      std::cin >> elem;

    int sum;
    std::cin >> sum;

    std::sort(v.begin(), v.end());
    std::vector<int> dummy;
    checkSum(sum, 0, 0, v, dummy);
    for(auto& elem : s)
       print(elem);
    if(!check)
      std::cout << "Empty";
    
    return 0;
}