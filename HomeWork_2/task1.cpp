#include <iostream>

void readSize(int &size);
void readArray(int *arr, const int &size);
void fillMatrix(const int *arr, int **matrix, const int &rows, const int &cols, const int &size);
void printMatrix(int **matrix, const int &rows, const int &cols);
void check(int **matrix, const int &rows, const int &cols);

int main() {

        int n = 0, rows = 0, cols = 0;
        readSize(n);
        int *arr;
        arr = new (std::nothrow) int[n];

        readArray(arr, n);

        std::cout << "Rows and colums: ";
        readSize(rows);
        readSize(cols);

        int **matrix;
        matrix = new int *[100];
        for(int i = 0; i < 100; i++)
                matrix[i] = new int[100];

        fillMatrix(arr, matrix, rows, cols, n);
        check(matrix, rows, cols);

        for(int i = 0; i < 100; i++)
                delete[] matrix[i];

        delete[] matrix;
        delete[] arr;
        return 0;
}
//7 6653 7854 9064 4444 6712 9064 2340 3 3

void readSize (int &size) {
        std::cin >> size;
}

void readArray(int *arr, const int &size) {
        for(int i = 0; i < size; i++)
        {
                std::cin >> arr[i];
        }
}

void fillMatrix(const int *arr, int **matrix, const int &rows, const int &cols, const int &size) {
        int counter = 0;
        for(int i = 0; i < rows; i++)
                for(int k = 0; k < cols; k++)
                {
                        if(counter >= size) matrix[i][k] = 0;
                        else {
                                matrix[i][k] = arr[counter];
                                counter++;
                        }
                }
}

void printMatrix(int **matrix, const int &rows, const int &cols) {
        for(int i = 0; i < rows; i++)
        {
                for(int k = 0; k < cols; k++)
                {
                        if(matrix[i][k] != 0) std::cout << matrix[i][k] << " ";
                        else std::cout << "0000" << " ";
                }
                std::cout << "\n";
        }
}

void check(int **matrix, const int &rows, const int &cols)
{
  printMatrix(matrix, rows, cols);
    bool flag = false;
    for(int i = 0; i < cols; i++)
    {
      flag = false;
            for(int k = 0; k < rows - 1; k++)
            {
                    for(int j = k + 1; j < rows; j++)
                    {
                      if(matrix[k][i] == matrix[j][i]) flag = true;
                    }
            }
            std::cout << flag << " ";
            std::cout.width(4);
    }

}
