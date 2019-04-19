//
//  strOperate.h
//  HelloMac
//
//  Created by jains on 2019/4/18.
//  Copyright © 2019年 jains. All rights reserved.
//

#ifndef strOperate_h
#define strOperate_h
#include<string>
#include<vector>
#include<cmath>

#include <iostream>
using namespace std;

void Split(const std::string &strTarget, char ch, std::vector<std::string> &vctStr)
{
    if(strTarget.empty())
        return;
    int i=0;
    string tmp="";
    int cnt=0;
    while(i<strTarget.size())  {
        if(ch!=strTarget.at(i))
        {
            tmp.append(1, strTarget.at(i));
            //            tmp.insert(tmp.end()-1,strTarget.at(i));//添加到tmp中
        }
        else
        {
            cnt++;
            tmp=tmp+'\0';
            //            tmp.append('\0',1);
            //            cout<<tmp<<endl;
            vctStr.push_back(tmp);
            tmp.clear();
        }
        i++;
    }
    if(cnt==0)
        vctStr.push_back(strTarget);
    return;
}
//6.Z字型字符串匹配
string convert(string s, int numRows) {
    string res="";
    if (numRows==1) {
        return s;
    }
    vector<string> vres(numRows,"");
    int i=0;
    int cnt = numRows;
    while (s[i]!='\0') {
        //向下访问
        cnt=0;
        while (cnt<numRows && s[i]!='\0') {
            vres[cnt]+=s[i];
            cnt++;
            i++;
        }
        //需要向上访问2个
        cnt=0;
        while (cnt<numRows-2 && s[i]!='\0') {
            vres[numRows-2-cnt]+=s[i];
            cnt++;
            i++;
        }
    }
    cout<<endl;
    for(auto &e:vres)
        res+=e;
    return res;
}

///8. 字符串转换整数 (atoi)
int myAtoi(string str) {
    int res=0;
    if(str.empty())//空直接返回
        return res;
    vector<char>vres;
    int i=0;
    while (str[i]!='\0') {//去掉空格
        if(str[i]==' ')
            i++;
        else
            break;//遇到非空格立刻结束
    }
    if(str[i]=='\0')//如果全是空格输入，则返回
        return res;
    int flag=0;//判断正负号
    if (str.at(i)=='+') {
        flag=1;
        i++;
    }
    else if(str.at(i)=='-')
    {
        flag=2;
        i++;
    }
    //除去空格后第一个字符不是+，-
    while (i<str.size()) {
        if(str.at(i)<='9' && str.at(i)>='0'){//满足0-9加入
            vres.push_back(str.at(i));
        }
        else//一旦后面出现非0-9字符，截断跳出
        {
            break;//截断333 aa类型
        }
        ++i;
    }
    if(vres.empty())///aaa类型返回0，在计算整数值之前判断是否有元素
        return res;
    if(flag==1)//+情况
    {
        for (int j=0; j<vres.size(); j++) {
            res+=pow(10,j)*(vres.at(vres.size()-1-j)-'0');//计算res，随后立即判断，res溢出必为负，
            if(res<0)//值溢出，直接给出正最大值
            {
                res=2147483647;
                return res;//直接返回
            }
        }
    }
    else if (flag==2) {//-开头情况
        for (int j=0; j<vres.size(); j++) {
            res+=pow(10,j)*(vres.at(vres.size()-1-j)-'0');
            if(res<0)//溢出为负值
            {
                res=-2147483648;//返回最小值
                return res;
            }
        }
        res = res*(-1);//未溢出，取反
    } else if(vres.at(0)=='0'|| vres.at(0)=='1'|| vres.at(0)=='2'|| vres.at(0)=='3'|| vres.at(0)=='4'|| vres.at(0)=='5'|| vres.at(0)=='6'|| vres.at(0)=='7'|| vres.at(0)=='8'|| vres.at(0)=='9'){
        for (int j=0; j<vres.size(); j++) {
            res+=pow(10,j)*(vres.at(vres.size()-1-j)-'0');
            if(res<0)//溢出必为负值，返回正最大值
            {
                res=2147483647;
                return res;
            }
        }
    }
    return res;
}


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
#endif /* strOperate_h */
