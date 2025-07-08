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
ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next; // store next
            curr->next = prev;               // reverse pointer
            prev = curr;                     // move prev forward
            curr = nextNode;                 // move curr forward
        }

        return prev; // new head
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head ;
        ListNode* fast = head;
        while(fast && fast ->next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* second = reverseList(slow);
        ListNode* first = head;
        while(second){
            if(first -> val != second -> val) return false;
            first = first -> next;
            second = second -> next;
        }
return true;
    }
};