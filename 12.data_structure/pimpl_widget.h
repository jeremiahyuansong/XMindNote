/**
 * @file pimpl_widget.h
 * @author yuansong
 * @date 2020/7/8
 * @brief modern effective c++ 中关于智能指针应用于pimpl手法中的使用
 */

#ifndef DATA_STRUCT_12_DATA_STRUCTURE_PIMPL_WIDGET_H_
#define DATA_STRUCT_12_DATA_STRUCTURE_PIMPL_WIDGET_H_

#include <memory>

class PImplWidget {
 public:
  PImplWidget();
  // 若使用编译器隐式inline的析构函数，则会在定义PImplWidget的对象地方报错，因为此时的Impl结构是个非完整类型。
  // 智能指针unique_ptr在为Impl对象生成析构函数的时候，会遇到断言错误
  // 解决方法：声明对应的特种函数 但是不要实现 实现在cpp文件中去做
  ~PImplWidget();
  PImplWidget(PImplWidget&& rhs);
  PImplWidget& operator=(PImplWidget&& rhs);

  /**
   * do sth
   * @return
   */
  std::string WhoIAm();

 private:
  struct Impl;
  std::unique_ptr<Impl> pImpl;
};

#endif  // DATA_STRUCT_12_DATA_STRUCTURE_PIMPL_WIDGET_H_
