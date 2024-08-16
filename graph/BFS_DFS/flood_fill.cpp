#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int n = image.size();
    int m = image[0].size();
    queue<pair<int, int>> q;
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, 1, 0, -1};
    q.push({sr,sc});
    int src=image[sr][sc];
    image[sr][sc]=color;
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int I=p.first+di[i];
            int J=p.second+dj[i];
            if(I>=0 && I<n && J>=0 && J<m && image[I][J]==src)
            {
                image[I][J]=color;
                q.push({I,J});
            }
        }
    }
    return image;
}

int main()
{
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;
    floodFill(image,sr,sc,color);
    for(auto i:image)
    {
        for(auto j:i)cout<<j<<" ";
        cout<<endl;
    }
}