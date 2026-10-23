class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        dic ={}

        for i in range(len(nums)):
            n = nums[i]
            diff = target - n
            if diff in dic:
                return [dic[diff], i] #return the index of the two numbers
            dic[n]= i #else add the num to dic/hashtable
        return  

        