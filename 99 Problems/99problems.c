#include <stdio.h>

int main() {
    int price;
    scanf("%d", &price);
    if (price < 100)
        printf("%d", 99);
    else {
        int remainder = price % 100;
        int delta = 99 - remainder;
        if (remainder >= 49)
            printf("%d", price + delta);
        else 
            printf("%d", price - 100 + delta);
    }

    return 0;
}