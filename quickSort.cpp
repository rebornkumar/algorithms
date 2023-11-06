#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&A,int start,int end)
{
	int pivot=A[end];
	int pIndex=start;
	for(int i=start;i<end;i++)
	{
		if(A[i]<=pivot)
		{
			swap(A[i],A[pIndex++]);
		}
	}
	swap(A[pIndex],A[end]);
	return pIndex;
}
void quickSort(vector<int>&A,int start,int end)
{
	if(start>=end)
	return ;
	int pIndex=partition(A,start,end);
	quickSort(A,start,pIndex-1);
	quickSort(A,pIndex+1,end);
}

int main()
{
	//code
	int N;
	cin>>N;
	vector<int>A(N,0);
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
	}
	quickSort(A,0,N-1);
	for(int i=0;i<N;i++)
	{
		cout<<A[i]<<"  ";
	}
	cout<<endl;
	
	
	//code
	return 0;
}
