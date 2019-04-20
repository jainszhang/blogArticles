//
// Created by jains on 2019-04-20.
//

#ifndef HELLOCPP_DEVIDECONQUER_H
#define HELLOCPP_DEVIDECONQUER_H

#include <iostream>
#include <vector>
using namespace std;
//53.寻找最大和的连续子数组
//找跨左右的值
int crossMaxArr(vector<int>&arr,int low,int mid,int high)
{
    int leftSum = INT_MIN,rightSum=INT_MIN;
    int sum=0;
    for (int i=mid; i>=low; i--) {
        sum = sum+arr[i];
        if(sum>leftSum)
        {
            leftSum = sum;
        }
    }
    sum=0;
    for (int i=mid+1; i<=high; i++) {
        sum+=arr[i];
        if(sum>rightSum)
        {
            rightSum=sum;
        }
    }
    return leftSum+rightSum;
}
//递归
int findMaxArr(vector<int>&arr,int low,int high)
{
    int lowSum,highSum,midSum;
    if(low==high)
    {
        return arr[low];
    }
    else//继续分治
    {
        int mid = (low+high)/2;
        lowSum = findMaxArr(arr, low, mid);
        highSum=findMaxArr(arr, mid+1, high);
        midSum = crossMaxArr(arr, low, mid, high);
        if(lowSum>=highSum && lowSum>=midSum)
            return lowSum;
        else if(highSum>=lowSum && highSum>=midSum)
            return highSum;
        else
            return midSum;
    }
}
///最大子数组的和，只返回值
int maxSubArray(vector<int>& nums) {
    return findMaxArr(nums,0,int(nums.size()-1));
}



///169.寻找众数
int majorityElement(vector<int>& nums) {


    return 0;
}
#endif //HELLOCPP_DEVIDECONQUER_H
