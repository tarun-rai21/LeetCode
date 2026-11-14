class Solution:
    def intersection(self, nums1: list[int], nums2: list[int]) -> list[int]:
        nums1.sort()
        nums2.sort()
        result = []

        p1 = 0      #pointer to nums1
        p2 = 0      #pointer to nums2

        while p1<len(nums1) and p2<len(nums2):
            if nums1[p1] == nums2[p2]:
                if not result or nums1[p1]!=result[-1]:
                    result.append(nums1[p1])
                p1 += 1
                p2 += 1
            else:
                if nums1[p1]>nums2[p2]:
                    p2 += 1
                else:
                    p1 += 1
        return result