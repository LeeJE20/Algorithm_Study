#include <iostream>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	
	int nums[100];
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	
	int result=0;
	
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				if(nums[i]+nums[j]+nums[k]<=m&&m-(nums[i]+nums[j]+nums[k])<=m-result)
					result=nums[i]+nums[j]+nums[k];
			}
		}
	}
	
	cout<<result;
}
