/**
 * @file pimpl_widget.cpp
 * @author yuansong
 * @date 2020/7/8
 * @brief modern effective c++ 中关于智能指针应用于pimpl手法中的使用
 */

#include "pimpl_widget.h"

#include <vector>

struct PImplWidget::Impl {
  std::string name{"yuansong"};
  std::vector<size_t> position{};
};

PImplWidget::PImplWidget() : pImpl(std::make_unique<Impl>()) {}

// 默认实现析构
PImplWidget::~PImplWidget() = default;

// 默认实现的移动构造函数
PImplWidget::PImplWidget(PImplWidget&& rhs) = default;

// 默认实现的移动赋值运算符
PImplWidget& PImplWidget::operator=(PImplWidget&& rhs) = default;

std::string PImplWidget::WhoIAm() { return "i am a pimpl widget " + pImpl->name; }
