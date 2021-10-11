#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> mul(vector<vector<int>>v, vector<vector<int>>v1){
    vector<vector<int>>res(v.size(), vector<int>(v1[0].size()));
    for(int i=0; i<v.size(); ++i){
        for(int k=0; k<v1.size(); ++k){
            for(int j=0; j<v1[0].size();++j) {
                res[i][j] += (v[i][k] * v1[k][j]); 
            }
        }           
    }
        return res;
}
void print(vector<vector<int>>v){
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v.size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
vector<vector<int>> pow(vector<vector<int>>v, int dim, int n){
    vector<vector<int>>I(dim, vector<int>(dim, 0));
    for(int i = 0; i<I.size(); i++){I[i][i]=1;}

    // brute force
    // for(int i = 0; i<n; i++){
    //     I = mul(I, v); 
    // }

    // Matric Exponential
    while(n>0){
        if(n%2!=0){I = mul(I, v);n--;}
        else{
            v = mul(v, v);
            n=n/2;
        }
    }
    print(I);
    return I;
}

    int main(){
    int t;
    cin>>t;
    while(t--){
        int n, dim;
        cin>>dim>>n;
        vector<vector<int>>v(dim, vector<int>(dim));
        for(int i = 0; i<dim; i++){
            for(int j = 0; j<dim; j++){cin>>v[i][j];}
        }
         vector<vector<int>>b = pow(v, dim, n);
    }
    return 0;
}