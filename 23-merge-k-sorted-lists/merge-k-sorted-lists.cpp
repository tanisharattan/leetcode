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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        if(lists.size()==0) return NULL;
        for(int i=0;i<lists.size();i++) {
            if(lists[i]!=NULL) pq.push({lists[i]->val,lists[i]});
        }
        ListNode* root=NULL;
        ListNode* temproot=root;
        while(!pq.empty()) {
            ListNode* temp=pq.top().second;
            int val=pq.top().first;
            pq.pop();
            if(root==NULL) {
                root=temp;
                temproot=root;
            } else {
                temproot->next=temp;
                temproot=temp;
            }
            ListNode* tempnext=NULL;
            if(temp->next!=NULL) {
                tempnext=temp->next;

            }
            temp->next=NULL;
            if(tempnext!=NULL) pq.push({tempnext->val,tempnext});
        }
        return root;
    }
};