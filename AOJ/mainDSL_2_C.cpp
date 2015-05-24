#include <cstdio>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;

int np = 0;
int N;
struct Tree{
  int loc, l, r;
};
Tree T[500000+1];
struct P{
  int id, x, y;
};
P ps[500000+1];

int mk2DTree(int l, int r, int depth){
  if(r <= l) return -1;
  int mid = (l + r) / 2;

  int t = np++;
  if(depth % 2)
	sort(ps+l, ps+r, [](const P& lh, const P& rh){return lh.x < rh.x;});
  else
	sort(ps+l, ps+r, [](const P& lh, const P& rh){return lh.y < rh.y;});

  T[t].loc = mid;
  T[t].l = mk2DTree(l, mid, depth+1);
  T[t].r = mk2DTree(mid+1, r, depth+1);

  return t;
}

void find(int v, int sx, int tx, int sy, int ty, int depth, set<int>& s){
  int x = ps[T[v].loc].x;
  int y = ps[T[v].loc].y;

  if(sx <= x && x <= tx && sy <= y && y <= ty)
	s.insert(ps[T[v].loc].id);

  if(depth % 2){
	if(T[v].l != -1 && sx <= x)
	  find(T[v].l, sx, tx, sy, ty, depth+1, s);
	if(T[v].r != -1 && x <= tx)
	  find(T[v].r, sx, tx, sy, ty, depth+1, s);	
  }
  else{
	if(T[v].l != -1 && sy <= y)
	  find(T[v].l, sx, tx, sy, ty, depth+1, s);
	if(T[v].r != -1 && y <= ty)
	  find(T[v].r, sx, tx, sy, ty, depth+1, s);
  }
}

int main(){
  scanf("%d", &N);
  for(int i=0;i<N;++i){
	scanf("%d %d", &ps[i].x, &ps[i].y);
	ps[i].id = i;
  }
  mk2DTree(0, N, 0);
  int Q; scanf("%d", &Q);
  while(Q--){
	int sx, tx, sy, ty;
	scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
	set<int> s;
	find(0, sx, tx, sy, ty, 0, s);
	for(int x: s)
	  printf("%d\n", x);
	printf("\n");
  }
  
  return 0;
}
