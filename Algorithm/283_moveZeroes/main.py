

from pip import List


def moveZeroes(self, nums: List[int]) -> None:
    current = 0
    for i in range(len(nums)):
        if nums[i] != 0:
            nums[current] = nums[i]
            current += 1
    while current < len(nums):
        nums[current] = 0
        current += 1
    return


print("bas")
