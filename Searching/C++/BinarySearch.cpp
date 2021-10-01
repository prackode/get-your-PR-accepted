#include<bits/stdc++.h>
using namespace std;
bool binsearch(vector<int> vec, int * pos,int x){
	int len=vec.size();
	int lb=0,rb=len-1;
	int mid,count=0;
	while(lb<=rb){
		mid=(lb+rb)/2;
		if(mid==x){
			*pos=mid;
			return true;
			count++;
		}
		else if(mid>x){
			rb=mid-1;
		}
		else if(mid<x){
			lb=mid+1;
		}
	}
	return false;
}

int main(){
	int n,pos;
	vector<int> vec;
	cout<<"Enter length of array"<<endl;
	cin>>n;
	cout<<"Enter elements"<<endl;
	while(n){
		int x;
		cin>>x;
		vec.push_back(x);
		n--;
	}
	sort(vec.begin(),vec.end());
	cout<<"Enter element to search for."<<endl;
	int x;
	bool status;
	cin>>x;
	status=binsearch(vec,&pos,x);
	if(status){
		cout<<"Found "<<x<<" at "<<pos<<" position"<<endl;
	}
	else if(!status){
		cout<<x<<" not found."<<endl;
	}
}