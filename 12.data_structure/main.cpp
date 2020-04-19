/***************************************************************************
 * @file main.cpp
 * @author jeremiahyuansong
 * @date 2020/4/11
 * @brief 算法测试
 ***************************************************************************/

#include <iostream>
#include <memory>
#include <vector>

#include "binary_search.h"
#include "bubble_sort.h"
#include "select_sort.h"
#include "insert_sort.h"

enum SortType { kBubbleSort = 0, kSelectSort = 1, kInsertSort = 2 };

enum SearchType { kBinarySearchLinear = 0, kBinarySearchRecursive = 1 };

Sort *CreateSortMethod(SortType sort_type) {
  Sort *sort = nullptr;
  switch (sort_type) {
  case kBubbleSort:
    sort = new BubbleSort();
    break;
  case kSelectSort:
    sort = new SelectSort();
    break;
  case kInsertSort:
    sort = new InsertSort();
    break;
  default:
    sort = new BubbleSort();
    break;
  }
  return sort;
}

Search *CreateSearchMethod(SearchType search_type) {
  Search *search = nullptr;
  switch (search_type) {
  case kBinarySearchLinear:
    search = new BinarySearchIterate();
    break;
  case kBinarySearchRecursive:
    search = new BinarySearchRecursive();
    break;
  default:
    search = new BinarySearchIterate();
    break;
  }
  return search;
}

int main(int argc, char *argv[]) {
  auto log_data = [](const std::vector<int> &data) {
    for (auto num : data) {
      std::cout << num << "\t";
    }
    std::cout << std::endl;
  };
  std::vector<int> data = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
  std::cout << "before sort:" << std::endl;
  log_data(data);

#if 0
  // bubble sort
  std::unique_ptr<Sort> bubble_sort(CreateSortMethod(kBubbleSort));
  bubble_sort->DoSort(data);
#endif

#if 0
  // select sort
  std::unique_ptr<Sort> select_sort(CreateSortMethod(kSelectSort));
  select_sort->DoSort(data);
#endif

  // insert sort
  std::unique_ptr<Sort> insert_sort(CreateSortMethod(kInsertSort));
  insert_sort->DoSort(data);


  std::cout << "after sort:" << std::endl;
  log_data(data);

  // binary search:based on a sorted data vector
//  std::unique_ptr<Search> binary_seach(CreateSearchMethod(kBinarySearchLinear));
  std::unique_ptr<Search> binary_seach(CreateSearchMethod(kBinarySearchRecursive));
  int32_t not_exist = binary_seach->DoSearch(data, 20);
  int32_t exist = binary_seach->DoSearch(data, 8);
  std::cout << "not_exist=" << not_exist << ", exist index=" << exist
            << std::endl;
  return 0;
}
