//
// Created by jains on 2019-04-22.
//
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

namespace nameArray{
    //声明：
    /*reference at ( size_type n );
      const_reference at ( size_type n ) const;*/
    //1.access or modify elements.
    //2.超过边界会抛出异常
    void AtOpt()//
    {
        std::array<int,10>myarray={};
        for (int i = 0; i < 10; ++i) {//assign values
            myarray.at(i)=i+1;
        }
        //print content
        for(auto &elem:myarray)
            std::cout<<elem<<" ";
        std::cout<<endl;
    }
    //声明：
    /*reference back();
    const_reference back() const;*/
    //描述：返回array容器最后一个元素的引用
    //注意：1.在空数组上调用该函数会造成未知行为
    //2.可以用来访问和修改元素
    void BackOpt()
    {
        std::array<int,3>myarray={1,2,3};
        std::cout<<"front "<<myarray.front()<<endl;
        std::cout<<"back "<<myarray.back()<<endl;
        myarray.back()=50;
        myarray.front()=10;
        std::cout<<"modify front "<<myarray.front()<<endl;
        std::cout<<"modifu back "<<myarray.back()<<endl;
        std::array<int,0>myarray1={};//空数组
        cout<<myarray1.back()<<endl;
    }

    //声明：
    /*value_type* data() noexcept;
    const value_type* data() const noexcept;*/
    //描述：返回指向array对象首元素的指针
    //注意：
    //1.由于元素在内存中连续存储，因此可以根据首元素指针访问整个数组
    //2.如果是常对象，返回值为常指针
    void DataOpt()
    {
        const char *cstr = "test string";
        std::array<char,12>chararray;
        std::memcpy(chararray.data(),cstr,12);
        std::cout<<chararray.data()<<std::endl;
    }

    //声明：
    /*void fill (const value_type& val);*/
    //描述：
    //给array对象所有元素设置为一个同样的值
    //注意：
    //1.所有元素都会被修改为value
    void FillOpt()
    {
        std::array<int,6>myarray;
        myarray.fill(5);
        std::cout<<"myarray contains:"<<std::endl;
        for (int i = 0; i < myarray.size(); ++i) {
            std::cout<<myarray.at(i)<<" ";
        }
        std::cout<<endl;
    }

    //声明：
    /*constexpr size_type max_size() noexcept;*/
    //描述：
    //返回array容器可以包含元素的最大值
    //注意：
    //1.类似size，
    //2.对array容器讲，size总是与maxsize一致
    void Max_SizeOpt()
    {
        std::array<int,10>myints;
        std::cout<<"size of myints: "<<myints.size()<<std::endl;
        std::cout<<"max_size of myints: "<<myints.max_size()<<std::endl;
    }

    //swap
    //声明：
    /*void swap (array& x) noexcept(noexcept(swap(declval<value_type&>(),declval<value_type&>())));*/
    //描述：
    //通过x的内容来交换操作的数组对象，交换的数组元素类型和size需要和被交换数组一致
    void SwapOpt()
    {
        std::array<int,5>first={10,20,30,40,50};
        std::array<int,5>second={11,21,31,41,51};
        first.swap(second);
        std::cout<<"first:";
        for(auto &e:first)
            std::cout<<e<<" ";
        std::cout<<endl<<"second:";
        for(auto &e:second)
            std::cout<<e<<" ";
        std::cout<<endl;
    }
}
namespace nameVector{
    //assign
    //声明：
    /*  template <class InputIterator>void assign (InputIterator first, InputIterator last);
        void assign (size_type n, const value_type& val);*/
    //描述：给vector赋值新内容，替代当前内容，并根据世纪情况重新分配大小
    //注意：1.第一个：根据迭代器来赋值
    //2.第二个：根据值来赋值，n个value赋值
    void AssignOpt()
    {
        std::vector<int>first;
        std::vector<int>second;
        std::vector<int>third;
        first.assign(7,100);//赋值7个100
        auto it = first.begin()+1;
        second.assign(it,first.end()-1);//it1到it2之间的值，包括it1，不包括it2
        int myints[]={1776,7,4};
        third.assign(myints,myints+3);
        std::cout<<"size of first: "<<first.size()<<std::endl;
        std::cout<<"size of second: "<<second.size()<<std::endl;
        std::cout<<"size of third: "<<third.size()<<std::endl;
//        cout<<second.size()<<endl;
    }
    //at与array基本一致
    //first(),back()等与array基本面一致
    //data()与array的data()基本一致

    //capacity
    //声明：
    /*size_type capacity() const;*/
    //描述：返回分配给当前vector的内存可容纳的元素个数
    //1.capacity不等同于size，capacity>=size，当capacity不够用时，会自动分配新的内存
    //2.vector的capacity可以通过vector::reserve显式的设置固定大小
    void CapacityOpt()
    {
        std::vector<int>myvector;
        for (int i = 0; i < 100; ++i) {
            myvector.push_back(i);
        }
        std::cout<<"size: "<<myvector.size()<<std::endl;
        std::cout<<"capacity: "<<myvector.capacity()<<std::endl;
        std::cout<<"max_size: "<<myvector.max_size()<<std::endl;
    }


    //emplace
    //声明：/*template <class... Args>iterator emplace (const_iterator position, Args&&... args);*/
    //参数：position：新元素插入为止的迭代器；args：元素
    //返回值：返回指向新插入元素位置迭代器
    // 描述：通过在指定position插入新元素扩展容器
    //1.通过每次增加一个元素有效的扩展容器
    //2.如果扩展后size超过capacity会自动重新分配内存
    //3.类似的有insert：表示拷贝或者移动已经存在对象到容器中
    void EmplaceOpt()
    {
        std::vector<int>myvector={10,20,30};
        auto it = myvector.emplace(myvector.begin()+1,100);//在第二个位置插入100
        myvector.emplace(it,200);//在第二个位置插入200
        myvector.emplace(myvector.end(),300);//在最后一个位置插入300
        std::cout<<"myvector contains: ";
        for(auto &e:myvector)
            std::cout<<" "<<e;
        std::cout<<std::endl;
    }


    //emplace_back
    //声明：/*template <class... Args>void emplace_back (Args&&... args);*/
    //描述：在vector尾部插入新元素；类似的有push_back，该函数是拷贝或者移动已经存在的对象到容器中
    //参数：插入的值
    void Emplace_BackOpt()
    {
        std::vector<int>myvector={10,20,30};
//        myvector.push_back(100);
        myvector.emplace_back(100);
        myvector.emplace_back(200);
        std::cout<<"myvector contains: ";
        for(auto &e:myvector)
        {
            std::cout<<e<<" ";
        }
        std::cout<<'\n';
    }


}