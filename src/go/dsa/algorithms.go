package dsa

import "cmp"

func BinarySearchList[CT cmp.Ordered](list MyList[CT], key CT) int {
	return -1
}

func BinarySearchListIndices[CT cmp.Ordered](list MyList[CT],
	startIndex, endIndex uint, key CT) int {
	return -1
}

func BinarySearchArray[CT cmp.Ordered](array []CT, key CT) int {
	return -1
}

func BinarySearchArrayIndices[CT cmp.Ordered](array []CT,
	startIndex, endIndex uint, key CT) int {
	return -1
}

func MergesortList[CT cmp.Ordered](list MyList[CT]) {

}

func MergesortArray[CT cmp.Ordered](array []CT) {

}

func QuicksortList[CT cmp.Ordered](list MyList[CT]) {

}

func QuicksortArray[CT cmp.Ordered](array []CT) {

}

func HeapsortList[CT cmp.Ordered](list MyList[CT]) {

}

func HeapsortArray[CT cmp.Ordered](array []CT) {

}
