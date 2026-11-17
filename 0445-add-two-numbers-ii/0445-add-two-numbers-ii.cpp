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
    ListNode* reversed(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp != nullptr) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode* temp1 = reversed(l1);
        ListNode* temp2 = reversed(l2);
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int carry = 0;
        while(temp1 != nullptr || temp2 != nullptr || carry != 0) {
            int val1 = (temp1 != nullptr) ? temp1->val : 0;
            int val2 = (temp2 != nullptr) ? temp2->val : 0;
            int value = val1 + val2 + carry;
            carry = value / 10;
            ListNode* newNode = new ListNode(value % 10);
            temp->next = newNode;
            temp = newNode;
            if(temp1 != nullptr)
                temp1 = temp1->next;
            if(temp2 != nullptr)
                temp2 = temp2->next;
        }
        ListNode* ans = dummy->next;
        delete dummy;
        return reversed(ans);
    }
};
