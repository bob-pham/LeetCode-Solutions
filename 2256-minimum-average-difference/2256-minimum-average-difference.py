class Solution(object):
    def minimumAverageDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        end = 0
        front = 0
        mindif = 100000000000
        location = 0

        for x in nums:
            end += x

        for x in range(len(nums)):
            front += nums[x]
            end -= nums[x]
            if x == len(nums) - 1:
                currdif = front/len(nums)
            else:
                currdif = abs((front/(x+1)) - (end/(len(nums)-(x+1))))
            if currdif < mindif:
                mindif = currdif
                location = x 
 
        return location