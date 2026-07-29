/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        return nullptr;
        Node * temp=head;
        Node * head2=new Node(head->val);
        Node * temp2=head2;

        unordered_map<Node*,Node*> mp;
        mp[head]=head2;

        while(temp->next)
        {
            Node * NewNode=new Node(temp->next->val);
            temp=temp->next;
            mp[temp]=NewNode;
            temp2->next=NewNode;
            temp2=temp2->next;
        }
        temp=head;
        temp2=head2;
        while(temp)
        {
            temp2->random=mp[temp->random];
            temp=temp->next;
            temp2=temp2->next;
        }
        return head2;
    }
};
