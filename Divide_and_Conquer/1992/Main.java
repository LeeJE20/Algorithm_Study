
import java.util.Scanner;
//분할 정복 쿼드 트리
//

public class Main {
	static int[][] arr;

	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
			
		int N=sc.nextInt();

		arr = new int[N][N];
		
		for(int i=0; i<N; i++) {
			String t = sc.next();
			for(int j=0;j<N;j++) {
				arr[i][j] = Character.getNumericValue(t.charAt(j));
			}
		}

		quadtree(arr, N,N,N);
		
		//System.out.println(result);		
	}
	public static boolean same(int point, int arr[][]){
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++){
				if(arr[i][j]!=point) return false;}

		return true;
	}

	public static void quadtree(int arr[][],int startx,int starty,int size) {

		int point=arr[startx][starty];
		
		if(same(point,arr)){	System.out.println(point);}
		else 
		{
		System.out.println("(");
		quadtree(arr,startx,starty,size/2); //1
		quadtree(arr,startx/2,starty,size/2); //2
		quadtree(arr,startx,starty/2,size/2); //3
		quadtree(arr,startx/2,starty/2,size/2); //4}
		System.out.println(")");
	}
}
}
