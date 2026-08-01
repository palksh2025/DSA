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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr){
            return nullptr;
        }
        else if(head->next->next == nullptr){
            head->next = nullptr;
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next;
        
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        cout<<slow->val<<endl;

        ListNode* temp = slow->next;

        slow->next = temp->next;

        delete temp;

        return head;
    }
};