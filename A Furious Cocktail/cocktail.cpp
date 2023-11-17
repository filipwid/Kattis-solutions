#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int numPotions, time;
    std::cin >> numPotions >> time;
    std::vector<int> potions(numPotions);    
    int tempPotion;
    for (int i = 0; i < numPotions; i++) {
        std::cin >> tempPotion;
        potions[i] = tempPotion;
    }

    bool result = true;
    std::sort(potions.begin(), potions.end());
    for (int i = 0; i < numPotions; i++) {
        int rem = numPotions - i -1;
        if(potions[rem] <= rem*time) {
            result = false;
        
        }
    }

    if (result)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    return 0;
}