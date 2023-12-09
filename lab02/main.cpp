#include <iostream>
#include "include/CNumber.h"
#include <iomanip>



void print_line(int width) {
    for (int i = 0; i < 65; i++) {
        std::cout << "-";
    }
    std::cout << "+";
    for (int i = 66; i < width; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}


int operator<=(int &val, const CNumber& pcother){
    int n = pcother.toInt();
    val = n;
    return val;
}


int main() {

CNumber n(-223382465);
CNumber m;
int x;

x <= (m <= n);
std::cout << x << std::endl;
std::cout << m.toString() << std::endl;


    int numbers_1[] = {344, -6439, 98534, -3748324, -324793, -1234};
    int numbers_2[] = {38492, 49385, -3498942, 34958, -324793, -1234};

    std::cout << std::left << std::setw(15) << "number1" << std::setw(10) << "operator" << std::setw(15) << "number2" << std::setw(10) << "=" << std::setw(15) << "my result" << std::setw(10) << "|   " << "expected" << std::endl;
    print_line(85);
    for (int i = 0; i < 5; i++) {
        CNumber c_number1(numbers_1[i]);
        CNumber c_number2(numbers_2[i]);
        CNumber sum = c_number1 + c_number2;
        std::cout << std::left << std::setw(15) << c_number1.toString() << std::setw(10) << "+" << std::setw(15) << c_number2.toString() << std::setw(10) << "=" << std::setw(15) << sum.toString() << std::setw(10) << "|   "  << (numbers_1[i] + numbers_2[i]) << std::endl;
    }
    print_line(85);
    for (int i = 0; i < 5; i++) {
        CNumber c_number1(numbers_1[i]);
        CNumber c_number2(numbers_2[i]);
        CNumber diff = c_number1 - c_number2;
        std::cout << std::left << std::setw(15) << c_number1.toString() << std::setw(10) << "-" << std::setw(15) << c_number2.toString() << std::setw(10) << "=" << std::setw(15) << diff.toString() << std::setw(10) << "|   " << (numbers_1[i] - numbers_2[i]) << std::endl;
    }
    print_line(85);
    int numbers_mult[] = {-3498, -66, 0, 128};
    int numbers_mult2[] = {23, -120, 21398, 512};
    for(int i = 0; i < 4; i++) {
        CNumber c_number1(numbers_mult[i]);
        CNumber c_number2(numbers_mult2[i]);
        CNumber mult = c_number1 * c_number2;
        std::cout << std::left << std::setw(15) << c_number1.toString() << std::setw(10) << "*" << std::setw(15) << c_number2.toString() << std::setw(10) << "=" << std::setw(15) << mult.toString() << std::setw(10) << "|   " << (numbers_mult[i] * numbers_mult2[i]) << std::endl;
    }
    print_line(85);

    int numbers_div[] = {-3498, -66, 12345, 1024, 49023940};
    int numbers_div2[] = {23, -120, -12, 32, 213};
    for(int i = 0; i < 5; i++) {
        CNumber c_number1(numbers_div[i]);
        CNumber c_number2(numbers_div2[i]);
        CNumber div = c_number1 / c_number2;
        std::cout << std::left << std::setw(15) << c_number1.toString() << std::setw(10) << "/" << std::setw(15) << c_number2.toString() << std::setw(10) << "=" << std::setw(15) << div.toString() << std::setw(10) << "|   " << (numbers_div[i] / numbers_div2[i]) << std::endl;

    }
    print_line(85);

    CNumber res, temp;
    temp =  2457723;
    res = temp * 230 - 128 / 3 + 21940; // 2457723 * 230 - 128 / 3 + 21940 = 565298187.333
    std::cout << res.toString() << std::endl;
    return 0;
}


