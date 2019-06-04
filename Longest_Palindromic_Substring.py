class Solution(object):
    def longestPalindrome(self, s):
        l = len(s)
        table = [[0 for x in range(l)] for y in range(l)]
        
        maxlen = 1
        for i in range(0,l):
            table[i][i] = True
        start = 0
        
        for i in range(0, l-1):
            if (s[i] == s[i+1]):
                table[i][i+1] = True
                start = i
                maxlen = 2
        
        k = 3
        while(k<=l):
            i = 0
            while(i < l-k+1):
                j = i+k-1
                
                if(table[i+1][j-1] and s[i]==s[j]):
                    table[i][j] = True
                    if(k>maxlen):
                        start = i
                        maxlen = k
                i = i+1
            k = k+1
        sub = s[start:start+maxlen]
        return str(sub)
