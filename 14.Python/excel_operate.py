# -*- coding: UTF-8 -*-
# author: yuansong
# date: 2020-06-10
# description: xlwing操作表格

# 库安装的教程：包含mac和windows
# https://zhuanlan.zhihu.com/p/107086691
import xlwings as xw

# 创建excel实例，打开Excel
app = xw.App(visible=True, add_book=False)

# 打开工作簿
target = app.books.open(r"/Users/jeremiahyuan/Desktop/11.xls")
source = app.books.open(r"/Users/jeremiahyuan/Desktop/22220191129.xls")

# 在工作簿中打开工作表
sht_data = source.sheets["sheetname"]


ID_xz = "aaa"
ID_gx = "bbb"

# 配合for循环用下标读取工作表设置的变量
n = 1

# 循环范围需手动修改
for i in range(4, 160):
    # 获取原数据中身份证号，与户主关系，电话,姓名
    sfz = sht_data.range("I"+str(i)).value
    gx = sht_data.range("K"+str(i)).value
    tel = sht_data.range("AA"+str(i)).value
    name = sht_data.range("H"+str(i)).value

    print(sfz, gx, tel, name)

    if ((sht_data.range("E"+str(i)).value == ID_xz) and (sht_data.range("K"+str(i)).value == ID_gx)):
        # 根据下标获取工作表
        sht = target.sheets["Sheet" + str(n)]
        # 下面的数据是只在为户主的时候填写的
        print(str(i) + ":enter if")
        sht.range("C3").value = "xxxxx"+ID_xz

        # 修改工作表名称
        sht.name = name

        # 获取数据复制到新的表的对应位置
        sht.range("C4").value = name
        sht.range("B9").value = name
        sht.range("A9").value = gx
        # 身份证号码前加"'"可以完美复制
        sht.range("C9").value = "'"+sfz
        sht.range("F4").value = tel

        # n递增进入下一户人家
        n += 1
        # m重新赋值1
        m = 1
    else:
        print("enter else")
        # 获取数据复制到新的表的对应位置
        sht.range("B"+str(m+9)).value = name
        sht.range("A"+str(m+9)).value = gx
        sht.range("C"+str(m+9)).value = "'"+sfz
        m += 1

target.save()
target.close()
source.close()
app.quit()
