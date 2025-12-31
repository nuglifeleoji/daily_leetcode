package priority_queue;

import java.util.PriorityQueue;

public class lc_778 {
    public int swimInWater(int[][] grid) {
        PriorityQueue<int[]> pq=new PriorityQueue<>((a,b)->a[2]-b[2]);
        pq.add(new int[]{0,0,grid[0][0]});
        boolean[][] visited=new boolean[grid.length][grid[0].length];
        visited[0][0]=true;
        int time=0;
        int[] dx=new int[]{0,1,-1,0};
        int[] dy=new int[]{1    ,0,0,-1};
        while(!pq.isEmpty()){
            int[] g=pq.poll();
            time=Math. max(g[2], time);
            if(g[0]==grid.length-1 && g[1]==grid[0].length-1){
                return time;
            }
            for(int i=0;i<4;i++){
                int x=dx[i]+g[0];
                int y=dy[i]+g[1];
                if(x>=0 && x<grid.length && y>=0 && y<grid[0].length && !visited[x][y]){
                    visited[x][y]=true;
                    pq.add(new int[]{x,y,grid[x][y]});
                }
            }
        }
        return time;
    }
}
