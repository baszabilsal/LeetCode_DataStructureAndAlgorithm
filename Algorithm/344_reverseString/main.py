from math import ceil

from pip import List


def reverseString(self, s: List[str]) -> None:
    size = len(s)
    mid = int(ceil(size/2))
    print(mid)
    for a in range(mid):
        temp = s[a]
        s[a] = s[size-1]
        s[size-1] = temp
        size -= 1


nums = ["h", "e", "l", "m",  "o"]
ans = reverseString(0, nums)
for n in nums:
    print(n)
