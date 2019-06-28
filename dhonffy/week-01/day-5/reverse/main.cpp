#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`
    int aj[] = {3, 4, 5, 6, 7};
    int temp[5];
    for (int i = 0; i < 5; ++i) {
        temp[4-i] = aj[i];
    }
    for (int j = 0; j < 5; ++j) {
        aj[j] = temp[j];
    }
    return 0;
}