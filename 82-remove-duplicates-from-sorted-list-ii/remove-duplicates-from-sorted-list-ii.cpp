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
        if(!head) return NULL;
        ListNode* dummy = new ListNode(0,head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        while(curr){
            if(curr -> next && curr -> val == curr->next->val){
                while (curr->next && curr->val == curr->next->val) {
                    ListNode* temp = curr;
                    curr = curr->next;
                    delete temp; 
                }
                ListNode* temp = curr;
                curr = curr -> next;
                delete temp;
                prev -> next = curr;
            }else{
                prev = curr;
                curr = curr -> next;
            }
        }
        ListNode* res = dummy -> next;
        delete dummy;
        return res;
    }
};