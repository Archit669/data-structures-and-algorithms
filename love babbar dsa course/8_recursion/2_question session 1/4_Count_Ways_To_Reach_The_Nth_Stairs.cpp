int countDistinctWayToClimbStair(long long nStairs)
{
    if (nStairs == 0) return 1;
    if (nStairs == 1) return 1;
    if (nStairs == 2) return 2;
        
    return  countDistinctWayToClimbStair(nStairs-1) + countDistinctWayToClimbStair(nStairs-2);
}