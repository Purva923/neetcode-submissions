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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * temp1=l1;
        ListNode * temp2=l2;
        ListNode * prev1=nullptr;
        ListNode * prev2=nullptr;
        int sum=0;

        int carry=0;
        while(temp1&&temp2)
        {
            sum=temp1->val+temp2->val+carry;
            carry=sum/10;
            sum=sum%10;
            temp1->val=sum;
            prev1=temp1;
            prev2=temp2;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp2)
        {
            prev1->next=temp2;
            sum=temp2->val+carry;
            carry=sum/10;
            sum=sum%10;
            if(carry>0)
            {
                temp2->val=sum;
                prev2=temp2;
                if(temp2->next)
                temp2=temp2->next;
                else
                {
                    ListNode * NewNode=new ListNode(carry);
                    prev2->next=NewNode;
                }
            }
            else 
            break;
        }
        while(temp1&&carry>0)
        {
            sum=temp1->val+carry;
            carry=sum/10;
            sum=sum%10;
            temp1->val=sum;
            prev1=temp1;
            temp1=temp1->next;
        }
        if(carry>0)
        {
            ListNode * NewNode=new ListNode(carry);
            prev1->next=NewNode;
        }
        return l1;
    }
};
