
from pip import List


def twoSum(seft, nums: List[int], target: int) -> List[int]:
    temp = {}
    for positionOfNum in range(len(nums)):
        valueOfNum = nums[positionOfNum]
        if valueOfNum in temp:
            return [temp[valueOfNum], positionOfNum]
        difFromTarget = target - nums[positionOfNum]
        temp[difFromTarget] = positionOfNum
    return [-1, -1]


nums = [2, 3, 5, 7]
target = 9
ans = twoSum(0, nums, target)
print(ans[0], ans[1])
