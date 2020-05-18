package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var line_dict = make(map[string]int)
	input := bufio.NewScanner(os.Stdin)
	for input.Scan() {
		if input.Text() == "end" {
			break
		}
		line_dict[input.Text()]++
	}
	for key, value := range line_dict {
		if value > 1 {
			fmt.Print("%s=%d\n", key, value)
		}
	}
}
