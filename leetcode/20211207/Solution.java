import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

class Solution{
    public int[][] colorBorder(int[][] grid,int row,int col,int color) {
        int m=grid.length,n=grid[0].length;
        boolean[][] visted=new boolean[m][n];
        List<int[]> borders=new ArrayList<>();

        int originColor=grid[row][col];
        int[][] direc = {{0,1},{1,0},{0,-1},{-1,0}};
        Deque<int[]> q=new ArrayDeque<>();

        q.offer(new int[]{row,col});
        visted[row][col]=true;

        while(!q.isEmpty()) {
            int []node=q.poll();
            int x=node[0],y=node[1];

            boolean isBorder=false;
            for(int i=0;i<4;i++) {
                int nx=x+direc[i][0],ny=y+direc[i][1];

                if(!(nx>=0&&nx<m&&ny>=0&&ny<n&&grid[nx][ny]==originColor)) {
                    isBorder=true;
                } else if(!visted[nx][ny]) {
                    visted[nx][ny]=true;
                    q.offer(new int[]{nx,ny});
                }
            }

            if(isBorder) {
                borders.add(new int[]{x,y});
            }
        }

        for(int i=0;i<borders.size();i++) {
            int x=borders.get(i)[0],y=borders.get(i)[1];
            grid[x][y] = color;
        }

        return grid;

    }
}