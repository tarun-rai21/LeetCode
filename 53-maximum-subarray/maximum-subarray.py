class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        curr_max = nums[0]
        result = nums[0]
        n = len(nums)

        if n==1:
            return nums[0] 
        for i in range(1, len(nums)):
            curr_max = max(nums[i], curr_max + nums[i])
            result = max(result, curr_max)
        return result