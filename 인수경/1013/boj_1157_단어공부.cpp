#include <iostream>
using namespace std;

int main(void){
  char str[1000000]= " ";
  cin >> str;
  int alpha[26]={0,};
  int frontmaxV = 0;
  int frontmaxIdx = 0;
  int backmaxIdx = 0;

  for(int i=0; i<1000000; i++){
    int idx = int(toupper(str[i])) - 65;
    alpha[idx]++;
  }

  for(int i=0; i<26;i++){
    if (alpha[i] > frontmaxV){
      frontmaxV = alpha[i];
      frontmaxIdx = i;
    }
  }

  for(int i=25; i >= 0; i--){
    if (alpha[i] == frontmaxV){
      backmaxIdx = i;
      break;
    }
  }

  if (frontmaxIdx == backmaxIdx){
    cout << char(frontmaxIdx + 65)<< "\n";
  }
  else cout << "?"<<"\n";

  return 0;
}
