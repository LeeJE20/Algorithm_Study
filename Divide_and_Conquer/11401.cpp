// 2020-08-26 22:50 시작
// https://www.acmicpc.net/problem/11401
// 이항 계수 3 


#include<iostream>
#include<stdio.h>
using namespace std;

#define DNUM 1000000007
// #define DNUM 10 //테스트용


int cT[2000001] = {1}; // 캐시테이블

int com(int n, int k)
{
	// cout<<"k = "<<k<<endl;
	if (n <= 2) return 1;
	if (k> (int)(n/2)) k = n-k;
	if (k == 0) return 1;
	
	
	if (k == 1) return n;
	
	// cout<<"k = "<<k<<endl;
	// 하나 작게 구함. 마지막줄은 다른 루프..
	for (int i = 3; i < n ; i++)
	{
		// printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~i = %3d   \n", i);
		int tmp1 = -1;
		int tmp2 = -1;
		// printf("(int)(i/2 +1) = %d\n", (int)(i/2 +1));
		
		
		
		
		
		for (int j = 1; (j<(int)(i/2 +1)) && (j < k+1) ; j++)
		// for (int j = 1; (j<(int)(i/2 +1)) ; j++)
		{
			
			if (j == 1) 
			{
				tmp1 = 1;
				tmp2 = cT[j];
				cT[j] = i;
				// printf("j == 1일때 %3d \n", cT[j]);

			}
			else if ((i %2 == 0) && (j == (i/2))) // 배열 칸 수 늘어나는 부분
			{
				cT[j] = tmp2+tmp2;
				// printf("j = %3d 일때 배열 칸 수 늘어나서 %3d \n",j,  cT[j]);
			}
			else
			{
				tmp1 = tmp2;
				tmp2 = cT[j];
				cT[j] = tmp1 + tmp2;
				
				// printf("j = %3d 일때 평범하게 %3d \n",j,  cT[j]);
			}
			
			
			if (cT[j] >= DNUM) cT[j] -=DNUM; // DNUM 넘지 않게
			// printf("DNUM 조정하여 cT[%d] = %3d \n\n", j, cT[j]);
		}
	}
	
	int result = -1;
	// printf("cT[%d], cT[%d]= %3d, %3d\n",k-1, k, cT[k-1], cT[k] );
	if (  (n %2 == 0) && (k == (n/2))    )
		result = cT[k-1]+ cT[k-1];
	else
		result = cT[k-1]+ cT[k];
		
	// printf("result : %3d \n\n", result);
	if (result >= DNUM) result -= DNUM; 
	
	return result;
}


int main()
{
	// cout<<endl<<"11401 시작"<<endl;
	
	cin.sync_with_stdio(false);
	int n;
	int k;
	
	cin >> n >> k;
	
	int result = com(n, k);
	
	cout<< result;
}
