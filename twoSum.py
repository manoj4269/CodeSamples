class Solution(object):
    def twoSum(self, nums, target):
        res = []
        l = len(nums)
        k = 0
        for i in range(0, l):
            k+=1
            a = nums[i]
            b = target-a
            temp = nums[k:]
            if b in temp:
                return [k-1, temp.index(b)+k]
