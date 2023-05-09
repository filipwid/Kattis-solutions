#include <stdio.h>

/*
Codes for the operators are:
+ = 0
- = 1
* = 2
/ = 3
*/
int DoOperation(int op, int num1, int num2) {
    if (op == 0) { 
        return (num1+num2);
    }
    if (op == 1) { 
        return (num1-num2);
    } 
    if (op == 2) { 
        return (num1*num2);
    }
    if (op == 3) { 
        return (num1/num2);
    }
}

int IsMultOrDiv(int operation) {
    return (operation == 2 || operation == 3);
}

int CalculateNum(int op1, int op2, int op3) {
    int mop1 = IsMultOrDiv(op1);
    int mop2 = IsMultOrDiv(op2);
    int mop3 = IsMultOrDiv(op3);
    
    if ((mop1 == mop2 && mop2 == mop3) || (mop1 && mop2 && !mop3)) { 
        return (DoOperation(op3, DoOperation(op2, DoOperation(op1, 4, 4), 4), 4));
    } 
    else if (mop1 && !mop2 && mop3) {
        return (DoOperation(op2, DoOperation(op1, 4, 4), DoOperation(op3, 4, 4)));
    }
    else if (!mop1 && mop2 && mop3) {
        return (DoOperation(op1, 4, DoOperation(op3, DoOperation(op2, 4, 4), 4)));
    }
    else if (mop1 && !mop2 && !mop3) {
        return (DoOperation(op3, DoOperation(op2, DoOperation(op1, 4, 4), 4), 4));
    }
    else if (!mop1 && !mop2 && mop3) {
        return (DoOperation(op2, DoOperation(op1, 4, 4), DoOperation(op3, 4, 4)));
    }

}

char OperatorChar(int op) {
    if (op == 0) {
        return '+';
    }
    if (op == 1) {
        return '-';
    }
    if (op == 2) {
        return '*';
    }
    if (op == 3) {
        return '/';
    }
}

void OutputHandler(int op1, int op2, int op3, int result) {
    printf("4 %c 4 %c 4 %c 4 = %d\n", OperatorChar(op1), OperatorChar(op2), OperatorChar(op3), result);
}

void FindNum(int targetVal) {
    if (targetVal < -60 || targetVal > 256) {
        printf("no solution\n");
        return;
    }
    for (int op1 = 0; op1 < 4; op1++) {
        for (int op2 = 0; op2 < 4; op2++) {
            for (int op3 = 0; op3 < 4; op3++) {
                if (CalculateNum(op1, op2, op3) == targetVal) {
                    OutputHandler(op1, op2, op3, targetVal);
                    return;
                }
            }
        }
    }

    printf("no solution\n");
}

int main() {
    int n;
    int targetValue;

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &targetValue);
        FindNum(targetValue);
    }

    return 0;
}