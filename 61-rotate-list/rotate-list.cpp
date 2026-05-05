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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        if(k == 0) return head;
        ListNode* curr = head;
        ListNode* first = head;
        int n = 1;
        while(curr -> next){
            curr = curr -> next;
            n++;
        }
        curr -> next = first;
        int pos = n + (-k)%n;
        ListNode* res = head;
        ListNode* prev;
        for(int i = 0; i < pos; i++){
            prev = res;
            res = res -> next;
        }
        prev -> next = NULL;
        return res;
    }
};