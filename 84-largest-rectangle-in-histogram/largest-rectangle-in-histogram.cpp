#include<bits/stdc++.h>
class Solution {
    private:
    vector<int> nextsmallerElement(vector<int> &arr, int n)
{
    vector <int> ans(n);
    stack <int> s;
    s.push(-1);
    for(int i=n-1;i>=0;i--)
    {
        while(s.top()!=-1 && arr[s.top()]>=arr[i])
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevsmallerElement(vector<int> &arr, int n)
{
    vector <int> ans(n);
    stack <int> s;
    s.push(-1);
    for(int i=0;i<n;i++)
    {
        while(s.top()!=-1 && arr[s.top()]>=arr[i])
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();

        vector<int> next(n);
        next=nextsmallerElement(heights,n);
        vector<int> prev(n);
        prev=prevsmallerElement(heights,n);
         int area=0;
        for(int i=0;i<n;i++)
        {
            int length=heights[i];
           
            if(next[i]==-1)
            {
                next[i]=n;
            }
             int breath=next[i]-prev[i]-1;
            int newarea=length*breath;
             area=max(area,newarea);
        }
        return area;
    }
};