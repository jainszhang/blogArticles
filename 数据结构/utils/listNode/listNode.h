//
//  listNode.h
//  HelloMac
//
//  Created by jains on 2019/4/12.
//  Copyright © 2019年 jains. All rights reserved.
//

#ifndef listNode_h
#define listNode_h

#include <iostream>
#include<stack>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x=0) :val(x), next(nullptr) {}
};
#endif /* listNode_h */
