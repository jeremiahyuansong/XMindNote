/***************************************************************************
 * @file binary_search.h
 * @author jeremiahyuansong
 * @date 2020/4/17
 * @brief 二分查找法
 ***************************************************************************/

#ifndef DATA_STRUCT_12_DATA_STRUCTURE_BINARY_SEARCH_H_
#define DATA_STRUCT_12_DATA_STRUCTURE_BINARY_SEARCH_H_

#include "search.h"

/*
 * @brief 线性二分查找
 */
class BinarySearchIterate : public Search {
public:
  BinarySearchIterate() = default;
  ~BinarySearchIterate() {}
  int32_t DoSearch(const std::vector<int> &data, int target_data) override {
    if (data.empty()) {
      return -1;
    }
    size_t left = 0, right = data.size() - 1;
    size_t index = 0;
    while (left <= right) {
      index = (left + right) / 2;
      if (data[index] == target_data) {
        return index;
      } else if (data[index] > target_data) {
        right = index - 1;
      } else {
        left = index + 1;
      }
    }
    return -1;
  }
};

/*
 * @brief 递归二分查找
 */
class BinarySearchRecursive : public Search {
public:
  BinarySearchRecursive() = default;
  ~BinarySearchRecursive() = default;
  int32_t DoSearch(const std::vector<int> &data, int target_data) override {
    if (data.empty()) {return -1;}
    return DoSearchImp(data, target_data, 0, data.size() - 1);
  }

private:
  int32_t DoSearchImp(const std::vector<int> &data, int target_data, size_t left, size_t right) {
    if (left <= right) {
      size_t idx = (left + right)/2;
      if (data[idx] == target_data) {
        return idx;
      } else if (data[idx] < target_data) {
        return DoSearchImp(data, target_data, idx + 1, right);
      } else if (data[idx] > target_data) {
        return DoSearchImp(data, target_data, left, idx - 1);
      }
    }
    return -1;
  }
};
#endif // DATA_STRUCT_12_DATA_STRUCTURE_BINARY_SEARCH_H_
