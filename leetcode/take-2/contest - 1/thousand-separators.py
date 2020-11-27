class Solution:
    def thousandSeparator(self, n: int) -> str:
        res = ""
        place = 3
        while n > 0:
            res += str(n %10)
            n = n //10
            if len(res) == place and n>0:
                res+="."
                place += 3 + 1
                
        res = res[::-1]
        if res == "":
            return "0"
        return res
                
        
