#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int countParing(bool[]);

bool areFriends[10][10];
int N, M;
int main(void){
    int C=0;

    for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
                areFriends[i][j] = false;

    freopen("input.txt","r",stdin);
    cin >> C;
    while(C != 0){
        cin >> N >> M;
        for(int i=0; i != M; i++){
            int a, b;
            cin >> a >> b;
            areFriends[a][b] = true;
            areFriends[b][a] = true;
        }
        bool taken[10] = {false, };
        printf("%d\n", countParing(taken));

        N = 0;
        M = 0;
        for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
                areFriends[i][j] = false;

        C -= 1;
    }
    return 0;
}

int countParing(bool taken[]){
    int firstFree = -1;
    for(int i=0; i<N; i++){
        if(!taken[i]){
            firstFree = i;
            break;
        }
    }
    if(firstFree == -1) return 1;
    int ret = 0;

    for(int who=firstFree+1; who < N; who++){
        if(!taken[who] && areFriends[firstFree][who]){
            taken[firstFree] = taken[who] = true;
            ret += countParing(taken);
            taken[firstFree] = taken[who] = false;
        }
    }
    return ret;
}