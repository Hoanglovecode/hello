#include <bits/stdc++.h>
using namespace std;
int main(){
/*Ép Kiểu:
    -1 chuỗi kí tự sang kiểu nguyên:int a=stoi(s)
        string s = "123";
        int a = stoi(s);           // ép chuỗi "123" → số 123
    -1 dãy số nguyên sang kí tự:string b=to_string(a)
        int z = 456;
        string t = to_string(z);   // ép số 456 → chuỗi "456"
    -Chuyển 1 kí tự sang kiểu nguyên thì trừ '0'
        char s = '8';
        int a = s - '0';           // ép ký tự '8' → số 8
    -Chuyển 1 số nguyên sang kí tự thì cộng  '0'
        int a = 4;
        char s = a + '0';          // ép số 4 → ký tự '4'
*/
  string s;
  cin>>s;
  int tong=0;
  for(int i=0;i<s.size();i++){
    int a=s[i]-'0';
    tong+=pow(a,s.size());
  }
  int b=stoi(s);
  if (tong == b)
    cout <<"YES";
  else
    cout<<"NO";
}