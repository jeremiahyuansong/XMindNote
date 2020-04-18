## 数据结构和算法  
B站上面的学习视频，通俗易懂，简单入门，该笔记用来简单记录。  
https://www.bilibili.com/video/BV1AW411k7rw?p=4

### 文件结构
```
├── CMakeLists.txt
├── main.cpp           
├── readme.md
|── sort.h              // 排序基类
├── select_sort.h       // 选择排序
├── bubble_sort.h       // 冒泡排序
├── search.h            // 查找基类
└── xxxxx 
```


### 冒泡排序

- 算法思路：每轮将最大的数据选择出来，放在数据队列的最右侧
- 时间复杂度：O(n^2)

```c++
  void DoSort(std::vector<int> &data) {
    for (size_t i = 0; i < data.size() - 1; ++i) {
      for (size_t j = 0; j < data.size() - i - 1; ++j) {
        if (data[j] > data[j + 1]) {
          std::swap(data[j], data[j + 1]);
        }
      }
    }
  }
```

### 选择排序
- 算法思路：每轮将最小的数据放在队列的最左侧，左侧构成一个有序队列。其中，每轮的最小数据先用标记位标志，最后进行交换。
- 时间复杂度: O(n^2)

```c++
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
```