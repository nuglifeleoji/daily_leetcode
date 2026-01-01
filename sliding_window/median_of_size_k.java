package sliding_window;

import java.util.TreeSet;

public class median_of_size_k{
    public double[] MedianOfSizeK(int[] nums, int k){
        double[] result=new double[nums.length-k+1];
        TreeSet<Integer> smaller=new TreeSet<>();
        TreeSet<Integer> larger=new TreeSet<>((a,b)->b-a);
        for(int i=0;i<k;i++){
            smaller.add(nums[i]);
        }
        for(int i=0;i<k/2;i++){
            larger.add(smaller.pollFirst());
        }
        result[0]=smaller.size()==larger.size()?(double)(smaller.first()+larger.first())/2:smaller.first();
        for(int i=k;i<nums.length;i++){
            if(!smaller.remove(nums[i-k])){
                larger.remove(nums[i-k]);
            }
            if(nums[i]<smaller.last()){
                smaller.add(nums[i]);
            }
            else{
                larger.add(nums[i]);
            }
            if(smaller.size()<larger.size()){
                smaller.add(larger.pollFirst());
            }
            result[i-k+1]=smaller.size()==larger.size()?(double)(smaller.first()+larger.first())/2:smaller.first();
        }
        return result;
    }
}