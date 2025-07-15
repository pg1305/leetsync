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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-5001, head);
        ListNode* ptr1 = head;
        while (ptr1->next) {
            if (ptr1->val < ptr1->next->val) {
                ptr1 = ptr1->next;
                continue;
            }

            ListNode* ptr2 = &dummy;
            while (ptr2->next->val < ptr1->next->val) {
                ptr2 = ptr2->next;
            }

            ListNode* temp = ptr1->next;
            ptr1->next = temp->next;
            temp->next = ptr2->next;
            ptr2->next = temp;
        }
        return dummy.next;
    }
};