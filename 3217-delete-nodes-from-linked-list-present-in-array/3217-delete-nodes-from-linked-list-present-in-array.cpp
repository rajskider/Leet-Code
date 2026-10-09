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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, bool> mp;
        for(int i : nums)
            mp[i] = true;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* temp = head;
        ListNode* prev = dummy;
        while(temp != nullptr){
            if(mp.find(temp->val) != mp.end()){
                prev->next = temp->next;
                temp = prev->next;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};