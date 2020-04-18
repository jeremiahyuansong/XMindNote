/***************************************************************************
 * @file search.h
 * @author jeremiahyuansong
 * @date 2020/4/16
 * @brief 查找基类
 ***************************************************************************/

#ifndef DATA_STRUCT_12_DATA_STRUCTURE_SEARCH_H_
#define DATA_STRUCT_12_DATA_STRUCTURE_SEARCH_H_

#include <vector>

class Search {
public:
  Search() = default;
  virtual ~Search() {}
  virtual int32_t DoSearch(const std::vector<int> &data, int target_data) = 0;
};
#endif // DATA_STRUCT_12_DATA_STRUCTURE_SEARCH_H_
