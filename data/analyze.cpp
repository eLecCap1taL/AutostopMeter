#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
map<string,vector<double>> mp;
string s;
ifstream fin("dat.txt",ios::in);
ofstream fout("res.txt",ios::out);
void readuntilstr(string tg,function<void(void)> callback=[](){}){
    while(1){
        fin>>s;
        if(s.substr(0,3)=="[U:")    continue;
        if(s.substr(0,3)=="[Co")    continue;
        if(s.substr(0,4)=="[Inp")   continue;
        if(s.substr(0,4)=="[Cli")   continue;
        if(s==tg){
            callback();
            return ;
        }
    }
}
void readuntilchar(char tg,function<void(void)> callback=[](){}){
    while(1){
        fin>>s;
        if(s.substr(0,3)=="[U:")    continue;
        if(s.substr(0,3)=="[Co")    continue;
        if(s.substr(0,4)=="[Inp")   continue;
        if(s.substr(0,4)=="[Cli")   continue;
        if(s[0]==tg){
            callback();
            return ;
        }
    }
}
void calc(string key,pair<double,double> x,pair<double,double> y){
    double ans=sqrtl((x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se));
    mp[key].push_back(ans);
    // mp[key].fi+=ans;
    // mp[key].se+=1.0;
}
void outputData(){
    for(auto [key,ls]:mp){
        double sum=0;
        double Max=-1e10;
        double Min=1e10;
        double num=0;
        for(auto dis:ls){
            sum+=dis;
            Max=max(Max,dis);
            Min=min(Min,dis);
            num+=1.0;
        }
        double p=sum/num;
        double s=0;
        for(auto dis:ls){
            s+=(dis-p)*(dis-p);
        }
        s/=num;
        fout << format("{} [{:d} times]:", key, (int)num) << endl;
        fout << format("  [Average Glide Distance (smaller is better)]:  {:.6f}", p) << endl;
        fout << format("  [Maximum Glide Distance]:  {:.6f}", Max) << endl;
        fout << format("  [Minimum Glide Distance]:  {:.6f}", Min) << endl;
        fout << format("  [Range (Max - Min)]:  {:.6f}", Max - Min) << endl;
        fout << format("  [Variance]:  {:.6f}", s) << endl;
        fout << format("  [Standard Deviation]:  {:.6f}", sqrtl(s)) << endl;

    }
}
int main(){
    readuntilstr("[begin]",[](){
        fout<<"Format Confirmed"<<endl;
    });
    while(1){
        readuntilchar('[');
        if(s=="[TestStart]"){
            cout<<"TestStart"<<endl;
            readuntilchar('[');
            string key=s;
            pair<double,double> x,y;
            readuntilstr("[begin]");
            readuntilstr("[coord1]");
            fin>>x.fi;
            readuntilstr("[coord2]");
            fin>>x.se;

            readuntilstr("[end]");
            readuntilstr("[coord1]");
            fin>>y.fi;
            readuntilstr("[coord2]");
            fin>>y.se;

            readuntilstr("[TestCompleted]");

            calc(key,x,y);
        }else if(s=="[exit]"){
            break;
        }else{
            fout<<"Error with bad string: "<<s<<endl;
            exit(1);
        }
    }
    outputData();
    return 0;
}