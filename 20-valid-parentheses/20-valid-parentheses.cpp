class Solution {
public:
    bool isValid(string val) {
        
        stack<char> input;
        int len = val.length();
        int flag = 0;
        for(int i = 0 ; i< len ; i++)
        {
            if(val[i] == ')' || val[i] == ']' || val[i] == '}')
            {
                if(input.empty()){
                    flag = 1;
                    break;
                }

                char top = input.top();
                //cout<<top<<endl;
                if(val[i] == ')'){
                    if(top == '(')
                    {
                        input.pop();
                    }
                    else {
                        flag = 1;
                        break;
                    }
                }
                else if(val[i] == ']')
                {
                    if(top == '[')
                    {
                        input.pop();
                    }
                    else{
                        //cout<<"Inside false"<<endl;
                        flag = 1;
                        break;
                    } 
                }
                else if(val[i] == '}')
                {
                    if(top == '{')
                    {
                        input.pop();
                    }
                    else {
                        flag = 1;
                        break;
                    }
                }
            }else{
                input.push(val[i]);
            }
        }

        if(flag == 1 || input.size() > 0) return false;
        else return true;
    }
};