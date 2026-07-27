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
    unordered_map<Node*, Node*> mp;
    unordered_map<Node*, bool> vis;
    Node* dfs(Node* node) {
        // check if copy present or not
        if (mp.find(node) == mp.end()) {
            int val = node->val;
            Node* newNode = new Node(val);
            mp[node] = newNode;
        } else
            return mp[node];
        vector<Node*> nn;
        for (auto it : node->neighbors) {
            nn.push_back(dfs(it));
        }
        mp[node]->neighbors = nn;
        return mp[node];
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        return dfs(node);
    }
};
