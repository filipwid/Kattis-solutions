#numTests = int(input())
operators = ['+', '-', '*', '//']
numDict = {}

for i in operators:
    for j in operators:
        for k in operators:
            expr = '4 {:s} 4 {:s} 4 {:s} 4'.format(i, j, k)
            result = int(eval(expr))
            numDict[result] = expr.replace('//', '/') + " = " + str(result)

for i in range(-62, 258, 1):
    target = i
    if target in numDict:
        print("For {:d}: ".format(i) + numDict[target])

    else:
        print("For {:d}: ".format(i) + "no solution")