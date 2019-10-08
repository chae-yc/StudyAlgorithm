#define FILE_PATH "/Users/pd3chae/Xcode/test/test1/test1/input.txt"

#include <iostream>

using namespace std;

int N, L;
int map[100][100];

bool canBuild(const int map[], int base, int type){
    int cnt = 1;
    if(type == 0){   // down
        for(int i=base; i < N-1; i++){
            if(map[i] == map[i+1])
                cnt++;
        }
    }else{          // up
        for(int i=base; i > 0; i--){
            if(map[i] == map[i-1])
                cnt++;
        }
    }
    if(cnt >= L)
        return true;
    else
        return false;
}

int solution(){
    int answer = 0;
    int cur_height = 0;
    int cnt = 0;
    
    int i, j;
    // horizontal
    for(i=0; i<N; ++i){
        for(j=0; j<N-1; ++j){
            cur_height = map[i][j];
            if(cur_height == map[i][j+1]){
                cnt++;
                continue;
            }else if(cur_height - map[i][j+1] == 1){        // down hill
                cnt = 0;
                if(canBuild(map[i], j, 0)){
                    j += L;
                    continue;
                }
                else
                    break;
            }else if(cur_height - map[i][j+1] == -1){       // up hill
                if(cnt <= L){
                    cnt = 0;
                    continue;
                }else
                    break;
//                if(canBuild(map[i], j, 1))
//                    continue;
//                else
//                    break;
            }
        }
        if(j == N-1){
            answer++;
        }
    }
    
    
    cnt = 0;
    // vertical
    for(j=0; j<N; ++j){
        for(i=0; i<N-1; ++i){
                cur_height = map[i][j];
                if(cur_height == map[i+1][j]){
                    cnt++;
                    continue;
                }else if(cur_height - map[i+1][j] == 1){        // down hill
                    cnt = 0;
                    int tmp_map[100];
                    for(int t=0; t < N; t++){
                        tmp_map[t] = map[t][j];
                    }
                    if(canBuild(tmp_map, i, 0)){
                        i += L;
                        continue;
                    }
                    else
                        break;
                }else if(cur_height - map[i+1][j] == -1){       // up hill
                    
                    if(cnt <= L){
                        cnt = 0;
                        continue;
                    }else
                        break;
                    
//                    int tmp_map[100];
//                    for(int t=0; t < N; t++){
//                        tmp_map[t] = map[t][j];
//                    }
//                    if(canBuild(tmp_map, i, 1))
//                        continue;
//                    else
//                        break;
                }
            }
            if(i == N-1){
                answer++;
            }
        }
    
    
    return answer;
}
int main(void){
    freopen(FILE_PATH, "r", stdin);
    
    cin >> N >> L;
    
    for(int i=0; i != N; ++i){
        for(int j=0; j != N; ++j){
            cin >> map[i][j];
        }
    }
    
    cout << solution() << endl;
    
}
