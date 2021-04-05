/*
 * @Author       : yaowenzhou
 * @Date         : 2021-04-01 20:48:10
 * @LastEditors  : yaowenzhou
 * @LastEditTime : 2021-04-01 21:17:44
 * @version      :
 * @Description  :
 */
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  // 初始化一个空的unordered_set，默认构造器
  unordered_set<int> first;

  // 范围构造器
  int nums[5] = {0, 1, 2, 3, 4};
  unordered_set<int> second(nums, nums + 5);
  //复制构造器
  unordered_set<int> third(second);  //使用另一个set初始化
  unordered_set<int> fourth(second.begin(), second.end());  //使用迭代器构造
  // begin() 返回指向第一个元素的迭代器
  cout << "*second.begin() = " << *second.begin() << endl;
  // clear() 清除所有元素
  second.clear();
  cout << "second.size(): " << second.size() << endl;
  // count() 返回某个值元素的个数
  cout << "second.count(1): " << second.count(1) << endl;
  // empty() 如果集合为空，返回true
  if (second.empty()) {
    cout << "second is empty." << endl;
  } else {
    cout << "second is not empty." << endl;
  }
  // end() 返回指向最后一个元素之后位置的的迭代器
  // equal_range() 返回集合中与给定值相等的上下限的两个迭代器
  
  return 0;
}