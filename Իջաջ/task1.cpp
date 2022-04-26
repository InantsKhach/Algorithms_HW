#include <iostream>
#include <string>

bool is_substring(std::string str1, std::string str2, int index1, int index2)
{
    if(index2 == str2.size() && index1 != str1.size())
      return false;
    if(index1 == str1.size())
      return true;
    
    if(str1[index1] == str2[index2])
    {
      return is_substring(str1, str2, index1 + 1, index2 + 1);
    }
    else 
    {
      return is_substring(str1, str2, index1, index2 + 1);
    }
}

int main()
{
   std::string str1, str2;
   std::cin >> str1;
   std::cin >> str2; 
   std::cout << ((is_substring(str1, str2, 0, 0)) ? "YES" : "NO");
}