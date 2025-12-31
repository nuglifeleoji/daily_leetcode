package priority_queue;

import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;

public class lc_502 {
    class Solution {
        public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
            ArrayList<int[]> list=new ArrayList<>();
            for(int i=0;i<profits.length;i++){
                list.add(new int[]{profits[i], capital[i]});
            }
            Collections.sort(list, (a,b)->(a[1]-b[1]));
            PriorityQueue<int[]> unlocked=new PriorityQueue<>((a,b)->(b[0]-a[0]));
            int index=0;
            for(int i=0;i<k;i++){
                while(index<list.size() && w>=list.get(index)[1]){
                    unlocked.add(list.get(index));
                    index++;
                }
                if(unlocked.isEmpty()){
                    return w;
                }
                int[] t=unlocked.poll();
                w+=t[0];
            }
            return w;
        }
    }
}
