package _test

func shoppingOffers(price []int, special [][]int, needs []int) int {
	n := len(price)
	dp := map[string]int{}

	var dfs func([]byte) int
	dfs = func(curNeeds []byte) (minPrice int) {
		if res, has := dp[string(curNeeds)]; has {
			return res
		}

		for i, p := range price {
			minPrice += int(curNeeds[i]) * p
		}
		nextNeeds := make([]byte, n)
	outer:
		for _, s := range special {
			for i, need := range curNeeds {
				if need < byte(s[i]) {
					continue outer
				}
				nextNeeds[i] = need - byte(s[i])
			}
			minPrice = min(minPrice, dfs(nextNeeds)+s[n])

		}
		dp[string(curNeeds)] = minPrice
		return
	}
	curneeds := make([]byte, n)
	for i, need := range needs {
		curneeds[i] = byte(need)
	}
	return dfs(curneeds)
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}


