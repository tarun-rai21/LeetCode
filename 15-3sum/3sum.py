class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        result = []
        for i in range(0, len(nums)-2):
            #skip for duplicate i
            if (i>0) and(nums[i]==nums[i-1]):
                continue
            low = i+1
            high = len(nums)-1

            while low < high:
                sum = nums[i]+nums[low]+nums[high]
                if sum == 0:
                    result.append([nums[i], nums[low], nums[high]])
                    low += 1
                    high -= 1
                    #skip for duplicate low
                    while (low < high) and nums[low] == nums[low-1]:
                        low+=1
                    #skip for duplicate high
                    while (low < high) and nums[high] == nums[high+1]:
                        high-=1
                elif sum < 0:
                    low += 1
                else:
                    high -= 1
        return result
                