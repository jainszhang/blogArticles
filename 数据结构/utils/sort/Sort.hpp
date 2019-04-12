//
//  Sort.hpp
//  HelloMac
//
//  Created by jains on 2019/4/12.
//  Copyright © 2019年 jains. All rights reserved.
//

#ifndef Sort_hpp
#define Sort_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int>&arr);//冒泡
void select_Sort(vector<int>&arr);//选择
void insert_Sort(vector<int>&arr);//插入
void shell_Sort(vector<int>&arr);//希尔
void quick_Sort(vector<int> &arr,int left,int right);//快拍
void merge_Sort(vector<int>&arr,int first,int last);//归并
void count_Sort(vector<int> &arr);//计数
void bucket_Sort(vector<int>&arr);//桶排
void redix_Sort(vector<int>&arr);//基数
#endif /* Sort_hpp */
