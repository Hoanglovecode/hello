#include <bits/stdc++.h>
using namespace std;
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   //Dem so lan xuat hien cua cac phan tu trong mang, sau do in ra kem theo tan suat cua no ( <= 10^7)
//8
//1 1 2 1 3 5 1 -4
//Output
//1 4
//2 1
//3 1
//-4 1
//5 1
   int n;cin>>n;
   map<int,int>mp;
   for(int i=0;i<n;i++){
    int x;cin>>x;
    mp[x]++;
   }
   for(auto x:mp)cout<<x.first<<' '<<x.second<<endl;
   cout<<endl;
   /*Bài 2:
   input:
9
python
java
string
java
python
C++
sql
sq1
java
   */
  int m;cin>>m;
  map<string,int>mp2;
  for(int i=0;i<n;i++){
    string str;cin>>str;
    mp2[str]++;
  }
  for(auto x:mp2){
    cout<<x.first<<' '<<x.second<<endl;
  }
}
//Bài 1
/*
int main()
{
    map<int, int> mp;
    int n;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;

        for (int i = 0; i < n; i++)
        {
            if (mp[a[i]] != 0)
            {
                cout << a[i] << " " << mp[a[i]] << endl;
                mp[a[i]] = 0;
            }
        }
    }
}
*/
