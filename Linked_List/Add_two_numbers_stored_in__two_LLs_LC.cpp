#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode();
        ListNode* l3_temp = l3;
        int carry {0};
        ListNode* l1_temp = l1;
        ListNode* l2_temp = l2;
        while(l1_temp != NULL && l2_temp != NULL) {
            int sum {0};
            if(carry != 0) {
                sum = l1_temp->val + l2_temp->val + carry;
                if(sum >= 10) {
                    int ans = sum % 10;
                    l3_temp->val = ans;
                    ListNode* nextNode = new ListNode();
                    l3_temp->next = nextNode;
                    l3_temp = nextNode;
                    nextNode = NULL;
                    
                    carry = 1;
                }
                else {
                    int ans = sum;
                    l3_temp->val = ans;
                    ListNode* nextNode = new ListNode();
                    l3_temp->next = nextNode;
                    l3_temp = nextNode;
                    nextNode = NULL;
                    
                    carry = 0;
                }
            }
            else {
                sum = l1_temp->val + l2_temp->val;
                if(sum >= 10) {
                    int ans = sum % 10;
                    l3_temp->val = ans;
                    ListNode* nextNode = new ListNode();
                    l3_temp->next = nextNode;
                    l3_temp = nextNode;
                    nextNode = NULL;
                    
                    carry = 1;
                }
                else {
                    int ans = sum;
                    l3_temp->val = ans;
                    ListNode* nextNode = new ListNode();
                    l3_temp->next = nextNode;
                    l3_temp = nextNode;
                    nextNode = NULL;
                    
                    carry = 0;
                }
            }
            l1_temp = l1_temp->next;
            l2_temp = l2_temp->next;
        }
        
        
        if(l1_temp != NULL) {
            while(l1_temp != NULL) {
                if(carry != 0) {
                    int sum = l1_temp->val + carry;
                    if(sum >= 10) {
                        int ans = sum % 10;
                        l3_temp->val = ans;
                        ListNode* nextNode = new ListNode();
                        l3_temp->next = nextNode;
                        l3_temp = nextNode;
                        nextNode = NULL;
                        
                        carry = 1;
                    }
                    else {
                        int ans = sum;
                        l3_temp->val = ans;
                        ListNode* nextNode = new ListNode();
                        l3_temp->next = nextNode;
                        l3_temp = nextNode;
                        nextNode = NULL;
                        
                        carry = 0;
                    }
                }
                else {
                    int sum = l1_temp->val;
                    if(sum >= 10) {
                        int ans = sum % 10;
                        l3_temp->val = ans;
                        ListNode* nextNode = new ListNode();
                        l3_temp->next = nextNode;
                        l3_temp = nextNode;
                        nextNode = NULL;
                        
                        carry = 1;
                    }
                    else {
                        int ans = sum;
                        l3_temp->val = ans;
                        ListNode* nextNode = new ListNode();
                        l3_temp->next = nextNode;
                        l3_temp = nextNode;
                        nextNode = NULL;
                        
                        carry = 0;
                    }
                }
                l1_temp = l1_temp->next;
            }
        }
        else if(l2_temp != NULL) {
            while(l2_temp != NULL) {
                //cout << l1_temp->val << " ";
                if(carry != 0) {
                    int sum = l2_temp->val + carry;
                    if(sum >= 10) {
                        int ans = sum % 10;
                        l3_temp->val = ans;
                        ListNode* nextNode = new ListNode();
                        l3_temp->next = nextNode;
                        l3_temp = nextNode;
                        nextNode = NULL;
                        
                        carry = 1;
                    }
                    else {
                        int ans = sum;
                        l3_temp->val = ans;
                        ListNode* nextNode = new ListNode();
                        l3_temp->next = nextNode;
                        l3_temp = nextNode;
                        nextNode = NULL;
                        
                        carry = 0;
                    }
                }
                else {
                    int sum = l2_temp->val;
                    if(sum >= 10) {
                        int ans = sum % 10;
                        l3_temp->val = ans;
                        ListNode* nextNode = new ListNode();
                        l3_temp->next = nextNode;
                        l3_temp = nextNode;
                        nextNode = NULL;
                        
                        carry = 1;
                    }
                    else {
                        int ans = sum;
                        l3_temp->val = ans;
                        ListNode* nextNode = new ListNode();
                        l3_temp->next = nextNode;
                        l3_temp = nextNode;
                        nextNode = NULL;
                        
                        carry = 0;
                    }
                }
                l2_temp = l2_temp->next;
            }
        }
        if(carry == 1) {
            l3_temp->val = 1;
        }
        else {
            ListNode* l3_temp2 = l3;
            while(l3_temp2->next != l3_temp) {
                l3_temp2 = l3_temp2->next;
            }
            l3_temp2->next = NULL;
            delete l3_temp;
        }
        return l3;
    }
};

int main() {
    ListNode l1_3(2);
    ListNode l1_2(9, &l1_3);
    ListNode l1_1(9, &l1_2);
    ListNode* l1_temp = &l1_1;
    while(l1_temp != NULL) {
        cout << l1_temp->val << " ";
        l1_temp = l1_temp->next;
    }
    cout << endl;
    ListNode l2_3(2);
    ListNode l2_2(9, &l2_3);
    ListNode l2_1(9, &l2_2);
    ListNode* l2_temp = &l2_1;
    while(l2_temp != NULL) {
        cout << l2_temp->val << " ";
        l2_temp = l2_temp->next;
    }
    cout << endl;
    Solution s;
    ListNode* ans = s.addTwoNumbers(&l1_1, &l2_1);
    ListNode* ans_temp = ans;
    while(ans_temp != NULL) {
        cout << ans_temp->val << " ";
        ans_temp = ans_temp->next;
    }
    cout << endl;
    return 0;
}