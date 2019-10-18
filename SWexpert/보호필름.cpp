// 00:23
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int map[14][21];
int cpmap[14][21];

vector<int> select_line;
vector<int> selectA;
vector<int> selectB;
int D, W, K;
int answer;

int check(){
    int a_size = (int)selectA.size();
    int line_size = (int)select_line.size();
    
    selectB.clear();
    for(int i=0, i2=0; i<line_size; ++i){
        if(i2 < a_size && selectA[i2] == select_line[i]){
            ++i2;
        }else{
            selectB.push_back(select_line[i]);
        }
    }
    int b_size = (int)selectB.size();
    
    int a=0, b=0;
    for(int i=0; i<D; ++i){
        if(a < a_size && selectA[a] == i){
            for(int j=0; j<W; ++j)
                cpmap[i][j] = 0;
            ++a;
        }else if(b < b_size && selectB[b] == i){
            for(int j=0; j<W; ++j)
                cpmap[i][j] = 1;
            ++b;
        }else{
            for(int j=0; j<W; ++j)
                cpmap[i][j] = map[i][j];
        }
    }
    
    for(int i = 0; i < W; i++){
        int cnt = 1;
        for(int j = 0; j < D-1; j++){
            if(cnt >= K)
                break;
            if(D-K+1 == j && cnt == 1)
                break;
            
            if(cpmap[j][i] == cpmap[j+1][i])
                ++cnt;
            else
                cnt = 1;
            
        }
        if(cnt < K){
            return INT_MAX;
        }
    }
    return line_size;
}
void dfs2(int cur, int depth){
    if(answer != INT_MAX)
        return;
    if(selectA.size() == depth){
        int ret = check();
        if(ret != INT_MAX)
            answer = check();
        return;
    }
    for(int i=cur; i<select_line.size(); ++i){
        selectA.push_back(select_line[i]);
        dfs2(i+1, depth);
        selectA.pop_back();
    }
}
void dfs(int cur, int depth){
    if(answer != INT_MAX)
        return;
    if(select_line.size() == depth){
        selectA.clear();
        for(int i=0; i<=depth; ++i)
            dfs2(0, i);
        return;
    }
    for(int i=cur; i<D; ++i){
        select_line.push_back(i);
        dfs(i+1, depth);
        select_line.pop_back();
    }
}
int solution(){
    scanf("%d %d %d", &D, &W, &K);
    if(K == 1) return 0;
    
    for(int i=0; i<D; ++i){
        for(int j=0; j<W; ++j){
            scanf("%d", &map[i][j]);
        }
    }
    
    answer = INT_MAX;
    for(int i=0; i<=K; ++i){
        select_line.clear();
        dfs(0, i);
    }
    return answer;
}

int main(void){
    freopen("/Users/pd3chae/Xcode/test/test2/test2/input.txt", "r", stdin);
    int testcase;
    scanf("%d", &testcase);
    for(int i=1; i<=testcase; ++i){
        printf("#%d %d\n", i, solution());
    }
    return 0;
}

