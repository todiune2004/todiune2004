#include <bits/stdc++.h>
#include<chrono>
#include <cstdlib>
using namespace std;

int a[1005];
int n,k,p,final=1;
int x[1005];
vector <vector<int>> res;
void init(){
	for (int i=1; i<=k; i++) x[i]=i;
}
void sinh(){
	int i=k;
	while (i>=1 && x[i]==n-k+i){
		i--;
	}
	if (i==0){
		final=0;
	}
	else{
		x[i]++;
		for (int j=i+1; j<=k; j++) x[j]=x[j-1]+1;
	}
}
void result(){
	int s = 0;
	for (int i=1; i<=k; i++){
		s += a[x[i]];
	}
	if (s==p){
		vector <int> v;
		for (int i=1; i<=k; i++){
			v.push_back(a[x[i]]);
		}
		res.push_back(v);
	}
}

int main(){
	for(int i = 1 ; i <= 3 ; i++ ){
		string filename = "input" + to_string(i) + ".txt";
		cout<<filename<<endl;
		fstream inp;
		inp.open( filename, ios::in);
		inp >> n;
		for(int j = 1; j <= n ; j ++) {
			inp >> a[j];
		}
		sort(a+1,a+n+1);
		inp >> k >> p;
		if( n <= 0 || k<=0 && p == 0){
			cout<<"The input error! Re-enter n, a, k, p: ";
			return 0;
		}
		inp.close();
		auto start = chrono::high_resolution_clock::now();
		init();
		while (final){
			result();
			sinh();
		}
		auto end = chrono::high_resolution_clock::now();
		cout <<"The total number of solutions is "<< res.size() << endl;
		for (auto it : res){
			for (int u : it){
				cout<< u <<" ";
			}
			cout<< endl;
		}
		res.clear();
		memset(a, 0, 1005);
		memset(x, 0, 1005);
		final = 1;
		chrono::duration<double> duration = end - start;
    		cout << "Time to find solution: " << duration.count() << " seconds" << endl;
		if(i<3) system("cls");
		
	}
}
