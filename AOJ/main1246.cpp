#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define FF first
#define SS second

const int MAX = 370;
const int INF = 1e9;
int dp[2][MAX][MAX];
int main(){
  int N;
  while(cin>>N,N){
	vector<pair<PII,int>> xs(N);
	for(int i=0;i<N;++i)
	  cin >> xs[i].FF.FF >> xs[i].FF.SS >> xs[i].SS;
	sort(xs.begin(), xs.end());

	fill((int*)dp, (int*)dp+2*MAX*MAX, -INF);
	int crt = 0, nxt = 1;
	dp[crt][0][0] = 0;
	for(int i=0;i<N;++i){
	  for(int k=0;k<MAX;++k)
		for(int j=0;j<MAX;++j)
		  dp[nxt][k][j] = dp[crt][k][j];

	  for(int b=0;b<MAX;++b)
		for(int j=0;j<xs[i].FF.FF;++j)
		  dp[nxt][xs[i].FF.SS][b] = max(dp[nxt][xs[i].FF.SS][b], dp[crt][j][b]+xs[i].SS);
	  for(int a=0;a<MAX;++a)
		for(int j=0;j<xs[i].FF.FF;++j)
		  dp[nxt][a][xs[i].FF.SS] = max(dp[nxt][a][xs[i].FF.SS], dp[crt][a][j]+xs[i].SS);
	  swap(crt, nxt);
	}

	int ans = 0;
	for(int i=0;i<MAX;++i)
	  for(int j=0;j<MAX;++j)
		ans = max(ans, dp[crt][i][j]);
	cout << ans << endl;
	/*
	for(int i=0;i<10;++i){
	  for(int j=0;j<10;++j)cout<<dp[i][j]<<" ";
	  cout<<endl;
	}
	*/
  }
  
  return 0;
}
