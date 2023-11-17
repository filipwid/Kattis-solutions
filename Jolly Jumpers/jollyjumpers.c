#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int len;
    while(scanf("%d", &len) == 1) {
        int vals[len];
        bool check[len];
        for (int i = 0; i < len; i++) {
            int temp;
            scanf("%d", &temp);
            vals[i] = temp;
            check[i] = false;
        } 
        bool res = true;
        for (int i = 0; i < len-1; i++) {
            int absval = abs(vals[i] - vals[i+1]);
            if (absval == 0 || absval >= len || check[absval-1] == true) {
                res = false;
                break;
            }
            else {
                check[absval-1] = true;
            }

        }
        if (res) 
            printf("Jolly\n");
        else 
            printf("Not jolly\n");
    }
}