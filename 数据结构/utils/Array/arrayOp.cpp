
#include "arrayOp.h"
////1.C++实现二维数组的输入
// 例如：输入
// 1,2,3,4,5
// 1,2,3
// 输出：
// 1 2 3 4 5
// 1 2 3 -->

// 方法1:使用string输入，然后迭代删除每一个','字符.输入#结束
void exe1() {
    string num;

    vector <string> nums;
    while (1) {
        cin >> num;
        if ("#" == num)
            break;
        for (auto it = num.begin(); it != num.end(); it++) {
            if (*it == ',')
                num.erase(it);
        }
        nums.push_back(num);

    }
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << endl;
}
// 方法2:使用cin.get(ch)方法循环读取输入缓冲内的字符,这种方式输入' '作为结束标志
void exe()
{
    unsigned int mem;
    char ch;
    cin>>mem;
    vector<vector<char> > nums;
    vector<char> num;
    cin.get(ch);
    while(' '!=ch)
    {
        //输入子数组数组
        cin.get(ch);//获取第一个字符
        if(' '==ch )
            break;
        while('\n'!=ch)
        {
            if(','!=ch)//遇到','直接跳过
                num.push_back(ch);
            cin.get(ch);
        }
        nums.push_back(num); //把子数组数据添加到二维数组中
        num.clear();
    }
    for(int i=0;i<nums.size();i++)
    {
        for (int j = 0; j < nums[i].size(); ++j) {
            cout<<nums[i][j]<<" ";
        }

        cout<<endl;
    }
}

/// 2.输入多行，每行表示一个int数组，最后以两个回车结束整体操作
//思路：每次读取一个字符，转换为数字，遇到回车符时表明一行输入结束，再获取一个字符，如果还是回车，整体结束，否则加入到一维数组中
void get_input(vector<vector<int>> &arr){
    vector<int>num;//一维数组
    char ch;//获取一个字符
    while (1){
        cin.get(ch);//获取字符
        if('\n'!=ch && ','!=ch)//ch不为","并且不为回车符
        {

            num.push_back((int)ch - 48);//字符和数字的ASCII相差48，因此直接用字符的ASCII-48即可得到对应数字
        } else if('\n'==ch)//遇到回车符
        {
            arr.push_back(num);
            num.clear();//清空一维数组
            cin.get(ch);//获取下一行第一个字符
            if('\n'==ch)//如果维回车直接结束输入
            {
                break;
            }
            else{//不为回车添加到新的一维数组中继续操作
                num.push_back((int)ch-48);
            }
        }
    }
}

/// 3.实现数组内两个数字之和为目标值，返回下标，只存在一对
//寻找数组当中两个数字的和为指定目标
//方法1：两个循环遍历即可
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    if (nums.empty())
        return res;
    auto size = nums.size();
    for(int i=0;i<size;++i)
        for (int j = i+1; j < size; ++j) {
            if(nums[i]+nums[j] == target)
            {
                res.push_back(i);
                res.push_back(j);

                break;
            }
        }
    return res;
}
//方法2：x+y=target,那么x=target-y,对于每一个元素，计算target-y，映射y的下标，再在
vector<int> twoSum1(vector<int>& nums, int target) {
    vector<int> index;
    map<int,int>mapp;
    for (int i = 0; i < nums.size(); ++i) {
        mapp.insert(pair<int,int >(nums[i],i));//映射每一个值到下标，便于查询
    }
    for(int i=0;i<nums.size();i++)
    {
        int complement = target - nums[i];//相当于x
        if(mapp.count(complement) && mapp.at(complement)!=i) //如果在mapp当中存在x，并且map(x)的值与当前下标值不能一致，否则会出错3+3=6
            // ，那么返回该下标，否则寻找下一个
        {
            index.push_back(i);
            index.push_back(mapp.at(complement));
            return index;
        }
    }
    return index;

}
//方法3：一次map映射。。遍历一次数组
vector<int> twoSum2(vector<int>& nums, int target) {
    vector<int> res;
    map<int,int>mymap;
    for(int i=0;i<nums.size();i++)
    {
        //如果当前的值在映射区内，返回，否则把添加映射
        int com = target-nums[i];
        if(mymap.count(com))
        {
            res.push_back(mymap.at(com));
            res.push_back(i);
            return res;
        }

        mymap.insert(pair<int,int>(nums[i],i));//减的结果映射到下标
    }
    return res;
}

