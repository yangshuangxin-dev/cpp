package _test

func majorityElement(nums []int) (ans []int) {
	cnt := map[int]int{}
	for _, v := range nums {
		cnt[v]++
	}

	max := len(nums) / 3

	for k, v := range cnt {
		if v > max {
			ans = append(ans, k)
		}
	}

	return
}
