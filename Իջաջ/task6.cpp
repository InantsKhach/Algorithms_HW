#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(auto& elem : v)
      std::cin >> elem;
    int num = 0;
    for(int i = 0; i < n; i+=1)
    {
        num ^= v[i];
    }
    std::cout << num;
}