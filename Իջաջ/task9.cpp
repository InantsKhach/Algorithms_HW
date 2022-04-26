#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(auto& elem : v)
      std::cin >> elem;
    
    int min_value = v[0];
    int max_profit = v[1] - v[0];
    for(int i = 1; i < n; ++i)
    {
      int current = v[i] - min_value;
      max_profit = std::max(current, max_profit);
      min_value = std::min(v[i], min_value);
    }

    std::cout << ((max_profit > 0) ? max_profit : 0);

}