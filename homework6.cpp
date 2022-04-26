#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<vector<char>> matrix) {
    vector<vector<int>> sums(matrix.size());
   
    if(matrix.size() == 0)
      return 0;

    for(int i = 0; i < matrix.size(); ++i)
    {
        sums[i].resize(matrix[i].size());
    }

    for (int i = 0; i < matrix.size(); ++i)
    {
        if(matrix[i][0] == '0'){
          sums[i][0] = 0;
         // cout << "first if\n";
        }
        else {
          sums[i][0] = 1;
        //  cout << "first else\n";
        }
    }

    for(int i = 1; i < matrix[0].size(); ++i)
    {
        if(matrix[0][i] == '0'){
          sums[0][i] = 0;
          //cout << "Second if\n";
        }
        else {
          sums[0][i] = 1;
         // cout << "Second else\n";
        }
    }

    for(int i = 1; i < matrix.size(); ++i)
    {
        for(int j = 1; j < matrix[i].size(); ++j)
        {
           if(matrix[i][j] == '0')
           {
               sums[i][j] = 0;
           }
           else 
           {
               int temp = std::min(sums[i - 1][j - 1], std::min(sums[i - 1][j], sums[i][j - 1]));
               temp = sqrt(temp);
               sums[i][j] = (temp + 1) * (temp + 1);
           }
        }
    }

    int max = 0;

    for(int i = 0; i < matrix.size(); ++i)
    {
        for(int j = 0; j < matrix[i].size(); ++j)
        {
            if(sums[i][j] > max){
              max = sums[i][j];
              //cout << "Last if and max is " << max << '\n';
            }
        }
    }

    return max;
}


int main()
{
    vector<vector<char>> arr;
    
    std::cout << solution(arr) << endl;
}