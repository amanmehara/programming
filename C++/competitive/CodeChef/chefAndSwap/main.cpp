// Copyright 2020 Shubham Kumar
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<string> vs;

#define FOR(i, a, n) for (int i = (a); a<n? i<n:i>n; a<n? i++:i--)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define clr(x) memset(x, 0, sizeof(x))
#define pb push_back
#define f first
#define s second
#define lli ll
#define bhag_milkha ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define deb(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cout<<"\n";}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t";
	err(++it, args...);
}

const int MOD = 1000000007;
const int N = 2e5;

// Structure which will store both 
// array elements and queries. 
struct node { 
	int pos; 
	int l; 
	int r; 
	int val;
        int plus_minus; 
}; 

// Boolean comparator that will be used 
// for sorting the structural array. 
bool comp1(node a, node b) 
{ 
	// If 2 values are equal the query will 
	// occur first then array element 
	if (a.val == b.val) 
		return a.l > b.l; 

	// Otherwise sorted in descending order. 
	return a.val > b.val; 
}

bool comp2(node a, node b) 
{ 
	// If 2 values are equal the query will 
	// occur first then array element 
	if (a.val == b.val) 
		return a.l > b.l; 

	// Otherwise sorted in ascending order. 
	return a.val < b.val; 
}

// Updates the node of BIT array by adding 
// 1 to it and its ancestors. 
void update(int* BIT, int n, int idx) 
{ 
	while (idx <= n) { 
		BIT[idx]++; 
		idx += idx & (-idx); 
                // deb(idx);
	} 
} 
// Returns the count of numbers of elements 
// present from starting till idx. 
int query(int* BIT, int idx) 
{ 
	int ans = 0; 
	while (idx) { 
		ans += BIT[idx]; 

		idx -= idx & (-idx); 
	} 
	return ans; 
} 

// Function to solve the queries offline 
vi solveQuery(int arr[], int n, int QueryL[], 
				int QueryR[], int QueryK[], int sign[], int q, int type) 
{ 
	// create node to store the elements 
	// and the queries 
	node a[n + q + 1]; 
	// 1-based indexing. 

	// traverse for all array numbers 
	for (int i = 1; i <= n; ++i) { 
		a[i].val = arr[i]; 
		a[i].pos = 0; 
		a[i].l = 0; 
		a[i].r = i;
                a[i].plus_minus = 0;
	} 

	// iterate for all queries 
	for (int i = n + 1; i <= n + q; ++i) { 
		a[i].pos = (i - n - 1)/2 + 1; 
		a[i].val = QueryK[i - n - 1]; 
		a[i].l = QueryL[i - n - 1]; 
		a[i].r = QueryR[i - n - 1];
                a[i].plus_minus = sign[i- n -1];
	} 

	// In-built sort function used to 
	// sort node array using comp function. 
        if(type==1)
	sort(a + 1, a + n + q + 1, comp1); 
        else
	sort(a + 1, a + n + q + 1, comp2); 
	// Binary Indexed tree with 
	// initially 0 at all places. 
	int BIT[n + 1]; 

	// initially 0 
	memset(BIT, 0, sizeof(BIT)); 

	// For storing answers for each query( 1-based indexing ). 
	vi ans(q/2+1,0);
	// traverse for numbers and query 
	for (int i = 1; i <= n + q; ++i) { 
                // deb(a[i].pos,a[i].l,a[i].r,a[i].val,a[i].plus_minus);
		if (a[i].pos != 0) { 

			// call function to returns answer for each query 
			int cnt = 0;
                        if(a[i].l <= a[i].r)
                        cnt = query(BIT, a[i].r) - query(BIT, a[i].l - 1); 
                        // deb(cnt);
			// This will ensure that answer of each query 
			// are stored in order it was initially asked. 
			ans[a[i].pos] += a[i].plus_minus*cnt; 
		} 
		else { 
			// a[i].r contains the position of the 
			// element in the original array. 
			update(BIT, n, a[i].r); 
		} 
	} 
        return ans; 
} 

ll _mergeSort(int arr[], int temp[], int left, int right); 
ll merge(int arr[], int temp[], int left, int mid, int right); 
  
/* This function sorts the input array and returns the  
number of inversions in the array */
ll mergeSort(int arr[], int array_size) 
{ 
    int temp[array_size]; 
    return _mergeSort(arr, temp, 0, array_size - 1); 
} 
  
/* An auxiliary recursive function that sorts the input array and  
returns the number of inversions in the array. */
ll _mergeSort(int arr[], int temp[], int left, int right) 
{ 
    ll mid, inv_count = 0; 
    if (right > left) { 
        /* Divide the array into two parts and  
        call _mergeSortAndCountInv()  
        for each of the parts */
        mid = (right + left) / 2; 
  
        /* Inversion count will be sum of  
        inversions in left-part, right-part  
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid + 1, right); 
  
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
} 
  
/* This funt merges two sorted arrays  
and returns inversion count in the arrays.*/
ll merge(int arr[], int temp[], int left, 
          int mid, int right) 
{ 
    int i, j, k; 
    ll inv_count = 0; 
  
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
  
            /* this is tricky -- see above  
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i); 
        } 
    } 
  
    /* Copy the remaining elements of left subarray  
(if there are any) to temp*/
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    /* Copy the remaining elements of right subarray  
(if there are any) to temp*/
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
}
// Driver Code 
int main() 
{ 
        int n,m;
        cin>>n>>m;
        int a[n+1];
        FOR(i,1,n+1) cin>>a[i];
        vpi q(m);
        trav(i,q) cin>>i.f>>i.s;
        int queryL[2*m],queryR[2*m],queryK[2*m],sign[2*m];
        FOR(i,0,m)
        {
                if(q[i].f > q[i].s) swap(q[i].f,q[i].s);
                queryL[2*i] = queryL[2*i+1] = q[i].f+1;
                queryR[2*i] = queryR[2*i+1] = q[i].s-1;
                queryK[2*i] = a[q[i].f];
                queryK[2*i+1] = a[q[i].s];
                sign[2*i] = 1;
                sign[2*i+1] = -1;
        }
        vi q1 = solveQuery(a,n,queryL,queryR,queryK,sign,2*m,1);
        FOR(i,0,m)
        {
                queryL[2*i] = queryL[2*i+1] = q[i].f+1;
                queryR[2*i] = queryR[2*i+1] = q[i].s-1;
                queryK[2*i] = a[q[i].f];
                queryK[2*i+1] = a[q[i].s];
                sign[2*i] = -1;
                sign[2*i+1] = 1;
        }
        vi q2 = solveQuery(a,n,queryL,queryR,queryK,sign,2*m,2);
        FOR(i,1,m+1)
        {
                int ans = q1[i]+q2[i];
                if(a[q[i-1].f] < a[q[i-1].s])
                ans++;
                if(a[q[i-1].f] > a[q[i-1].s])
                ans--;
                q1[i] = ans;
                // deb(ans);
        }
        FOR(i,0,n) a[i] = a[i+1];
        ll inv = mergeSort(a,n);
        FOR(i,1,m+1) cout<<(ll)q1[i]+inv<<"\n";
	return 0; 
} 
