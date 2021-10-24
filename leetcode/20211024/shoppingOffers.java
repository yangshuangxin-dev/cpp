import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    Map<List<Integer>, Integer> cache = new HashMap<List<Integer>, Integer>();

    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        return dfs(needs, price, special);
    }

    private int dfs(List<Integer> needs, List<Integer> price, List<List<Integer>> special) {
        if (cache.containsKey(needs)) {
            return cache.get(needs);
        }

        int ans = 0;
        for (int i = 0; i < needs.size(); i++) {
            ans += price.get(i) * needs.get(i);
        }

        for (int i = 0; i < special.size(); i++) {
            List<Integer> next = new ArrayList<Integer>(needs);
            boolean flag = true;
            for (int item = 0; item < price.size(); item++) {
                if (special.get(i).get(item) > needs.get(item)) {
                    flag = false;
                    break;
                }
            }

            if (!flag) {
                continue;
            }

            for (int item = 0; item < price.size(); item++) {
                next.set(item, next.get(item) - special.get(i).get(item));
            }

            ans = Math.min(ans, dfs(next, price, special) + special.get(i).get(price.size()));

        }

        cache.put(needs, ans);
        return ans;
    }
}