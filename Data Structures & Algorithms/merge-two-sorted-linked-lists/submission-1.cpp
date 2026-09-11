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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *  curr1=list1;
        ListNode *  curr2=list2;

        if(!curr1&&!curr2)
        return nullptr;
        else if(!curr1)
        return curr2;
        else if(!curr2)
        return curr1;

        ListNode *head;
        if(curr1->val>=curr2->val)
        {
            head=curr2;
            curr2=curr2->next;
        }
        else
        {
            head=curr1;
            curr1=curr1->next;
        }
        ListNode * temp=head;
        while(curr1&&curr2)
        {
            if(curr1->val>=curr2->val)
            {
                temp->next=curr2;
                curr2=curr2->next;
            }
            else
            {
                temp->next=curr1;
                curr1=curr1->next;
            }
            temp=temp->next;
        }
        if(curr1)
        temp->next=curr1;
        else
        temp->next=curr2;

        return head ;
    }
};
