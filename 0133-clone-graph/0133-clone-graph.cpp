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
    void dfs(Node* node, Node* copy, vector<Node*> &vis)
    {
        vis[copy->val] = copy;
        for(auto a : node->neighbors)
        {
            if(vis[a->val] == NULL)
            {
                Node* newNode = new Node(a->val);
                copy->neighbors.push_back(newNode);
                dfs(a, newNode, vis);
            }
            else copy->neighbors.push_back(vis[a->val]);
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
        vector<Node*> vis(101, NULL);
        Node* copy = new Node(node->val);
        dfs(node, copy, vis);
        
        return copy;
    }
};