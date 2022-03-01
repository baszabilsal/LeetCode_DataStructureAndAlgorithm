from pip import List


def maxSubArray(self, nums: List[int]) -> int:
    sum = nums[0]
    max = nums[0]
    for i in range(len(nums)):
        if i == 0:
            continue
        sum += nums[i]
        if sum < nums[i]:
            sum = nums[i]
        if max < sum:
            max = sum
    return max


nums = [1]
ans = maxSubArray(0, nums)
print(ans)
