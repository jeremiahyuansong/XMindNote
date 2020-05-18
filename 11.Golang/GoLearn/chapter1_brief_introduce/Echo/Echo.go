package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var result string
	//// 常规for循环
	//for i := 1; i < len(os.Args); i++ {
	//	sep = " "
	//	result += sep + os.Args[i]
	//}
	//fmt.Println(result)

	//// 直接通过string的方法打印
	//fmt.Println(strings.Join(os.Args[0:], " "))

	//// 范围的for循环 打印索引和值的对组合
	for index, args := range os.Args[0:] {
		fmt.Println(strconv.Itoa(index) + "=" + args)
	}
	fmt.Println(result)
}
