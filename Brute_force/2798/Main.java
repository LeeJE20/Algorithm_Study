//테스트


import java.util.Scanner;
//블랙잭 규칙
//n개의 카드 중에서 3장의 카드를 뽑아서
//뽑은 카드의 수의 합 중 M보다 작은 값을 구해 출력
//입력: n카드수, m기준값, 카드 숫자
//출력: 최대합
public class Main {
//	int total;
	static int[] picked;
	static int result;

	public static void blackjack(int max, int arr[]) {
		int picked[]=new int[3];
		int total=0;

		pick(max,arr,arr.length);
		for(int i=0;i<picked.length;i++)
			total=total+picked[i];
		if(total>result && total<max) result=total;
		//3장의 합 구하기
	}

	public static void pick(int n,int arr[], int topick) {
		//재귀 사용 카드 세 장 뽑기  
		if(topick==0) {return;} //뽑은 원소 출력
		boolean y=true;
		if(picked==null) y=false;
		int smallest= y? 0:picked[topick]+1;
		for(int next=smallest;next<arr.length;++next) { 
			picked[topick]=next;
			pick(n,picked,topick-1);}
			//picked.pop_back(); //왜 하는거지?
		
		}

	
	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		//System.out.println("기록의 갯수를 입력하세요");
		
		int num=sc.nextInt();
		int max=sc.nextInt();
		
		int arr[]=new int[num];
		for(int i=0;i<arr.length;i++) {
			arr[i]=sc.nextInt();
		}
		
		blackjack(max,arr);
		System.out.println(result);
	}
}
