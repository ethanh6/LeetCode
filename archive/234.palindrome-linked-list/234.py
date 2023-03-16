from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:

        # ptr to iterate forward
        self.front = head
        
        # check if the linked-list with starting at cur is a palindrome
        def recur(cur):
            if cur:
                if not recur(cur.next):
                    return False

                # cur.val at this point is the last node

                # if front and cur don't equal, return False
                if self.front.val != cur.val:
                    return False

                # advance front pointers
                self.front = self.front.next
            return True
        return recur(head)


if __name__ == "__main__":
    sol = Solution()
    head = ListNode(0, ListNode(1, ListNode(2, ListNode(3, None))))
    myans = sol.isPalindrome(head)
    print(myans)

    head = ListNode(0, ListNode(1, ListNode(1, ListNode(0, None))))
    myans = sol.isPalindrome(head)
    print(myans)

