def reverseWords(self, s: str) -> str:
    i = 0
    t = list(s)
    while i < len(t):
        start = i
        end = i
        while end < len(s) and s[end] != " ":
            end += 1
        i = end
        end -= 1
        while start < end:
            temp = s[start]
            t[start] = s[end]
            t[end] = s[start]
            start += 1
            end -= 1
        i += 1
    return ''.join(t)


a = "Let's take LeetCode contest"
ans = reverseWords(0, a)
print(ans)
