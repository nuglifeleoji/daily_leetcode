package daily_challenges;

import java.util.HashMap;
import java.util.List;
import java.util.PriorityQueue;

public class lc3408 {
    //taskid-priority
    HashMap<Integer, Integer> graph1=new HashMap<>();
    //taskid-userid
    HashMap<Integer, Integer> graph2=new HashMap<>();
    PriorityQueue<int[]> pq=new PriorityQueue<>((a,b)->{
        if(a[2]!=b[2]){
            return b[2]-a[2];
        }
        else{
            return b[1]-a[1];
        }
    });
    public lc3408(List<List<Integer>> tasks) {
        for(List<Integer> task: tasks){
            graph1.put(task.get(1), task.get(2));
            graph2.put(task.get(1), task.get(0));
            pq.add(new int[]{task.get(0), task.get(1), task.get(2)});
        }
    }
    
    public void add(int userId, int taskId, int priority) {
        graph1.put(taskId, priority);
        graph2.put(taskId, userId);
        pq.add(new int[]{userId, taskId, priority});
    }
    
    public void edit(int taskId, int newPriority) {
        graph1.put(taskId, newPriority);
        int userId=graph2.get(taskId);
        pq.add(new int[]{userId, taskId, newPriority});
    }
    
    public void rmv(int taskId) {
        graph1.remove(taskId);
        graph2.remove(taskId);
    }
    
    public int execTop() {
        while(!pq.isEmpty() && ((!graph1.keySet().contains(pq.peek()[1])) || graph1.get(pq.peek()[1]) != pq.peek()[2] ||  graph2.get(pq.peek()[1]) != pq.peek()[0])){
            pq.poll();
        }
        if(pq.isEmpty()){
            return -1;
        }
        int[] s=pq.poll();
        rmv(s[1]);
        return s[0];
    }
}

