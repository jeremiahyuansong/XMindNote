/***************************************************************************
 * @file main.cpp
 * @author jeremiahyuansong
 * @date 2020/4/21
 * @brief
 ***************************************************************************/

#include <iostream>
#include <thread>
#include <vector>

#include "single_instance.h"

const size_t num = 20;

std::vector<long> results;

void DoSingleCreate(size_t index) {
  SingleInstanceLazyImp* instance = SingleInstanceLazyImp::GetInstance();
  results[index] = (long)instance;
}

int main(int argc, char *argv[]) {
  std::vector<std::thread> single_threads;
  single_threads.reserve(num);
  results.resize(num);
  for (size_t i = 0; i < num; ++i) {
    single_threads.emplace_back();
    auto& thread_item = single_threads[single_threads.size()-1];
    thread_item = std::thread(DoSingleCreate, i);
  }
  for (size_t i = 0; i < num; ++i) {
    single_threads[i].join();
  }
  for (auto addres : results) {
    std::cout << addres << std::endl;
  }
  std::cout << "hello world" << std::endl;
}