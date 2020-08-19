//진행중-테스트


import java.util.Scanner;
//맨 위 칸이 흰색이거나 검정색이거나
//입력: 행n, 열m, 각 생의 상태
//출력: 다시 칠해야 하는 정사각형 개수 최솟값
//그냥 검정 개수랑 하양 개수 비율맞추면 되는거아닌교..

public class Main {
	static char[][] arr;
	static int black = 0;
	static int white = 0;
	static int result=100;

	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		//System.out.println("기록의 갯수를 입력하세요");
		
		int n=sc.nextInt();
		int m=sc.nextInt();
		//m과 n은 8보다 크거나 같고, 50보다 작거나 같다
		arr = new char[n][m];
		
		for(int i=0; i<n; i++) {
			 String t = sc.next();
			for(int j=0;j<m;j++) {
				arr[i][j] = t.charAt(j);
			}
		}
		solve(arr, n-1,m-1);
		System.out.println(result);
			
	}

	public static void solve(char arr[][],int n,int m) {
		int temp='B';
		int change=0;
		
		if(n<=7||m<=7) return;

		if(arr[n][m]=='W')
		{
			for(int i=n-8;i<n;i++)
				for(int j=m-8;j<m;j++){
					if(arr[i][j]==temp)
						temp='W';
					else if(arr[i][j]!=temp)
						change++;
			}
		}
		
		else if (arr[n][m]=='B')
		{
			for(int i=n-8;i<n;i++)
				for(int j=m-8;j<m;j++){
					if(arr[i][j]!=temp)
						temp='B';
					else if(arr[i][j]==temp)
						change++;
			}
		}
		
		if(change<result) result=change;
		System.out.println(change);

		solve(arr,n-1,m);
		solve(arr,n,m-1);
	}
}
