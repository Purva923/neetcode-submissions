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
    void reorderList(ListNode* head) {
        ListNode * prev=head;

        while(prev->next&&prev->next->next)
        {
            ListNode * temp=prev;
            while(temp->next&&temp->next->next)
            {
                temp=temp->next;
            }
            temp->next->next=prev->next;
            prev->next=temp->next;
            temp->next=nullptr;

            prev=prev->next->next;
        }
    }
};
