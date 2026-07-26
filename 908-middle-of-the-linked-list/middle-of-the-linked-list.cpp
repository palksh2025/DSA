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
    ListNode* middleNode(ListNode* head) {
        int count = 0;

        ListNode* temp = head;

        while(temp){
            count++;
            temp = temp->next;
        }
        
        ListNode* temp1 = head;
        int cnt = 0;
        while(temp1){
            cnt++;
            if(cnt == ((count / 2) + 1)){
                return temp1;
            }

            temp1 = temp1->next;
        }

        return head;
    }
};