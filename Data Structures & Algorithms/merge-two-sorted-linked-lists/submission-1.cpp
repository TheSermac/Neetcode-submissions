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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        ListNode* newList = new ListNode;
        ListNode* currList = newList;

        //Head of new list
        if(curr1->val <= curr2->val){
            newList->val = curr1->val;     
            curr1 = curr1->next;
        }
        else{
            newList->val = curr2->val;
            curr2 = curr2->next;
        }

        //Loop
        while(curr1 != NULL && curr2 != NULL){
            if(curr1->val <= curr2->val){
                currList->next = curr1;     
                curr1 = curr1->next;
            }
            else{
                currList->next = curr2;
                curr2 = curr2->next;
            }
            currList = currList->next;
        }

        //Apply rest of the list
        if(curr1 != NULL){
            currList->next = curr1;
        }
        if(curr2 != NULL){
            currList->next = curr2;
        }

        return newList;
    }
};
