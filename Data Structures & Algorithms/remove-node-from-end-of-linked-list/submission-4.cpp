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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * back=head;
        ListNode * front=head;

        while(n--)
        front=front->next;


        while(front&&front->next)
        {
            back=back->next;
            front=front->next;
        }
        if(back==head&&!front)
        {
            head=back->next;
            back->next=nullptr;
        }
        else
        {
            ListNode * temp=back->next;
            back->next=temp->next;
            temp->next=nullptr;
        }

        return head ;
    }
};
