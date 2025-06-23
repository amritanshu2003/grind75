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
/*
Use two pointer to traverse through each list
create a list where we will put the element from list1 or list2

traverse through both the list
compare the elements pointed by both the pointers
whichever is smaller insert that element into the new list
increment the corresponding pointers

1- if both the lists are empty return an empty list
2- if list1 is empty return list2
3- if list2 is empty return list1

O(n) time if n>m where n is size of list1 & m is size of list2
O(m+n) space size occupied by the new merged list

*/
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //create a dummy head that will point to merged linked list
        ListNode dummy = ListNode(0);
        //pointer to move with in the merged list
        ListNode* cur = &dummy;
        
        while( list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;//reset the pointer to the next of the list1 or list2 node        
        }
        if(list1 != nullptr){
            cur->next = list1;
            
        } else if( list2 != nullptr){
            cur->next = list2;
        }
        return dummy.next;
    }
};
