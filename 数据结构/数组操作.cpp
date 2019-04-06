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

}
