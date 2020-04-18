/***************************************************************************
 * @file select_sort.h
 * @author jeremiahyuansong
 * @date 2020/4/12
 * @brief 选择排序
 ***************************************************************************/

#ifndef DATA_STRUCT_12_DATA_STRUCTURE_SELECT_SORT_H_
#define DATA_STRUCT_12_DATA_STRUCTURE_SELECT_SORT_H_

#include <vector>

class SelectSort : public Sort {
public:
  SelectSort() = default;
  ~SelectSort() = default;
  void DoSort(std::vector<int> &data) {
    for (size_t i = 0; i < data.size() - 1; ++i) {
      size_t min = i;
      for (size_t j = i + 1; j < data.size(); ++j) {
        if (data[j] < data[min]) {
          min = j;
        }
      }
      std::swap(data[i], data[min]);
    }
  }
};
#endif // DATA_STRUCT_12_DATA_STRUCTURE_SELECT_SORT_H_
