#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long LL;

LL INF = (1LL<<31) - 1;
int N;
unsigned int A[1<<18];

void update(int i, int x){
  i += N;
  A[i] = x;

  i /= 2;
  int li = i*2, ri = i*2+1;
  while(i > 0){
	A[i] = min(A[li], A[ri]);
	i /= 2;
	li = i*2, ri = i*2+1;
  }
}

int find(int s, int t, int v = 1, int l = 0, int r = N){
  if(t <= l || r <= s || r <= l) return INF;
  if(s <= l && r <= t) return A[v];
  return min(find(s, t, v*2, l, (l+r)/2),
			 find(s, t, v*2+1, (l+r)/2, r));
}

int main(){
  int Q; scanf("%d %d", &N, &Q);
  int N_ = 2;
  while(N_ < N) N_ <<= 1;
  N = N_;

  for(int i=0;i<N*2;++i)
	A[i] = INF;
  
  while(Q--){
	int c, x, y;
	scanf("%d %d %d", &c, &x, &y);
	if(c) printf("%d\n", find(x, y+1));
	else update(x, y);
  }
}
