//
//  backTrack.cpp
//  HelloMac
//
//  Created by jains on 2019/4/13.
//  Copyright © 2019年 jains. All rights reserved.
//



//回溯法类似于枚举搜索的方式，在搜索尝试过程中寻找问题的解，当发现不满足d求解条件时就“回溯”返回，尝试别的路径
/*回溯法思想：在包含问题的所有解的解空间树中，按照深度优先搜索的策略，从根结点出发深度探索解空间树。当探索到某一结点时，要先判断该结点是否包含问题的解，如果包含，就从该结点出发继续探索下去，如果该结点不包含问题的解，则逐层向其祖先结点回溯。（其实回溯法就是对隐式图的深度优先搜索算法）。若用回溯法求问题的所有解时，要回溯到根，且根结点的所有可行的子树都要已被搜索遍才结束。而若使用回溯法求任一个解时，只要搜索到问题的一个解就可以结束*/
/*回溯法一般步骤：
 （1）针对所给问题，确定问题的解空间：
    首先应明确定义问题的解空间，问题的解空间应至少包含问题的一个（最优）解。
 （2）确定结点的扩展搜索规则
 （3）以深度优先方式搜索解空间，并在搜索过程中用剪枝函数避免无效搜索。*/
/*算法框架：
 （1）问题框架：设问题的解是一个n维向量(a1,a2,………,an),约束条件是ai(i=1,2,3,…..,n)之间满足某种条件，记为f(ai)。
 
 （2）回溯法非递归方式模版*/
 void back()
{
    const int n = 8;
//    int a[n];//初始化数组a[];
    int i = 1;
    while (i>0 && i<n)//i>0(有路可走)   and  (未达到目标))  // 还未回溯到头
    {
     if(i > n)  // 搜索到叶结点
        {
            //搜索到一个解，输出；
        }
        else                                                   // 处理第i个元素
        {
            //a[i]第一个可能的值；
            while(1)//a[i]在不满足约束条件且在搜索空间内)
            {
             //a[i]下一个可能的值；
                break;
            }
           // 如果满足条件，则可以输出一个解，继续下一个解
            if(i==1)//a[i]在搜索空间内)
             {
                 //标识占用的资源；
                i = i+1;                              // 扩展下一个结点
            }
             else///这里需要回溯了，回溯到上一层，移动到下一个位置
             {
              //清理所占的状态空间；            // 回溯
//                 i--;
              }
        }
        
    }
}
/*
 （3）递归方式
 1: int a[n];
 2: try(int i)
 3: {
 4:     if(i>n)
 5:        输出结果;
 6:      else
 7:     {
 8:        for(j = 下界; j <= 上界; j=j+1)  // 枚举i所有可能的路径
 9:        {
 10:            if(fun(j))                 // 满足限界函数和约束条件
 11:              {
 12:                 a[i] = j;
 13:               ...                         // 其他操作
 14:                 try(i+1);
 15:               回溯前的清理工作（如a[i]置空值等）;
 16:               }
 17:          }
 18:      }
 19: }

 */


#include "backTrack.hpp"
///////////////////////1.八皇后回溯法//////////////

