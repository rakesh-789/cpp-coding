class Solution {
public:

    vector<int> nearestsmallertoleft(vector<int>& heights)
    {
        stack<int> s;
        int n=heights.size();
        vector<int> NSL(n,-1);

        for(int i=0;i<n;i++)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                NSL[i]=s.top();
            }

            s.push(i);
        }

        return NSL;
    }

    vector<int> nearestsmallertoright(vector<int>& heights)
    {
        stack<int> s;
        int n=heights.size();
        vector<int> NSR(n,n);

        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                NSR[i]=s.top();
            }

            s.push(i);
        }

        return NSR;
    }
    int largestRectangleArea(vector<int>& heights) {

        int n=heights.size();
        int maxarea=0;

        vector<int> NSL=nearestsmallertoleft(heights);
        vector<int> NSR=nearestsmallertoright(heights);

        for(int i=0;i<n;i++)
        {
            int width=NSR[i]-NSL[i]-1;
            int area=heights[i]*width;
            maxarea=max(maxarea, area);
        }

        return maxarea;
        
    }
};
