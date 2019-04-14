package main

import "fmt"

func binarySearchIterative(arr []int, x int) int {
	left := 0
	right := len(arr)

	for left <= right {
		mid := (left + right) / 2
		if arr[mid] == x {
			return mid
		} else if x < arr[mid] {
			right = mid - 1
		} else if x > arr[mid] {
			left = mid + 1
		}
	}
	return -1
}

func binarySearchRecursive(arr []int, x int, left int, right int) int {
	mid := (left + right) / 2
	if left > right {
		return -1
	}
	if arr[mid] == x {
		return mid
	} else if x < arr[mid] {
		return binarySearchRecursive(arr, x, left, mid-1)
	} else {
		return binarySearchRecursive(arr, x, mid+1, right)
	}

}

func main() {
	arr := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}

	resultIterative := binarySearchIterative(arr, 15)
	resultRecursive := binarySearchRecursive(arr, 15, 0, len(arr))

	fmt.Printf("Element %d\n\nIterative result : %d\nRecursive result : %d\n", 15, resultIterative, resultRecursive)
}