///4.找出两个排序好的数组的中间的数，如果合并是偶数，则返回两数平均值---等价于找第k大的值
//方法1：合并数组，然后找出第k大的值
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //按顺序合并两个数组，然后找到即可
    if(nums1.size()==0 && nums2.size()==0)
        return 0;
    if(nums1.size()!=0 && nums2.size()==0)
        return (nums1.size() % 2 == 0) ? (nums1[nums1.size()/2]+nums1[(nums1.size()-1)/2])/2.:nums1[nums1.size()/2];
    if(nums1.size()==0 && nums2.size()!=0)
        return (nums2.size() % 2 == 0) ? (nums2[nums2.size()/2]+nums2[(nums2.size()-1)/2])/2.:nums2[nums2.size()/2];
    //合并数组
    vector<int> res;
    auto it1 = nums1.begin();
    auto it2 = nums2.begin();

    while (it1 != nums1.end() && it2 != nums2.end())
    {
        if(*it1 <= *it2)
        {
            res.push_back(*it1);
            it1++;
        }
        else
        {
            res.push_back(*it2);
            it2++;
        }
    }
    //合并未追加完毕的元素
    if(it1 != nums1.end())
    {
        res.insert(res.end(),it1,nums1.end());
    }
    if(it2!=nums2.end())
    {
        res.insert(res.end(),it2,nums2.end());
    }
    return (res.size() % 2 == 0) ? (res[res.size()/2]+res[(res.size()-1)/2])/2.:res[res.size()/2];
}
//方法2：使用分治的思想---分治这块不怎么懂
double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
    int n = int(nums1.size());
    int m = int(nums2.size());
    if(n > m)   //保证数组1一定最短
        return findMedianSortedArrays(nums2,nums1);
    int L1,L2,R1,R2,c1,c2,lo = 0, hi = 2*n;  //我们目前是虚拟加了'#'所以数组1是2*n长度
    while(lo <= hi)   //二分
    {
        c1 = (lo+hi)/2;  //c1是二分的结果
        c2 = m+n- c1;
        L1 = (c1 == 0)?INT_MIN:nums1[(c1-1)/2];   //map to original element
        R1 = (c1 == 2*n)?INT_MAX:nums1[c1/2];
        L2 = (c2 == 0)?INT_MIN:nums2[(c2-1)/2];
        R2 = (c2 == 2*m)?INT_MAX:nums2[c2/2];

        if(L1 > R2)
            hi = c1-1;
        else if(L2 > R1)
            lo = c1+1;
        else
            break;
    }
    return (max(L1,L2)+ min(R1,R2))/2.0;
}
///5.给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
/// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
///转换思路：其实就是求idx1和idx2，使得(idx2-idx1)*min(num[idx1],num[idx1])最大
//方法1：暴力法--两个循环遍历即可
int maxArea(vector<int>& height) {
    if(height.size()<=1)
        return 0;
    int max_Area=0;
    for (int i = 0; i < height.size(); ++i) {
        for (int j = i+1; j < height.size(); ++j) {
            if(max_Area < (j-i)*min(height[i],height[j]))
            {
                max_Area = (j-i)*min(height[i],height[j]);
            }
        }
    }
    return max_Area;
}
//方法2：这里用到了动态规划，基本的表达式: area = min(height[i], height[j]) * (j - i) 使用两个指针，值小的指针向内移动，
// 这样就减小了搜索空间 因为面积取决于指针的距离与值小的值乘积，如果值大的值向内移动，距离一定减小，而求面积的另外一个乘数一定小于等于值小的值，因此面积一定减小，
// 而我们要求最大的面积，因此值大的指针不动，而值小的指针向内移动遍历
int maxArea1(vector<int>&height){
    if(height.size()<=1)
        return 0;
    int max_Area = 0;
    int pre=0,last=int(height.size()-1);
    while (pre!=last)
    {
        int h = min(height[last],height[pre]);//最小高度
        max_Area = max(max_Area,(last-pre)*h);
        if(height[pre] < height[last])
            pre++;
        else
            last--;

    }
    return max_Area;

}

