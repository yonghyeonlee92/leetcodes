#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
     ListNode* next;    
     ListNode(int x) : val(x), next(NULL) {};
     ListNode(int x, ListNode* next) : val(x), next(next) {};
};

class Solution {
public:
    vector<int> getMinMaxDistance(vector<int>& local) {
        vector<int> temp;

        int min_distance = 100000;
        int max_distance = local.back() - local[0];
        for (int i = 0; i <= local.size() - 2; i++) {
            if (local[i + 1] - local[i] < min_distance) {
                min_distance = local[i + 1] - local[i];
            }
        }

        temp.push_back(min_distance);
        temp.push_back(max_distance);

        return temp;
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        vector<int> local;

        ListNode* prevp = head;
        if (head->next == nullptr || head->next->next == nullptr) {
            ans = { -1, -1 };
            return ans;
        }
        ListNode* currp = head->next;
        ListNode* nextp = head->next->next;

        int curr_index = 2;
        while (nextp != nullptr) {
            if ((currp->val > prevp->val) && (currp->val > nextp->val)) {
                local.push_back(curr_index);
            }
            else if ((currp->val < prevp->val) && (currp->val < nextp->val)) {
                local.push_back(curr_index);
            }

            prevp = prevp->next;
            currp = currp->next;
            nextp = nextp->next;
            curr_index++;
        }

        if (local.size() == 0 || local.size() == 1) {
            ans = { -1, -1 };
            return ans;
        }

        return getMinMaxDistance(local);
    }
};

int main() {
    Solution solution;

    // example 1
    // ListNode* head = new ListNode(3, new ListNode(1));
     
    // example 2
    ListNode* head = new ListNode(5, new ListNode(3, new ListNode(1, new ListNode(2, new ListNode(5, new ListNode(1, new ListNode(2)))))));

    // example 3
    // ListNode* head = new ListNode(1, new ListNode(3, new ListNode(2, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(2, new ListNode(2, new ListNode(7)))))))));

    vector<int> result = solution.nodesBetweenCriticalPoints(head);

    cout << result[0] << endl;
    cout << result[1] << endl;
    
}