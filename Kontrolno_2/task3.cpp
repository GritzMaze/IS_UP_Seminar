#include <iostream>

bool check(double *arr, int size, int number, int times = 1, double sum = 1, int pos = 1)
{
  if(size == 0) return false;
  if(sum == number) return true;
  if(times == 3) return false;
  double number1 = *arr;
  double number2 = *arr + pos;
  sum = number1*number2;
  return check(arr + 1, size - 1, number, times + 1, sum, pos + 1);
}

bool isThere(double *arr, int size, int number)
{
  if(size == 0) return false;

  return check(arr, size, number) ? true : isThere(arr + 1, size - 1, number);
}


int main() {

double arr[10] = {5, 2, 1, 10, 3, 9, 1};
int size = 7;
int number = 6;
std::cout << isThere(arr, size, number);


  return 0;
}
