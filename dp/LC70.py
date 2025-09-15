class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        ls=[]
        ls.append(1)
        ls.append(2)
        if(n==1):return 1
        if(n==2):return 2
        for i in range (3,n+1):
            ls.append(ls[i-1]+ls[i-2])
        return ls[n-1]