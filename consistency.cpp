#include <iostream>
#include <stack>
#include <string>
#include <algorithm>


using namespace std;

void consistency(string x)
{
    bool closing = false;
    int i = 0;
    int j = 0;
    string word;
    string sub, sb, save;
    string chk1, chk2;
    stack<string> o, c, s;
    while (i < x.size())
    {
        sub = x[i];
        if (sub == "<")
        {
            sb = x[i + 1];
            if (sb != "/")
            {
                sub = x[i];
                while (sub != ">")
                {
                    sub = x[i];
                    save += sub;
                    i++;
                }
                closing = false;
                word += save;
                chk1 = save;
                chk1.erase(remove(chk1.begin(), chk1.end(), '<'), chk1.end());
                chk1.erase(remove(chk1.begin(), chk1.end(), '>'), chk1.end());
                o.push(chk1);
            }
            else if (sb == "/")
            {
                while (sub != ">")
                {
                    sub = x[i];
                    save += sub;
                    i++;
                }
                closing = true;
                word += save;
                chk2 = save;
                chk2.erase(remove(chk2.begin(), chk2.end(), '<'), chk2.end());
                chk2.erase(remove(chk2.begin(), chk2.end(), '>'), chk2.end());
                chk2.erase(remove(chk2.begin(), chk2.end(), '/'), chk2.end());
                c.push(chk2);

            }
        }
        else
        {
            i++;
            continue;
        }
        if (closing && !o.empty())
        {
            //if(!o.empty())
           // {
            if (c.top() != o.top())
            {
                /**
                //cout << c.top() << " tag isn't opened" << endl;
                cout << o.top() << " tag isn't closed" << endl;
                o.pop();
               // c.pop();
               **/
                while (!o.empty())
                {
                    s.push(o.top());
                    o.pop();
                    if (!o.empty())
                    {
                        if (c.top() == o.top())
                        {
                            c.pop();
                            o.pop();
                            while (!s.empty())
                            {
                                cout << s.top() << " tag isn't closed" << endl;
                                s.pop();
                            }
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
                while (!s.empty())
                {
                    o.push(s.top());
                    s.pop();
                }
                if (!c.empty()) {
                    cout << c.top() << " tag isn't opened" << endl;
                    c.pop();
                }
            }
            else
            {
                o.pop();
                c.pop();
            }
            // }
            closing = false;
        }
        word = "";
        save = "";
        chk1 = "";
        chk2 = "";
    }
    while (!o.empty())
    {
        cout << o.top() << " tag is not closed" << endl;
        o.pop();
    }
    while (!c.empty())
    {
        cout << c.top() << " tag is not opened" << endl;
        c.pop();
    }
}

int main()
{
    // string x ="<id>1</user></users>";

    string x = "<users><user><id>1</id><name>user1</name><posts><post>Lorem ipsum dolor sit amet</post></posts><followers><follower><id>2345</id></follower><follower><id>45</id></follower></followers></user></users>";
    consistency(x);
    return 0;
}