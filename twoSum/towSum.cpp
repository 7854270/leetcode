/*
问题描述:给定一个整数数组和一个目标值找出数组中和为目标值的两个数,且同样的元素不能被重复利用。
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target);


int main()
{
	//测试部分
	vector<int> nums{ 1,4,3,5 };  //声明并初始化向量
	cout << twoSum(nums, 2)[0] << " " << twoSum(nums, 2)[1];  //打印能够组成目标值元素的下标以逻辑序号开始
	return 0;
}

vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> res;  
	multimap<int,int> numsMap;
	multimap<int,int>::iterator iter;  //定义迭代器为了访问容器元素
	int max = nums.size(); //容器大小

	//数组转进numsMap以元素为key,以下标为value
	for (int i = 0; i < max; i++)
	{
		numsMap.insert(pair<int,int>(nums[i], i + 1));
	}

	//遍历容器查找是否存在能组成目标值的两个元素
	for (iter = numsMap.begin(); iter != numsMap.end(); iter++)
	{
		//判断条件为成功查找到存在目标值的差值并且目标值不能以相同下标值的和组成
		if (numsMap.find(target - iter->first) != numsMap.end() &&
			numsMap.find(target - iter->first)->second != iter->second)
		{
		
			res.push_back(numsMap.find(target - iter->first)->second); 	//将差值加入向量尾部
			res.push_back(iter->second); //将符号条件的另外一个元素加入向量尾部
			sort(res.begin(), res.end()); //默认按升序排列
			break;
		}
	}
	return res;
}
