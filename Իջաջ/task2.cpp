#include <iostream>


void rec(int num, int n)
{
  std::cout << num << ' ';
  if(num == n)
    exit(0);
  rec(num + 5, n);
}

void recursion(int num, int n)
{
  std::cout << num << ' ';
  if(num <= 0)
    rec(num + 5, n);
  recursion(num - 5, n);
}

int main() {
  int n;
  std::cin >> n;
  recursion(n, n);
}