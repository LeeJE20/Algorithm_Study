import java.util.Scanner;
//1182 부분수열의 합
//N개의 정수 수열, 양수인 부분수열 중 원소를 다 더한 값이 S가 되는 경우의 수
//입력 N과 S, 수열 N개의 정수
//합이 S가 되는 부분수열의 개수

public class  Main 
{
	static int[] arr;
	static int result;

	public static void main(String[] args) 
	{
		Scanner sc=new Scanner(System.in);

		int N=sc.nextInt();
		int S=sc.nextInt();
		
		arr = new int[N];
		
		for(int i=0; i<N; i++) {
				arr[i] = sc.nextInt();
		}
		
		Solve(0);

		System.out.println(result);
	}

	
	public static void Solve(int num){
		int sum=0;
		if(num>=N) return; 

		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				sum=sum+arr[i];
				if(sum=S) result++;
			}}

		solve(num+1);
	}
	
}