///6.给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
///注意：答案中不可以包含重复的三元组。
//方法1：暴力---三个循环
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if(nums.size()<3)
        return res;
    std::sort(nums.begin(),nums.end());//对元素排序
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i+1; j < nums.size(); ++j) {
            for (int k = j+1; k < nums.size(); ++k) {
                if (0==nums[i]+nums[j]+nums[k])
                {
                    vector<int>key{nums[i],nums[j],nums[k]};
                    if(res.end()==std::find(res.begin(),res.end(),key))//新的对不存在
                        res.push_back({nums[i],nums[j],nums[k]});
                    key.clear();
                }
            }
        }
    }
    return res;
}
//方法2：
//我们对原数组进行排序，然后开始遍历排序后的数组，这里注意不是遍历到最后一个停止，而是到倒数第三个就可以了。这里我们可以先做个剪枝优化，
// 就是当遍历到正数的时候就break，为啥呢，因为我们的数组现在是有序的了，如果第一个要fix的数就是正数了，那么后面的数字就都是正数，就永远不会出现和为0的情况了。
// 然后我们还要加上重复就跳过的处理，处理方法是从第二个数开始，如果和前面的数字相等，就跳过，因为我们不想把相同的数字fix两次。对于遍历到的数，用0减去这个fix的数得到一个target，
// 然后只需要再之后找到两个数之和等于target即可。我们用两个指针分别指向fix数字之后开始的数组首尾两个数，如果两个数和正好为target，则将这两个数和fix的数一起存入结果中。
// 然后就是跳过重复数字的步骤了，两个指针都需要检测重复数字。如果两数之和小于target，则我们将左边那个指针i右移一位，使得指向的数字增大一些。同理，如果两数之和大于target，
// 则我们将右边那个指针j左移一位，使得指向的数字减小一些
//
// 2层循环，使用两个数之和办法不再适用---这是因为输入值存在重复值，因此使用第一种map不再适用
vector<vector<int>> threeSum1(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());//vector排序
    if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};//不满足条件的情况
    for (int k = 0; k < nums.size(); ++k) {//固定值
        if (nums[k] > 0) break;//不存在
        if (k > 0 && nums[k] == nums[k - 1]) continue;//剪枝操作
        int target = 0 - nums[k];//目标值
        int i = k + 1, j = int(nums.size() - 1);//开始遍历
        while (i < j) {
            if (nums[i] + nums[j] == target) {
                res.push_back({nums[k], nums[i], nums[j]});
                while (i < j && nums[i] == nums[i + 1]) ++i;//跳过重复的数字
                while (i < j && nums[j] == nums[j - 1]) --j;
                ++i; --j;
            } else if (nums[i] + nums[j] < target) ++i;
            else --j;
        }
    }
    return res;

}

