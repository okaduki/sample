#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int ds[2][100001];
int ns[2][100001];
vector<vector<int>> G;
void bfs(int x, int d, int i){
  queue<int> q, dis;
  q.push(x);
  dis.push(0);

  while(!q.empty()){
	x = q.front(); q.pop();
	d = dis.front(); dis.pop();
	if(ds[i][x] >= 0) continue;
	ds[i][x] = d;
	ns[i][d]++;
	for(int to: G[x]){
	  q.push(to);
	  dis.push(d+1);
	}
  }
}

int main(){
  fill((int*)ds, (int*)ds+2*100001, -1);
  fill((int*)ns, (int*)ns+2*100001, 0);

  int N, M, S, T;
  cin >> N >> M >> S >> T;
  --S, --T;
  G.assign(N, vector<int>());
  for(int i=0;i<M;++i){
	int x, y; cin >> x >> y;
	--x, --y;
	G[x].push_back(y);
	G[y].push_back(x);
  }
  bfs(S, 0, 0);
  bfs(T, 0, 1);

  long long ans = 0, d = ds[0][T];
  for(int i=0;i<=d-2;++i)
	ans += (long long)ns[0][i] * ns[1][d-2-i];
  cout << ans << endl;
}
