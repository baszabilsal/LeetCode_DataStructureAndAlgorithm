def lengthOfLongestSubstring(self, s: str) -> int:
    temp = ""
    output = 0
    for i in range(len(s)):
        index = temp.find(s[i])
        if(index >= 0):
            temp = temp[index+1:]
            print(temp)
        temp += s[i]
        output = max(output, len(temp))
    return output


s = "1232453"
print(lengthOfLongestSubstring(0, s))
