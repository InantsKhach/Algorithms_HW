#include <iostream>
#include <vector>

void Solve( int open_count, int close_count, int n, std::vector<char>& curr_comb )
{
    if(curr_comb.size() == 2 * n)
    {
        for(const auto& elem : curr_comb)
           std::cout << elem;
        std::cout << '\n';
        return;
    }

    if(open_count < n )
    {
        curr_comb.push_back('(');
        Solve(open_count + 1, close_count, n, curr_comb);
        curr_comb.pop_back();
    }

    if(close_count < open_count)
    {
        curr_comb.push_back(')');
        Solve(open_count, close_count + 1, n, curr_comb);
        curr_comb.pop_back();
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<char> dummy;
    Solve( 0, 0, n, dummy );
    
}