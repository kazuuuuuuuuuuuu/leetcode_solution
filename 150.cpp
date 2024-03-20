class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> st;
        for(string a : tokens)
        {
            if(a=="+")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1+num2);                
            }
            else if(a=="-")
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                st.push(num1-num2);               
            }
            else if(a=="*")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1*num2);                
            }
            else if(a=="/")
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                st.push(num1/num2);                
            }
            else
                st.push(stoi(a));
            
        }        
        return st.top();
    }
};