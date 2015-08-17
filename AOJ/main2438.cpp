#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

struct Obj{
  int lv;
  map<string,string> strs;
  map<string,Obj*> objs;

  int find(vector<string>& path, string& res, int idx = 0){
	if(path.size() == idx+1){
	  if(strs.count(path[idx])){
		res = strs[path[idx]];
		return 1;
	  }
	  else if(objs.count(path[idx]))
		return 0;
	  return -1;
	}
	else{
	  if(!objs.count(path[idx])) return -1;
	  return objs[path[idx]]->find(path, res, idx+1);
	}
  }
};

int N;
vector<int> level;
vector<string> vs;

vector<string> split(string s, const string &delim) {
    vector<string> res;
    int pos;
    while((pos = s.find(delim)) != string::npos) {
        if(pos) res.emplace_back(s.substr(0, pos));
        s = s.substr(pos + 1);
    }
    if(s.size()) res.emplace_back(s);
    return res;
}

void dfs(int& idx, int lv, Obj* obj){
  for(;idx<N;){
	if(idx == N || level[idx] <= lv) return;
	int lv_c = level[idx];
	int p = vs[idx].find(":");

	string key = vs[idx].substr(level[idx], p-level[idx]);
	if(p+1 == vs[idx].size()){
	  Obj* c = new Obj();
	  c->lv = lv_c;
	  ++idx;
	  dfs(idx, lv_c, c);
	  obj->objs[key] = c;
	}
	else{
	  string str = vs[idx].substr(p+2);
	  obj->strs[key] = str;
	  ++idx;
	}
  }
}

void debug(Obj* obj){
  cout << obj->lv << ": " << endl;
  for(auto& ss: obj->strs)
	cout << ss.first << " -> " << ss.second << endl;
  for(auto& ss: obj->objs){
	cout << ss.first << " -> *" << endl;
	debug(ss.second);
  }
}

int main(){
  string query; cin >> query; cin.ignore();

  string line;
  N = 0;
  while(getline(cin, line)){
	int lv = 0;
	for(;line[lv]==' ';++lv);
	level.push_back(lv);
	vs.push_back(line);
	++N;
  }
  Obj* yaml = new Obj();
  yaml->lv = -1;
  int idx = 0;
  dfs(idx,-1,yaml);

  //  debug(yaml);

  vector<string> path = split(query, ".");

  string res;
  switch(yaml->find(path, res)){
  case 1:
	cout << "string \"" << res << "\"" << endl;
	break;
  case 0:
	cout << "object" << endl;
	break;
  default:
	cout << "no such property" << endl;
  }
  
  return 0;
}
