
from pip import List


def twoSum(self, numbers: List[int], target: int) -> List[int]:
    l = 0
    r = len(numbers)-1
    while(l <= r):
        sum = numbers[l]+numbers[r]
        if sum > target:
            r -= 1
        elif sum < target:
            l += 1
        else:
            break
    return [l+1, r+1]


nums = [2, 7, 11, 15]
target = 9
ans = twoSum(0,nums, target)
print(ans[0], ans[1])
