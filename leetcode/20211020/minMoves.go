package _test

func minMoves(nums []int)(ans int) {
	min:=nums[0]
	for _,num:=range nums {
		if num<min {
			min=num
		}
	}

	for _,num:= range nums {
		ans+=num-min
	}

	return
}