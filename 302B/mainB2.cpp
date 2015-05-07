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

struct Edge{
  int to, cost;

  Edge(int t, int c): to(t), cost(c)
  {}
  bool operator>(const Edge& rhs) const{
	return cost > rhs.cost;
  }
};
typedef vector< vector<Edge> > Graph;

void Dijkstra(const Graph& edges, vector<int>& d, VI& prv, int s){
  const int V = edges.size();
  priority_queue<PII, vector<PII>, greater<PII> > pq;
  fill(d.begin(), d.end(), INF);
  d[s] = 0;
  prv[s] = -1;
  pq.push(MP(0,s));

  while(!pq.empty()){
	PII pii = pq.top(); pq.pop();
	int v = pii.second;
	if(d[v] < pii.first) continue;
	for(int i=0;i<edges[v].size();++i){
	  const Edge& e = edges[v][i];
	  if(d[e.to] > d[v] + e.cost){
		d[e.to] = d[v] + e.cost;
		prv[e.to] = v;
		pq.push(MP(d[e.to], e.to));
	  }
	}
  }
}


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  Graph G(N+1);
  REP(i,M){
	int a, b;
	cin >> a >> b;
	G[a].PB(Edge(b,1));
	G[b].PB(Edge(a,1));
  }

  int s1, t1, l1, s2, t2, l2;
  cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;

  VI dist1(N+1), prv1(N+1);
  Dijkstra(G, dist1, prv1, s1);  
  VI dist1_(N+1), prv1_(N+1);
  Dijkstra(G, dist1_, prv1_, t1);  

  VI dist2(N+1), prv2(N+1);
  Dijkstra(G, dist2, prv2, s2);
  VI dist3(N+1), prv3(N+1);
  Dijkstra(G, dist3, prv3, t2);
  if(dist1[t1] > l1 || dist2[t2] > l2){
	cout << -1 <<endl;
	return 0;
  }

  int ans = M - dist1[t1] - dist2[t2];
  for(int u=1;u<=N;++u){
	for(int v=1;v<=N;++v){
	  int s1u = dist1[u];
	  int s2u = dist2[u];
	  int vt1 = dist1_[v];
	  int vt2 = dist3[v];

	  int uv = min(abs(dist1[v] - dist1[u]), abs(dist2[v]-dist2[u]));
	  if(s1u+uv+vt1 <= l1 && s2u+uv+vt2 <= l2){
		ans = max(ans, M - (s1u+s2u+uv+vt1+vt2));
		//		cout << u<<"->"<<v<<": "<<M - (s1u+s2u+uv+vt1+vt2) << endl;
	  }
	}
  }

  cout << ans << endl;
  
  return 0;
}










