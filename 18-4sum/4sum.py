class Solution:
    def fourSum(self, nums: list[int], target: int) -> list[list[int]]:
        nums.sort()
        result = []
        n = len(nums)

        for i in range(0, n-3):
            if (i > 0 and nums[i]==nums[i-1]):
                continue
            for j in range(i+1, n-2):
                if (j > (i+1) and nums[j] == nums[j-1]):
                    continue
                
                low = j+1
                high = n-1
                while low<high:
                    curr_sum = nums[i]+nums[j]+nums[low]+nums[high]
                    if curr_sum == target:
                        result.append([nums[i], nums[j], nums[low], nums[high]])
                        low += 1
                        high -= 1

                        while low < high and nums[low] == nums[low-1]:
                            low += 1
                        while low < high and nums[high] == nums[high+1] :
                            high -= 1
                    elif curr_sum < target:
                        low += 1
                    else:
                        high -= 1
        return result