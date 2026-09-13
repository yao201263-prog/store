#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<utility>
using namespace std;
typedef vector<pair<int,int>>vpii;
typedef vector<vector<char>> vvc;
typedef vector<vector<int>> vvi;
int arr[9]={1,1,2,6,24,120,720,5040,40320};

bool isvalid(vvc&board,int i,int j){
    int n=board.size();
    if(0<=i&&i<n&&0<=j&&j<n&&board[i][j]=='#'){
        return 1;
    }
    return 0;
}

bool collision(vpii&path,int r,int c){
    if(path.size()==0)return 0;
    for(auto it:path){
        if(it.first==r||it.second==c)return 1;
    }
    return 0;
}

int ans;
vvi visited(8,vector<int>(8,0));
void get_num_of_solution(vvc&board,vpii&path,int k){
    int n=board.size();
    if(path.size()==k){
        ans++;
    }else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isvalid(board,i,j)&&!collision(path,i,j)&&!visited[i][j]){
                    path.push_back({i,j}); visited[i][j]=1;
                    get_num_of_solution(board,path,k);
                    path.pop_back();visited[i][j]=0;
                }
            }
        }
    }
}

int main()
{
    int n,k;
    while(cin>>n>>k&&n!=-1){
        vvc board(n,vector<char>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>board[i][j];
            }
        }
        visited.assign(8,vector<int>(8,0));
        ans=0; vpii path;
        get_num_of_solution(board,path,k);
        cout<<ans/arr[k]<<endl;
    }
    return 0;
}

/*正常方法

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, k;
vector<string> board;
vector<bool> colUsed;
int ans;

void dfs(int row, int placed) {
    if (placed == k) {
        ans++;
        return;
    }
    if (row >= n) return;

    // 不选当前行
    dfs(row + 1, placed);

    // 尝试在当前行放一个棋子
    for (int col = 0; col < n; ++col) {
        if (board[row][col] == '#' && !colUsed[col]) {
            colUsed[col] = true;
            dfs(row + 1, placed + 1);
            colUsed[col] = false;
        }
    }
}

int main() {
    while (cin >> n >> k && (n != -1 || k != -1)) {
        board.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> board[i];
        }
        colUsed.assign(n, false);
        ans = 0;
        dfs(0, 0);
        cout << ans << endl;
    }
    return 0;
}

*/