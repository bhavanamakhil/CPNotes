#include<bits/stdc++.h>

using namespace std;

int  fib(int n)
{
    //Base case
    if(n<=1)
    return n;
    //recursive intuition
     int subproblem1=fib(n-1);
     int subproblem2=fib(n-2);
    //self work
    return subproblem1+subproblem2;
}
void natural(int n)
{
    //Base case
    if(n==1)
    {
        cout<<n<<" ";
        return;
    }
    //recursive
    cout<<n<<" ";
    natural(n-1);
    //self work
    cout<<n<<" ";

}

int binary(int n)
{
    if(n<=2)
    return n+1;

    int num1=binary(n-1);
    int num2=binary(n-2);
    return num2+num1;
}

int numberofways(int n)
{
    //base
    if(n<=2)
    return n;
    //recursive
    //self work
    return numberofways(n-1)+numberofways(n-2)*(n-1);

}
int exponent(int a,int b)
{
    if(b==0)
    return 1;
    return a*exponent(a,b-1);
}
int optimizedexponent(int a,int b)
{
    if(b<=1)
    return a*b;
    int temp=optimizedexponent(a,b/2);
    if(b%2==0)
        return temp*temp;
    return a*temp*temp;
}
void printpattern(int r,int c,int n)
{
    if(r==n)
    return;
    if(c>r)
    {  
        cout<<endl;
        printpattern(r+1,0,n);
    }
    else
    {
        cout<<"*"<<" ";
        printpattern(r,c+1,n);
    }
    
}
void generate(vector<int> &A,int curr,vector<int> currarr)
{
    if(curr<0)
    {
        reverse(currarr.begin(),currarr.end());
        for(auto i:currarr)
            cout<<i<<" ";
        cout<<endl;
        return;
    }
    generate(A,curr-1,currarr);
    currarr.push_back(A[curr]);
    generate(A,curr-1,currarr);

}
void generatesubsets(int n)
{
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    generate(A,n-1,{});
}
vector<string> res;
vector<string> printbinary(int n)
{
    if(n==1)
    {
        return {"1","0"};
    }
    vector<string> temp=printbinary(n-1);
    vector<string> temp2;
    for(int i=0;i<temp.size();i++)
    {
        if(temp[i][0]=='0')
            temp2.push_back('1'+temp[i]);
    }
   for(int i=0;i<temp.size();i++)
    {
        temp2.push_back('0'+temp[i]);
    }
    return temp2;

}
bool checksorted(int curr,vector<int> &A)
{
    if(curr==A.size()-1)
    return true;
    if(A[curr]<=A[curr+1] && checksorted(curr+1,A)  )
    return true;
    return false;
}
bool checksorted1(int curr,vector<int> &A)
{
    if(curr==A.size()-1)
    return true;
    if(A[curr]>=A[curr+1] && checksorted1(curr+1,A)  )
    return true;
    return false;
}
void issorted(int n)
{
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cout<< (checksorted(0,A) || checksorted1(0,A));
}
void paths2(int n,int m,string pathsofar,int x,int y)
{
    if(x==n && y==m)
    {
        cout<<pathsofar<<endl;
        return;
    }
    if(x>n || y>m)
    return;
    paths2(n,m,pathsofar+" D",x+1,y);
    paths2(n,m,pathsofar+" R",x,y+1);
    paths2(n,m,pathsofar+" Dia",x+1,y+1);
    return;
}

vector<string> paths1(int n,int m)
{
    //base case
    if(n==0 && m==0)
    return {" "};
    //recursive
    vector<string> paths;
    if(n>0)
    {
        vector<string> path1=paths1(n-1,m);
        
        for(int i=0;i<path1.size();i++)
        {
            paths.push_back(path1[i]+" D");
        }
    }
    if(m>0)
    {
        vector<string> path2=paths1(n,m-1);
        for(int i=0;i<path2.size();i++)
        {
            paths.push_back(path2[i]+" R");
        }
    }
    return paths;
}

