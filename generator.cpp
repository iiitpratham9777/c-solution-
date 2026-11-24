#include <bits/stdc++.h>
using namespace std;
int main(int argc,char**argv){int n=argc>1?atoi(argv[1]):20; unsigned seed=argc>2?stoul(argv[2]):20261124; mt19937 rng(seed); vector<int>a(n);iota(a.begin(),a.end(),1);shuffle(a.begin(),a.end(),rng);cout<<n<<"\n";for(int i=0;i<n;i++)cout<<a[i]<<(i+1==n?'\n':' ');}
