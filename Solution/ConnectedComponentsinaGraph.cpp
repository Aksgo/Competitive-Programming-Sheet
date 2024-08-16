#include <bits/stdc++.h>
using namespace std;
#define rep(i,st,n) for(int i=st; i<n; i++)
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
void dfs(int vertex){
	vis[vertex]=true;
	for(int child : g[vertex]){
		if(!vis[child]){
			dfs(child);
		}
	}
}
int main(){
	int n,e;
	cin>>n>>e;
	rep(i,0,e){
		int v1,v2;
		cin>>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	int ct=0;
	rep(i,1,n+1){
		if(!vis[i])dfs(i),ct++;
	}
	cout<<ct;
}
