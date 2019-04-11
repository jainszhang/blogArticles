//
//  main.cpp
//  HelloMac
//
//  Created by jains on 2019/4/11.
//  Copyright © 2019年 jains. All rights reserved.
//

#include <iostream>
using namespace std;
#include <vector>
namespace name_sort {
    /*冒泡排序
     1.平均时间复杂度O（n2）
     2.最坏情况O（n2）
     3.最好情况，已经有序O（n）
     4.空间复杂度O（1）
     5.稳定的算法
     */
    void bubbleSort(vector<int>&arr)
    {
        //shengxu
        int len = int(arr.size());
        int tmp=0;
        for (int i=0; i<len; ++i) {
            for (int j = i; j<len ; ++j) {
                if(arr[i]>arr[j])
                {
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
    }
    /*简单选择排序
     1.平均时间复杂度O（n2）
     2.最坏情况：O（n2）
     3.最好情况：O（n2）
     4.空间复杂度O（1）
     5.不稳定
     */
    void select_Sort(vector<int>&arr)
    {
        int len = int(arr.size());
        int minValue = arr.at(0);
        int tmp;
        int minIdx=0;//最小值的下标
        for (int i=0; i<len; ++i) {
            minIdx = i;
            for(int j=i;j<len;j++)
            {
                if (minValue > arr.at(j)) {
                    minIdx = j;
                }
            }
            //交换最小值
            tmp = arr.at(i);
            arr.at(i) = arr.at(minIdx);
            arr.at(minIdx) = tmp;
        }
    }
    /*插入排序
     1.平均时间复杂度O（n2）
     2.最坏情况：O（n2）
     3.最好情况：O（n）
     4.空间：O（1）
     5.稳定
     */
    void insert_Sort(vector<int>&arr)
    {
        int len = int(arr.size());
        int preIndex,current;
        for(int i=1;i<len;++i)
        {
            preIndex = i - 1;
            current = arr[i];
            while (preIndex>=0 && arr[preIndex]>current) {//向后移动所有元素
                arr[preIndex+1] = arr[preIndex];
                preIndex--;
            }
            arr[preIndex+1]=current;//把元素插入到头
        }
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> arr{6,5,4,3,2,1};
    
    name_sort::insert_Sort(arr);
    for(auto &elem:arr)
        cout<<elem<<" ";
    cout<<endl;
    return 0;
}