pair<int,vector<string>>noofcellsways(int x)
{
    if(x==0)
    return {1,{""}};
    if(x<0)
    return {0,{}};
    int ways=0;
    vector<string> paths;
    for(int i=1;i<=6;i++)
    {
        pair<int,vector<string>> p=noofcellsways(x-i);
        ways+=p.first;
        for(int j=0;j<p.second.size();j++)
        {
            paths.push_back(p.second[j]+" "+to_string(i));
        }

    }
    return {ways,paths};
}
int noofways;
void ways(int n,int x,string osf)
{
    if(x==n-1)
    {
        cout<<osf<<endl;
        noofways+=1;
        return;
    }
    if(x>n-1)
    return;
    for(int i=1;i<=6;i++)
    {
        ways(n,x+i,osf+" "+to_string(i));
    }
}
int countdigits(int x)
{
    int count=0;
    while(x!=0)
    {
        count++;
        x/=10;
    }
    return count;
}
void printlex(int n,int osf)
{
    if(osf>n)
        return;
    cout<<osf<<endl;
    for(int i=(osf==0?1:0);i<=9;i++)
    {
        printlex(n,osf*10+i);
    }  
}
vector<string> printpermut(string s,int idx)
{
    //base case
    if(idx==s.size())
    return {""};
    vector<string> temp=printpermut(s,idx+1);
    vector<string> res;
    for(int i=0;i<temp.size();i++)
    {
        string str=temp[i];
        for(int j=0;j<=str.size();j++)
        {
            string temp2,temp3=str;
            temp2.push_back(s[idx]);
            temp3.insert(j,temp2);
            res.push_back(temp3);
        }
    }
    return res;
}
vector<string> printpermut1(string s,int idx)
{
    //base case
    if(idx==-1)
    return {""};
    vector<string> temp=printpermut1(s,idx-1);
    vector<string> res;
    for(int i=0;i<temp.size();i++)
    {
        string str=temp[i];
        for(int j=0;j<=str.size();j++)
        {
            string temp2,temp3=str;
            temp2.push_back(s[idx]);
            temp3.insert(j,temp2);
            res.push_back(temp3);
        }
    }
    return res;
}
void printpermut3(string s,string osf)
{
    cout<<s<<" ";
    if(s.size()==0)
    {   
        cout<<osf<<endl;
    }
    for(int i=0;i<s.size();i++)
    {
        string t=s;
        // cout<<t<<" ";
        t.erase(i,1);
        // cout<<t<<endl;
        printpermut3(t,osf+s[i]);
    }
}
void printpermut4(string s,int j)
{
    if(j==s.size()-1)
    {
        cout<<s<<endl;
        return;
    }
    for(int i=j ;i<s.size();i++)
    {
        swap(s[i],s[j]);
        printpermut4(s,j+1);
        swap(s[i],s[j]);
    }
}
int main()
{
    int n1,n2;
    cin>>n1;
    int n=n1;
    // cin>>n2;
    // cout<<fib(n);
    // natural(n);
    // bitset<16> b;
    // b.set();
    // cout<<binary(n);
    // cout<<numberofways(n);
    // cout<<exponent(n1,n2);
    //cout<<optimizedexponent(n1,n2);
    //printpattern(0,0,n);
    // vector<string> res=printbinary(n);
    // for(auto i:res)
    // {
    //     cout<<i<<endl;
    // }
    //issorted(n);
    // vector<string> paths= paths1(n1-1,n2-1);
    // for(auto i:paths)
    // {
    //     cout<<i<<endl;
    // }
    // cout<<endl;
    // paths2(n1-1,n2-1,"",0,0);
    // pair<int,vector<string>> p=noofcellsways(n);
    // for(auto i:p.second)
    // {
    //     cout<<i<<endl;
    // }
    // cout<<"*********"<<endl;
    // ways(n+1,0,"");
    //printlex(n,0);
    string s;
    cin>>s;
    // vector<string> res=printpermut(s,0);
    // sort(res.begin(),res.end());
    // vector<string> res1=printpermut1(s,n-1);
    // sort(res1.begin(),res1.end());
    // assert(res==res1);
    //printpermut3(s,"");
    printpermut4(s,0);
    //changes(s);
    return 0;
}