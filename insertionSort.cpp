#include<bits/stdc++.h>
using namespace std;
void inSort(vector<int>&A,int N)
{
    for(int i=1;i<N;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(A[j]<A[j-1])
            {
                swap(A[j-1],A[j]);
            }
        }
    }
    return;
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
    for(int i=0;i<N;i++)
    cout<<A[i]<<"  ";
    cout<<""<<endl;
    inSort(A,N);
    for(int i=0;i<N;i++)
    cout<<A[i]<<"  ";
    cout<<""<<endl;
    //code 
    return 0;
}
