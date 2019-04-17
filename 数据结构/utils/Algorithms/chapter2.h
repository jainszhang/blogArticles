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
template <typename T>
void merge_Sort(vector<T>&arr,int p,int r)
{
    if(arr.empty())
        return ;
//    merge_Array(arr, 0, 2, 5);
    if(p<r)
    {
        int q = int((p+r)/2);
        merge_Sort(arr, p, q);
        merge_Sort(arr, q+1, r);
        merge_Array(arr, p, q, r);
    }
}


#endif /* chapter2_h */
