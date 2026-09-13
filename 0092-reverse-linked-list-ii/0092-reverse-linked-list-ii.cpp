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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right)
            return head;
        ListNode* temp = head;
        ListNode* before = nullptr;
        int count = 1;
        while (count < left) {
            before = temp;
            temp = temp->next;
            count++;
        }
        ListNode* newHead = temp;
        ListNode* prev = nullptr;
        while (count <= right) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            count++;
        }
        newHead->next = temp;
        if (before == nullptr) head = prev;
        else before->next = prev;
        return head;
    }
};