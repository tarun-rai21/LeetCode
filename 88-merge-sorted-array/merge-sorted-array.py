class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        p1 = m-1 # pointer to the last valid elements in nums1
        p2 = n-1 # pointer to the last element in nums2
        tail = m+n-1

        while p2>=0:
            if p1>=0 and nums1[p1] >= nums2[p2]:
                nums1[tail] = nums1[p1]
                p1 -= 1
            else:
                nums1[tail] = nums2[p2]
                p2 -= 1
            tail -= 1