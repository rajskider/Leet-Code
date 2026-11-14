/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        Node* dummy = new Node(-1);
        Node* temp1 = head;
        Node* temp2 = dummy;
        while(temp1 != nullptr){
            temp2->next = new Node(temp1->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp2 = dummy->next;
        delete dummy;
        temp1 = head;
        while(temp1 != nullptr){
            Node* orgNext = temp1->next;
            Node* cloneNext = temp2->next;
            temp1->next = temp2;
            temp1 = orgNext;
            temp2->next = temp1;
            temp2 = cloneNext;
        }
        temp1 = head;
        while(temp1 != nullptr){
            temp2 = temp1->next;
            if(temp1->random != nullptr)
                temp2->random = temp1->random->next;
            temp1 = temp1->next->next;
        }
        temp1 = head;
        Node* result = head->next;
        while(temp1 != nullptr){
            temp2 = temp1->next;
            temp1->next = temp2->next;
            temp1 = temp1->next;
            if(temp1 != nullptr)
                temp2->next = temp1->next;
        }
        return result;
    }
};