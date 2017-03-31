#include <iostream>
#include <vector>

using namespace std;

struct node{
  int value;
  int parent;
  bool isLeaf;
};

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    node level[m][k];
    int leaf[k];
    int size[m];
    int distance[k][k];
    for(int i=0; i<m; i++){
        int j;
        cin >> j;
        size[i] = j;
    }
    for (int i=0; i<m; i++){
        for(int j=0; j<size[i]; j++){
            int x;
            cin >> x;
            level[i][j].value = x; 
            level[i][j].isLeaf = false;
        }
    }
    for (int i=0; i<k; i++) {
      int x;
      cin >> x;
      leaf[i] = x;
      for (int p=0; p<m; p++){
        bool find = false;
        for(int q=0; q<size[p]; q++){
          if(level[p][q].value == x) {
            level[p][q].isLeaf = true;
            find = true;
            break;
          }
        }
        if(find) {break;}
      }
    }
    for (int i=0; i<k; i++) {
      for (int j=0; j<k; j++) {
        int x;
        cin >> x;
        distance[i][j] = x;
      }
    }
    level[0][0].parent = 0;
    for(int i=0; i< size[1]; i++) {
      level[1][i].parent = level[0][0].value;
    }
    for(int i=m-1; i>1; i--) {
      for(int j=0 ; j<size[i]; j++) {
        int parentIndex;
        for (int tmp=0; tmp<size[i-1]; tmp++){
          if (level[i-1][tmp].isLeaf == false) {
            parentIndex = tmp;
            level[i-1][tmp].isLeaf = true;
            break;
          }
        }
        int childIndex;
        for (childIndex = 0; childIndex < k; childIndex++) {
          if (leaf[childIndex] == level[i][j].value) {
            level[i][j].parent = level[i-1][parentIndex].value;
            break;
          }
        }
        while(1) {
          int child2Index;
          if(j+1 >= size[i]) break;
          for (child2Index = 0; child2Index < k; child2Index++) {
            if (leaf[child2Index] == level[i][j+1].value && distance[child2Index][childIndex]==2) {
              level[i][j+1].parent = level[i-1][parentIndex].value;
              j++;
              continue;
            } else {
              break;
            }
          }
          leaf[childIndex] = level[i-1][parentIndex].value;
          for (int i=0; i<k; i++) {
            distance[childIndex][i] -= 1;
            distance[i][childIndex] -= 1;
          }
          distance[childIndex][childIndex] ++;
          break;
        }
      }
    }
    for(int i=0; i<m; i++) {
      for(int j=0; j<size[i]; j++) {
        if(i==m-1 && j==size[i]-1){
          cout << level[i][j].parent;
          break;
        }
        cout << level[i][j].parent << " ";
      }
    }
    return 0;
}
