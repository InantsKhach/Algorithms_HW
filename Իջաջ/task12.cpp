#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    if(n == 0)
    {
        std::cout << 0;
        return 0;
    }
    std::vector<int> v(n);
    for(auto& elem : v)
      std::cin >> elem;
    
    if(n == 1)
    {
        std::cout << v[0];
        return 0;
    }
    std::vector<int> res(n);
    res[0] = v[0];
    res[1] = std::max(v[0], v[1]);

    for(int i = 2; i < n; ++i)
    {
        res[i] = std::max(res[i - 1], res[i - 2] + v[i]);
    }
    std::cout << res[n - 1];
    return 0;

}