#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef vector<vector<int>> vvi;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m,n;
    cin>>m>>n;
    vvi mat(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    vvi psum(m,vector<int>(n));
    psum[0][0]=mat[0][0];
    for(int i=1;i<m;i++){
        psum[i][0]=psum[i-1][0]+mat[i][0];
    }

    for(int i=1;i<n;i++){
        psum[0][i]=psum[0][i-1]+mat[0][i];
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+mat[i][j];        
        }
    }

    int x1,y1,x2,y2;
    while(cin>>x1>>y1>>x2>>y2&&(x1!=-1)){
        int ans=psum[x2][y2] 
      -(x1>0?psum[x1-1][y2]:0)
      -(y1>0?psum[x2][y1-1]:0)
      +(x1>0&&y1>0?psum[x1-1][y1-1]:0);
        cout<<ans<<endl;
    }
    return 0;
}