/**
 * @File: fetch.go
 * @Author: yuansong
 * @Date: 2020/3/22 10:54 上午
 * @Brief: 获取给定网址的body内容并进行输出打印
 */

package main

import (
	"bytes"
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
)

func main() {
	input := os.Args[1:]
	var http_address string
	for _, url := range input {
		if !bytes.HasPrefix([]byte(url), []byte("http://")) {
			http_address = "http://" + url
			fmt.Printf("original url=%s\t new url=%s\n", url, http_address)
		} else {
			http_address = url
		}
		resp, err := http.Get(http_address)
		if err != nil {
			fmt.Fprint(os.Stdout, "get http error :%v\n", err)
			os.Exit(1)
		}
		body, err := ioutil.ReadAll(resp.Body)
		status := resp.Status
		resp.Body.Close()
		if err != nil {
			fmt.Fprint(os.Stdout, "read response body error%v\n", err)
			os.Exit(1)
		}
		fmt.Printf("%s", body)
		fmt.Printf("status=%s\n", status)
	}
}
