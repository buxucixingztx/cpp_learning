// 力扣第2题，两数相加
/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){};
};

class Solution_00{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode l(0);
        ListNode * first = &l;
        ListNode * lp = &l;
        int carry = 0;
        while (l1->val != NULL || l2->val != NULL){
            int l1_v = 0;
            int l2_v = 0;
            if (l1->val != NULL)
                l1_v = l1->val;
            if (l2->val != NULL)
                l2_v = l2->val;
            int val = (lp->val + l1->val + l2->val) % 10;
            carry = (lp->val + l1->val +l2->val) / 10;
            lp->val = val;
            if (l1->next == NULL && l2->next == NULL)
                break;
            l1 = l1->next;
            l2 = l2->next;
            lp->next = new ListNode(carry);
            lp = lp->next;
        };
        if (carry != 0){
            lp->next = new ListNode(carry); 
            lp = lp->next;
        }
        return first;
    }
};


int main()
{
    // ListNode nn(0);
    // int carry = 1;
    ListNode nn(1);
    cout << "nn->val: " << nn.val<< endl;

    cin.get();
    return 0;
}
