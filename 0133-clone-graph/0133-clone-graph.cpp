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
    Node* dfs(unordered_map<Node*, Node*>& visited, Node* node) {
        if(visited.count(node)) {
            return visited[node];
        }
        
        Node* clone = new Node(node->val);
        visited[node] = clone;
        for(auto i:node->neighbors) {
            clone->neighbors.push_back(dfs(visited,i));
        }
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) {
            return NULL;
        }
        unordered_map<Node*, Node*> visited;
        
        return dfs(visited,node);
        

    }
};