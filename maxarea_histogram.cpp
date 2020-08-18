#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int largestRectangleArea(vector<int>& heights) 
{
    int n = heights.size();
    
    stack<int> st;
    
    int i = 0;
    
    int area;
    int max_area = 0;
    int tp;
    
    while(i<n)
    {
        if(st.empty() || heights[st.top()] <= heights[i])
        {
            st.push(i++);
        }
        else
        {
            tp = st.top();
            st.pop();
            area = heights[tp] * (st.empty() ? i : i - st.top() - 1);
            max_area = max(max_area, area);
        }
    }
    
    while (st.empty() == false) 
    { 
        tp = st.top(); 
        st.pop(); 
        area = heights[tp] * (st.empty() ? i : i - st.top() - 1); 
        max_area = max(max_area, area);
    } 

    return max_area; 
}
int main()
{
    cout << "Enter size : \n";
    int n;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements : \n";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << "Max histogram area : " << largestRectangleArea(arr) << '\n';
    return 0;
}