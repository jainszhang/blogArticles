//
// Created by jains on 2019-04-20.
//

#ifndef HELLOCPP_EXAMQUSTIONS_H
#define HELLOCPP_EXAMQUSTIONS_H

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include<cmath>
#include <stack>



////网易互喻笔试题////
///1.
typedef pair<char, int> CHARPOSITION;
std::string RemoveBrackets(std::string Input)
{
    stack<CHARPOSITION> staCheak;
    for (size_t i = 0; i < Input.length(); i++)
    {
        char ch = Input[i];
        switch(ch)
        {
            case  '(':
            case  '[':
            case  '{':
            case  '<':
            {
                staCheak.push(make_pair(Input[i],i));
                break;
            }
            case ')':
            case ']':
            case '}':
            case '>':
            {
                if (!staCheak.empty())
                {
                    CHARPOSITION charPos = staCheak.top();
                    if ( (Input[i] == ')' && charPos.first == '(' ) || (Input[i] == ']' && charPos.first == '[' )
                         || (Input[i] == '>' && charPos.first == '<' ) || (Input[i] == '}' && charPos.first == '{' ) )
                    {
                        staCheak.pop();
                        size_t Left = charPos.second;
                        Input.replace(Left,i - Left + 1, i - Left + 1, ' ');
                    }
                }
                break;
            }
        }
    }
    return Input;
}

int resolution(vector<string>&arr,int rowNum)
{
    if(arr.size()!=rowNum || arr.empty())
        return -1;
    int res=0;
    //去掉#
    for (int i=0; i<rowNum; ++i) {
        string tmpStr = arr[i];
        int j=0;
        while (tmpStr.at(j)=='#') {
            j++;
        }
        arr[i] = arr[i].substr(j,arr[i].size()-j);
    }
    //去掉tab,把字符+看作黑色点
    for (int i=0; i<rowNum; ++i) {
        string tmpStr = arr[i];
        string tmpOut = "";
        for (int j=0; j<tmpStr.size(); j++) {
            if (tmpStr[j]!='\t') {
                tmpOut+=tmpStr[j];
            }
        }
        arr[i] = tmpOut;
//        cout<<arr[i]<<endl;
    }
//    cout<<endl;
    //处理[]
    for (int i=0; i<rowNum; ++i) {
        string tmpStr = arr[i];
        string tmpOut = "";
        for (int j=0; j<tmpStr.size(); j++) {
            if (tmpStr[j]=='['||tmpStr[j]==']') {
                continue;
            }
            else
                tmpOut+=tmpStr[j];
        }
        arr[i] = tmpOut;
//        cout<<arr[i]<<endl;
    }
    //处理()
//    cout<<endl;
    for (int i=0; i<rowNum; ++i) {
        string tmpStr = RemoveBrackets(arr[i]);
        arr[i] = tmpStr;
//        cout<< tmpStr<<endl;
    }

    //统计个数
    for (int i=0; i<rowNum; i++) {
        string tmpStr = arr[i];
        int tmpCnt=0;
        for (int j=0; j<tmpStr.size(); j++) {
            if(tmpStr[j]!=' ')
            {
                tmpCnt++;
            }
        }
        res+=tmpCnt;
//        cout<<tmpCnt<<" ";
    }
//    cout<<endl;
    return res;
}
void  wangYiPractice1(){
    vector<vector<string> >inputVector;

//    cout<<endl;
    int TNum;
    cin>>TNum;
    if(TNum>50 || TNum<0)
        return;
    for (int i=0; i<TNum; i++) {
        int rowNum;
        cin>>rowNum;//获取行数
        if (rowNum <0 || rowNum>500) {
            return;
        }
        cin.get();//d切掉换行
        vector<string>inputTmp;
        for (int j=0; j<rowNum; j++) {
            string strTmp="";
            char ch;
            while (cin.get(ch)) {
                if(ch!='\n')
                {
                    strTmp+=ch;
                }
                else
                    break;
            }
            inputTmp.push_back(strTmp);
        }
        inputVector.push_back(inputTmp);
    }
    cout<<endl;
    for (int i=0; i<TNum; i++) {
        for(auto &elem:inputVector[i])
            cout<<elem<<endl;
        cout<<"-----------------"<<endl;
    }



    int allSum=0;
    for (int i=0; i<TNum; i++) {
        allSum+=resolution(inputVector[i], int(inputVector[i].size()));
    }
    cout<<allSum<<endl;
//    inputVector={"#title","###subtitleone","helloworld","####[subtitletwo](http://xxx.com)","+\tlistone",
//        "+\t[listtwo](http://yyy.com)","+\t[listthree](http://z.com)more","MagicEditor"};
//        cout<<resolution(inputVector, rowNum)<<endl;
}

#endif //HELLOCPP_EXAMQUSTIONS_H
