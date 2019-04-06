namespace name_array{

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
        unsigned int mem;
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
        int n = nums1.size();
        int m = nums2.size();
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
        int pre=0,last=height.size()-1;
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
            int i = k + 1, j = nums.size() - 1;//开始遍历
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
}
