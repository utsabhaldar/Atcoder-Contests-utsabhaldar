#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;
int N,M,A[2<<17],B[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int j=0;j<M;j++)cin>>B[j];
	sort(A,A+N);
	sort(B,B+M);
	int j=0;
	long ans=0;
	for(int i=0;i<M;i++)
	{
		while(j<N&&A[j]<B[i])j++;
		if(j==N)
		{
			cout<<-1<<endl;
			return 0;
		}
		ans+=A[j++];
	}
	cout<<ans<<endl;
}
