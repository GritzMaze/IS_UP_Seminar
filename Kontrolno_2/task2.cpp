#include <iostream>

int whatDigit(char a)
{
        switch(a)
        {
        case '1': return 1;
                break;
        case '2': return 2;
                break;
        case '3': return 3;
                break;
        case '4': return 4;
                break;
        case '5': return 5;
                break;
        case '6': return 6;
                break;
        case '7': return 7;
                break;
        case '8': return 8;
                break;
        case '9': return 9;
                break;
        case '0': return 0;
                break;
        default: return -1;
                break;
        }
}

void toUpperCase(char *arr, int size, int times)
{
        for(int i = 0; i < times && i < size; i++)
        {
                if(arr[i] >= 'a' && arr[i] <= 'z')
                        arr[i] = arr[i] - 'a' + 'A';
        }
}

void removeDigits(char *arr, int &size)
{
        for(int i = 0; i < size; i++)
        {
                if(arr[i] <= '9' && arr[i] >= '0') {

                        toUpperCase(arr+i+1, size - i, whatDigit(arr[i]));

                        for(int k = i; k < size-1; k++) arr[k] = arr[k + 1];
                        size--;
                }
        }
}

void printArr(const char *arr,const int size)
{
        for(int i = 0; i < size; i++)
                std::cout << arr[i];
}

int getLength(char *arr, int &length)
{
        for(length = 0; arr[length] != '\0'; length++);
        return length;
}

int main() {

        char *arr = new char[256];

        std::cin.getline(arr, 256);
        int length = 0;
        getLength(arr, length);

        removeDigits(arr, length);
        printArr(arr, length);

        delete [] arr;

        return 0;
}
