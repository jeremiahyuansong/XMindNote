/**
 * @file AbstractFactory.cpp
 * @author yuansong
 * @date 2020/6/16
 * @brief 抽象工厂模式
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * 滚动条组件接口类
 */
class ScrollBarItem {
 public:
  virtual ~ScrollBarItem() {}
  virtual void WhoAmI() const = 0;
};

/**
 * 窗口组件接口类
 */
class WidgetItem {
 public:
  virtual ~WidgetItem() {}
  virtual void WidgetInstallScrollBar(ScrollBarItem *scroll_bar) = 0;
  virtual void WhoAmI() const = 0;

 protected:
  bool scrollbar_installed_ = false;
};

/**
 * mac风格滚动条
 * 说明：接口的实现定义为private 意在说明这个接口只能通过基类指针进行调用
 *      而不能直接在子类的对象上进行调用，后面的均是这种风格
 */
class MacScrollBarItem : public ScrollBarItem {
 public:
  ~MacScrollBarItem() {}

 private:
  void WhoAmI() const override { cout << "i am MacScrollBarItem" << endl; }
};

/**
 * mac风格窗口
 */
class MacWidgetItem : public WidgetItem {
 public:
  ~MacWidgetItem() {}

 private:
  void WhoAmI() const override {
    string scrollbar_install_result = scrollbar_installed_ ? "with" : "without";
    cout << "i am MacWidgetItem " + scrollbar_install_result + " scrollbar" << endl;
  }

  void WidgetInstallScrollBar(ScrollBarItem *scoroll_bar) override {
    // do sth
    if (scoroll_bar) scrollbar_installed_ = true;
  }
};

/**
 * linux风格滚动条
 */
class LinuxScrollBarItem : public ScrollBarItem {
 public:
  ~LinuxScrollBarItem() {}

 private:
  void WhoAmI() const override { cout << "i am LinuxScrollBar" << endl; }
};

/**
 * linux风格窗口
 */
class LinuxWidgetItem : public WidgetItem {
 public:
  ~LinuxWidgetItem() {}

 private:
  void WhoAmI() const override {
    string scrollbar_install_result = scrollbar_installed_ ? "with" : "without";
    cout << "i am LinuxWidgetItem " + scrollbar_install_result + " scrollbar" << endl;
  }
  void WidgetInstallScrollBar(ScrollBarItem *scroll_bar) override {
    // do sth
    if (scroll_bar) scrollbar_installed_ = true;
  }
};

/**
 * 文件管理器创建工厂接口
 */
class FileManagerFactory {
 public:
  virtual ~FileManagerFactory() {}
  virtual WidgetItem *CreateWidget() = 0;
  virtual ScrollBarItem *CreateScrollBar() = 0;
};

/**
 * Mac风格的文件管理器工厂
 */
class MacFileManagerFactory : public FileManagerFactory {
 public:
  ~MacFileManagerFactory() {}

 private:
  WidgetItem *CreateWidget() override { return new MacWidgetItem(); }

  ScrollBarItem *CreateScrollBar() override { return new MacScrollBarItem(); }
};

/**
 * Linux风格的文件管理器工厂
 */
class LinuxFileManagerFactory : public FileManagerFactory {
 public:
  ~LinuxFileManagerFactory() {}

 private:
  WidgetItem *CreateWidget() override { return new LinuxWidgetItem(); }
  ScrollBarItem *CreateScrollBar() override { return new LinuxScrollBarItem(); }
};

int main(int argc, char *argv[]) {
  auto test_file_manager = [](FileManagerFactory* file_manager_factory) {
    // 利用抽象工厂创建组件(产品)
    WidgetItem *widget = file_manager_factory->CreateWidget();
    ScrollBarItem *scrollbar = file_manager_factory->CreateScrollBar();

    // 体现产品的关联特性——family
    widget->WidgetInstallScrollBar(scrollbar);

    // 产品干活--哈哈哈 听着像是研发不干活一样
    scrollbar->WhoAmI();
    widget->WhoAmI();

    // 回收产品--emm 当我没说
    delete scrollbar;
    delete widget;
  };
  // Mac风格的文件管理器
  FileManagerFactory *mac_file_manager_factory = new MacFileManagerFactory();
  test_file_manager(mac_file_manager_factory);
  delete mac_file_manager_factory;

  // Linux风格文件管理器
  FileManagerFactory *linux_file_manager_factory = new LinuxFileManagerFactory();
  test_file_manager(linux_file_manager_factory);
  delete linux_file_manager_factory;

  return 0;
}