///7.给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
///例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
///与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
//分析：三个数的和与目标值之差最小，输入只存在唯一答案因此不存在重复情况
//方法1：暴力求解--3个循环
int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size()<3)
        return -1;
    int min_value=99999;
    int res=0;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i+1; j < nums.size(); ++j) {
            for (int k = j+1; k < nums.size(); ++k) {
                int tmp = abs(target - (nums[i]+nums[j]+nums[k]));
                if(tmp<min_value)
                {
                    min_value = tmp;
                    res = nums[i]+nums[j]+nums[k];
                }
            }
        }
    }
    return res;
}
//方法2:排序数组，固定一个目标值，使用前后指针相加
int threeSumClosest1(vector<int>& nums, int target) {
    if(nums.size()<=2)
        return -1;
    sort(nums.begin(),nums.end());//排序
    int closevalue = nums[0]+nums[1]+nums[2];//初始值
    int pre,last;
    for (int i = 0; i < nums.size(); ++i) {//固定一个值
        static_cast<void>(pre = i+1),last = unsigned (nums.size() - 1);//前后指针
        while (pre<last)
        {
            int sum = nums[pre] + nums[last] + nums[i];//3个值相加
            if(abs(sum-target) < abs(closevalue-target))
            {
                closevalue = sum;
            }
            if(sum >target) last --;//搜索的3个值大于目标值，需要向左移动
            else if(sum <target) pre++;//搜索的3个值小于目标值，需要向右移动
            else return target;
        }
    }
    return closevalue;
}

///8.给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？
/// 找出所有满足条件且不重复的四元组。注意：答案中不可以包含重复的四元组。
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    set<int>myset;
    if(nums.size()<4)
        return res;
    //固定两个值，使用前后指针
    sort(nums.begin(),nums.end());//排序
    int pre,last;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i+1; j < nums.size(); ++j) {
            pre = j+1;
            last = unsigned (nums.size()-1);
            while (pre<last)
            {
                int sum = nums[i] +nums[j]+nums[pre]+nums[last];
                if(sum == target)
                {
                    vector<int> key{nums[i],nums[j],nums[pre],nums[last]};
                    auto it = find(res.begin(),res.end(),key);//去掉重复值，这是因为j取值可能会有重复的
                    if(it==res.end())//没有找到
                        res.push_back(key);
                    while (pre<last && nums[pre] == nums[pre+1]) ++pre;//去掉排序后紧挨着的相同的值
                    while (pre<last && nums[last] == nums[last-1]) --last;
                    pre++;last--;

                }
                else if(sum < target)
                {
                    pre++;
                }
                else if(sum >target) last--;
            }
        }
    }

    return res;

}

///9.给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
///不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//方法1：遇到相等的直接删除，但是回移动元素，速度降低
int removeDuplicates(vector<int>& nums) {
    if(nums.size()==0)
        return 0;
    auto pre = nums.begin();
    for (auto it = nums.begin()+1;it!=nums.end();it++) {
        if(*pre == *it)
        {
            nums.erase(it);
            it--;//抵消it++操作
        } else
        {
            pre = it;
        }
    }
    return int(nums.size());
}
//方法2：使用元素覆盖方式，不删除元素，不会造成元素移动，因此速度快
int removeDuplicates1(vector<int>& nums) {
    if(nums.size()==0)
        return 0;
    int len=1;
    auto pre = nums.begin();
    auto cur = nums.begin()+1;
    while(cur != nums.end())
    {
        if(*pre == *cur)
        {
            *pre = *cur;
            cur++;
        }
        else if(*pre != *cur)
        {
            len++;
            pre++;
            *pre = *cur;
        }
    }
    nums.erase(pre+1,nums.end());
    return len;
}
///10。给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
///不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
///元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//方法1：遍历，使用erase删除对应的元素即可，但是回造成元素在移动，耗费时间
//方法2：遍历，使用一个新的指针维护新数组即可
int removeElement(vector<int>& nums, int val) {
    if(nums.size()==0)
        return 0;
    auto cur = nums.begin();//cur遍历当前的数组
    auto pre = nums.begin();//pre维护新的数组
    while (cur!=nums.end())
    {
        if(val != *cur)//遇到和目标值相等的值，继续移动直到和目标值不等
        {
            *pre = *cur;
            pre++;
        }
        cur++;
    }
    nums.erase(pre,nums.end());
    return int (nums.size());
}
int removeElement1(vector<int>& nums,int val){
    int idx = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[idx] = nums[i];
            idx++;
        }
    }

    nums.resize(idx);
    return idx;

}

