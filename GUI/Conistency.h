#pragma once

#include <iostream>
#include <stack>
#include <string>
#include<vector>
#include <math.h>


using namespace std;
using namespace System;

string RemoveSpace(string xml) {
    string removed = "";
    string s, s1;
    int size = xml.length();
    int i = 0;

    while (i < size) {
        s = xml[i];
            s1 = xml[i + 1];

            if (s == " " && s1 == " ") {
                i += 2;
            }

            else if (s == "\r" || s == "\n" || s == "\t") {
                i++;
            }

            else {
                removed += s;
                i++;
            }

    }
    return removed;
}



string output = "";
string checkConsistency(string x)
{
    string co, corrected;;
    int sz;
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
                    if (i == x.size()) {
                        break;
                    }
                    sub = x[i];
                    save += sub;
                    i++;
                }
                closing = false;
                corrected += save;
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
                    if (i == x.size()) {
                        break;
                    }
                    sub = x[i];
                    save += sub;
                    i++;
                }
                closing = true;
                corrected += save;
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
            while (sub != "<")
            {
                if (i == x.size()) {
                    break;
                }
                save += sub;
                i++;
                sub = x[i];
            }
            corrected += save;
        }
        if (closing && !o.empty())
        {
            if (c.top() != o.top())
            {
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
                                output = output + s.top() + " tag isn't closed\r\n";
                                co = s.top();
                                co.insert(0, "<");
                                co.insert(1, "/");
                                sz = co.length();
                                co.insert(sz, ">");
                                corrected += co;
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
                    output = output + c.top() + " tag isn't opened\r\n";
                    co = c.top();
                    co.insert(0, "<");
                    sz = co.length();
                    co.insert(sz, ">");
                    corrected += co;
                    c.pop();
                }
            }
            else
            {
                o.pop();
                c.pop();
            }
            closing = false;
        }
        word = "";
        save = "";
        chk1 = "";
        chk2 = "";
        co = "";
    }
    while (!o.empty())
    {
        output = output + o.top() + " tag is not closed\r\n";
        co = o.top();
        co.insert(0, "<");
        co.insert(1, "/");
        sz = co.length();
        co.insert(sz, ">");
        corrected += co;
        o.pop();
    }
    while (!c.empty())
    {
        output = output + c.top() + " tag is not opened\r\n";
        co = c.top();
        co.insert(0, "<");
        sz = co.length();
        co.insert(sz, ">");
        corrected += co;
        c.pop();
    }
    //output = output + "********The file has no ERORRS********";

    return corrected;

}

/*********************************************************************************/

String^ correct(string x)
{
    int sz;
    int i = 0;
    string ch, sub, sb, show, save, word;
    string chk1, chk2;
    stack<string> o, c, temp;
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
                    if (i == x.size()) {
                        break;
                    }
                    sub = x[i];
                    save += sub;
                    i++;
                }
                
                chk1 = save;
                chk1.erase(remove(chk1.begin(), chk1.end(), '<'), chk1.end());
                chk1.erase(remove(chk1.begin(), chk1.end(), '>'), chk1.end());
                o.push(chk1);
                if (!o.empty() && !c.empty())
                {
                    if (c.top() == o.top())
                    {
                        show += save;
                        ch = c.top();
                        ch.insert(0, "<");
                        ch.insert(1, "/");
                        sz = ch.length();
                        ch.insert(sz, ">");
                        o.pop();
                        c.pop();
                        show += ch;
                    }
                    else
                    {
                        show += save;
                    }
                }
                else
                {
                    show += save;
                }

            }
            else if (sb == "/")
            {
                while (sub != ">")
                {
                    if (i == x.size()) {
                        break;
                    }
                    sub = x[i];
                    save += sub;
                    i++;
                }
                chk2 = save;
                chk2.erase(remove(chk2.begin(), chk2.end(), '<'), chk2.end());
                chk2.erase(remove(chk2.begin(), chk2.end(), '>'), chk2.end());
                chk2.erase(remove(chk2.begin(), chk2.end(), '/'), chk2.end());
                c.push(chk2);
                if (!o.empty() && !c.empty())
                {
                    if (c.top() != o.top())
                    {
                        while (!c.empty())
                        {
                            temp.push(c.top());
                            c.pop();
                        }
                    }
                    else if (c.top() == o.top())
                    {
                        while (!o.empty() && !c.empty())
                        {
                            ch = c.top();
                            ch.insert(0, "<");
                            ch.insert(1, "/");
                            sz = ch.length();
                            ch.insert(sz, ">");
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
            while (sub != "<")
            {
                if (i == x.size()) {
                    break;
                }
                save += sub;
                i++;
                sub = x[i];
            }
            show += save;
        }
        save = "";
        chk1 = "";
        chk2 = "";
        ch = "";
        while (!temp.empty())
        {
            c.push(temp.top());
            temp.pop();
        }
    }
    String^ Show = gcnew String(show.c_str());
    return Show;
}

vector<vector<string>> ids;
int a = -1;
String^ format(string xml)
{
    string x = RemoveSpace(xml);
    string formated = "";
    vector<string> v;
    int b = 0;
    int i = 0;
    int j = 0;
    int z;
    string id = "";
    string show;
    string sub, sb, save;
    stack<int> stk;
    stk.push(j);
    while (i < x.size())
    {
        string word(j, ' ');
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
                j+= 4;
                stk.push(j);
                word += save;
                show = word;
            }

            if (save == "<user>")
            {
                while (!v.empty())
                {
                    v.pop_back();
                }
                b = 0;
                a++;
            }
            if (save == "<id>")
            {
                z = i;
                while (sub != "<")
                {
                    sub = x[z];
                    z++;
                    id += sub;
                }
                id.pop_back();
                v.push_back(id);
                b++;
            }

            else if (sb == "/")
            {
                while (sub != ">")
                {
                    sub = x[i];
                    save += sub;
                    i++;
                }
                stk.pop();
                j = stk.top();
                string word(j, ' ');
                word += save;
                show = word;

            }
            if (save == "</user>")
            {
                ids.push_back(v);
            }

        }
        else
        {
            while (sub != "<")
            {
                save += sub;
                word += sub;
                i++;
                sub = x[i];
            }
            show = word;
        }

        formated += show + "\r\n";
        word = "";
        save = "";
        show = "";
        id = "";
    }
    
    String^ FORMATED = gcnew String(formated.c_str());
    return FORMATED;
}

string Lists = "";
string test()
{
    int x = ids.size()/3;
    //int x = sqrt(ids.size());
    string Lists = "";
    for (int i = 0; i < x ; i++)
    {
        Lists = Lists + ids[i][0] + " -> {";
        for (int j = 1; j < ids[i].size(); j++)
        {
            Lists = Lists + ids[i][j] + ",";
        }

        if (Lists.back() == ',')
        {
            Lists.pop_back();
        }

        Lists = Lists + "}\r\n";
    }
    return Lists;

}


string Finaal() {
    string Final = "digraph test{\n" + test() + "\n}";
    return Final;
}
