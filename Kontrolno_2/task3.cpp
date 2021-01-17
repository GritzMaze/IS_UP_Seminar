#include <iostream>

bool tripletExists(double *arr, int size, double prod, int count)
{
        if (count == 3 && prod == 1.0)
                return true;

        if (count == 3 || size == 0)
                return false;

        return tripletExists(arr, size - 1, prod / arr[size - 1], count + 1) ||
               tripletExists(arr, size - 1, prod, count);
}

int main()
{
        double arr[] = {5, 2, 1, 10, 3, 9, 1 };
        double number = 6;

        int size = sizeof(arr) / sizeof(*arr);

        std::cout << std::boolalpha << tripletExists(arr, size, number, 0);
        return 0;
}
