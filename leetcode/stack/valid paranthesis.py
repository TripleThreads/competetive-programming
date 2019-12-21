# //
# // Created by segni on 21/12/2019.
# //

class Solution:

    def __init__(self):
        self.stack = []

    def isValid(self, s: str) -> bool:

        dictionary = {')': '(', '}': '{', ']': '['}

        for i in s:

            if len(self.stack) > 0 and dictionary.get(i, None) == self.stack[-1]:

                self.stack.pop()

            else:
                self.stack.append(i)

        return self.stack == []
