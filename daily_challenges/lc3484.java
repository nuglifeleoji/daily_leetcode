package daily_challenges;

import java.util.HashMap;

public class lc3484 {
    HashMap<Integer, int[]> graph;
    public lc3484(int rows) {
        graph=new HashMap<>();
        for(int i=1;i<=rows;i++){
            int[] g=new int[26];
            graph.put(i, g);
        }
    }
    
    public void setCell(String cell, int value) {
        char d=cell.charAt(0);
        String x=cell.substring(1);
        int g=Integer.parseInt(x);
        graph.get(g)[(int)(d-'A')]=value;
    }
    
    public void resetCell(String cell) {
        setCell(cell, 0);
    }
    
    public int getValue(String formula) {
        int start1=1;
        while(formula.charAt(start1)!='+'){
            start1++;
        }
        String m=formula.substring(1, start1);
        start1++;
        String y=formula.substring(start1);
        return compute(m)+compute(y);
    }
    public int compute(String m){
        if(m.charAt(0)>='A' && m.charAt(0)<='Z'){
            char t=m.charAt(0);
            String k=m.substring(1);
            int g=compute(k);
            return graph.get(g)[(int)(t-'A')];
        }
        else{
            return Integer.parseInt(m);
        }
    }
}