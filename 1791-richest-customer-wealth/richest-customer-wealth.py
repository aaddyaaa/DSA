class Solution(object):
    def maximumWealth(self, accounts):
        n = len(accounts)
        m = len(accounts[0])
        maximum = 0
        for i in range(n):
            total = 0
            for j in range(m):
                total += accounts[i][j]
            maximum = max(maximum,total)
        return maximum

        """
        :type accounts: List[List[int]]
        :rtype: int
        """
        