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
    void dfs(Node* node) {
        // check if copy present or not
        if (mp.find(node) == mp.end()) {
            int val = node->val;
            Node* newNode = new Node(val);
            mp[node] = newNode;
        }
        for (auto it : node->neighbors) {
            if (mp.find(it) == mp.end()) dfs(it);
        }
    }

    void join(Node* node) {
        if (vis[node]) return;
        vis[node] = true;
        vector<Node*> newNeighbors;
        for (auto it : node->neighbors) {
            newNeighbors.push_back(mp[it]);
        }
        mp[node]->neighbors = newNeighbors;
        for (auto it : node->neighbors) {
            join(it);
        }
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        dfs(node);
        join(node);
        return mp[node];
    }
};
