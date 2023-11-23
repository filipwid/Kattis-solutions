#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Compare (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main () {
    int numPotions, time;
    scanf("%d %d", &numPotions, &time);
    int potions[numPotions]; 

    int tempPotion;
    for (int i = 0; i < numPotions; i++) {
        scanf("%d", &tempPotion);
        potions[i] = tempPotion;
    }

    bool result = true;
    qsort(potions, numPotions, sizeof(int), Compare);
    for (int i = 0; i < numPotions; i++) {
        int rem = numPotions - i -1;
        if(potions[rem] <= rem*time) {
            result = false;
        
        }
    }

    if (result)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
