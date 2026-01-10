/*

problem URL : https://leetcode.com/problems/merge-two-sorted-lists/

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

struct ListNode* make_list(int *arr, int n) {
    if (n == 0) return NULL;
    struct ListNode *head = malloc(sizeof(struct ListNode) * n);
    for (int i = 0; i < n; i++) {
        head[i].val = arr[i];
        head[i].next = (i < n-1) ? &head[i+1] : NULL;
    }
    return head;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    int node_arr[100] = {-101};
    int node_idx = 0;
    int node_len = 0;

    struct ListNode *curr1 = list1;
    while (curr1) {
        node_arr[node_idx++] = curr1->val;
        curr1 = curr1->next;
        node_len++;
    }

    struct ListNode *curr2 = list2;
    while (curr2) {
        node_arr[node_idx++] = curr2->val;
        curr2 = curr2->next;
        node_len++;
    }

    qsort(node_arr, node_len, sizeof(int), cmp);

    return make_list(node_arr, node_len);
}

int main(void) {
    struct ListNode* result;

    // example 1
    int list_arr1[3] = {1, 2, 4};
    struct ListNode* list1 = make_list(list_arr1, 3);

    int list_arr2[3] = {1, 3, 4};
    struct ListNode* list2 = make_list(list_arr2, 3);

    result = mergeTwoLists(list1, list2);
    while (result) {
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\n");

    return 0;
}

