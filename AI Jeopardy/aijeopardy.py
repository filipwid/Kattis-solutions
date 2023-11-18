from math import comb

target = int(input())

# Given that the max value of n choose k is when n = 2k
# The first k where n = 2k, to reach 10^100 is k = 169
finalN = 10**100
finalK = 1
for k in range(1, 170):
    if target == 1:
        finalN = 0
        finalK = 0
        break
    if (comb(2*k, k) > target):
        break
    upper = 2*k

    while comb(upper, k) < target:
        upper *= 2    
    lower = upper // 2
    while lower <= upper:
        # Binary search for  n 
        mid = (lower+upper)//2
        temp = comb(mid, k)

        if temp == target:
            if mid < finalN:
                finalN = mid
                finalK = k
            break
        elif temp > target:
            upper = mid-1
        elif temp < target:
            lower = mid+1
            
print(finalN, finalK)
