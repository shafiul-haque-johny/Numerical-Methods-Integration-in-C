#include<stdio.h>
float total;


   int trapizoidal(float a,float b, float h)
 {
  float result;
  result=((a+b)/2)*h;
  total=total+result;

  //printf("%f\n",total);
 }


 float simpsons_one_third(float a,float b,float c,float h)
{
    float result;
    result=h*(a+(4*b)+c)/6;
    total=total+result;


}


float simpsons_three_eight(float a,float b,float c,float d,float h)
{
    float result;


    result=h*((a+(3*b)+(3*c)+d))/8;
    total=total+result;
    printf("nahian");


}


int main()
{
    double dist[50];
    float value[50];

    float fun_value[50];
    int n,i;
    float d;
    total=0;

    printf("enter the number of input");
    scanf("%d",&n);
    printf("enter the values and funtion values: \n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&value[i]);
        printf("  ");
        scanf("%f",&fun_value[i]);
    }

    for(i=0;i<n-1;i++)
    {
        dist[i]=value[i+1]-value[i];
    }


     //for(i=0;i<n-1;i++)
    //{
        //printf("%f\n",dist[i]);
    //}



    i=0;
    int a;
   while(i<n)
    {   a=0;
        if((!dist[i]>dist[i+1]&&!dist[i]<dist[i+1])&&(!dist[i]>dist[i+2]&&!dist[i]<dist[i+1])&&a==0)
        {
            d=value[i+3]-value[i];
            //printf("%f\n",d);
            simpsons_three_eight(fun_value[i],fun_value[i+1],fun_value[i+2],fun_value[i+3],d);
            i=i+4;
            a=1;
        }
        if((!dist[i]>dist[i+1]&&!dist[i]<dist[i+1])&&a==0)
        {
            d=value[i+2]-value[i];
            //printf("%f",d);
          simpsons_one_third(fun_value[i],fun_value[i+1],fun_value[i+2],d);
            i=i+3;
            a=1;
        }

        if(dist[i]!=dist[i+1]&&a==0)
        {   d=value[i+1]-value[i];
            trapizoidal(fun_value[i],fun_value[i+1],d);
            i=i+2;
            a=1;
        }



    }
    printf("integral value is:%f",total);

}
