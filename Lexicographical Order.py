#code to find the lexicographical order of a number given number n from 1 to n

class Solution(object):
    def lexicographical(self, n):
        result = []
        stack = []
        x = 1
        while (x<=n):  #first finish off the integers with 1 as the starting digit
            stack.append(x)
            result.append(x)
            x *= 10

        while(stack):
            y = stack.pop()
            if(y%10 == 9): continue
            y += 1        #start incrementing the digit and continue the same
            while (y<=n):
                stack.append(y)
                result.append(y)
                y *= 10
        return result
