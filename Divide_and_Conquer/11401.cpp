// 2020-08-26 22:50 시작
// https://www.acmicpc.net/problem/11401
// 이항 계수 3 


#include<iostream>
#include<stdio.h>
using namespace std;

#define DNUM 1000000007
// #define DNUM 10 //테스트용


// int cT[2000001] = {1}; // 캐시테이블

int com(int n, int k)
{
	// cout<<"k = "<<k<<endl;
	if (n <= 2) return 1;
	if (k> (int)(n/2)) k = n-k;
	if (k == 0) return 1;
	
	
	if (k == 1) return n;
	
	int result = com(n-1, k-1) + com(n-1, k);
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
