#include <iostream>
#include <stack>
#include <string>


using namespace std;

void format (string x)
{
    int i=0;
    int j=0;
    string show;
    string sub,sb,save;
    stack<int> stk;
    stk.push(j);
    while(i<x.size())
    {
        string word(j,' ');  //creating string that contain space in a variable j
        sub = x[i];
        if (sub=="<")
        {
            sb=x[i+1];
                  if (sb!="/")   
                {
                    sub = x[i];
                    while(sub!=">")
                    {
                       sub = x[i];
                       save+=sub;
                       i++;
                    }
                    j+=4;
                    stk.push(j);   //if it's an opening tag save the number of spaces in stack
                    word+=save;
                    show = word;
                }    
                    else if (sb=="/")
                {    
                        while(sub!=">")
                        {
                          sub = x[i];
                          save+=sub;
                          i++;
                        }
                        stk.pop();     
                        j=stk.top();     // if it's a closing tag pop it from the stack and save the new number of spaces in the string
                        string word(j,' ');
                        word += save;
                        show =word;
                        
                }
        }
        else 
        {
            while(sub!="<")
            {
                save+=sub;
                word+=sub;
                i++;
                sub = x[i];
            }
            show = word;
        }
        cout<<show<<endl;
        word="";
        save="";
        show="";
    } 
}

int main()
{
   
    string x = "<users><user><id>1</id><name>user1</name><posts><post>Lorem ipsum dolor sit amet</post></posts><followers><follower><id>2345</id></follower><follower><id>45</id></follower></followers></user></users>";
    format (x);
    return 0;
}




