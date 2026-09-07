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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Take edge cases off
        if(head->next == NULL){
            return NULL;
        }

        // Count size
        ListNode* count = head;
        int size = 1;
        while(count->next != NULL){
            size++;
            count = count->next;
        }

        //The element to erase is equal to size - n.
        int pos = size- n;
        ListNode* prev = NULL; ListNode* erase = head;
        //Find the pointers to those elements
        for(int i = 0; i < pos; i++){
            prev = erase;
            erase = erase->next;
        }
        
        if(prev == NULL){
            ListNode* new_head = head->next;
            head->next = NULL;
            delete head;
            return new_head;
        }
        else{
            prev->next = erase->next;
            erase->next = NULL;
            delete erase;
        }

        return head;
    }
};
