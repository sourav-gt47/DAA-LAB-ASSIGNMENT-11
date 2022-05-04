#include<bits/stdc++.h>
using namespace std;


void POP(int *s,int i, int j,int n){
 
 if(i == j)
  cout<< "A"<< i;

 else{

   cout<< "(";
   POP(s, i , *((s + i*n) + j), n);
   POP(s, *((s + i*n) + j) + 1, j, n);
   cout<< ")";

 } 


}

int matrix_chain_order(int p[],int n){

  int M[n][n];
  int S[n][n];
  int cost;

  for(int i = 1;i<n;i++)
       M[i][i] = 0;

  for(int l = 2; l < n; l++)
  {
     for(int i = 1; i < n - l +1; i++)
     {
        int j =(i + l -1);
        M[i][j] = INT_MAX;

        for(int k = i; k <= j - 1; k++)
         {

              cost = M[i][k] + M[k+1][j] + p[i-1]*p[k]*p[j];
              
                if(cost < M[i][j])
                {
                    M[i][j] = cost;
                    S[i][j] = k;
                }
         
         }



     }




  }
  
  POP((int* )S, 1, n-1,n);
  return M[1][n-1];



}


int main()
{  int n;
   cout<<"Enter size::";
   cin>>n;
   int arr[n];
   cout<<"Enter the array::";
   for(int i = 0; i < n; i++)
   cin>> arr[i];

   cout<<"\nMinimum number of scalar multiplications::" << matrix_chain_order(arr,n)<< endl;
   
    return 0;
}