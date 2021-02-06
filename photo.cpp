//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct u{
	int qs,zs,cz;
}ans[10010]; 
u cl[10010];
int cljs;
int n,anw,anws;
bool cmp(u a,u b){
	return a.cz>b.cz;
}
bool cmpw(u a,u b){
	return a.cz<b.cz;
}
int zsh,qsh;
int szcsh=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ans[++szcsh].zs>>ans[szcsh].qs;
		if(ans[szcsh].zs<0 && ans[szcsh].qs<0) szcsh--;
		ans[szcsh].cz=ans[szcsh].zs+ans[szcsh].qs;
	}
	sort(ans+1,ans+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(anw>anw+ans[i].cz){
			anws=i-1;
		}
		else{
			anw+=ans[i].cz;
		}
	}
	for(int i=1;i<=anws;i++){
		zsh+=ans[i].zs;
		qsh+=ans[i].qs;
	}
	if(zsh<0){
		for(int i=1;i<=anws;i++){
			if(ans[i].zs<0){
				cl[++cljs]=ans[i];
		//		cl[cljs].cz=-1*cl[cljs].zs-cl[cljs].qs; 
			}
		}
		sort(cl+1,cl+1+anws,cmpw);
		for(int i=1;i<=anws;i++){
			int ll=zsh-cl[++cljs].zs;
			if(ll>=0){
				break;
			}
			else{
				zsh=ll;
				anw-=cl[cljs].cz; 
			}
		}
	}
	if(qsh<0){
		for(int i=1;i<=anws;i++){
			if(ans[i].qs<0){
				cl[++cljs]=ans[i];
		//		cl[cljs].cz=-1*cl[cljs].zs-cl[cljs].qs; 
			}
		}
		sort(cl+1,cl+1+anws,cmpw);
		for(int i=1;i<=anws;i++){
			int llt=qsh-cl[++cljs].qs;
			if(llt>=0){
				break;
			}
			else{
				qsh=llt;
				anw-=cl[cljs].cz; 
			}
		}
	}
	cout<<anw;
	return 0;
}
