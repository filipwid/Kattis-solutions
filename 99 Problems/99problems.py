price = int(input())

if (price < 100):
    print(99)
else:
    pricemod = price % 100
    delta = 99 - pricemod
    if pricemod >= 49:
        print(price + delta)
    else:
        print(price - 100 + delta)