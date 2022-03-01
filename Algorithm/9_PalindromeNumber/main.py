from math import ceil, floor


def isPalindrome(self, x: int) -> bool:
    if x < 0:
        return False
    num = str(x)
    r = 0
    l = 0
    if len(num) % 2 > 0:
        med = int(ceil(len(num)/2))
        r, l = med-1, med-1
    else:
        med = int(len(num)/2)
        r, l = med - 1, med
    error = False
    while l >= 0 and r < len(num):
        print(num[l], num[r])
        if num[r] != num[l]:
            error = True
            break
        r += 1
        l -= 1
    return error == False


print(isPalindrome(10, 100))
