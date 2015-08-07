#include <iostream>

using namespace std;

const int INF = 1e9;

int N, M, L, S, T;
int dp[20][1<<17];

int bc(int x){
  int res = 0;
  while(x > 0){
	if(x&1) ++res;
	x >>= 1;
  }
  return res;
}

int main(){
  while(cin>>N>>M>>L>>S>>T,N){
	--S;
	int dist[310][310];
	fill((int*)dist, (int*)dist+310*310, INF);
	for(int i=0;i<M;++i){
	  int a, b, t; cin >> a >> b >> t;
	  --a, --b;
	  dist[a][b] = dist[b][a] = t;
	}
	
	int pl[20], ct[20];
	for(int i=0;i<L;++i){
	  cin >> pl[i+1] >> ct[i+1];
	  --pl[i+1];
	}
	  
	++L;
	pl[0] = S;
	ct[0] = 0;

	for(int i=0;i<N;++i)
	  dist[i][i] = 0;
	for(int k=0;k<N;++k)
	  for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
		  dist[i][j] = dist[j][i] = min(dist[i][j], dist[i][k] + dist[k][j]);

	fill((int*)dp, (int*)dp+20*(1<<17), INF);
	dp[0][1] = 0;
	for(int b=0;b<(1<<L);++b){
	  for(int i=0;i<L;++i){
		if((b>>i&1) == 0) continue;
		for(int j=0;j<L;++j){
		  if(b>>j&1) continue;
		  dp[j][b|(1<<j)] = min(dp[j][b|(1<<j)], dp[i][b] + dist[pl[i]][pl[j]] + ct[j]);
		}
	  }
	}

	int ans = 0;
	for(int i=0;i<L;++i)
	  for(int b=0;b<(1<<L);++b)
		if(dp[i][b] + dist[pl[i]][pl[0]] <= T)
		  ans = max(ans, bc(b)-1);
	cout << ans << endl;
  }
  
  return 0;
}