const int QUEEN = 8;
int a[QUEEN];//表示解空间a[1]=2表示，1，2位置有皇后
void init()//初始化
{
    int *p;
    for(p=a;p<a+QUEEN;++p)
        *p = INITIAL;
}
int valid(int row, int col)    //判断第row行第col列是否可以放置皇后
{
    int i;
    for (i = 0; i < QUEEN; ++i)  //对已得到的解搜索，看是否冲突
    {   //判断列冲突与斜线上的冲突
        //表示第i行第col列放了皇后，(row - i) / (col - arr[i]) != 1 或 -1
        // arr[i] = k表示第i行第k列放了皇后
        if (a[i] == col || abs(i - row) == abs(a[i] - col))
            return 0;
    }
    return 1;
}
void print()    //打印输出N皇后的一组解
{
    int i, j;
    for (i = 0; i < QUEEN; ++i)
    {
        for (j = 0; j < QUEEN; ++j)
        {
            if (a[i] != j)      //a[i]为初始值
                printf("%c ", '.');
            else                //a[i]表示在第i行的第a[i]列可以放置皇后
                printf("%c ", '#');
        }
        printf("\n");
    }
    for (i = 0; i < QUEEN; ++i)
        printf("%d ", a[i]);
    printf("\n");
    printf("--------------------------------\n");
}
void queen()      //N皇后程序
{
    int n = 0;
    int i = 0, j = 0;//i表示行，j表示每行的列
    while (i < QUEEN)//满足继续搜索的条件
    {
        ///没有到叶子结点情况下就继续搜索
        while (j < QUEEN)        //对i行的每一列进行探测，看是否可以放置皇后
        {
            if(valid(i, j))      //该位置可以放置皇后
            {
                a[i] = j;        //第i行放置皇后，位置位j列
                j = 0;           //第i行放置皇后以后，需要继续探测下一行的皇后位置，
                //所以此处将j清零，从下一行的第0列开始逐列探测
                break;
            }
            else
            {
                ++j;             //继续探测下一列
            }
        }
        ///搜索到了叶子结点但是无解，直接回溯到上一行
        if(a[i] == INITIAL)         //第i行没有找到可以放置皇后的位置
        {
            if (i == 0)             //回溯到第一行，仍然无法找到可以放置皇后的位置，
                //则说明已经找到所有的解，程序终止
                break;
            else                    //没有找到可以放置皇后的列，此时就应该回溯
            {
                --i;
                j = a[i] + 1;        //把上一行皇后的位置往后移一列
                a[i] = INITIAL;      //把上一行皇后的位置清除，重新探测
                continue;
            }
        }
        //找到解
        if (i == QUEEN - 1)          //最后一行找到了一个皇后位置，
            //说明找到一个结果，打印出来
        {
            printf("answer %d : \n", ++n);
            print();
            //不能在此处结束程序，因为我们要找的是N皇后问题的所有解，
            //此时应该清除该行的皇后，从当前放置皇后列数的下一列继续探测。
            j = a[i] + 1;             //从最后一行放置皇后列数的下一列继续探测
            a[i] = INITIAL;           //清除最后一行的皇后位置
            continue;
        }
        ++i;              //继续探测下一行的皇后位置
    }
}
#include <iostream>
using namespace std;
void queen1()
{
    int n = 0;
    int i = 0, j = 0;//i表示行，j表示每行的列
    //什么时候结速搜索
    while(i<8)
    {
        if (i>8)
        {
            //此处需要给出解空间向量
            return;
        }
        else
        {///此处表示继续向下搜索
            
            //这一段循环要么找到第i行皇后位置，要么没找到第i行皇后位置，
            //找到的话a[i]=j,否则a[i]=INITIAL
            while(j<8)
            {
                if(valid(i,j))
                {
                    a[i] = j;//（i，j）位置放一个皇后
                    j=0;//搜索下一行时，从第0列开始
                    break;
                }
                else//（i，j）与前面放的皇后位置冲突，就是和解向量冲突
                {
                    ++j;//判断下一列
                }
            }
            
            //未找到解向量需要回溯继续找
            if(a[i]==INITIAL)
            {
                if(i==0)
                    break;
                else
                {
                    --i;//回溯到上一行
                    j=a[i]+1;//把上一行皇后位置向后移动一列
                    a[i] = INITIAL;//清除上一行皇后位置,重新寻找
                    continue;
                }
            }
            
            //找到解向量需要满足的条件
            if (i==7)//表示最后一行也找到了，意味着找到了一个解向量
            {
                cout<<"answer :"<<++n<<endl;//打印第n个结果
                print();
                //继续寻找下一个解向量
                j = a[i]+1;//列位置继续加1，从下一个位置继续寻找
                a[i] = INITIAL;//把刚刚找到的解注释掉
                continue;
            }
            ++i;//找下一行
            
        }
    }
    
}


