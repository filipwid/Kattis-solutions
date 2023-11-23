#include <iostream>
#include <cmath>

int main() {
    int len;
    while(std::cin >> len) {
        int vals[len];
        for (int i = 0; i < len; i++) {
            int temp;
            std::cin >> temp;
            vals[i] = temp;
        } 
        bool check[len] = { false };
        bool res = true;
        for (int i = 0; i < len-1; i++) {
            int absval = std::abs(vals[i] - vals[i+1]);
            if (absval == 0 || absval >= len || check[absval-1] == true) {
                res = false;
                break;
            }
            else {
                check[absval-1] = true;
            }


        }
        if (res) 
            std::cout << "Jolly" << std::endl;
        else 
            std::cout << "Not jolly" << std::endl;
    }
}