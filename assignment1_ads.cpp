#include<bits/stdc++.h>
using namespace std;

// --------Task 1---------
//Complexity: linear - O(n)

int findmin(int n, int* a, int i){
	if(i < n-1){
		return min(a[i], findmin(n, a, i+1));
	}else{
		return a[i];
	}
}

void Task1(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	cout<<findmin(n, a, 0);
}


// --------Task 2---------
//Complexity: linear - O(n)

double average(int n, int* a, int i){
	if(i < n-1){
		return (i == 0) ? (a[i] + average(n,a,i+1))/n : a[i] + average(n,a,i+1);
	}else{
		return a[i];
	}
}


void Task2(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<average(n,a,0);
}


// --------Task 3---------
//Complexity: sub-linear - (sqrt(n))

bool checkForPrime(int n, int div, int sq){
	if(n % div == 0){
		return false;
	}else{
		if(div == sq){
			return true;
		}else{
			return checkForPrime(n, div+1, sq);
		}
	}
}

bool isPrime(int n){
	const int sq = ceil(sqrt(n));
	return checkForPrime(n, 2, sq);
}


void Task3(){
	int n;
	cin>>n;
	cout<<(isPrime(n) ? "Prime" : "Composite");
}


// --------Task 4---------
//Complexity: linear - O(n)

int factorial(int n, int a){
	if(a < n){
		return factorial(n, a+1) * a;
	}
	return a;
}

void Task4(){
	int n;
	cin>>n;
	cout<<factorial(n, 1);
}



// --------Task 5---------
//Complexity: linear - O(n)


int fibonacci(int f1, int f2, int left, int right){
	if(left < right){
		return fibonacci(f2, f1+f2, left+1, right);
	}else{
		return f2;
	}
}

void Task5(){
	int n;
	cin>>n;
	cout<<fibonacci(0, 1, 1, n);
}



// --------Task 6---------
//Complexity: linear - O(n)

int power(int sum, int a, int n){
	if(n == 1){
		return sum;
	}
	return power(sum, a, n-1) * a;
}


void Task6(){
	int a,n;
	cin>>a>>n;
	cout<<power(a, a, n);
}


// --------Task 7---------
//Complexity: super-exponential - O( (n-1)! )


void rec(string s, map<string, bool>* u){
  	cout<<s<<endl;
  	(*u)[s] = true;
  	for(int i=1; i<s.size(); i++){
    	string g = s;
    	swap(g[0], g[i]);
    	if(!(*u)[g]){
      		rec(g, u);
    	}
	}
}

void Task7(){
	map<string, bool> u;
	string s;
	cin>>s;
	u[s] = true;
	rec(s, &u);
}


// --------Task 8---------
//Complexity: linear - O(n)

bool stopAtLetter(string s, int i){
	if(i == s.size()){
		return false;
	}
	if(s[i] < '0' || s[i] > '9'){
		return true;
	}
	if(s[i] >= '0' && s[i] <= '9'){
		return stopAtLetter(s, i+1);
	}
}

void Task8(){
	string s;
	cin>>s;
	cout<<(stopAtLetter(s, 0) ? "Yes" : "No");
}


// --------Task 9---------
//Complexity: exponential - O(2^n)

int binomialCoeff(int n, int k) {
    if (k == 0 || k == n)
        return 1;

    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

void Task9(){
	int n, k;
    cin>>n>>k;

    cout<<binomialCoeff(n, k);
    
}


// --------Task 10---------
//Complexity: Logarithmic - O(log(n))

int gcd(int a, int b) {
    if (b == 0)
        return a;
	
    return gcd(b, a % b);
}

void Task10(){
	int a, b;
    cin>>a>>b;
    cout<<gcd(a, b);
}

int main(){
	//Enter the function as "TaskN()"
}
