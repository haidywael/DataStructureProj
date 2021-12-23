#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
//correct function will take the string returned from the consistency function
void correct (string x)
{
    int sz;
    int i=0;
    string ch,sub,sb,show,save,word;
    string chk1,chk2;
    stack<string> o,c,temp; //o for openning tag, c for closing tag
    while(i<x.size())
    {
        sub = x[i];
        if (sub=="<")
        {
            sb=x[i+1];
                  if (sb!="/")   //open tag
                {
                    sub = x[i];
                    while(sub!=">")  //will loop till the open tag ends
                    {
                       sub = x[i];
                       save+=sub;
                       i++;
                    }
                    chk1 = save;
                    chk1.erase(remove(chk1.begin(), chk1.end(), '<'), chk1.end());
                    chk1.erase(remove(chk1.begin(), chk1.end(), '>'), chk1.end());
                    o.push(chk1);  //push the opened tag in the stack after removing the symbols: < >
                    if (!o.empty() && !c.empty()) //as if it's not the first open tag to enter will enter the condition to compare
                    {
                        if (c.top() == o.top())
                        {
                            show += save;
                            ch = c.top();
                            ch.insert(0,"<");
                            ch.insert(1,"/");
                            sz = ch.length();
                            ch.insert(sz,">"); //ch now will add the symbols: < > / as it's a closed tag
                            o.pop();
                            c.pop();
                            show += ch;
                        }
                        else
                        {
                            show += save;
                        }
                    }
                    else     //as if it's the first open tag to enter
                    {
                        show += save;
                    }
                    
                }    
                    else if (sb=="/")  //closed tag
                {    
                        while(sub!=">") //will loop till the closed tag ends
                        {
                          sub = x[i];
                          save+=sub;
                          i++;
                        }
                        chk2 = save;
                        chk2.erase(remove(chk2.begin(), chk2.end(), '<'), chk2.end());
                        chk2.erase(remove(chk2.begin(), chk2.end(), '>'), chk2.end());
                        chk2.erase(remove(chk2.begin(), chk2.end(), '/'), chk2.end());
                        c.push(chk2);  //push the closed tag in the stack after removing the symbols: < > /
                        if (!o.empty() && !c.empty())
                        {
                            if ( c.top()!= o.top() )
                            {
                                while ( !c.empty() )
                                {
                                    temp.push(c.top());  //push the closing tag into another temporary stack
                                    c.pop();
                                }
                            }
                            else if (c.top()== o.top())  
                            { 
                                while ( !o.empty() && !c.empty())
                                {
                                    ch = c.top();
                                    ch.insert(0,"<");
                                    ch.insert(1,"/");
                                    sz = ch.length();
                                    ch.insert(sz,">");  //ch now will add the symbols: < > / as it's a closed tag
                                    c.pop();
                                    o.pop();
                                    show += ch;
                                }
                            }
                        }
                        
                }
        }
        else 
        {
           while(sub!="<")  //neither opened tag nor closed tag
            {
                save+=sub;
                i++;
                sub = x[i];
            }
            show += save;
        }
        save = "";
        chk1 ="";
        chk2 ="";
        ch = "";
        while (!temp.empty())
        {
            c.push(temp.top());  //returning the closed tag back in c stack
            temp.pop();
        }
    }
    cout <<show;
}

int main() 
{
    string x = "<user><post><name>Ahmed</name><id>1</user></post></id>";
    correct(x);
    return 0;
}
