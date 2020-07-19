/**
 * @file Observer.cpp
 * @author yuansong
 * @date 2020/7/19
 * @brief 用表格数据展示的例子说明观察者模式
 */

#include <iostream>
#include <unordered_set>

class Observer;

struct StockVokeData {
  size_t cow_exit = 0;
  size_t cow_not_exit = 0;
};

/**
 * 被观察对象
 */
class ObservableSubject {
 public:
  void Attach(Observer* observer) { observers_.insert(observer); }
  void Dettach(Observer* observer) { observers_.erase(observer); }
  void SetData(const StockVokeData& data) { data_ = data; }
  const StockVokeData GetData() const { return data_; }
  void Notify();

 private:
  std::unordered_set<Observer*> observers_{};
  StockVokeData data_{};
};

/**
 * 观察者接口
 */
class Observer {
 public:
  virtual void Update() = 0;
  virtual void SetData(const StockVokeData& data) { observable_subject_->SetData(data); }
  virtual ~Observer() {}

 protected:
  ObservableSubject* observable_subject_ = nullptr;
};

/**
 * 柱状图观察者实现
 */
class BarObserver : public Observer {
 public:
  BarObserver(ObservableSubject* stock_data) { observable_subject_ = stock_data; }

  void Update() override {
    // do sth with the new data
    std::cout << "draw bar with data cow exit=" << observable_subject_->GetData().cow_exit
              << ", cow not exit=" << observable_subject_->GetData().cow_not_exit << std::endl;
  }
};

/**
 * 饼图观察者实现
 */
class PieObserver : public Observer {
 public:
  PieObserver(ObservableSubject* stock_data) { observable_subject_ = stock_data; }
  void Update() override {
    // do sth with the new data
    std::cout << "draw pie with data cow exit=" << observable_subject_->GetData().cow_exit
              << ", cow not exit=" << observable_subject_->GetData().cow_not_exit << std::endl;
  }
};

void ObservableSubject::Notify() {
  for (const auto& iter : observers_) {
    iter->Update();
  }
}

int main(int argc, char* argv[]) {
  ObservableSubject observable_subject;
  observable_subject.SetData({60, 40});

  // 把被观察数据对象传递给观察者保留下来主要是为了后面在观察者中更改数据时使用
  Observer* bar_observer = new BarObserver(&observable_subject);
  Observer* pie_observer = new PieObserver(&observable_subject);

  // 观察者订阅数据
  std::cout << "observer subscribe data..." << std::endl;
  observable_subject.Attach(bar_observer);
  observable_subject.Attach(pie_observer);
  observable_subject.Notify();

  // 观察者取消订阅
  std::cout << "observer unsubscribe data..." << std::endl;
  observable_subject.Dettach(bar_observer);
  observable_subject.Notify();
  observable_subject.Attach(bar_observer);

  // 直接更改数据源更新数据
  std::cout << "update by change original data..." << std::endl;
  observable_subject.SetData({70, 30});
  observable_subject.Notify();

  // 通过更改bar视图更新数据
  std::cout << "update by change bar data..." << std::endl;
  bar_observer->SetData({50, 50});
  observable_subject.Notify();

  // 通过更改pie视图更新数据
  std::cout << "update by change pie data..." << std::endl;
  pie_observer->SetData({100, 0});
  observable_subject.Notify();

  delete bar_observer;
  delete pie_observer;
}
