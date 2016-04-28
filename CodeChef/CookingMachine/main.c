#include<stdio.h>
#include<conio.h>
int main()
{
 int t,i,count;
 long long int a,b;
 scanf("%d",&t);
 for(i=0;i<t;i++)
 {
  count=0;
  scanf("%lld %lld",&a,&b);
  if(a==b)
 { printf("%d\n",count);}
  else
  {
  while((a&(a-1))!=0)
	  { if(a%2==0)
	    {
	      count++;
	      a=a/2;
	    }
	    else
	    {
	     count++;
	     a=(a-1)/2;
	    }
	  }
 if(a<=b)
   {
    while(a!=b)
    { count++;
      a=2*a;
    }
    printf("%d\n",count);
   }
 else
   {
    while(a!=b)
    { count++;
    a=a/2;
    }
    printf("%d\n",count);
   }
 }}
 getch();
return 0;

}
