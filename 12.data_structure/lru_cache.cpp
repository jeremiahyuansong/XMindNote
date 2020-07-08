/***************************************************************************
 * @file lru_cache.cpp
 * @author jeremiahyuansong
 * @date 2020/5/9
 * @brief 利用标准库的hash_map和list实现的lru缓存
 ***************************************************************************/

#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <unordered_map>

using namespace std;

template <typename K, typename V>
class LRUCache {
public:

  struct CacheData {
    K key;
    V data;
  };

  typedef std::shared_ptr<CacheData> CacheDataPtr;

  explicit LRUCache(const size_t &size)
      : cache_data_map_(), cache_data_list_(), cache_size_(size) {}

  ~LRUCache() = default;

public:
  std::shared_ptr<V> Get(string key) {
    auto find_item = cache_data_map_.find(key);
    if (find_item != cache_data_map_.end()) {
      // 也需要移动到链表头部
      cache_data_list_.remove(find_item->second);
      cache_data_list_.push_front(find_item->second);
      return find_item->second;
    }
    return CacheDataPtr(nullptr);
  }

  bool Put(const string &key, CacheDataPtr cache_data) {
    auto find_item = cache_data_map_.find(key);
    if (find_item != cache_data_map_.end()) {
      // 先删除 后面移动到链表头部
      cache_data_list_.remove(find_item->second);
    } else if (cache_data_list_.size() >= cache_size_) {
      // 淘汰尾部元素
      cache_data_map_.erase(cache_data_list_.back()->key);
      cache_data_list_.pop_back();
      cache_size_--;
    }
    // 插入到链表头部
    cache_data_list_.push_front(cache_data);
    cache_data_map_[key] = cache_data;
    cache_size_++;
    return true;
  }

private:
  unordered_map<string, CacheDataPtr> cache_data_map_; ///< 查询
  list<CacheDataPtr> cache_data_list_;                 ///< 存储
  size_t cache_size_;                                  ///< 缓存大小
};
