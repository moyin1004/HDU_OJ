/// @file    2.AddTwoNumbers.cc
/// @author  moyin(moyin1004@163.com)
/// @data    2021-01-15 21:20:59

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *pre = p1;
        int carry = 0;
        while (p1 && p2) {
            p1->val += p2->val + carry;
            carry = p1->val / 10;
            p1->val %= 10;
            pre = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (!pre->next) pre->next = p2;   // 处理剩余结点
        while (carry) {
            if (!pre->next && carry) {
                pre->next = new ListNode(carry);
                break;
            }
            pre = pre->next;
            pre->val = pre->val + carry;
            carry = pre->val / 10;
            pre->val %= 10;
        }
        return l1;
    }
};

ListNode* read(int n) {
    ListNode *l = new ListNode();
    cin >> l->val;
    ListNode *node = l;
    for (int i = 1; i < n; ++i) {
        node->next = new ListNode();
        cin >> node->next->val;
        node = node->next;
    }
    return l;
}

void deleteList(ListNode *l) {
    if (l) {
        deleteList(l->next);
        delete l;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    ListNode *l1 = read(n);
    ListNode *l2 = read(m);
    Solution s;
    ListNode *ans = s.addTwoNumbers(l1, l2);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    deleteList(l1);
    deleteList(l2);
    return 0;
}