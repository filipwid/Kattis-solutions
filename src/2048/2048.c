#include <stdio.h>
#include <stdbool.h>

int main() {
    int grid[4][4];
    for(int row=0; row<4; row++) {
        for(int col=0; col<4; col++) {
            int temp;
            scanf("%d", &temp);
            grid[row][col] = temp;
        }
    }

    int opCode;
    scanf("%d", &opCode);

    if(opCode == 0) {
        for(int row=0; row<4; row++) {
            for(int col=0; col<4; col++) {
                for(int outerCol=col+1; outerCol < 4; outerCol++) {
                    if (grid[row][outerCol] == 0) {
                        continue;
                    } 
                    if(grid[row][col] == 0) {
                        grid[row][col] = grid[row][outerCol];
                        grid[row][outerCol] = 0;
                        continue;
                    }
                    if(grid[row][col] == grid[row][outerCol]) {
                        grid[row][col] *= 2;
                        grid[row][outerCol] = 0;
                        break;
                    }
                    break;
                }
            }
        }
    }
    else if(opCode == 1){
        for(int col=0; col<4; col++) {
            for(int row=0; row<4; row++) {
                for(int lowerRow=row+1; lowerRow<4; lowerRow++) {
                    if (grid[lowerRow][col] == 0) {
                        continue;
                    } 
                    if(grid[row][col] == 0) {
                        grid[row][col] = grid[lowerRow][col];
                        grid[lowerRow][col] = 0;
                        continue;
                    }
                    if(grid[row][col] == grid[lowerRow][col]) {
                        grid[row][col] *= 2;
                        grid[lowerRow][col] = 0;
                        break;
                    }
                    break;
                }
            }
        }
    }
    else if(opCode == 2){
        for(int row=0; row<4; row++) {
            for(int col=3; col>=0; col--) {
                for(int outerCol=col-1; outerCol >= 0; outerCol--) {
                    if (grid[row][outerCol] == 0) {
                        continue;
                    } 
                    if(grid[row][col] == 0) {
                        grid[row][col] = grid[row][outerCol];
                        grid[row][outerCol] = 0;
                        continue;
                    }
                    if(grid[row][col] == grid[row][outerCol]) {
                        grid[row][col] *= 2;
                        grid[row][outerCol] = 0;
                        break;
                    }
                    break;
                }
            }
        }
    }
    else if(opCode == 3){
        for(int col=0; col<4; col++) {
            for(int row=3; row>=0; row--) {
                for(int upperRow=row-1; upperRow>=0; upperRow--) {
                    if (grid[upperRow][col] == 0) {
                        continue;
                    } 
                    if(grid[row][col] == 0) {
                        grid[row][col] = grid[upperRow][col];
                        grid[upperRow][col] = 0;
                        continue;
                    }
                    if(grid[row][col] == grid[upperRow][col]) {
                        grid[row][col] *= 2;
                        grid[upperRow][col] = 0;
                        break;
                    }
                    break;
                }
            }
        }
    }
    for(int row=0; row<4; row++) {
        for(int col=0; col<4; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
    return 0;
}