/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       ListNode* dummy = new ListNode(0);
       ListNode* tail = dummy;
       while (l1 && l2) {
           if (l1 -> val < l2 -> val) {
               tail -> next = l1;
               l1 = l1 -> next;
           } else {
               tail -> next = l2;
               l2 = l2 -> next;
           }
           tail = tail -> next;
       }
       if (l1 != NULL) {
           tail -> next = l1;
       } else {
           tail -> next = l2;
       }
       return dummy -> next;
    }
};