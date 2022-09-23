// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem23.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
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
 #include <queue>
class Solution {
public:
    struct pListNodeGreat {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *pResult = nullptr;
        ListNode **ppPrev = &pResult;

        priority_queue<ListNode*, std::vector<ListNode*>, pListNodeGreat> pq;
        for(auto pNode : lists) {
            if(pNode != nullptr) pq.emplace(pNode);
        }

        while(!pq.empty()) {
            auto pNode = pq.top();
            *ppPrev = pNode;
            ppPrev = &pNode->next;
            pq.pop();
            if(pNode->next != nullptr) {
                pq.emplace(pNode->next);
            }
        }

        return pResult;
    }
};
// @lc code=end