///11.实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
///如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
///必须原地修改，只允许使用额外常数空间。
///以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
//1,2,3 → 1,3,2
//3,2,1 → 1,2,3
//1,1,5 → 1,5,1
//分析：从后向前找，如果找到2个相邻的值是pre<last，那么就调换，然后在last到end之间寻找一个最接近且大于pre的值，再对last-end排序即可
// 如果找到头还没有找到这种情况，就对数组排序
int cmp1(int a,int b)
{return b>a;}
void nextPermutation(vector<int>& nums) {
    if(nums.size()==0)
        return ;
    unsigned long pre = nums.size()-2,last = nums.size()-1;
    for (int i = (int)pre; i >=0 ; --i) {
        if(nums[pre] < nums[last])
        {
            //寻找last-end之间最接近pre的数，且大于pre
            int idx_tmp=int(nums.size()-1);
            while (idx_tmp >= last)
            {
                if(nums[pre]<nums[idx_tmp])
                {
                    int tmp = nums[pre];
                    nums[pre] = nums[idx_tmp];
                    nums[idx_tmp] = tmp;
                    break;
                }
                idx_tmp --;
            }
            sort(nums.begin()+last,nums.end(),cmp1);
            return;
        }
        pre--;last--;
    }
    vector<int> newvector;
    if(++pre==0)
    {
        for (auto rit = nums.rbegin(); rit!=nums.rend(); ++rit) {
            newvector.push_back(*rit);
        }
    }
    nums = newvector;
}
///13.假设按照升序排序的数组在预先未知的某个点上进行了旋转。
///( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
///搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
///你可以假设数组中不存在重复的元素。
///你的算法时间复杂度必须是 O(log n) 级别。
//分析：在二分查找的基础上做，二分后两端一端有序，一端可能有序可能无序，有序则继续二分，无序也继续二分
//方法1：非递归方式
int search1(vector<int>& nums, int target){
    if(nums.size()==0)
        return -1;
    int left =0,right = int(nums.size()-1),mid=0;
    while (left<right)
    {
        mid = (left + right )/2;
        if(target == nums[left])
            return left;
        if(target == nums[right])
            return right;
        if(target == nums[mid])
            return mid;
        if(nums[left] < nums[mid])//左边有序，右边无序
        {
            if(target > nums[left] && target<nums[mid])//目标值在左边有序序列,二分查找
            {
                right = mid - 1;
            }
            else//目标值不在左边有序序列---意味着目标值在右边序列
            {
                left = mid + 1;
            }
        }
        else if(nums[mid] < nums[right])//右边有序的情况
        {
            if(target > nums[mid] && target < nums[right])//目标值在右边的有序序列中，二分查找
            {
                left = mid+1;
            }
            else//目标值不在右边有序序列中---意味着在左边序列中
            {
                right = mid -1;
            }
        }
    }
    if(nums[left] == target)
        return left;
    return -1;

}


///14.给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
///你的算法时间复杂度必须是 O(log n) 级别。
///如果数组中不存在目标值，返回 [-1, -1]。
//关键词：升序，log n时间，返回目标值起始和结束位置idx。隐含信息：相同的值肯定紧挨着
//分析：依旧是二分查找，目标值都在左边区间，目标值都在右边区间，目标值被一分为二
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    if(nums.size()==0)
        return res;
    if(nums.size()==2 && target==nums[0] && target==nums[1])
    {
        res.push_back(0);
        res.push_back(1);
        return res;
    }
    if(nums.size()==2 && target==nums[0] && target!=nums[1])
    {
        res.push_back(0);
        res.push_back(0);
        return res;
    }
    if(nums.size()==2 && target!=nums[0] && target==nums[1])
    {
        res.push_back(1);
        res.push_back(1);
        return res;
    }
    int left=0,right = int(nums.size()-1),mid =0;
    while(left<right)
    {
        mid = (left + right) /2;

        if(target == nums[mid] && target > nums[mid-1])//目标值都在右边
        {
            int tmp_idx=mid;
            while (target == nums[tmp_idx]) tmp_idx++;//找到最右边的target值
            res.push_back(mid);
            res.push_back(--tmp_idx);
            return res;
        }
        else if(target == nums[mid] && target < nums[mid+1])//目标值都在左边
        {
            int tmp_idx=mid;
            while (target == nums[tmp_idx])
                tmp_idx--;//找到最右边的target值
            res.push_back(++tmp_idx);
            res.push_back(mid);

            return res;
        }
        else if(target == nums[mid] && target == nums[mid-1] && target == nums[mid+1])//目标值分布在两边
        {
            //以mid为中点，向两边查找
            int tmp_idx_l=mid,tmp_idx_r =mid;
            while (target == nums[tmp_idx_l]) tmp_idx_l--;//向左边找边界
            while (target == nums[tmp_idx_r]) tmp_idx_r++;//向右边找边界
            res.push_back(++tmp_idx_l);
            res.push_back(--tmp_idx_r);
            return res;
        }

        //如果没有找到任何的target值，继续二分
        if(target<nums[mid]) right = mid-1;
        else if(target > nums[mid]) left = mid +1;
    }

    res.push_back(-1);
    res.push_back(-1);
    return res;
}

