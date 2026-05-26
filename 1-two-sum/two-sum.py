class Solution(object):
    def twoSum(self, nums, target):
        mpp = {}
        # for i in range(len(nums))
        for i, num in enumerate(nums):
            need = target - num
            if need in mpp :
               return [mpp[need], i]
            mpp[num] = i