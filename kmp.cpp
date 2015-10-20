#include<bits/stdc++.h>
#define lim 1000000
#define ll long long 
using namespace std;
ll f[lim],i,j,n;

void preprocess(char pat[])
{
	ll len=strlen(pat);
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

void match(char text[],char pat[])
{
	preprocess(pat);
	j=0;i=0;
	bool flag=0;
	ll plen=strlen(pat),tlen=strlen(text);
   while(i<tlen)
   {
      
	  if(pat[j]==text[i])
	  {
	  i++;j++; 
	  }
      if(j==plen)
	  {
	  	printf("%lld\n",i-j);
	    j=f[j-1];
	  	flag=1;
	  }
      else if(i<tlen && pat[j]!=text[i])
	  {
	  	if(j>0)
	  	j=f[j-1];
	  	else
	    i++;
      }
   }	
   if(flag)
   printf("\n");
}

int main()
{ 
  //std::ios_base::sync_with_stdio(false);
 //freopen("in.txt","r",stdin);
  char pat[lim],text[lim];
  scanf("%s%s",pat,text);
  match(text,pat);
  return 0;
}
