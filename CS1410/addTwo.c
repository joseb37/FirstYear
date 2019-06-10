#include <math.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* curr1 = l1;
    struct ListNode* curr2 = l2;
    int sum = 0;
    int longest = 1; //if longest is 1 then l1 is longester
    if(l1->val == 0){
        return l2;
    }
    if(l1->val == 0){
        return l2;
   }else if(l2->val == 0){
       return l1;
   }
    for(int i = 0;curr1 != NULL || curr2!=NULL;i++){
        if(curr1 != NULL && curr2 !=NULL){
            sum += ( pow(10,i) ) * (curr1->val + curr2->val) ;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }else if(curr1 == NULL){
            sum += ( pow(10,i) ) *(curr2->val);
            curr2 = curr2->next;
        }else if(curr2 == NULL){
            sum += ( pow(10,i) ) *(curr1->val);
            curr1 = curr1->next;
        }
    }
    curr1 = l1;
    curr2 = l2;
    while(sum != 0){
       if(longest){
            if(curr1!= NULL){
                curr1->val = sum%10;
                sum = sum/10;
                curr1 = curr1->next;
            }
        }else{
           if(curr2!= NULL){
                curr1->val = sum%10;
                sum = sum/10;
                curr2 = curr1->next;
            }
       }
    }
    if(longest){
        return l1;
    }
    return l2;
}