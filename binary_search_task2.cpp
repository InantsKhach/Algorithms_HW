#include <iostream>
#include <vector>

int left_side(const std::vector<int>& arr, int value, int m)
{
  int l = 0;
  int r = m;
  int ret_val = m;
  std::cout << "left side started \n\n\n";
  while(l <= r)
  {
    int mid = l +  ( (r - l) / 2);
    if(arr[mid] == value)
    {
      r = mid - 1;
      ret_val = mid;
      std::cout << "ret_val is following " << ret_val << '\n';
      std::cout << "r is " << r << '\n';
    }
    else if(arr[mid] < value)
    {
      l = mid + 1;
      std::cout << "ret_val is following " << ret_val << '\n';
      std::cout << "l is " << l << '\n';
    }
  }

  return ret_val;
}

int right_side(const std::vector<int>& arr, int value, int m)
{
  int l = m;
  int r = arr.size() - 1;
  int ret_val = m;
  std::cout << "right side started \n\n\n";
  while(l <= r)
  {
    int mid = l +  ( (r - l) / 2);
    if(arr[mid] == value)
    {
      l = mid + 1;
      ret_val = mid;
      std::cout << "ret_val is following " << ret_val << '\n';
      std::cout << "l is " << l << '\n';
    }
    else if(arr[mid] > value)
    {
      r = mid - 1;
      std::cout << "ret_val is following " << ret_val << '\n';
      std::cout << "r is " << r << '\n';
    }
  }

  return ret_val;
}

std::vector<int> solve(const std::vector<int>& arr, int value)
{
    std::vector<int> ret(2, -1);
    int l = 0;
    int r = arr.size() - 1;
    while(l <= r)
    {
        int m = l +  ( (r - l) / 2);
        if(arr[m] > value)
        {
            r = m - 1;
        }
        else if(arr[m] < value)
        {
            l = m + 1; 
        }
        else
        {
            std::cout << "they are equal\n";
            ret[0] = left_side(arr, value, m);
            ret[1] = right_side(arr, value, m);
            break;
        }
    }

    return ret;
}