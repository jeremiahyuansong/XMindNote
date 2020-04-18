/***************************************************************************
 * @file bubble_sort.h
 * @author jeremiahyuansong
 * @date 2020/4/11
 * @brief 冒泡排序
 ***************************************************************************/

#ifndef XMINDNOTE_12_DATA_STRUCTURE_BUBBLE_SORT_H_
#define XMINDNOTE_12_DATA_STRUCTURE_BUBBLE_SORT_H_

#include <algorithm>

#include "sort.h"

class BubbleSort : public Sort {
public:
  BubbleSort() = default;
  ~BubbleSort() = default;
  void DoSort(std::vector<int> &data) override {
    for (size_t i = 0; i < data.size() - 1; ++i) {
      for (size_t j = 0; j < data.size() - i - 1; ++j) {
        if (data[j] > data[j + 1]) {
          std::swap(data[j], data[j + 1]);
        }
      }
    }
  }
};

#endif // XMINDNOTE_12_DATA_STRUCTURE_BUBBLE_SORT_H_
