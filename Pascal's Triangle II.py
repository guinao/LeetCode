class Solution:
    # @return a list of integers
    def getRow(self, rowIndex):
        # if rowIndex == 0:
            # return [1]
        f = [1] * (rowIndex+1)
        for i in range(1,rowIndex+1):
            f[i] = i * f[i-1]
        ans = [0] * (rowIndex+1)
        for i in range(rowIndex+1):
            ans[i] = f[rowIndex] / f[i] / f[rowIndex-i]
        return ans