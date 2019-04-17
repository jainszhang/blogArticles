//
//  chapter2.h
//  HelloMac
//
//  Created by jains on 2019/4/17.
//  Copyright © 2019年 jains. All rights reserved.
//

#ifndef chapter2_h
#define chapter2_h

#include<iostream>
using namespace std;
#include<vector>

template <typename T>
void insert_Sort(vector<T>&arr)
{
    if(arr.empty())
        return;
    
    //j=2 to n;key = arr[j]
    //i=j-1 to --- arr[i]>key就一直向前访问
    for (int j=1; j<arr.size(); ++j) {
        T key = arr[j];
        int i=0;
        for (i=j-1; i>=0 && arr[i]>key; --i) {
            arr[i+1] = arr[i];
        }
        arr[++i] = key;
    }
}
template<typename T>
void merge_Array(vector<T>&arr,int p,int q,int r)
{
    //L[p,q],R[q+1,r],哨兵
    //合并L和R到arr中
    vector<T>L(arr.begin()+p,arr.begin()+q+1);
    L.push_back(T(65536));//哨兵
    vector<T>R(arr.begin()+q+1,arr.begin()+r+1);
    R.push_back(T(65536));//哨兵
    int i=0,j=0;//迭代L和R的值
    for (int idx=p; idx<=r; ++idx) {
        if(L[i]<R[j])//不用判断i和j是否到达了最后，因为存在哨兵
        {
            arr[idx] = L[i];
            i++;
        }
        else
        {
            arr[idx] = R[j];
            j++;
        }
    }
}
template<typename T> void practice_3_2(vector<T>&arr,int p,int q,int r);
template <typename T>
void merge_Sort(vector<T>&arr,int p,int r)
{
    if(arr.empty())
        return ;
//    arr.clear();
//    arr = {1,3,5,7,1,2,3,3,4,6,8,10,12};
//    practice_3_1(arr, 0, 3, 9);
    if(p<r)
    {
        int q = int((p+r)/2);
        merge_Sort(arr, p, q);
        merge_Sort(arr, q+1, r);
        practice_3_2(arr, p, q, r);//不使用哨兵，需要判断某一个数组是否遍历完毕
//        merge_Array(arr, p, q, r);//使用哨兵，不用判断哪个数组遍历完毕
    }
}
template<typename T>
void practice_2_2(vector<T>&arr)
{
    //选择排序//
    //从A中找出最小元素与A[1]交换，从A[2..n]中找出最小元素与A[2]交换...
    if(arr.empty())
        return;
    
    for(int i=0;i<arr.size();++i)
    {
        int minIdx=i;
        int j;
        for (j=i+1; j<arr.size(); ++j) {
            if(arr[j]<arr[minIdx])
            {
                minIdx = j;
            }
        }
        T tmp=arr[i];
        arr[i]=arr[minIdx];
        arr[minIdx] = tmp;

    }
}

template <typename T>
void practice_3_2(vector<T>&arr,int p,int q,int r)
{
    //不实用哨兵来写归并排序的merge函数
    if (arr.empty()) {
        return;
    }
    vector<T>L(arr.begin()+p,arr.begin()+q+1);
    vector<T>R(arr.begin()+q+1,arr.begin()+r+1);
    int idx=p;//idx为p
    int i=0,j=0;//计数数组L和R
    while(i<L.size() && j<R.size())//合并直到任何一个数组为空
    {
        if(L[i]<R[j])
        {
            arr[idx++]=L[i];
            i++;
        }
        else
        {
            arr[idx++]=R[j];
            j++;
        }
    }
    while (i<L.size()) {//合并非空数组
        arr[idx++] = L[i++];
    }
    while (j<R.size()) {//合并非空数组
        arr[idx++]=R[j++];
    }
}
template<typename T>
void practice_3_4cur(vector<T>&arr,int n)//把数组a的第n个数插入前n-1个数中，注意前n-1个数已经是排好序的了
{
    int i=n-1;
    T key = arr[n];
    while (i>=0 && key <arr[i]) {
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1]=key;
    return;
}
///不是很懂哦
template<typename T>
void practice_3_4(vector<T>&arr,int n)
{
    //递归方式实现插入排序：排序A[1..n-1]，把A[n]插入到已排好序的A[1..n-1]中
    if(n>0)
    {
        practice_3_4(arr, n-1);//递归
        practice_3_4cur(arr, n);//插入
    }
    else
        return;
}

#endif /* chapter2_h */
