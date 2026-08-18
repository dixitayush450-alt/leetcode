class Solution:
    def smallestDivisor(self, nums, threshold):
        
        l, r = 1, max(nums)
        res = r

        while l <= r:
            mid = (l + r) // 2
            total = 0

            for num in nums:
                total += (num + mid - 1) // mid

            if total <= threshold:
                res = mid
                r = mid - 1
            else:
                l = mid + 1

        return res