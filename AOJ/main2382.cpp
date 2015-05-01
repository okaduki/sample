#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int,int> PII;
#define MP make_pair

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


int main(){
  int N, W, H; cin >> N >> W >> H;
  vector<PII> xs(N), ys(N);
  for(int i=0;i<N;++i){
	int x, y; cin >> x >> y;
	xs[i] = MP(x,i), ys[i] = MP(y,i);
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());

  UnionFind uf(N);
  for(int i=0;i+1<N;++i){
	if(xs[i].first == xs[i+1].first)
	  uf.unite(xs[i].second, xs[i+1].second);
	if(ys[i].first == ys[i+1].first)
	  uf.unite(ys[i].second, ys[i+1].second);
  }

  vector<int> cnt(N, 0);
  for(int i=0;i<N;++i)
	cnt[uf.find(i)]++;

  int ans = 0, tot = 0;
  for(int i=0;i<N;++i)
	if(cnt[i] != 0)
	  ++tot, ans += cnt[i] - 1;

  //cout << "(" << tot << ", " << ans << ")" << endl;
  if(tot > 1){
	if(xs[0].first == 1 || xs.back().first == W || ys[0].first == 1 || ys.back().first == H)
	  ans += 2*tot - 2;
	else
	  ans += 2 * tot - 1;
  }
  cout << ans << endl;
  
  return 0;
}
