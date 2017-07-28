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
    ListNode* swapPairs(ListNode* head) {
       ListNode *a, *b, *c;
        if (head == NULL || head->next == NULL) return head;
        a = head;
        b = head->next;
        
        head = b;
        a->next = b->next;
        head->next = a;
        c = a;
        
        while ((c->next != NULL) && (c->next->next != NULL)
        {
            a = a->next;
            b = a->next;
            c->next = b;
            a->next = b->next;
            b->next = a;
            c = a;
        }
        return head;
    }
};