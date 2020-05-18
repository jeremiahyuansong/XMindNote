/**
 * @File: fetchall.go
 * @Author: yuansong
 * @Date: 2020/3/22 4:57 下午
 * @Brief: 并行获取多个网址
 */

package main

import (
	"fmt"
	"io"
	"io/ioutil"
	"net/http"
	"os"
	time2 "time"
)

func fetch(url string, ch chan<- string) {
	start := time2.Now()
	resp, err := http.Get(url)
	if err != nil {
		ch <- fmt.Sprint(err)
		return
	}
	count, err := io.Copy(ioutil.Discard, resp.Body)
	resp.Body.Close()
	if err != nil {
		ch <- fmt.Sprint(err)
		return
	}
	ch <- fmt.Sprint("count=%7d, time cost=0.2f%, %s", count,
		time2.Since(start).Seconds(), url)
}

func main() {
	start := time2.Now()
	// 创建一个传递string类型的管道 用于gocoroutine之间通信
	ch := make(chan string)
	for _, url := range os.Args[1:] {
		go fetch(url, ch)
	}
	for range os.Args[1:] {
		// 为什么符号是<-
		fmt.Println(<-ch)
	}
	fmt.Printf("%0.2f time cost", time2.Since(start).Seconds())
}
