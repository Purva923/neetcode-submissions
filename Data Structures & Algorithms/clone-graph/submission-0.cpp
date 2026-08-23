/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node1) {
        if (node1==nullptr)
        return nullptr;

        Node *node2=new Node(node1->val);
        
        /*for(auto ng:node1.neighbours)
        {
            Node *temp=new Node(ng.val)
            node2.neighbours.push_back(temp);
        }*/
        
        unordered_map <Node*,Node*> visited;
        visited[node1]=node2;

        queue <Node*> q1;
        q1.push(node1);

        queue <Node*> q2;
        q2.push(node2);

        while(!q1.empty())
        {
            Node *temp1=q1.front();
            q1.pop();
            Node *temp2=q2.front();
            q2.pop();

            for(auto ng:temp1->neighbors)
            {
                if(visited.find(ng)==visited.end())
                {
                    Node * temp=new Node(ng->val);
                    q1.push(ng);
                    q2.push(temp);
                    visited[ng]=temp;
                }
                temp2->neighbors.push_back(visited[ng]);
            }
        }
        return node2;
    }
};
