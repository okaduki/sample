#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> PII;
#define MP make_pair;

int hp, hp_max;
int R, C;
char maze[101][101];
int T;
int dat[101][101];
int S;
PII path[1001];
int P;
int portion[16];
int dp[1<<12][1010];

int main(){
  while(cin>>hp>>hp_max, hp){
	cin >> R >> C;
	for(int y=0;y<R;++y)
	  for(int x=0;x<C;++x)
		cin >> maze[y][x];
	cin >> T;
	for(int t=0;t<T;++t){
	  char c; int d; cin >> c >> d;
	  for(int y=0;y<R;++y)
		for(int x=0;x<C;++x)
		  if(maze[y][x] == c)
			dat[y][x] = d;
	}
	cin >> S;
	int N = 1;
	path[0].first = 0;
	path[0].second = 0;
	for(int i=0;i<S;++i){
	  char c; int x;
	  cin >> c >> x;
	  switch(c){
	  case 'U':
		for(int j=0;j<x;++j){
		  path[N] = path[N-1];
		  path[N++].first--;
		}
		break;
	  case 'D':
		for(int j=0;j<x;++j){
		  path[N] = path[N-1];
		  path[N++].first++;
		}
		break;
	  case 'L':
		for(int j=0;j<x;++j){
		  path[N] = path[N-1];
		  path[N++].second--;
		}
		break;
	  case 'R':
		for(int j=0;j<x;++j){
		  path[N] = path[N-1];
		  path[N++].second++;
		}
		break;
	  }
	}
	cin >> P;
	for(int i=0;i<P;++i) cin >> portion[i];

	fill((int*)dp, (int*)dp+(1<<12)*1010, 0);
	dp[0][0] = hp;
	for(int i=0;i<N;++i){
	  int y = path[i].first, x = path[i].second;
	  for(int b=0;b<1<<P;++b){
		if(!dp[b][i]) continue;
		if(dp[b][i] > dat[y][x])
		  dp[b][i+1] = max(dp[b][i+1], dp[b][i] - dat[y][x]);
		else
		  for(int j=0;j<P;++j)
			if((b>>j&1) == 0)
			  dp[b|(1<<j)][i] = max(dp[b|(1<<j)][i], min(hp_max, dp[b][i] + portion[j]));
	  }
	}

	bool ans = false;
	for(int b=0;b<1<<P;++b)
	  if(dp[b][N]) ans = true;
	cout << (ans? "YES": "NO") << endl;
  }
  
  return 0;
}
