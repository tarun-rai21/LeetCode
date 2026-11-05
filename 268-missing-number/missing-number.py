class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        n = len(nums) + 1
        expectedSum = (n*(n-1))//2
        currSum = sum(nums)
        return expectedSum - currSum