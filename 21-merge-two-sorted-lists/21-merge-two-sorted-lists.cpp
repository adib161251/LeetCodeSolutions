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
        ListNode * newNode = NULL;
        ListNode * sortedList = NULL;
        
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        if(list1->val <= list2->val){
            sortedList = list1;
            list1 = sortedList->next;
        }else{
            sortedList = list2;
            list2 = sortedList->next;
        }
        
        newNode = sortedList;
        
        while(1){
            if(list1 == NULL){
                sortedList->next = list2;
                break;
            }
            
            if(list2 == NULL){
                sortedList->next = list1;
                break;
            }
            
            if(list1->val <= list2->val){
                sortedList->next = list1;
                sortedList = list1;
                list1 = sortedList->next;
            }else{
                sortedList->next = list2;
                sortedList = list2;
                list2 = sortedList->next;
            }
        }
        
        return newNode;
        
        
    }
};