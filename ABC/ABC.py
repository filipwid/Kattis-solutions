from sys import stdin
numList = stdin.readline().split()
for i in range(0, len(numList)):
    numList[i] = int(numList[i])
numList.sort()
numDict = {
    "A": numList[0],
    "B": numList[1],
    "C": numList[2],
}
for i in input():
    print(numDict[i], end=" ")