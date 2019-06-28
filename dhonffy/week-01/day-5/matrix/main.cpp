#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create (dynamically) a two dimensional array
    //   with the following matrix. Use a loop!
    //   by dynamically, we mean here that you can change the size of the matrix
    //   by changing an input value or a parameter or this combined
    //
    //   1 0 0 0
    //   0 1 0 0
    //   0 0 1 0
    //   0 0 0 1
    //
    // - Print this two dimensional array to the output

    int x;
    std::cout << "How many lines and columns should the matrix have?" << std::endl;
    std::cin >> x;
    int matrix[x][x];
    for (int k = 0; k < x; ++k) {
        for (int l = 0; l < x; ++l) {
            matrix[k][l] = 0;
        }
    }
    for (int i = 0; i < x ; ++i) {
        matrix[i][i] = 1;
    }
    for (int j = 0; j < x ; ++j) {
        for (int m = 0; m < x; ++m) {
            std::cout << matrix[j][m] << " ";
        }
        std::cout << std::endl;

    }

    return 0;
}