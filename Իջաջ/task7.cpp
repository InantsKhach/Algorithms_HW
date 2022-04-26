#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

int count = 0;

void print(std::vector<int>& v)
{
    for(const auto& elem : v)
       std::cout << elem << ' ';
    std::cout << '\n';
    ++count;
}

void Solve(std::size_t start_index, std::vector<int>& to_print, std::vector<int>& orig)
{
    if(count == ( pow(2, orig.size()) - 1) )
    {
      exit(0);
    }

    for(std::size_t i = start_index; i < orig.size(); ++i)
    {
        to_print.push_back(orig[i]);
        print( to_print );
        Solve( i + 1, to_print, orig );
        to_print.pop_back();
    }

    // 1 2 3

    // 1     i = 0 a 
    // 1 2   i = 1 b
    // 1 2 3 i = 2
    // 1 3   i = 2 b
    // 
}

// Solve(0, dummy, v);

int main()
{
   std::set<int> s;
   int n;
   while(std::cin >> n)
   {
       s.insert(n);
   }
   std::vector<int> v;
   for(auto elem : s)
     v.push_back(elem);

   std::sort(v.begin(), v.end());
   std::vector<int> dummy;
   std::cout << '\n';
   Solve(0, dummy, v);
}