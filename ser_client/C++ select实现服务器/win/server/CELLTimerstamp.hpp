#pragma once
#ifndef _CELLTimerstamp_HPP_
#define _CELLTimerstamp_HPP_


#include<chrono>
using namespace std::chrono;

class CELLTimestamp
{
public:
	CELLTimestamp()
	{
		update();
	}
	~CELLTimestamp()
	{

	}
	//��ȡ��ǰ��
	double getElapsedSecond()
	{
		return getElapsedTimeInMicroSec()*0.000001;
	}
	//��ȡ����
	double getElapsedTimeInMilliSec()
	{
		return this->getElapsedTimeInMicroSec() *0.001;
	}
	//��ȡ΢�� 
	long long getElapsedTimeInMicroSec()
	{
		return duration_cast<microseconds>(high_resolution_clock::now() - _begin).count();
		
	}
	void update()
	{
		_begin = high_resolution_clock::now();
	}
private:
	time_point<high_resolution_clock> _begin;
};


#endif // !_CELLTimerstamp_HPP_