#include <iostream>
#include <math.h>

int main() {
    long long num1, num2;
    while (std::cin >> num1 >> num2){    
        std::cout << abs(num1 - num2) << "\n";
    }
    return 0;
}