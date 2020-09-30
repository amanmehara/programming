"""
Given an unsorted array of integers, this algorithm finds the length of the longest increasing subsequence.
"""
# nums is the input array which may be unsorted
def lengthOfLIS(nums):
    if not nums:
        return 0
    dp = [1 for i in range(len(nums))]    # the dp array
    longest = 1    # variable to keep track of the longest increasing subsequence at every iteration
    for i in range(1, len(nums)):
        for j in range(i):
            if nums[j] < nums[i]:
                dp[i] = max(dp[i], dp[j] + 1)
        longest = max(dp[i], longest)    # check if the length of LIS has changed
    return longest

print(lengthOfLIS([10,9,2,5,3,7,101,18]))