package _test

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	len1, len2 := len(nums1), len(nums2)
	left, right := -1, -1
	sumLen := len1 + len2

	start1, start2 := 0, 0

	for i := 0; i <= sumLen/2; i++ {
		left = right
		if start1 < len1 && (start2 >= len2 || nums1[start1] < nums2[start2]) {
			right = nums1[start1]
			start1++
		} else {
			right = nums2[start2]
			start2++
		}
	}

	if sumLen&1 == 0 {
		return (float64(left) + float64(right)) / 2
	}

	return float64(right)

}
