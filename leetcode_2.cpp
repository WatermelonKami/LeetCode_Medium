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
        ListNode* l1_curr = l1;
        ListNode* l1_prev;
        ListNode* l2_curr = l2;
        vector<int> output;
        int carry = 0;

        while(l1_curr != NULL || l2_curr != NULL)
        {
            if (l1_curr == NULL)
            {  
                ListNode *newnode;
                newnode = new ListNode(l2_curr->val + carry);
                if(newnode->val >= 10)
                {
                    newnode->val = newnode->val - 10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
                l1_prev->next = newnode;
                l1_prev = l1_prev->next;
                l2_curr = l2_curr->next;
                l1_curr = l1_prev->next;
            }
            else if (l2_curr == NULL)
            {
                l1_curr->val = (l1_curr->val + carry);
                if (l1_curr->val >= 10){
                    l1_curr->val = l1_curr->val - 10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
                l1_prev = l1_curr;
                l1_curr = l1_curr->next;
            }
            else
            {
                int sum = l1_curr->val + l2_curr->val + carry;
                if (sum >= 10)
                {
                    carry = 1;
                    sum = sum -10;
                }
                else
                {
                    carry = 0;
                }
                l1_curr->val = sum;
                l1_prev = l1_curr;
                l2_curr = l2_curr->next;
                l1_curr = l1_curr->next;
            }
        }
        if (carry == 1){
            ListNode *newnode;
            newnode = new ListNode(1);
            l1_prev->next = newnode;
        }
        return l1;
    }
};
