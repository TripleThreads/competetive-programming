class Solution:
    def addTwoNumbers(self, first_linked, second_linked):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """

        remainder = 0
        head = node = ListNode(None)

        while first_linked or second_linked:

            l1_val = 0 if not first_linked  else first_linked.val
            l2_val = 0 if not second_linked  else second_linked.val
            _sum =l1_val + l2_val + remainder

            temp = ListNode(_sum % 10 )
            remainder = _sum // 10

            node.next = temp
            node = temp

            first_linked = first_linked.next if first_linked else None
            second_linked = second_linked.next if second_linked else None

            if remainder != 0 and not first_linked and not second_linked:
                node.next = ListNode(remainder)

        return head.next