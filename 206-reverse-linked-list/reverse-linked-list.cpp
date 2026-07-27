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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }

        vector<int> temp;

        ListNode* mover = head;
        while(mover != nullptr){
            temp.push_back(mover->val);
            mover = mover->next;
        }

        int n = temp.size();

        ListNode* head1 = new ListNode();
        ListNode* temp1 = head1;
        
        for(int i = n-1; i >= 0; i--){
            temp1->next = new ListNode(temp[i]);
            temp1 = temp1 -> next;
        }

        return head1->next;
    }
};