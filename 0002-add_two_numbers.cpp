/* 2. Add Two Numbers
 * Link: https://leetcode.com/problems/add-two-numbers/description/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // because the length of the linked list is pretty big, we can't just add the two numbers
        // we will have to do "string calculator"

        // the fact that the list is in reverse order really helps us here
        // because we can just go down the line and if the sum is over 9
        // then we just add 1 to the next element in the linked list

        ListNode* l3 = new ListNode;

        ListNode* l3_head = l3;

        ListNode* iter_l1 = l1;
        ListNode* iter_l2 = l2;

        int sum = 0;

        int int_l1 = 0;
        int int_l2 = 0;

        int carry = 0;

        while (iter_l1 != nullptr || iter_l2 != nullptr)
        {
            // if we are at a nullptr in the list, then set the node's value to zero
            if (iter_l1 == nullptr)
            {
                int_l1 = 0;
            }
            else
            {
                int_l1 = iter_l1->val;
                // std::cout<< int_l1 <<std::endl;
                iter_l1 = iter_l1->next;
            }

            if (iter_l2 == nullptr)
            {
                int_l2 = 0;
            }
            else
            {
                int_l2 = iter_l2->val;
                // std::cout<< int_l2 <<std::endl;
                iter_l2 = iter_l2->next;
            }

            sum = int_l1 + int_l2;

            if (carry)
            {
                ++sum;
                --carry;
            }

            if (sum > 9)
            {
                ++carry;
            }

            // now add the sum (or sum mod 10) to the l3 list
            l3->val = sum % 10;

            // if both of the iterators are nullptr, then we don't want to add another l3; it will fail the loop condition
            // and we will have an extra random zero at the end

            if (iter_l1 != nullptr || iter_l2 != nullptr || carry)
            {
                l3->next = new ListNode;
                l3 = l3->next;
            }
            
        }
        
        // final check to see if carry is a 1; if it is, then we need to add one to the final l3 value
        if (carry)
            l3->val += 1;

        return l3_head;
    }
};
