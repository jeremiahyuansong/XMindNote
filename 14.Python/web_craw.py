# -*- coding: UTF-8 -*-
# author: yuansong
# date: 2020-06-10
# description: 抓取福建气象数据

import requests
import lxml
import xlwt
import re
from lxml import etree
from bs4 import BeautifulSoup


# 乱码问题解决
def encode_format(req):
    if req.encoding == 'ISO-8859-1':
        encodings = requests.utils.get_encodings_from_content(req.text)
        if encodings:
            encoding = encodings[0]
        else:
            encoding = req.apparent_encoding

        return req.content.decode(
            encoding, 'replace')  # 如果设置为replace，则会用?取代非法字符；


def craw():
    file = xlwt.Workbook()
    table = file.add_sheet('有点6', cell_overwrite_ok=True)
    print('正在爬取，请稍等....')
    row_count = 0
    for n in range(1, 18):
        print('第' + str(n) + '页......')
        # 这个网址后缀不小心多加个l->"html"还不行,我也是醉了
        url = 'http://fj.cma.gov.cn/fzsqxj/zwgk/yjgl/yjxy_1571/index_' + \
            str(n) + '.htm'
        print(url)
        req = requests.get(url)
        encode_content = encode_format(req)

        # 打印网页原始内容
        # print(encode_content)

        soup = BeautifulSoup(encode_content, 'html.parser')
        list = []
        list = soup.find_all('ul', class_='pad-T10 list-ndbg')
        for i in range(len(list)):
            text = list[i]
            # print(text)
            soup2 = BeautifulSoup(str(text), 'lxml')
            li_list = []
            li_list = soup2.find_all('li')
            for j in range(len(li_list)):
                li_text = li_list[j]
                soup3 = BeautifulSoup(str(li_text), 'lxml')
                time = soup3.find('span').text
                text = soup3.find('a').text
                if ("解除" not in text):
                    continue
                if ("2019" not in time and "2018" not in time):
                    continue
                print(time)
                print(text)
                # 写表格的row_count行 第一二列
                table.write(row_count, 1, time)
                table.write(row_count, 2, text)
                row_count += 1
    file.save('C:/D/result.xls')


if __name__ == '__main__':
    craw()
