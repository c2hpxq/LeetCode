## [区间求和](https://github.com/c2hpxq/LeetCode/blob/master/2659_Make_Array_Empty/range_sum.cpp)
- 将位于数组开头的元素放到数组末尾，向后逐个元素遍历数组 等价于 遍历环形数组
- 问题可以转化为数环形数组上**大小相邻**的元素间的元素个数，可以使用支持
  - 区间和查询
  - 单点插入
  
  的数据结构

## [单趟消除单调递增](https://github.com/c2hpxq/LeetCode/blob/master/2659_Make_Array_Empty/eliminate_increasing.cpp)
从头开始扫描**一遍**数组的代价=数组中元素个数，将会删除当前数组中以最小元素开始的上升序列