class Solution(object):
    def lengthOfLongestSubstring(self, s):
        l = len(s)
        lis = []
        lengths = []
        flag = 1
        if l == 0:
            return 0
        for i in range(0,len(s)):
            if (s[i] not in lis):
                lis.append(s[i])
            else:
                lengths.append(len(lis))
                index = lis.index(s[i])
                lis = lis[index+1:]
                lis.append(s[i])
                flag = 0
        lengths.append(len(lis))
        sol = len(lis) if flag == 1 else max(lengths)
        return sol
