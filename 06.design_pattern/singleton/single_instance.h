/***************************************************************************
 * @file single_instance.h
 * @author jeremiahyuansong
 * @date 2020/4/21
 * @brief 单例模式（懒汉、饿汉）
 ***************************************************************************/
#ifndef DATA_STRUCT_06_DESIGN_PATTERN_SINGLE_INSTANCE_H_
#define DATA_STRUCT_06_DESIGN_PATTERN_SINGLE_INSTANCE_H_

#include <mutex>

/*
 * 懒汉模式 线程安全
 */
class SingleInstanceLazyImp {
 private:
  static std::mutex mtx_;
  static SingleInstanceLazyImp* instance_;
  SingleInstanceLazyImp() {}

 public:
  static SingleInstanceLazyImp* GetInstance();
};

// Non-const static data member must be initialized out of line
std::mutex SingleInstanceLazyImp::mtx_ = {};
SingleInstanceLazyImp* SingleInstanceLazyImp::instance_ = nullptr;

SingleInstanceLazyImp* SingleInstanceLazyImp::GetInstance() {
  if (instance_ == nullptr) {
    std::lock_guard<std::mutex> lk(mtx_);
    if (instance_ == nullptr) {
      instance_ = new SingleInstanceLazyImp();
    }
  }
  return instance_;
}

#endif  // DATA_STRUCT_06_DESIGN_PATTERN_SINGLE_INSTANCE_H_
