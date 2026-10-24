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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* temp = head;
        ListNode* prev = dummy;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->val == temp->next->val) {
                int dup = temp->val;
                while (temp != nullptr && temp->val == dup) {
                    ListNode* todelete = temp;
                    temp = temp->next;
                    delete todelete;
                }
                prev->next = temp;
            } 
            else {
                prev = temp;
                temp = temp->next;
            }
        }
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
