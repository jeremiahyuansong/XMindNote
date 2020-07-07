/**
 * @file Builder.cpp
 * @author yuansong
 * @date 2020/7/7
 * @brief Builder构造器模式
 */

#include <iostream>
#include <memory>
#include <string>

using namespace std;

/**
 * 建筑材料
 */
enum class Material {
  MaoCao = 0,   ///< 茅草
  GuangSha = 1  ///< 砖瓦
};

/**
 * 房屋
 */
class House {
 public:
  string Get() {
    string result = "you have got a";
    if (foundation_ == Material::MaoCao && wall_ == Material::MaoCao && roof_ == Material::MaoCao) {
      result += " MaoCao House";
    } else if (foundation_ == Material::GuangSha && wall_ == Material::GuangSha &&
               roof_ == Material::GuangSha) {
      result += " GuangSha House";
    } else {
      result += " Wrong House";
    }
    return result;
  }
  void SetFoundation(Material material) { foundation_ = material; }
  void SetWall(Material material) { wall_ = material; }
  void SetRoof(Material material) { roof_ = material; }

 private:
  Material foundation_;  ///< 地基
  Material wall_;        ///< 墙
  Material roof_;        ///< 屋顶
};

/**
 * 建造接口类
 */
class Builder {
 public:
  virtual ~Builder() {}
  House GetHouse() { return house_; }
  virtual void BuilderFoundation() = 0;
  virtual void BuilderWall() = 0;
  virtual void BuilderRoof() = 0;

 protected:
  House house_;
};

/**
 * 茅草屋构建
 */
class MaoCaoBuilder : public Builder {
 private:
  void BuilderFoundation() override { house_.SetFoundation(Material::MaoCao); }
  void BuilderWall() override { house_.SetWall(Material::MaoCao); }
  void BuilderRoof() override { house_.SetRoof(Material::MaoCao); }
};

/**
 * 广厦屋构建
 */
class GuangShaBuilder : public Builder {
 private:
  void BuilderFoundation() override { house_.SetFoundation(Material::GuangSha); }
  void BuilderWall() override { house_.SetWall(Material::GuangSha); }
  void BuilderRoof() override { house_.SetRoof(Material::GuangSha); }
};

class HouseDirector {
 public:
  /// 盖房子
  void ConstructHouse() {
    // 下面的一系列步骤是一个相对稳定的构造过程
    // 实际情况可能是一个更加复杂的流程

    // 打地基
    builder_->BuilderFoundation();

    //墙
    builder_->BuilderWall();

    // 屋顶
    builder_->BuilderRoof();
  }

  void SetBuilder(Builder* builder) { builder_ = builder; }

  House GetHouse() { return builder_->GetHouse(); }

 private:
  Builder* builder_;
};

int main(int argc, char* argv[]) {
  auto house_director = make_unique<HouseDirector>();

  // 盖茅草屋
  unique_ptr<Builder> maocao_builder = make_unique<MaoCaoBuilder>();
  house_director->SetBuilder(maocao_builder.get());
  house_director->ConstructHouse();
  cout << house_director->GetHouse().Get() << endl;

  // 盖砖瓦房
  unique_ptr<Builder> guangsha_builder = make_unique<GuangShaBuilder>();
  house_director->SetBuilder(guangsha_builder.get());
  house_director->ConstructHouse();
  cout << house_director->GetHouse().Get() << endl;

  return 0;
}
