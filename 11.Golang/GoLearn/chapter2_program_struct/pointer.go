/**
 * @File: pointer.go
 * @Author: yuansong
 * @Date: 2020/4/11 10:30 上午
 * @Brief: 测试指针
 */

package main

var gloabal *int

func f() {
	a := 1
	p := &a
	gloabal = &a // 变量a从函数f中逃逸，生命周期在整个程序期间
}

func fun() *int {
	a := 2
	return &a
}

func main() {
	println(fun(), fun())
}
