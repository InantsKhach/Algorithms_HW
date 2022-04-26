#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    int n;
    std::cin >> n;
    if(n == 1 || n == 2)
    {
      std::cout << n << '\n';
      return 0;
    }
    std::vector<long long int> v(n);
    v[0] = 1;
    v[1] = 2;
    for(int i = 2; i < n; ++i)
    {
        v[i] = v[i - 1] + v[i - 2];
    }
    std::cout << v[n - 1] << '\n';
}