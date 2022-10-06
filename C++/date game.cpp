#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,int>mp{
        1,31;2,59;3,90;4,120;5,151;6,181;7,212;8,243;9,273;10,304;11,334;12,365;
    };

string date="2019-02-10";
int month=stoi(date.substr(5,2));
int day=stoi(date.substr(8,2));
int year=stoi(date.substr(0,4));
int flag=0;
if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
          flag=1;
      }
      else {
          flag=0;
      }
    }
    else {
      flag=1;
    }
  }
  else {
    flag=0;
  }
  if(flag==1)mp[2]+=1;
  int days=mp[month-1]+day;
  cout<<days*10;
    return 0;

}