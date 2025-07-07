// 合并K个升序链表
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){};
    ListNode(int x):val(x),next(nullptr){};
    ListNode(int x,ListNode *next):val(x),next(next){};
};

class Solution{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return nullptr;
        if(n==1) return lists[0];

        ListNode *head = nullptr;
        ListNode *cur = nullptr;

        int minIndex = 0;
        while(head==nullptr && minIndex<n){
            head = lists[minIndex++];
        }

        if(minIndex==n) return head;

        minIndex--;
        for(int i=minIndex+1;i<n;i++){
            if(lists[i]!=nullptr && lists[minIndex]->val>lists[i]->val){
                minIndex = i;
            }
        }
        head = lists[minIndex];
        lists[minIndex] = lists[minIndex]->next;
        cur = head;

        ListNode *next = nullptr;
        while(1){
            minIndex = 0;
            next = nullptr;
            
            while(next==nullptr && minIndex<n){
                next = lists[minIndex++];
            }

            if(next==nullptr){
                cur->next = next;
                break;
            }

            minIndex--;
            for(int i=minIndex+1;i<n;i++){
                if(lists[i]!=nullptr && lists[minIndex]->val>lists[i]->val){
                    minIndex = i;
                }
            }
            next = lists[minIndex];

            cur->next = next;
            cur = cur->next;
            lists[minIndex] = lists[minIndex]->next;
        }

        return head;
    }
};