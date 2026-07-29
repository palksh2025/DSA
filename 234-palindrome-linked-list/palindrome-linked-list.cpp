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
    bool isPalindrome(ListNode* head) {
        int count = 0;

        ListNode* temp1 = head;

        ListNode* end;
        while(temp1){
            count++;

            if(temp1->next == nullptr){
                end = temp1;
            }

            temp1 = temp1->next;
        }

        if(count == 1){
            return true;
        }
        
        if(count == 2){
            if(head->val == head->next->val){
                return true;
            }
            return false;
        }

        int count2 = 1;
        temp1 = head;

        while(count2 != (count/2 + 1)){
            temp1 = temp1->next;
            count2++;    
        }

        ListNode* prev = temp1;
        ListNode* curr = temp1->next;
        ListNode* next = temp1->next->next;

        temp1->next = nullptr;

        while(curr != nullptr){
            curr->next = prev;
            prev = curr;
            curr = next;

            if(curr == nullptr){
                break;
            }
            next = curr->next;
        }

        ListNode* start = head;


        while(start->next != end && start != end){
            if(start->val != end->val){
                return false;
            }
            start = start->next;
            end = end->next;
        }

        if(start->next == end){
            if (start->val == end->val){
                return true;
            }
            return false;
        }

        return true;   
    }
};