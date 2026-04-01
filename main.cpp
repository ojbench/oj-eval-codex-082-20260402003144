#include <bits/stdc++.h>
#include "LinkedHashMap.hpp"
using namespace std;

// We infer an implicit I/O format from similar assignments:
// First line: n (bucket count), m (operation count), t (0: by index, 1: by time)
// Then m lines of operations:
//   insert k v
//   remove k v
//   ask k
//   foreach
// For ask: output values in bucket order (head -> tail) separated by spaces, or empty line if none
// For foreach: output pairs "k v" per line in traversal order

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; int byTimeInt=0;
    if(!(cin>>n>>m>>byTimeInt)){
        return 0; // no input
    }
    LinkedHashMap lhm(n, byTimeInt!=0);
    string op;
    for(int i=0;i<m;i++){
        if(!(cin>>op)) break;
        if(op=="insert"){
            int k; string v; cin>>k>>v;
            lhm.insert(k,v);
        }else if(op=="remove"){
            int k; string v; cin>>k>>v;
            lhm.remove(k,v);
        }else if(op=="ask"){
            int k; cin>>k;
            vector<string> ans=lhm.ask(k);
            for(size_t j=0;j<ans.size();j++){
                if(j) cout<<' ';
                cout<<ans[j];
            }
            cout<<"\n";
        }else if(op=="foreach"){
            vector<Data> arr=lhm.forEach();
            for(size_t j=0;j<arr.size();j++){
                cout<<arr[j].key<<" "<<arr[j].value<<"\n";
            }
        }else{
            // unknown op: ignore line
            string rest; getline(cin, rest);
        }
    }
    return 0;
}

