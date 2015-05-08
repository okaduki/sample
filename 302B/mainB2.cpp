//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <queue>

using namespace std;

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int INF = 1e8;

VI G[3001];
int dist[3001][3001];
void bfs(int idx){
  fill(dist[idx], dist[idx]+3001, INF);
  queue<int> q;
  dist[idx][idx] = 0;
  q.push(idx);

  while(!q.empty()){
	int node = q.front(); q.pop();
	for(int to: G[node]){
	  if(dist[idx][to] > dist[idx][node]+1){
		dist[idx][to] = dist[idx][node] + 1;
		q.push(to);
	  }
	}
  }
}


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  REP(i,M){
	int a, b;
	cin >> a >> b;
	G[a].PB(b);
	G[b].PB(a);
  }

  int s1, t1, l1, s2, t2, l2;
  cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;

  for(int u=1;u<=N;++u)
	bfs(u);
  if(dist[s1][t1] > l1 || dist[s2][t2] > l2){
	cout << -1 <<endl;
	return 0;
  }

  int ans = M - dist[s1][t1] - dist[s2][t2];
  for(int u=1;u<=N;++u){
	for(int v=1;v<=N;++v){
	  int suvt1 = min(dist[s1][u]+dist[u][v]+dist[v][t1],
					  dist[s1][v]+dist[v][u]+dist[u][t1]);
	  int suvt2 = min(dist[s2][u]+dist[u][v]+dist[v][t2],
					  dist[s2][v]+dist[v][u]+dist[u][t2]);

	  if(suvt1 <= l1 && suvt2 <= l2)
		ans = max(ans, M - (suvt1 + suvt2 - dist[u][v]));
	}
  }

  cout << ans << endl;
  
  return 0;
}
