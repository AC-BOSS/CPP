#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> maximumCrossingSubarraySum(ll arr[],ll low,ll mid,ll high){
    ll left_sum=INT_MIN;
    ll sum=0,max_left,max_right;
    for(ll i=mid;i>=low;i--){
        sum+=arr[i];
        if(sum>left_sum){
            left_sum=sum;
            max_left=i;
        }
        else{
            break;
        }
    }
    ll right_sum=INT_MIN;
    sum=0;
    for(ll i=mid+1;i<=high;i++){
        sum+=arr[i];
        if(sum>right_sum){
            right_sum=sum;
            max_right=i;
        }
    }
    vector<ll> v;
    v.push_back(max_left);
    v.push_back(max_right);
    v.push_back(left_sum+right_sum);
    return v;
}
vector<ll> maximumSubarraySum(ll arr[],ll low,ll high){
    if(low==high){
        vector<ll> v;
        v.push_back(low);
        v.push_back(high);
        v.push_back(arr[low]);
        return v;
    }
    else{
        ll mid;
        mid=(low+high)/2;
        vector<ll> v1,v2,v3,v;
        v1=maximumSubarraySum(arr,low,mid);
        v2=maximumSubarraySum(arr,mid+1,high);
        v3=maximumCrossingSubarraySum(arr,low,mid,high);
        if(v1[2]>=v2[2]&&v3[2]<=v1[2]){
            return v1;
        }
        else if(v1[2]<=v2[2]&&v3[2]<=v2[2]){
            return v2;
        }
        else{
            return v3;
        }
    } 
}
void solver(){
    ll n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    cout<<"\n";
    ll arr[n];
    cout<<"Enter the elements of the array : ";
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\n";
    vector<ll> res;
    res=maximumSubarraySum(arr,0,n-1);
    cout<<"The maximum subarray starts from index "<<res[0]<<" and ends at index "<<res[1]<<" and the sum is "<<res[2]<<"\n\n";
}
int main(){
    solver();
    return 0;
}
