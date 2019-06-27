#include <iostream>

int main(int argc, char* args[]) {

    double massInKg = 81.2;
    double heightInM = 1.78;
    double BMI;
    // Print the Body mass index (BMI) based on these values
    //BMI=mass/heightˇ2
    BMI = massInKg / heightInM / heightInM;
    std:: cout << "The BMI index is: "<< BMI << std::endl;
    return 0;
}