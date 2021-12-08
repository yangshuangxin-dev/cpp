package _test

func maxSumOfThreeSubarrays(nums []int, k int) (ans []int) {
	var sum1, maxSum1, maxSum1Idx int
	var sum2, maxSum12, maxSum12Idx1, maxSum12Idx2 int
	var sum3, Total int

	for i := k * 2; i < len(nums); i++ {
		sum1 += nums[i-k*2]
		sum2 += nums[i-k]
		sum3 += nums[i]

		if i >= k*3-1 {
			if sum1 > maxSum1 {
				maxSum1 = sum1
				maxSum1Idx = i - 3*k + 1
			}

			if sum2+maxSum1 > maxSum12 {
				maxSum12 = sum2 + maxSum1
				maxSum12Idx1, maxSum12Idx2 = maxSum1Idx, i-k*2+1
			}

			if maxSum12+sum3 > Total {
				Total = maxSum12 + sum3
				ans = []int{maxSum12Idx1, maxSum12Idx2, i - k + 1}
			}

			sum1 -= nums[i-3*k+1]
			sum2 -= nums[i-2*k+1]
			sum3 -= nums[i-k+1]
		}
	}

	return
}
