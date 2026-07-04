/*
------------------------------------------------------------
Problem: Add Two Numbers
Platform: LeetCode

Approach:
- Traverse both linked lists simultaneously.
- At each step:
    - Add the current digits along with any carry.
    - Create a new node containing (sum % 10).
    - Update carry as (sum / 10).
- Continue until both lists are exhausted and carry becomes 0.

Time Complexity: O(max(m, n))
Space Complexity: O(max(m, n))
------------------------------------------------------------
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node simplifies insertion logic
        ListNode dummy(0);
        ListNode* tail = &dummy;

        int carry = 0;

        while (l1 || l2 || carry) {

            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }

        return dummy.next;
    }
};