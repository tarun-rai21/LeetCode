class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        unique = 0
        for curr in range(1, len(nums)):
            if nums[unique] != nums[curr]:
                unique += 1
                nums[unique] = nums[curr]
        return unique+1            