///15.给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//candidates 中的数字可以无限制重复被选取。
//说明：
//所有数字（包括 target）都是正整数。
//解集不能包含重复的组合。

///解题思路：
///1、这道题给定一个vector，里面装着彼此不重复的元素，元素是正整数，还给了一个target，也是正整数。
//要求找出各种有可能的组合，使得vector中的元素的和等于target。
//每个组合存储在一个一维的vector中，最终把这些一维的vector存在二维的vector中，返回二维vector。
//各个组合不能重复。
//2、我们先来看一个例子，vector是[2,3,6,7]，target是7，我们人类怎么解决这个问题呢？
//我们当然是从后面看起，最大的7，看能不能满足target，结果是可以的，那么我们再看前一个数6。
//6小于等于7，我们还要一个1，往本身或者前面看有没有小于等于1的，结果没有，那么我们就没有办法搭配6了，我们再看前一个数3。
//3小于等于7，我们还要4，本身还可以再减去3，那么还要一个1，再往本身或者前面看，没有1。
//那我们也许可以不要第二次减去3，我们减去前一个数2，然后还要一个2，刚好本身可以满足。
//然后再看前一个数2，本身还可以再减去2，然后本身还可以再减去2，然后还要一个1，但没有办法了。
//所以最终我们得到的组合是[[7],[3,2,2]]。
//做的题目比较多的同学，可能已经嗅到了一股递归的味道。
//这道题就是要不断试探，试探可以满足target的，插入到二维vector中，试探到不可以满足的，回退一步，再试其他可能。
///从后向前走
vector<vector<int>>res;
vector<int>res1;//存储每次可能的组合结果
void digui(vector<int>& candidates,int index,int target,vector<int>&res1)
{
    if(target == 0)//组合数找到了，加入res
    {
        res.push_back(res1);
        return;
    }
    while(index>=0)//找下标直到第一个数为止
    {
        if(candidates[index]<=target)//目标值还未到负数，继续寻找
        {
            res1.push_back(candidates[index]);//找到组合对第一个值
            digui(candidates,index,target-candidates[index],res1);//继续寻找下一个值
            res1.pop_back();//寻找结束后退出一个值，再寻找下一个
        }
        index--;//index的值找完了，找前一个index对应值
    }
    if(index<=0)
        return;
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if(int(candidates.size())==0) return res;
    digui(candidates,int(candidates.size()-1),target,res1);
    return res;

}
///从前向后走
void backtrad(vector<int>candidates,int start,int target,vector<int>item,vector<vector<int>> &res)
{
    if(target<0)
        return;
    if(target == 0)
    {
        res.push_back(item);
        return;
    }
    for(int i = start;i<candidates.size();i++)
    {
        item.push_back(candidates[i]);
        backtrad(candidates,i,target - candidates[i],item,res);
        item.pop_back();
    }

}
vector<vector<int>> combinationSum1(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int>item;
    backtrad(candidates,0,target,item,res);
    return res;
}

