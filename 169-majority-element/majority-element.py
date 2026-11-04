class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        countDict = {}
        k = len(nums)
        for i in range(k):
            countDict[nums[i]] = countDict.get(nums[i], 0) + 1
            if countDict[nums[i]] >= k/2:
                return nums[i]