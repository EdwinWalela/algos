package main

import "fmt"

// Calculate and print the sum of the elements in an array,
// keeping in mind that some of those integers may be quite large.

func aVeryBigSum(arr []int64) int64 {
	var total int64
	for _, v := range arr {
		total += int64(v)
	}
	return total
}

func main() {
	result := aVeryBigSum([]int64{1000000000, 100000000, 100000000, 100000000, 100000000})
	fmt.Println(result)
}
