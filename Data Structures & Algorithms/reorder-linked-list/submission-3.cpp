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
private:
    ListNode * rec(ListNode * root,ListNode * curr)
    {
        if(curr==nullptr)
        return root;

        root=rec(root,curr->next);
        if(root==nullptr)
        return nullptr;

        ListNode * temp=nullptr;
        if(root->next!=curr&&root!=curr)
        {
            temp=root->next;
            root->next=curr;
            curr->next=temp;
        }
        else
        {
            curr->next=nullptr;
        }
        return temp;
    }

public:
    void reorderList(ListNode* head) {
        head=rec(head,head->next);
    }
};
