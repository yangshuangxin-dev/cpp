import java.util.stream.IntStream;

public class Solution {
    public int minMoves(int[] nums) {
        int min=IntStream.of(nums).min().getAsInt();
        return IntStream.of(nums).map(a->a-min).sum();
    }
}
