class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dictionary = {}
        length = len(nums)
        for i in range(length):
            if nums[i] in dictionary:
                return [dictionary[nums[i]], i]
            else:
                dictionary[target - nums[i]] = i

        return [-1, -1]
