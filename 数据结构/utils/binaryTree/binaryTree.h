//
//  binaryTree.h
//  HelloMac
//
//  Created by jains on 2019/4/12.
//  Copyright © 2019年 jains. All rights reserved.
//

#ifndef binaryTree_h
#define binaryTree_h
#include <iostream>
using namespace std;
//1.二叉树节点和创建
//2.二叉树前序、中序、后序遍历
//3.层次遍历
//
//1.1 二叉树节点定义
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
    val(x), left(NULL), right(NULL) {
    }
};

#endif /* binaryTree_h */
