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
    ListNode* reversed(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while(temp != nullptr){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = reversed(head);
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* iter = dummy;
        while(temp != nullptr || carry != 0){
            int val = ((temp != nullptr) ? 2 * temp->val : 0) + carry;
            carry = val / 10;
            iter->next = new ListNode(val % 10);
            iter = iter->next;
            if(temp != nullptr)
                temp = temp->next; 
        }
        ListNode* result = dummy->next;
        delete dummy;
        return reversed(result);
    }
};