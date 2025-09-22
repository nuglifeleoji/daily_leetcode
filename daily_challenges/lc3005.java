package daily_challenges;

import java.util.HashMap;
public class lc3005 {
    public int maxFrequencyElements(int[] nums) {
        HashMap<Integer, Integer> map=new HashMap<>();
        for(int num: nums){
            map.put(num, map.getOrDefault(num, 0)+1);
        }
        int maxfreq=0;
        int ans=0;
        for(int y: map.keySet()){
            if(map.get(y)>maxfreq){
                maxfreq=map.get(y);
                ans=map.get(y);
            }
            else if(map.get(y)==maxfreq){
                ans+=map.get(y);
            }
        }
        return ans;
    }
}