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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head -> next) return NULL;
        ListNode* sl = head;
        ListNode* fa = sl ->next ->next;
        while(fa && fa -> next){
            sl = sl ->next;
            fa = fa ->next ->next;
        }
        sl ->next = sl ->next ->next;
        return head;
    }
};