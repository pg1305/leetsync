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
    ListNode* sortList(ListNode* head) {
        vector<int> toSort;
        ListNode* curr = head;
        while(curr){
            toSort.push_back(curr->val);
            curr = curr->next;
        }
        sort(toSort.begin(), toSort.end());
        ListNode dummy(0);
        ListNode* temp = &dummy;
        for(int i : toSort){
            temp -> next = new ListNode(i);
            temp = temp -> next;
        }
        return dummy.next;
    }
};