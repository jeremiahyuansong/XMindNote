/**
 * @File: webserver.go
 * @Author: yuansong
 * @Date: 2020/3/22 5:17 下午
 * @Brief: 实现一个简单的webserver响应用户请求
 * 			端口监听8000
 */

package main

import (
	"fmt"
	"log"
	"net/http"
)

func handler(rsp http.ResponseWriter, req *http.Request) {
	fmt.Fprintf(rsp, "URL.Path = %q\n", req.URL.Path)
}

func main() {
	http.HandleFunc("/", handler)
	log.Fatal(http.ListenAndServe("localhost:8000", nil))
}
