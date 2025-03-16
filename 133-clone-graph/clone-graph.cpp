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

    Node* dfs(Node* curr,unordered_map<Node*,Node*>&vis){
        vector<Node*>neighbor;
        Node* clone=new Node(curr->val);
        vis[curr]=clone;
        for(auto it:curr->neighbors){
             if(vis.find(it)!=vis.end()){
                neighbor.push_back(vis[it]);
             }else{
                neighbor.push_back(dfs(it,vis));
             }
        }

        clone->neighbors=neighbor;
        return clone;

    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>vis;
        if(node==NULL) return NULL;
        if(node->neighbors.size()==0)   //if only one node present no neighbors
        {
            Node* clone= new Node(node->val);
            return clone; 
        }

        return dfs(node,vis);
    }
};