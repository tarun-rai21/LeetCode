class Solution:
    def reverse_range(self, nums: list[int], start: int, end: int) -> None:
        """Reverses nums in-place from index 'start' to 'end' (inclusive)."""
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1

    def rotate(self, nums: list[int], k: int) -> None:
        """Do not return anything, modify nums in-place instead."""
        n = len(nums)
        k = k%n
        self.reverse_range(nums, 0, (n-k-1))
        self.reverse_range(nums, n-k, n-1)
        self.reverse_range(nums, 0, n-1)