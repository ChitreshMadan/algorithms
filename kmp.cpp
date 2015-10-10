#include<bits/stdc++.h>
#define lim 1000
#define ll long long 
using namespace std;
ll f[lim],i,j;

void preprocess(string pat)
{
	ll len=pat.length();
	f[0]=0;
	for(i=1;i<len;i++)
	{
		while( j>=0 && pat[i]!=pat[j])
		{
			if(j>=1)
			j=f[j-1];
		
			else
			j--;
		}
		j++;
		f[i]=j;
	}
}

void match(string text,string pat)
{
	preprocess(pat);
	j=0;
	ll plen=pat.length(),tlen=text.length();
   for(i=0;i<tlen;i++)
   {
      while(j>=0 && text[i]!=pat[j])
	  {
	    if(j>=1)
		j=f[j-1];
		
		else
		j--;
		
	  }	
	  j++;
	  if(j==plen)
	  {
	  	j=f[plen-1];
	  	cout<<i-plen+1;
	  }
   }	
}

int main()
{ freopen("in.txt","r",stdin);
  string pat,text;
  cin>>text>>pat;
  ll plen=pat.length();
  match(text,pat);
  return 0;
}

