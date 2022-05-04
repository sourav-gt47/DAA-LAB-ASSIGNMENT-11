#include<bits/stdc++.h>
using namespace std;

void print(int n, int W,int wt[],int val[],int* X){
    
    cout<<"Items included::\n";
    int total_profit = *((X + n*W) + W );
    int w = W;
  
    for (int i=n; i>=1; i--){
        
        
        if(total_profit == *((X + (i-1)*W) + w)  )
          {
              continue;
          }
          
        else{
            cout<<"Item no = ";
            cout<< i <<endl;  //this item is included
            w = (w - wt[i]);
            total_profit = total_profit - val[i];
            if(total_profit == 0)
                {
                    break;
                    
                }
            
        }  
        
        
        
        
    }
    
    
    
}


int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	int  K[n+1][W+1];

	
	for(i = 0; i <= n; i++)
	{
		for(w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] +
								K[i - 1][w - wt[i - 1]],
								K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	
	
    print (n,W,wt,val,(int*) K );
	return K[n][W];

}



int main()
{
	int val[] = { 100,20,40,60,50,30,80};
	int wt[] = { 5,4,3,2,1,3,2};
	int W = 10;
	int n = sizeof(val) / sizeof(val[0]);  
	 int res = knapSack(W, wt, val, n);
	cout<<"Toatl cost:: "<< res<< endl;
	return 0;
}


