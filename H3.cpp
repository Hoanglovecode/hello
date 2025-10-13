#include <bits/stdc++.h>
using namespace std;
int main()
{ //Nhập từng phần tử đến khi có số 0 là dừng
  int n=0;
  int mang[100000];
  for (int i = 0; i < 100000; i++)
  {
    cin >> mang[i];
    if (mang[i] == 0)
      break;
    n++;
  }
  //Tìm gtln trong mảng
  int max=mang[1];
  for(int j=0;j<n;j++){
    if(mang[j]>=max)
    max=mang[j];
  }
  //Tìm gtnn trong mảng
  int min=mang[1];
  for(int y=0;y<n;y++){
    if(mang[y]<=min)
    min=mang[y];
  }
  //Bitcoin
  if (max > 20000)
    cout << max - 20000;
  else if(max<=20000)
  cout << 0;
  if (min < 20000)
    cout <<" "<< 20000 - min;
  else if(min>=20000)
    cout <<" "<< 0;
}