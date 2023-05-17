
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
    int pairSum(ListNode* head) {
        vector<int>list;
        while(head != NULL){
            list.push_back(head->val);
            head = head->next;
        }

        int sum1 = 0, sum2 = 0;
        int ans = 0;
        int n = list.size();
        for(int i = 0; i <= n/2; i++){
            sum1 = list[i] + list[n-1-i];
            // sum2 = list[i+1] + list[n-2-i];
            // ans = max(sum1,sum1);
            ans = max(ans, sum1);
        }
        return ans;
    }
};
