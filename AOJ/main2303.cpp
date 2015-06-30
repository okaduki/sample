#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

double choose(int n, int k){
  double res = 1.;
  for(int i=0;i<k;++i)
	res *= (n - i) * 1. / (k - i);
  return res;
}

double bin(double p, int M, int x, int T){
  double res = 0.;
  for(int i=0;i<=M;++i)
	res += choose(M,i) * pow(p,i) * pow(1-p,M-i) * i * T;
  return res;
}

int main(){
  int N, M, L; cin >> N >> M >> L;
  vector<int> P(N), T(N), V(N);
  for(int i=0;i<N;++i){
	cin >> P[i] >> T[i] >> V[i];
  }

  double S[110][100], prob[110][100];
  vector<double> ans(N,0);
  for(int i=0;i<N;++i){
	for(int j=0;j<=M;++j){
	  prob[i][j] = choose(M,j) * pow(P[i]/100.,j) * pow((100-P[i])/100.,M-j);
	  S[i][j] = L *1./V[i] + j*T[i];
	}
  }

  for(int i=0;i<N;++i)
	for(int j=0;j<=M;++j){
	  double p = 1.;
	  for(int i1=0;i1<N;++i1){
		if(i == i1) continue;
		double q = 0.;
		for(int j1=0;j1<=M;++j1){
		  if(S[i1][j1] > S[i][j])
			q += prob[i1][j1];
		}
		p *= q;
	  }
	  ans[i] += p * prob[i][j];
	}
  for(int i=0;i<N;++i)
	cout << fixed << setprecision(9) << ans[i] << endl;
  

  return 0;
}
