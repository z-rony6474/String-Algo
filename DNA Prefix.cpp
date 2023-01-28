//Light OJ Problem

#include<bits/stdc++.h>
#define nl cout<<endl;
#define First_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
typedef long long ll;

struct node
{
    ll cnt;
    node* next[4]; //for {A,C,G,T) array we declared with length 4 
    node()
    {
        cnt = 0;
        for (int i = 0; i < 4; i++)
            next[i] = NULL;
    }
} * root;

void insert(string str, ll len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = 0;//for A;
        if(str[i]=='C')id=1;
         if(str[i]=='G')id=2;
          if(str[i]=='T')id=3;
        if (curr->next[id] == NULL) curr->next[id] = new node();
        curr = curr->next[id];
        curr->cnt++;
    }
}
ll calculate(node* newnode,ll level)
{
    ll cpr = 0;
    cpr = (newnode->cnt * level);
    for (int i = 0; i < 4; i++)
    {
        if(newnode->next[i]!=NULL)
        {
            cpr = max(cpr,calculate(newnode->next[i],level+1));
        }
    }
    return cpr;
}

void del(node* newnode)
{
    for(int i=0; i<4; i++)
    {
        if(newnode->next[i]!=NULL)
          del(newnode->next[i]);
    }
    delete(newnode);
}

void solve(ll ca)
{
    root = new node();
	ll n;
	std::cin >> n;
	while(n--)
	{
	    string s;
	    std::cin >> s;
	    insert(s,s.size());
	}
	std::cout <<"Case "<<ca<<": " <<calculate(root,0ll) << std::endl;
	del(root);
}
int main()
{
	First_IO;
	ll t,ca=0;
	std::cin >> t;
	while(t--)
	{
	   	solve(++ca);
	}
	return 0;
}
// Alhamdulillah
