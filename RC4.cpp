#include <bits/stdc++.h>

#define N 256   // 2^8
using namespace std;

int main() {
	int n,i,j,len,x;
    cout<<"Enter secret key legth: ";
    cin>>n;
    cout<<"Enter secret key values:"<<endl;
    int sec_key[n];
    for(i=0;i<n;i++)
     cin>>sec_key[i];
     
    int s[N],k[N];
    for(i=0;i<N;i++){
    	s[i]=i;
    	k[i]=sec_key[i%n];
	}
	
//	cout<<endl<<"Initial arrays of s and k are:"<<endl<<endl;
//	cout<<"s:"<<endl;
//	for(int i=0;i<256;i++)
//	 cout<<i<<" "<<s[i]<<endl;
//	cout<<endl<<endl;
//	cout<<"k:"<<endl;
//	for(int i=0;i<256;i++)
//	 cout<<i<<" "<<k[i]<<endl;
//	cout<<endl<<endl;

	j=0;
	for(i=0;i<N;i++) {
        j=(j+s[i]+k[i])%N;
        swap(s[i],s[j]);
    }
    
//	cout<<"Array s after swapping:"<<endl;
//	for(int i=0;i<256;i++)
//	 cout<<i<<" "<<s[i]<<endl;
//	cout<<endl<<endl;

	string p;
	cout<<"Enter plain text:"<<endl;
	cin>>p;
    i=0;j=0;
	len=p.size();
	int c[len];
	cout<<endl;
	cout<<"Key stream:"<<endl;
	
    for(x=0;x<len;x++) {
        i = (i + 1) % N;
        j = (j + s[i]) % N;

        swap(s[i],s[j]);
        int rnd = s[(s[i] + s[j]) % N];
		cout<<"Round"<<x<<":"<<endl;
		cout<<"key:"<<rnd<<endl;
		cout<<endl;
        c[x] = (rnd^int(p[x]));
    }
    
    cout<<"Cipher text is:"<<endl;
    for(auto ch:c)
     cout<<ch<<" ";
    cout<<endl;

    return 0;
}
