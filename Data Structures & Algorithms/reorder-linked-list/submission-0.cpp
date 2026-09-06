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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return;
        }

        //Count list
        int size = 0; ListNode* tmp = head;
        while(tmp != NULL){
            tmp = tmp->next;
            size++;
        }

        //Take half the list
        ListNode* second_head = head;
        for(int i = 0; i < size/2; i++){
            second_head = second_head->next;
        }
        tmp = second_head;
        second_head = second_head->next;
        tmp->next = NULL;

        //Reverse the list
        second_head = reverseList(second_head);

        //Reunite both lists 
        ListNode* first_head = head;
        ListNode* first_next;
        ListNode* second_next;
        while(first_head != NULL && second_head != NULL){
            first_next = first_head->next; 
            second_next = second_head->next;
            first_head->next = second_head; 
            first_head = first_next;
            second_head->next = first_head; 
            second_head = second_next;
        }
    }

    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode* newHead = head;
        if (head->next) {
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;

        return newHead;
    }
};
