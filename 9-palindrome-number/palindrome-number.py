class Solution(object):
    def isPalindrome(self, x):
        result = 0
        if x < 0:
            return False
        original = x
        while x!= 0:
            digit = x%10
            x = x// 10
            result = result * 10 + digit
        if result == original:
            return True
        else :
            return False

        """
        :type x: int
        :rtype: bool
        """