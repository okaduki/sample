#include <bits/stdc++.h>

using namespace std;
#define SZ(x) (x).size()
#define ALL(x) (x).begin(),(x).end()
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
#define MP make_pair

struct Edge{
  int to, cost;
  Edge(int to_, int cost_) : to(to_), cost(cost_){
  }
};
typedef vector<vector<Edge>> Graph;


class UnionFind{
private:
  vector<int> par, rank;
public:
  UnionFind(int n){
	par.assign(n, 0);
	rank.assign(n, 0);
	for(int i=0;i<n;++i)
	  par[i] = i;
  }

  //find root of x
  int find(int x){
	if(par[x] == x)
	  return x;
	return (par[x] = find(par[x]));
  }

  void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y) return;

	if(rank[x] < rank[y])
	  par[x] = y;
	else{
	  par[y] = x;
	  if(rank[x] == rank[y])
		++rank[x];
	}
  }

  bool same(int x, int y){
	return find(x) == find(y);
  }
};

const int INF = 1e9;

void dfs(int u, VI& dist, Graph& G){
  for(auto& e: G[u]){
	if(dist[e.to] == INF){
	  dist[e.to] = dist[u] + e.cost;
	  dfs(e.to, dist, G);
	}
  }
}

int main(){
  int N, M;
  while(cin>>N>>M,N&&M){
	VI kind;
	vector<PII> query;
	Graph G(N);
	UnionFind after(N), tmp(N);
	for(int i=0;i<M;++i){
	  char c; cin >> c;
	  if(c == '!'){
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		kind.push_back(0);
		query.push_back(MP(a,b));
		G[a].emplace_back(b,c);
		G[b].emplace_back(a,-c);
		after.unite(a, b);
	  }
	  else{
		int a, b; cin >> a >> b;
		--a, --b;
		kind.push_back(1);
		query.push_back(MP(a,b));
	  }
	}

	VI dist(N, INF);
	for(int i=0;i<N;++i){
	  if(dist[i] == INF){
		int rt = after.find(i);
		dist[rt] = 0;
		dfs(rt, dist, G);
	  }
	}

	for(int i=0;i<SZ(query);++i){
	  if(kind[i]){
		int a = query[i].first;
		int b = query[i].second;
		int u = tmp.find(a);
		if(u != tmp.find(b)){
		  cout << "UNKNOWN" << endl;
		}
		else{
		  cout << dist[b] - dist[a] << endl;
		}
	  }
	  else{
		tmp.unite(query[i].first, query[i].second);
	  }
	}
  }
  
  return 0;
}
