#include <iostream>
#include <vector>

void merge(std::vector<int>& v, int start, int mid, int finish)
{
    int size_of_first = mid - start + 1;
    int size_of_second = finish - mid;
    std::vector<int> left;
    std::vector<int> right;

    for(int i = 0; i < size_of_first; ++i)
       left.push_back(v[start + i]);

    for(int i = 0; i < size_of_first; ++i)
       right.push_back(v[mid + 1 + i]);
    
    int i = 0, j = 0, k = start;
    while(i < size_of_first && j < size_of_second)
    {
        if(left[i] <= right[j])
        {
            v[k] = left[i];
            ++i;
        }
        else 
        {
            v[k] = right[j];
            ++j;
        }
        ++k;
    }

    while(i < size_of_first)
    {
        v[k] = left[i];
        ++i;
        ++k;
    }

    while(j < size_of_second)
    {
        v[k] = right[j];
        ++j;
        ++k;
    }

}

void merge_sort(std::vector<int>& v, int start, int finish)
{
    if(start >= finish)
      return;
    
    merge_sort(v, start, start + (finish - start) / 2);
    merge_sort(v, (start + (finish - start) / 2) + 1, finish);
    merge(v, start, start + (finish - start) / 2, finish);
}




int main()
{
    //std::vector<int> v = {1, 5, 23, 5, 3, 8, 17, 90, 54, 30};
    std::vector<int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(23);
    v.push_back(25);
    v.push_back(13);
    v.push_back(8);
    v.push_back(17);
    v.push_back(90);
    v.push_back(54);
    v.push_back(30);
    merge_sort(v, 0, 9);
    for(const auto& elem : v)
       std::cout << elem << ' ';
}