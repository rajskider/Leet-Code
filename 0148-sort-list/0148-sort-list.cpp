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
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;;
        while(left != nullptr && right != nullptr){
            if (left->val <= right->val){
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        temp->next = (left != nullptr) ? left : right;
        ListNode* todelete = dummy;
        dummy = dummy->next;
        delete todelete;
        return dummy;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* mid = middle(head);
        ListNode* right = mid->next;
        mid->next = nullptr;
        right = sortList(right);
        ListNode* left = sortList(head);
        return merge(left, right);
    }
};