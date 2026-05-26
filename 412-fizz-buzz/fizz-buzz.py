class Solution(object):
    def fizzBuzz(self, n):
        s = "Fizz"
        p = "Buzz"
        sp = "FizzBuzz"
        ans = []
        for i in range(1,n+1):
            if i%3 == 0 and i%5 == 0:
                ans.append("FizzBuzz")
            elif i%3 == 0:
                ans.append("Fizz") ## can i do append.(sp) - yes i can
            elif i%5 == 0:
                ans.append("Buzz")
            else:
                ans.append(str(i)) ## converts numerical i into string i
        return ans
        """
        :type n: int
        :rtype: List[str]
        """
        