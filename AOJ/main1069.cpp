#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;


LL gcd(LL x, LL y){
  if(y == 0) return x;
  return gcd(y, x%y);
}

int main(){
  LL N;
  while(cin>>N,N){
	const int NB = N * (N+1) /2;
	vector<LL> bs(NB);
	for(int i=0;i<NB;++i) cin >> bs[i];
	LL even = 0;
	for(int i=0;i<N;++i){
	  even = gcd(bs[i], even);
	}
	vector<LL> as(N);
	for(int i=0;i<N;++i)
	  as[i] = bs[i] / even;

	int idx = N;
	for(int i=0;i<N;++i){
	  for(int j=i+1;j<N;++j){
		if(as[i] * as[j] != bs[idx]){
		  LL lf = bs[idx] / as[i] / as[j];
		  //		  cout<<"!"<<i<<","<<j<<"->"<<lf<<endl;
		  lf = sqrt(lf);
		  even /= lf;
		  for(int k=0;k<N;++k)
			as[k] = bs[k] / even;
		}
		++idx;
	  }
	}
	
	cout << even << endl;
	sort(as.begin(), as.end());
	cout << as[0];
	for(int i=1;i<N;++i) cout << " " << as[i];
	cout << endl;
  }
  
  return 0;
}
