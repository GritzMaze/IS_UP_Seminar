#include <iostream>



int main() {

        unsigned int n = 0;

        std::cin >> n;
        if(n > 10 || n < 4) {std::cout << "Invalid number"; return -1; }

        double arr[10][10];

        for(int i = 0; i < n; i++)
                std::cin >> arr[i][i];


        for(int row = 0; row < n; row++)
                for(int col = 0; col < n; col++)
                        if(col > row) arr[row][col] = col + arr[row][col-1];


        for(int row = 0; row < n; row++)
                for(int col = n-1; col >= 0; col--)
                        if(row > col) arr[row][col] = (arr[row-1][col] + arr[row][col+1])/2;

        for(int i = 0; i < n; i++)
        {
                for(int k = 0; k < n; k++)
                        std::cout << arr[i][k] << " ";

                std::cout << "\n";
        }
        return 0;
}
// Да се напише програма, която по подаден този масив въвежда елементите в матрицата по нейния главен диагонал.
// Да се пресметнат елементите под главния диагонал, като всеки такъв елемент е равен на средното аритметично на елемента над него и елемента вдясно от него.
// Стойността на всеки елемент над главния диагонал се получава от сумата на индекса на текущата колона и стойността на елемента вляво от него.
