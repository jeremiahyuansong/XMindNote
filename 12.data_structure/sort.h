/***************************************************************************
 * @file sort.h
 * @author jeremiahyuansong
 * @date 2020/4/11
 * @brief 排序基类
 ***************************************************************************/

#ifndef DATA_STRUCT_12_DATA_STRUCTURE_SORT_H_
#define DATA_STRUCT_12_DATA_STRUCTURE_SORT_H_

#include <vector>

class Sort {
public:
  Sort() = default;
  virtual ~Sort() {}
  virtual void DoSort(std::vector<int> &data) = 0;
};

#endif // DATA_STRUCT_12_DATA_STRUCTURE_SORT_H_
