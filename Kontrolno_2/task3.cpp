#include <iostream>

// Naive recursive function to check if triplet exists in array
// with given sum
bool tripletExists(double *arr, int size, double prod, int count)
{
    // if triplet has desired sum, return true
    if (count == 3 && prod == 1.0)
        return true;

    // return false if sum is not possible with current configuration
    if (count == 3 || size == 0)
        return false;

    // recur with
    // 1. including current element
    // 2. excluding current element
    return tripletExists(arr, size - 1, prod / arr[size - 1], count + 1) ||
            tripletExists(arr, size - 1, prod, count);
}

// Find Triplet with given sum in an array
int main()
{
    double arr[] = {5, 2, 1, 10, 3, 9, 1 };
    double number = 6;

    int size = sizeof(arr) / sizeof(*arr);

    std::cout << std::boolalpha << tripletExists(arr, size, number, 0);
    return 0;
}
