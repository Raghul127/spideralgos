// C++ program to find adjoint and inverse of a matrix 
#include<bits/stdc++.h> 
using namespace std; 
typedef long int ll;
int N;
ll modu;
void getCofactor(ll A[][100], ll temp[][100], int p, int q, int n) 
{ 
	int i = 0, j = 0; 

	for (int row = 0; row < n; row++) 
	{ 
		for (int col = 0; col < n; col++) 
		{ 
			if (row != p && col != q) 
			{ 
				temp[i][j++] = A[row][col]; 

				if (j == n - 1) 
				{ 
					j = 0; 
					i++; 
				} 
			} 
		} 
	} 
} 

ll determinant(ll A[][100], int n) 
{ 
	ll D = 0; 
	if (n == 1) 
		return A[0][0]; 

	ll temp2[100][100]; 

	int sign = 1;  
	for (int f = 0; f < n; f++) 
	{  
		getCofactor(A, temp2, 0, f, n); 
		D += sign * A[0][f] * determinant(temp2, n - 1); 
		sign = -sign; 
	} 
	return D; 
} 

ll modn(ll a, ll n)
{
	if(a>=0)
	return (a%n);
	else
	{ll x=-(a);
	 x=x%n;
	 x=n-x;
	 if(x==n)
	 return 0;
	 else
	 return x;
	}
}


ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        {cout << "Inverse doesn't exist"; 
		return -1;}
    else
    { 
        // m is added to handle negative x 
        ll res = (x%m + m) % m; 
        cout<<res; 
        return res;
    } 
} 

void adjoint(ll A[][100],ll adj[][100]) 
{ 
	if (N == 1) 
	{ 
		adj[0][0] = 1; 
		return; 
	} 
	int sign = 1;
	ll temp[100][100]; 

	for (int i=0; i<N; i++) 
	{ 
		for (int j=0; j<N; j++) 
		{ 
			getCofactor(A, temp, i, j, N);  
			sign = ((i+j)%2==0)? 1: -1; 

			adj[i][j] = (sign)*(determinant(temp, N-1)); 
		} 
	} 
	
	cout<<"cofactor matrix-"<<endl;
	for(int i=0;i<N;i++)
	{for(int j=0;j<N;j++)
	cout<<adj[i][j]<<" ";
	 cout<<endl;
	}
	ll adjoi[100][100];
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	adjoi[i][j]=adj[j][i];
	
	cout<<"adjoint matrix-"<<endl;
	for(int i=0;i<N;i++)
	{for(int j=0;j<N;j++)
	cout<<adjoi[i][j]<<" ";
	 cout<<endl;
	}
	cout<<"adjoint matrix after modulo-"<<endl;
	for(int i=0;i<N;i++)
   {	for(int j=0;j<N;j++)
	{adjoi[i][j]=modn(adjoi[i][j],modu);
	 cout<<adjoi[i][j]<<" ";}
	 cout<<endl;
	}
	
	
	ll det = determinant(A, N); 
	if (det == 0) 
	{ 
		cout << "determinent is 0, not invertible"<<endl; 
	} 
    else
    {
    	cout<<"determinent-"<<det<<endl;
    	cout<<"determinent with modulo-"<<modn(det,modu)<<endl;
    	det=modn(det,modu);
    	cout<<"determinent inverse-";
		 ll indet=modInverse(det,modu);
		 indet=modn(indet,modu);
		 if(indet==-1)
		 {cout<<"cant do shit"<<endl;
		 }
		 else
		 {
		cout<<endl;
    	cout<<"multiply this det inverse with adjoint mat- (det inverse)*adjointmat= "<<endl;
    	for(int i=0;i<N;i++)
   {	for(int j=0;j<N;j++)
	{adjoi[i][j]=adjoi[i][j]*indet;
	 cout<<adjoi[i][j]<<" ";}
	 cout<<endl;
	}
	
	cout<<" final inverse-"<<endl;
	for(int i=0;i<N;i++)
   {	for(int j=0;j<N;j++)
	{adjoi[i][j]=modn(adjoi[i][j],modu);
	 cout<<adjoi[i][j]<<" ";}
	 cout<<endl;
	}
	
	
        }
	}
} 

 
int main() 
{ 
     cout<<"enter order of matrix-"<<endl;
     cin>>N;
	 ll A[100][100];
	 cout<<"enter matrix-"<<endl;
	 for(int i=0;i<N;i++)
	 for(int j=0;j<N;j++)
	 cin>>A[i][j]; 

	 ll adj[100][100]; // To store adjoint of A[][] 
     cout<<"enter modulo number-"<<endl;
     cin>>modu;
     adjoint(A,adj);

	return 0; 
} 
