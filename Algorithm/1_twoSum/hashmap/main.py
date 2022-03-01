
from pip import List


def twoSum(seft, nums: List[int], target: int) -> List[int]:
    hash = {}
    for i in range(len(nums)):
        if nums[i] in hash:
            return [hash[nums[i]], i]
        hash[target-nums[i]] = i
    return [-1, -1]


nums = [1, 2, 3, 5, 6, 7, 8]
target = 8
ans = twoSum(0, nums, target)
print(ans[0], ans[1])
