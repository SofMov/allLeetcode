/**
 * LeetCode 1833 solved:
 * Using a priority queue store all values below amount of coins
 * Take smallest number one by one from priority queue until either the queue ends or coins end
 * return the amount of numbers taken from the priority queue
 * Time Complexity: O(n log(n))) (adding all items), Space Complexity:O(n) (pq could contain all elements in cost)
 */
import java.util.PriorityQueue;

class Solution {
    public int maxIceCream(int[] costs, int coins) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int cnt = 0;
        for(Integer cost : costs){
            if(cost <= coins){
                pq.add(cost);
            }
        }
        while(!pq.isEmpty() && coins > 0){
            System.out.println("Removing "+pq.peek()+", have "+coins+" coins available\n");
            coins -= pq.poll();
            cnt++;
        }
        if(coins<0){
            cnt--;
        }
        return cnt;
    }
}