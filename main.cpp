#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<set>
#include<map>
#include<ctype.h>
#include<sstream>

using namespace std;

class vb
{
public:
    string tara;
    int min;
    vb(string t, int m)
    {
        tara=t;
        min=m;
    }
};

bool sortare(vb a, vb b)
{
    if(a.min>b.min)
        return true;
    if(a.min==b.min)
    {
        if(a.tara<b.tara)
            return true;
    }
    return false;
}

bool sortare1(vb a, vb b)
{
    if(a.tara<b.tara)
        return true;
    if(a.tara==b.tara)
    {
        if(a.min>b.min)
            return true;
    }
    return false;
}

int main()
{
    int min;
    int sum=0;
    string r;
    vector<vb>v;
    string tara;
    map<string,int>m;
    vector<string>y;
    scanf("\n");
    while (getline(cin,r,'\n'))
    {
        stringstream s(r);
        string word;
        while(s>>word)
        {
            if(!isdigit(word[0]))
                y.push_back(word);
        }
        for(int i=0;i<y.size()-1;i++)
        {
            tara.append(y[i]).append(" ");
        }
        tara.append(y[y.size()-1]);
        for(int i=0;i<word.size();i++)
        {
            char x=word[i];
            sum=sum*10+((int)word[i]-48);
        }
        min=sum;
        if(min>=10&&min<=60)
        {
            v.push_back(vb(tara,min));
            m[tara]++;
        }
        y.clear();
        tara="";
        sum=0;
        scanf("\n");
    }
    int ok=0;
    double smin=0;
    for(auto it:m)
    {
        if(it.second!=1)
        {
            ok=1;
        }
    }
    if(ok==0)
    {
        sort(v.begin(),v.end(),sortare);
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i].tara<<","<<v[i].min<<"\n";
            smin+=v[i].min;
        }
        if(smin>480)
        {
            while(smin>480)
            {
                smin=smin-v[0].min;
                v.erase(v.begin()+0);
            }
        }
        cout<<smin<<" "<<fixed<<setprecision(2)<<smin/v.size()<<"\n";
    }
    else
    {
        sort(v.begin(),v.end(),sortare1);
        for(int i=1;i<v.size();i++)
        {
            if(v[i-1].tara==v[i].tara)
            {
                v.erase(v.begin()+i);
                i--;
            }
        }
        sort(v.begin(),v.end(),sortare);
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i].tara<<","<<v[i].min<<"\n";
            smin+=v[i].min;
        }
        cout<<smin<<" "<<fixed<<setprecision(2)<<smin/v.size()<<"\n";
    }
    return 0;
}