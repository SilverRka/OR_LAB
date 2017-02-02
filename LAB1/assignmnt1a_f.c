#include<stdio.h>
int combinationUtil(int arr[], int data[], int start, int end,
		    int index, int r,int n,float data_cof[r][n],float b[r],int flag);


int gauss_elimination(int m,float mat_sub[m][m],float b[m],int var,int data[])
{
  int c_bfs=0,c_ndc=0;
  int i,j,k,dec,q,e,n;
  float div,sub;
  n=m+1;
  float x[m];
  float c;
  float mat[m][m+1];
  for(i=0;i<m;i++)
    {
      for(j=0;j<m;j++)
	{
	  mat[i][j]=mat_sub[i][j];
	}
      mat[i][j]=b[i];
    }
  for(i=0;i<m;i++)
    {
      if(mat[i][i]==0)
	{
	  j=i;
	  while(j<n)
	    {
	      if(mat[j][j]!=0)
		{
		  for(k=0;k<n;k++)
		    { 
		      c= mat[i][k];
		      mat[i][k]=mat[j][k];
		      mat[j][k]=c;
		    }
		  break;
		}
	      j++;
	    }
	  float temp1 = mat[i][i];
	   if(mat[i][i]==0)
	    break;
	  for(dec=i;dec<n;dec++)
	    {
	      mat[i][dec]=mat[i][dec]/temp1;
	    }
	}
      else
	{   
	  div=mat[i][i];
	  for(q=i;q<n;q++)
	    mat[i][q]=mat[i][q]/div;
	  for(q=i+1;q<m;q++)
	    { 
	      sub=mat[q][i];
	      for(e=i;e<n;e++)
		{
		  mat[q][e]= mat[q][e]-(mat[i][e]*sub);
	       	}
	    }
	}
    }
  for(i=m-1;i>=0;i--)
    {
      x[i]=mat[i][n-1];
      if(mat[i][i]!=0)
	{
	  k=m-1;
	  while(k>i)
	    {
	      x[i] =x[i]-mat[i][k]*x[k];
	      k--;
	    }
	}
      else
	{
	  return 0;	 
	}
      printf("x%d = %f ",data[i]+1,x[i]);      
    }
  return 1;
}
int findComb(int arr[], int n, int r,float data_cof[r][n],float b[r])
{
       
  int data[r];
  int x= combinationUtil(arr, data, 0, n-1, 0, r,n,data_cof,b,0);
  return x;
}

int fact(int n)
{
  while(n>=0)
    {
      if(n==0)
	return 1;
      n=n*fact(n-1);
      return n;
    }
}
int combinationUtil(int arr[], int data[], int start, int end,
		    int index, int r,int n,float data_cof[r][n],float b[r],int flag)
{
  int flag_1;
        
  float values[r][r];
  int res,l;        
  if (index == r)
    {
      for (int j=0; j<r; j++)
	{
	  
	  for(int k =0;k<r;k++)
	    {
	      values[k][j]=data_cof[k][data[j]];
	    }
	      
	}
      int x =gauss_elimination(r,values,b,n,data);
      if(x==1)
	{
	  l=0;
	  for(res=0;res<n;res++)
	    {
	      if(data[l]==res && l<r)
		l++;
	      else
		printf("x%d =0 ",res+1);
	    }
	  flag++;
	  printf("\n");

	}
      return flag;
    }
		    
  for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
      data[index] = arr[i];
      flag=  combinationUtil(arr, data, i+1, end, index+1, r,n,data_cof,b,flag);                                             
    }
  return flag;
}
 

int main()
{
  int m,n;
  printf("enter the value of m and n\n");
  scanf("%d",&m);
  scanf("%d",&n);
  float data[m][n];
  float b[m];
  int i,j;
  printf("enter the matrix\n");
  for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
	{
	  scanf("%f",&data[i][j]);
	}
    }
  printf("enter thee  b matrix\n");
  for(i=0;i<m;i++)
    {
      scanf("%f",&b[i]);
    }

  int arr[n];
  for(i =0 ;i<n;i++)
    arr[i]=i;
  int choice;
  int count = fact(n)/(fact(n-m)*fact(m));
  printf("Basic solutions are :\n");
  int count_2=findComb(arr, n, m,data,b);
  printf("Total number of Basic Solutions are : %d\n",count_2);
}
