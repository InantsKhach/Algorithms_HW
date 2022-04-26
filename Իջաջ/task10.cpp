#include <iostream>
#include <vector>
 
int Solve(std::vector<int>& v, int n)
{
    int profit = 0;
    for(int i = 1; i < n; ++i)
        if(v[i] > v[i - 1])
          profit += v[i] - v[i - 1];
    return profit;
}
 
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(auto& elem : v)
       std::cin >> elem;
    
    std::cout << Solve(v, n) << std::endl;
    return 0;
}