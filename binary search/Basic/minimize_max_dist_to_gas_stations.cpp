#include<bits/stdc++.h>
using namespace std;
bool isFeasable(vector<int> &stations, int K,double dist)
    {
        for(int i=0;i+1<stations.size();i++)
        {
            K-=ceil(stations[i+1]-stations[i])/dist   -1;
            if(K<0)return false;
        }
        return true;
    }
    double findSmallestMaxDist(vector<int> &stations, int K){
      // Code here
      int n=stations.size();
      double l=0,r=stations[n-1]-stations[0];
      double mid=0;
      while(r-l>1e-6)
      {
          mid=l+(double)(r-l)/2;
          if(isFeasable(stations,K,mid))r=mid;
          else l=mid;
      }
      return r;
    }
    int main()
    {
        vector<int> stations={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        cout<<findSmallestMaxDist(stations,9);
    }