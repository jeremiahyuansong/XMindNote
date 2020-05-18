/**
 * @File: assign.go
 * @Author: yuansong
 * @Date: 2020/4/11 11:27 上午
 * @Brief: 赋值
 */

package main

func main() {
	x := 1
	y := 2
	println("befor:%d,%d", x, y)
	x, y = y, x
	println("after:%d,%d", x, y)
}
