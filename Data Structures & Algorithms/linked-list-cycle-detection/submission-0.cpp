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
    bool hasCycle(ListNode* head) {
        ListNode* firstP = head;
        ListNode* secondP = head;

        while(firstP != NULL && secondP != NULL){
            firstP = firstP->next;
            secondP = secondP->next;

            if(secondP != NULL){
                secondP = secondP->next;
            }
            else{
                return false;
            }

            if(firstP == secondP){
                return true;
            }
        }

        return false;
    }
};
