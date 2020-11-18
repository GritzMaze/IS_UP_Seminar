#include <iostream>

int main() {

        //Declaration

        int arr[100];
        int n = 0;

        // Input
        std::cin >> n;
        std::cin >> arr[0];
        for(int i = 1; i < n; i++)
        {
                std::cin >> arr[i];
                // Check if 3 and 8 appear
                if(arr[i] == 8 && arr[i-1] == 3) {
                        arr[i-1] = 6;
                        i--;
                        n--;
                }
                // Check for 2's
                if(arr[i-1] == 2) arr[i-1] *= arr[i];
                if(i == n - 1 && arr[i] == 2)
                {
                        arr[i] *= arr[0];
                }
        }
        std::cout << "\n";
        //  Output
        for(int i = 0; i < n; i++)
        {
                std::cout << arr[i] << " ";
        }



        return 0;
}