///2. 0-1背包问题
//方法1:贪心算法
/*首先考虑贪心法，为了得到最大的价值，将所有物品按照单位价值（Vi/Wi）降序排列，在放入物品时优先考虑单位价值更高的物品.在搜索到空间树中的某个结点P时，已经确定了P及其前面的结点取值，进而判断从P继续扩展下去是否获得更大的价值，如果不能，该结点无需扩展，可以进行回溯了。下面的函数结合了贪心法判断从某一点扩展开去可能获得的最大的价值。*/
int Bound(vector<int> values,std::vector<int> weights,int n,int maxWeight,int num,int currentWeight,int currentProfit)
{
    int i = num+1;
    for(;i<n;i++)
    {
        if(currentWeight + weights[i] < maxWeight)
        {
            currentProfit = currentProfit + values[i];
            currentWeight = currentWeight + weights[i];
            
        }
        else
        {
            currentProfit+=(values[i]/weights[i])*(maxWeight-currentWeight);//计算是否可以获得更大的价值
            currentWeight=maxWeight;
            return currentProfit;
        }
    }
    return currentProfit;
}
int *Knapsack(vector<int>values,vector<int>weights,int n,int maxWeight)
{
    
    int *X = new int[n];
    int *Y = new int[n];
    int _weight = 0;
    int _profit = 0;
    int _currentWeight = 0,_currentProfit=0;
    int i=0;
    while (1) {
        while (i<n && _currentWeight + weights[i] <= maxWeight) {
            X[i] = SELECT;
            _currentWeight+=weights[i];
            _currentProfit+=values[i];
            i++;
        }
        //---上面的循环中，如果是由于i=n结束的，那么说明深度搜索已经搜索到了最底层
        if(i>=n)
        {
            _weight = _currentWeight;
            _profit = _currentProfit;
            i = n;
            for (int j=0;i<n;j++) {
                Y[j] = X[j];
            }
        }
        else  //否则就是由于第i个物品在当前情况下无法放入背包
        {
            X[i] = UNSELECT;
        }
        //如果不可能获得更大的价值，那么这个点就不需要进行扩展了；
        while (Bound(values, weights, n, maxWeight, i, _currentWeight, _currentProfit) <= _profit)
        {
            while (i!=0 && X[i]!=SELECT) {
                i--;
            }
            if(i==0)
            {
                return Y;
            }
            X[i] = UNSELECT;
            _currentProfit-=values[i];
            _currentWeight -=values[i];
        }
        i++;
    }
}

///3.给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。给出数字到字母的映射如下（与电话按键相同）。
///注意 1 不对应任何字母。输入："23"
///输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//分析：回溯法，digits有几个数字，就有几层树。终止条件：最后一个数字访问完毕。每一个数字需要对应的字母

vector<string> letterCombinations(string digits) {
    vector<string> res;
    if(digits.empty())
        return res;
    vector<string>dic{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int depth=int(digits.size());
    int n=0;
    int col=0;
    string str="";
    
    
    
    
    
    
    
    while (n<depth) {
        //到叶子结点
        while (n<depth) {
            str=str+'a';
            str[col];
//            break;
        }
        if (n==depth-1) {
            //push
            string ss = "ddd";
            for (int j=0; j<5; j++) {
                res.push_back(" ");
            }
            n--;
            col=col+1;
        }
//        n++;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return res;
////    int _level = int(digits.size());
//    //结束条件是第一个数字对应字符串个数访问完毕
//    int _idx = int(digits[0])-48;
//    string str = mymap.at(_idx);//第一个数字对应的字符串
//    auto _firstCnt = str.size();
//    int _count=0;
//    int _countLev=0;
//    vector<char> tmp;
//    int j=0;
//    while (_count<_firstCnt) {//记录第一个节点上字符访问的个数，达到最大时结束
//
//        if(_countLev==digits.size()-1)//到达最后一层，把所有结果放入res
//        {
//            int ii = int (digits[_countLev])-48;
//            auto ss = mymap.at(ii);//得到最后一层对应的字符串
//            while(j < ss.size())
//            {
//                tmp.push_back(ss[j]);//得到字符值
//                res.push_back(tmp);
//                tmp.pop_back();
//                j++;
//            }
//            _countLev--;
//            j=0;
//        }
//        if(_countLev<digits.size()-1)
//        {
//            j++;
//            while (_countLev<digits.size()-1) {
//                _countLev++;
//            }
////            while (_countLev < digits.size()-1) {
////                int ii = int (digits[_countLev])-48;
////                auto ss = mymap.at(ii);
////
////                tmp.push_back(ss[j]);
////                _countLev++;
////            }
//        }
//        if(_countLev == 0 && str[_count]!='\0')
//        {
//            _count++;
//        }
//
//    }
//
//
    
    
    
    
    
    
    
    
    
    
//
//
//    vector<string> res;
//    if (digits.empty())
//        return res;
//    string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//    res.push_back("");
//    for (int i = 0; i < digits.size(); ++i) {
//        int n = int (res.size());
//        string str = dict[digits[i] - '2'];
//        for (int j = 0; j < n; ++j) {
//            string tmp = res.front();
//            res.erase(res.begin());
//            for (int k = 0; k < str.size(); ++k) {
//                res.push_back(tmp + str[k]);
//            }
//        }
//    }
//    return res;

}
