import java.io.*;
import java.util.*;

public class NQueens{
    

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        boolean[][] chess = new boolean[n][n];
        nqueens(chess, 0, "");
    }

    private static void nqueens(boolean[][] chess,int r,String asf){
        // if(r==chess.length && c==0){
        //     if(qsf==chess.length)
        //         System.out.println(asf+".");
        //     return;    
        // }
        // else if(c==chess.length-1){
        //     nqueens(chess,r+1,0,qsf,asf);
        //     if(isQueenSafe(chess, r, c)==true){
        //         chess[r][c]=true;
        //         nqueens(chess, r+1, 0, qsf+1, asf+r+"-"+c+", ");
        //         chess[r][c]=false;
        //     }
        // }
        // else{
        //     nqueens(chess,r,c+1,qsf,asf);
        //     if(isQueenSafe(chess, r, c)==true){
        //         chess[r][c]=true;
        //         nqueens(chess, r, c+1, qsf+1, asf+r+"-"+c+", ");
        //         chess[r][c]=false;
        //     }
        // }
        if(r == chess.length){
            System.out.println(asf+".");
            return;
        }
        for(int col=0;col<chess.length;col++){
            if(isQueenSafe(chess, r, col)==true){
                chess[r][col] = true;
                nqueens(chess, r+1, asf+r+"-"+col+", ");
                chess[r][col] = false;
            }
        }
    }
    private static boolean isQueenSafe(boolean[][]  chess,int i,int j){
        for(int k=i-1;k>=0;k--)
            if(chess[k][j]==true)
                return false;
        for(int k=j-1;k>=0;k--)
            if(chess[i][k]==true)
                return false;
        for(int k=i-1,l=j-1;k>=0 && l>=0;k--,l--)
            if(chess[k][l]==true)
                return false;
        for(int k=i-1,l=j+1;k>=0 && l<chess[0].length;k--,l++)
            if(chess[k][l]==true)
                return false;                
        return true;        
    }
}