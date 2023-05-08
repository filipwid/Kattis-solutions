numTests = int(input())
operators = ['+', '-', '*', '//']
numDict = {}

for i in operators:
    for j in operators:
        for k in operators:
            expr = '4 {:s} 4 {:s} 4 {:s} 4'.format(i, j, k)
            result = int(eval(expr))
            numDict[result] = expr.replace('//', '/') + " = " + str(result)

for _ in range(numTests):
    target = int(input())
    if target in numDict:
        print(numDict[target])

    else:
        print('no solution')