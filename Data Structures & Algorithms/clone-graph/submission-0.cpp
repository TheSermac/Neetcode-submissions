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
private:
    map<Node*,Node*> oldToNew;
    Node* clone(Node* node, Node* parent = NULL){
        Node* newNode = new Node(node->val);
        oldToNew[node] = newNode;
        for(Node* adyacent : node->neighbors){
            if(oldToNew.find(adyacent) == oldToNew.end()){
                newNode->neighbors.push_back(clone(adyacent, parent));
            }
            else{
                newNode->neighbors.push_back(oldToNew.at(adyacent));
            }
        }
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        else return clone(node);
    }
};
