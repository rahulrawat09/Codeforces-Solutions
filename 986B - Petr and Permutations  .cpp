#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
//#define bint ll 1024_t
#define ld long double
#define vect vector<ll>
#define pb push_back
#define F first
#define pll pair<ll,ll>
#define S second
#define pi 3.1415926536
#define mp make_pair
#define mod int(1e9+7)
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;


ll  _mergeSort(ll  arr[], ll  temp[], ll  left, ll  right);
ll  merge(ll  arr[], ll  temp[], ll  left, ll  mid, ll  right);

/* This function sorts the input array and returns the
number of inversions in the array */
ll  mergeSort(ll  arr[], ll  array_size)
{
    ll  temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function that sorts the input array and
returns the number of inversions in the array. */
ll  _mergeSort(ll  arr[], ll  temp[], ll  left, ll  right)
{
    ll  mid, inv_count = 0;
    if (right > left) {
        /* Divide the array ll o two parts and
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
ll  merge(ll  arr[], ll  temp[], ll  left,
          ll  mid, ll  right)
{
    ll  i, j, k;
    ll  inv_count = 0;

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

int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll  n;
    cin>>n;
    ll  v[n];
    for(ll  i=0;i<n;i++) cin>>v[i];

    ll  p=mergeSort(v,n);

    if((3*n)%2==p%2) cout<<"Petr";
    else cout<<"Um_nik";

    return 0;
}
