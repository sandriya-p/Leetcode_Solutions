class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        result = -1
        for i in range(len(nums)):
            if i != nums[i]:
                result = result & nums[i]
        return 0 if result==-1 else result
