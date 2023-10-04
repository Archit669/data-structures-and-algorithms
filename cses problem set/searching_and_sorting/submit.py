from collections import OrderedDict

n = int(input())
arr = [int(x) for x in input().split()]

sum = 0
count = 0

d = OrderedDict()
d[0] = 1


for x in arr:
    sum += x
    rem = sum % n

    if (rem in d):
        count += d[rem]

    if (rem in d):
        d[rem] = d[rem] + 1
    else:
        d[rem] = 1


print(count)
