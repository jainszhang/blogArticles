//
//  Sort.cpp
//  HelloMac
//
//  Created by jains on 2019/4/12.
//  Copyright © 2019年 jains. All rights reserved.
//

#include "Sort.hpp"

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
        for (int j = 0; j<len-1-i ; ++j) {
            if(arr[j]>arr[j+1])
            {
                tmp = arr[j+1];
                arr[j+1] = arr[j];
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
    for(int i=1;i<len;i++)
    {
        preIndex = i - 1;
        current = arr[i];
        //把大于cur的值向后移动
        while (current<arr[preIndex] && preIndex>=0) {
            arr[preIndex+1] = arr[preIndex];
            preIndex--;
        }
        //把cur的值插入到空的位置
        arr[preIndex+1] = current;
    }
}
/*希尔排序:是简单插入排序的改进版。它与插入排序的不同之处在于，它会优先比较距离较远的元素。希尔排序又叫缩小增量排序。
 1.平均时间复杂度O（n1.3）
 2.最坏O（n2）
 3.最好O（n）
 4.空间O（1）
 5.不稳定
 */
void shell_Sort(vector<int>&arr)
{
    int len = int(arr.size());
    for (int gap=len/2;gap>0 ; gap=gap/2) {
        for (int i=gap; i<len; i++) {
            //相隔gap个值之间比较
            int j=i;
            int cur = arr[j];
            
            while (j - gap >= 0 && cur < arr[j - gap]) {
                arr[j] = arr[j - gap];
                j = j - gap;
            }
            arr[j] = cur;
        }
        
    }
}

/*快速排序
 1.平均O（nlogn）
 2.最坏：O（n2）
 3.最好：O（nlogn）
 4.空间复杂度：O（nlogn）
 5.不稳定*/
void quick_Sort(vector<int> &arr,int left,int right)
{
    if(left<right)
    {
        int i = left,j = right ;
        int x = arr[left];
        while (i<j) {
            //从右向左找到小于x的数填充arr【i】
            while (i<j && arr[j] >= x) {
                j--;
            }
            if (i<j) {
                arr[i++] = arr[j];//填充arr[i]，且下标加1
            }
            //从左向右找到第一个大于等于x的值，填充arr[j]
            while (i<j && arr[i] <x) {
                i++;
            }
            if(i<j)
            {
                arr[j--] = arr[i];//填充空位，j-1
            }
        }
        arr[i] = x;//这一轮找完，填充x
        //上面部分相当于分区操作，找到分区节点i
        quick_Sort(arr, left, i-1);//左边
        quick_Sort(arr, i+1, right);//右边
    }
}

/*归并排序
 1.平均复杂度O（nlogn）
 2.最坏情况O（nlogn）
 3.最好情况O（nlogn）
 4.空间复杂度：O（n）
 5.稳定：这是因为在1个或2个元素时，1个元素不会交换，2个元素如果大小相等也没有交换，这不会破坏稳定性*/
//将有二个有序数列a[first...mid]和a[mid...last]合并
void merge_Array(vector<int>&a ,int first,int mid,int last)
{
    vector<int> tmp;//用于存储合并的临时数组，first到last之间大小
    int i = first,j=mid+1;
    int m = mid,n=last;
    while (i<=m & j<=n) {
        if(a[i]<a[j])
        {
            tmp.push_back(a[i++]);
        }
        else
        {
            tmp.push_back(a[j++]);
        }
    }
    while (i<=m) {
        tmp.push_back(a[i++]);
    }
    while (j<=n) {
        tmp.push_back(a[j++]);
    }
    for (i=0; i<int(tmp.size()); i++) {//更改合并好的数组到原始数组当中，一共有tmp.size()个元素
        a[first+i] = tmp[i];
    }
}
void merge_Sort(vector<int>&arr,int first,int last)
{
    if(first<last)
    {
        int mid = (first+last) / 2;
        merge_Sort(arr, first, mid);//左边有序
        merge_Sort(arr, mid+1, last);//右边有序
        merge_Array(arr, first, mid, last);//合并左右两边
    }
}

/*堆排序
 */


/*计数排序
 找出待排序的数组中最大和最小的元素；
 统计数组中每个值为i的元素出现的次数，存入数组C的第i项；
 对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）；
 反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1。
 1.所有时间复杂度都是O（n+k）
 2.空间复杂度为O（n+k）
 3.稳定的算法*/
void count_Sort(vector<int> &arr)
{
    auto maxValue = max_element(arr.begin(), arr.end());//找到最大值
    vector<int> bucket(*maxValue+1,0);//初始化统计个数的数组
    for(int i=0;i<int(arr.size());i++)
    {
        bucket[arr[i]]++;//值为arr[i]个数加1
    }
    int k=0;
    for(int i=0;i<bucket.size();i++)
    {
        while (bucket[i]>0) {
            arr[k++]=i;
            bucket[i]--;
        }
    }
}

/*桶排序：桶排序是计数排序的升级版。它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。桶排序 (Bucket sort)的工作的原理：假设输入数据服从均匀分布，将数据分到有限数量的桶里，每个桶再分别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排）。
 桶排序思想：将某范围内数据存储在某一个桶中，再排序每个桶内数据
 */
void bucket_Sort(vector<int>&arr)
{
    auto maxValue = *max_element(arr.begin(), arr.end());//找到最大值
    auto minValue = *min_element(arr.begin(), arr.end());
    int bucket_Size = maxValue - minValue;//桶大小
    vector<int>bucket(bucket_Size+1,0);
    for(int i=0;i<int(arr.size());i++)
    {
        bucket[arr[i]-minValue]++;//统计个数
    }
    arr.clear();
    for(int i=0;i<bucket.size();i++)
    {
        while (bucket[i]--) {//桶计数个数
            arr.push_back(i+minValue);//加入到新数组
        }
    }
}
/*基数排序：具体做法是：将所有待比较数值统一为同样的数位长度，数位较短的数前面补零。然后，从最低位开始，依次进行一次排序。这样从最低位排序一直到最高位排序完成以后, 数列就变成一个有序序列。
 1.时间复杂度都为O（n*k）
 2.空间复杂度为O（n+k）
 3.稳定
 */
void count_sort(vector<int>&arr,int exp)
{
    vector<int>bucket(10,0);
    vector<int>tmp(arr.size());
    for(int i=0;i<arr.size();i++)//数据出现次数存储在buckets中
    {
        bucket[(arr[i]/exp)%10]++;
    }
    //关键一步：需要统计tmp位数
    for(int i=1;i<10;i++)
    {
        bucket[i]+=bucket[i-1];///目的是为了确定某个数的下标
    }
    //分组排序
    for(int i=int(arr.size()-1);i>=0;i--)
    {
        int k = (arr[i] / exp)%10;
        tmp[bucket[k]-1] = arr[i];
        bucket[k]--;
    }
    arr.swap(tmp);
    
}
///这种方式更容易理解
void count_sort1(vector<int>&arr,int exp)
{
    vector<vector<int> >tmp(10);//存储10个二维数组
    for(int i=0;i<arr.size();i++)//数据出现次数存储在buckets中
    {
        int k=(arr[i]/exp)%10;
        tmp[k].push_back(arr[i]);
        
    }
    int c=0;
    for (int i=0; i<tmp.size(); i++) {
        for (int j=0; j<tmp[i].size(); j++) {
            arr[c++] = tmp[i][j];
        }
    }
}
void redix_Sort(vector<int>&arr)
{
    int exp;
    int max = *max_element(arr.begin(), arr.end());
    for(exp=1;max/exp>0;exp*=10)//需要排序多少次，相当于多少位数据
    {
        count_sort1(arr, exp);
    }
}

