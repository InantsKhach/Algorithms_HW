#include <vector>
#include <iostream>

int solution(vector<int> arr, int target) 
{
    int count = 0;
    for(int i = 0; i < arr.size(); ++i)
    {
        int diff = arr[i] - target;
        if(diff >= 5)
        {
            int num = diff / 5;
            int res = diff % 5;
            arr[i] = arr[i] - (num * 5);
            diff = res;
            count += num;
        }
        if(diff >= 2)
        {
            int num = diff / 2;
            int res = diff % 2;
            arr[i] = arr[i] - (2 * num);
            count += num;
            diff = res;
        }
        if(diff == 1)  
        {
            --arr[i];
            ++count;
        }
    }
    return count;
}

int solution( vector<int> arr )
{
    int min = *min_element( arr.begin(), arr.end() );
    int result = 1'000'000'000;
    for ( int k = min; k > min-5; --k )
    {
        result = std::min( result, solution( arr, k ) );
    }
    return result;
}