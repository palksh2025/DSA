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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr){
            return nullptr;
        }
        else if(head->next == nullptr){
            return head;
        }


        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* temp = even;
        ListNode* temp2;

        while(odd->next != nullptr && even->next != nullptr){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        ListNode* test = head;
        while(test){
            cout<<test->val;
            test = test->next;
        }

        odd->next = temp;

        return head;
    }
};