from pip import List


def containsDuplicate(self, nums: List[int]) -> bool:
    hash = {}
    for i in range(len(nums)):
        if nums[i] in hash:
            hash[nums[i]] += 1
        else:
            hash[nums[i]] = 1
        if hash[nums[i]] > 1:
            return True
    return False


nums = [2, 2, 11, 15]
ans = containsDuplicate(0, nums)
print(ans)
