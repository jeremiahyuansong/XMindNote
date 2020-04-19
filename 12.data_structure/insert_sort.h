/***************************************************************************
 * @file insert_sort.h
 * @author jeremiahyuansong
 * @date 2020/4/19
 * @brief 插入排序
 ***************************************************************************/
#ifndef DATA_STRUCT_12_DATA_STRUCTURE_INSERT_SORT_H_
#define DATA_STRUCT_12_DATA_STRUCTURE_INSERT_SORT_H_

#include "sort.h"

class InsertSort : public Sort {
public:
  InsertSort() = default;
  ~InsertSort() = default;
  void DoSort(std::vector<int> &data) override {
    for (size_t out = 1; out < data.size(); ++out) {
      int temp = data[out]; // 被挑出来在外面的人的身高
      size_t in = out;
      while (in != 0 && data[in - 1] >= temp) { // 里面人身高大于外面的，不是待插入位置，继续往里面找(--in)
        data[in] = data[in - 1];
        --in;
      }
      data[in] = temp;
    }
  }
};

#endif // DATA_STRUCT_12_DATA_STRUCTURE_INSERT_SORT_H_
