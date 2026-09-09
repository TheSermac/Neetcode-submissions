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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1; ListNode* p2 = l2; 
        ListNode* new_head = NULL; 
        ListNode* new_p = NULL;

        while(p1 != NULL || p2 != NULL){
            int result = 0;
            //Calcular la suma a ese nodo
            if(p1 != NULL && p2 != NULL){
                result = p1->val + p2->val;
            }
            else if(p1 != NULL){
                result = p1->val;
            }
            else if(p2 != NULL){
                result = p2->val;
            }

            //Añadir nodo para ListNode->next;
            if(new_head == NULL){
                new_head = new ListNode(result);
                new_p = new_head;
            }
            else{
                new_p->next = new ListNode(result);
                new_p = new_p->next;
            }

            //Calcular el resultado
            if(new_p->val >= 10){
                if(p1 != NULL && p1->next != NULL){
                    p1->next->val += new_p->val/10;
                }
                else if(p2 != NULL && p2->next != NULL){
                    p2->next->val += new_p->val/10;
                }
                else{
                    new_p->next = new ListNode(new_p->val/10);
                }
                new_p->val %= 10;
            }
             
            if(p1 != NULL){
                p1 = p1->next;
            }
            if(p2 != NULL){
                p2 = p2->next;
            }
        }

        return new_head;
    }
};
