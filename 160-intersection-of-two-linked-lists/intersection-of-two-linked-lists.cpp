/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        int count1 = 0;
        int count2 = 0;

        while(temp1){
            count1++;
            temp1 = temp1->next;
        }

        while(temp2){
            count2++;
            temp2 = temp2->next;
        }

        ListNode* temp = nullptr;
        if (count1 < count2){
            int tempc = count2 - count1;
            temp = headB;

            while(tempc){
                temp = temp->next;
                tempc--;
            }

            while(headA){
                if (headA == temp){
                    return headA;
                }
                headA = headA->next;
                temp = temp->next;
            }
        }

        else if(count2 < count1){
            int tempc = count1 - count2;
            temp = headA;

            while(tempc){
                temp = temp->next;
                tempc--;
            }

            while(headB){
                if(headB == temp){
                    return headB;
                }
                headB = headB->next;
                temp = temp->next;
            }
        }
        
        else{
            while(headA){
                if(headA == headB){
                    return headA;
                }
                headA = headA->next;
                headB = headB->next;
            }
        }


        return nullptr;

    }
};