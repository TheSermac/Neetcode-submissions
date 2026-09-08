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
        if(head == NULL){
            return NULL;
        }
        map<Node*, Node*> nodes;
        Node* new_head = NULL;
        return copy(nodes, head, new_head);
    }

    Node* copy(map<Node*, Node*>& nodes, Node* head, Node* new_head){
        new_head = new Node(head->val);
        nodes[head] = new_head;
        if(head->next != NULL){
            new_head->next = copy(nodes, head->next, new_head->next);
        }

        if(head->random == NULL){
            new_head->random = NULL;
        }
        else{
            new_head->random = nodes[head->random];
        }

        return new_head;
    }
};
