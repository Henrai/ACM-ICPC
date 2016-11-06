// Anze Wang

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>

struct point  
{
    double x, y;  
    point (){}  
    point (double a,double b)  
    {  
        x=a,y=b;  
    }  
}p[1111],stack[1111];  

double dis(point a,point b)  
{  
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));  
}
point vector(point o,point a)  
{  
    return point(a.x-o.x,a.y-o.y);  
}  

bool real_cross(point a,point b)  
{  
    if(a.x*b.y>a.y*b.x)   
    return 1;  
    if(a.x*b.y<a.y*b.x)  
    return 0;  
    return dis(point(0.0,0.0),a)<dis(point(0.0,0.0),b);  
}

bool cross(point o,point a,point b)  
{  
    return real_cross(vector(o,a),vector(o,b));  
}

bool cmp(point a,point b)  
{  
    return cross(p[0],b,a);  
}
  
int graham()  
{  
     point q;  
     int i,j;  
     for(j=i=0;i<n;i++)  
     if(p[i].x<p[j].x||(p[i].x==p[j].x&&p[i].y<p[j].y))j=i;  
     q=p[j];p[j]=p[0];p[0]=q;  
     sort(p+1,p+n,cmp);  
     stack[0]=p[n]=p[0];  
     for(i=1;i<=n;i++)  
     {  
        while(m&&cross(stack[m-1],stack[m],p[i]))m--;  
        m++;stack[m]=p[i];   
     }  
}  

int main() {
    
    return 0;
}
