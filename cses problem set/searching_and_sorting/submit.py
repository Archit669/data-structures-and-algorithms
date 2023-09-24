n = int(input())
arr = [int(x) for x in input().split()]
print(max(2*max(arr) , sum(arr)))
