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
    ListNode* partition(ListNode* head, int x) {
        ListNode *temp, *curr = head, *firstGorE = NULL, *lastGorE = NULL, *prev=head;
        
        if (head == NULL || head->next == NULL)
            return head;
        
        while(curr != NULL)
        {
            if (curr->val < x)
            {
                if (firstGorE != NULL)
                {
                    if ((prev == head) && (prev->val >= x))
					{
						head = curr;
						prev = head;
						lastGorE->next = curr->next;
						head->next = firstGorE;
						curr = lastGorE;
					}
					else if(prev->val < x)
					{
						prev->next = curr;
						lastGorE->next = curr->next;
						curr->next = firstGorE;
						prev = curr;
						curr = lastGorE;
					}					
                }
				else
				{
					prev = curr;
				}
            }
			else
			{
				if (firstGorE == NULL)
				{
					firstGorE = curr;
					lastGorE = curr;
				}
				else
					lastGorE = curr;
			}           
            curr = curr->next;
        }
        return head;
    }
};