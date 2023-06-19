#include <iostream>




// function for performing a task with a matrix
void performMatrixTask() {
    const int N = 3;  // matrix size



    int matrix[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };



    int rowSums[N] = { 0 };



    for (int i = 0; i < N; ++i) {
        int sum = 0;
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] > 0 && matrix[i][j] % 2 == 0) {
                sum += matrix[i][j];
            }
        }



        rowSums[i] = sum;
    }



    std::cout << "characteristics of matrix rows:" << std::endl;



    for (int i = 0; i < N; ++i) {
        std::cout << "line " << i + 1 << ": " << rowSums[i] << std::endl;
    }
}



int main(){



performMatrixTask();




return 0;
}
