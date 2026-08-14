class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """

        # left = search ka starting index
        # right = search ka ending index
        left, right = 0, len(nums) - 1
        
        # jab tak search area valid hai tab tak loop chalega
        while left <= right:
            
            # beech ka index nikal rahe hain
            mid = (left + right) // 2
            
            # agar beech wala element hi target hai
            # to direct True return kar do
            if nums[mid] == target:
                return True
            
            # agar left, mid, right tino same value hain
            # to hume samajh nahi aata kaunsa half sorted hai
            # isliye dono side se 1-1 shrink kar dete hain
            if nums[left] == nums[mid] == nums[right]:
                left += 1
                right -= 1
            
            # agar left half sorted hai
            elif nums[left] <= nums[mid]:
                
                # check karo target left sorted half ke andar hai ya nahi
                # agar hai, to right = mid - 1
                # iska matlab:
                # mid aur uske right wala sab part chhod do
                # ab sirf left side me search karo
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                
                # warna target left half me nahi hai
                # to left ko mid + 1 kar do
                # matlab left part chhod ke right side me search karo
                else:
                    left = mid + 1
            
            # warna right half sorted hoga
            else:
                
                # check karo target right sorted half ke andar hai ya nahi
                # agar hai, to left = mid + 1
                # matlab mid aur uske left wala part chhod do
                # ab sirf right side me search karo
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                
                # warna target right half me bhi nahi hai
                # to right ko mid - 1 kar do
                # matlab ab left side me search karo
                else:
                    right = mid - 1
        
        # poora search kar liya aur target nahi mila
        return False
