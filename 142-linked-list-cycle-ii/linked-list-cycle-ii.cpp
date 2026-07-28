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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr){
            return nullptr;
        }
        if(head->next == nullptr){
            return nullptr;
        }

        vector<ListNode*> address;
        ListNode* temp = head;

        while(temp){
            if (find(address.begin(), address.end(), temp) == address.end()){
                address.push_back(temp);
            }
            else{
                return temp;
            }
            temp = temp->next;
        }

        return nullptr;
    }
};