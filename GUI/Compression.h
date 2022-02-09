#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

using namespace System;
using namespace std;
int CharctersFreq[95];

struct node {

    char character;
    int frequency;
    node* left;
    node* right;


};

node* makeNode(char c, int f, node* l, node* r)
{
    node* n = new node();
    n->character = c;
    n->frequency = f;
    n->left = l;
    n->right = r;
    return n;

}

struct comp
{
    bool operator()(node* l, node* r)
    {
        // highest priority item has lowest frequency
        return l->frequency > r->frequency;
    }
};

void encode(node* root, string str,
    map<char, string>& huffmanCode)
{
    if (root == nullptr)
        return;

    // found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->character] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// traverse the Huffman Tree and decode the encoded string
string demo = "";
void decode(node* root, int& index, string str)
{
    if (root == nullptr) {
        return ;
    }

    // found a leaf node
    if (!root->left && !root->right)
    {
        demo = demo + root->character;
        return ;
    }

    index++;

    if (str[index] == '0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}

void countFreq(std::string c)
{
    int j;
    string ch;
    ch.append(c);

    j = ch[0] - ' ';
    CharctersFreq[j]++;
}

void getCountFreq(string s, int size)
{
    for (int i = 0; i < size; i++)
    {
        string character, check;
        character = s[i];
        if (character == " ") {
            check = s[i + 1];
            if (character == check) continue;
        }

        countFreq(character);
    }
}

//For Compression
string encodedStr = "";
node* root;

//length of xml string -> Use it in decomposition
int length2;
string len;

//Compression
string HuffmanTree(string text) {

    string Huff = "";
    priority_queue<node*, vector<node*>, comp> pq;

    for (int i = 0; i < 95; i++)
    {
        if (CharctersFreq[i] == 0) continue;
        else
            pq.push(makeNode(char(i + ' '), CharctersFreq[i], nullptr, nullptr));

    }

    while (pq.size() != 1)
    {
        // Remove the two nodes of highest priority
        // (lowest frequency) from the queue
        node* left = pq.top(); pq.pop();
        node* right = pq.top();	pq.pop();

        /* Create a new internal node with these two nodes
           as children and with frequency equal to the sum
           of the two nodes' frequencies. Add the new node
           to the priority queue.*/
        int sum = left->frequency + right->frequency;
        pq.push(makeNode('\0', sum, left, right));
    }

    root = pq.top();
    ////////////////////////////////////////////////////
    map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    //Huff = Huff + "Huffman Codes are :\r\n" + "\r\n";

    /*for (auto pair : huffmanCode) {
        Huff = Huff + pair.first + " " + pair.second + "\r\n";
    }*/

    //Huff = Huff + "\r\nOriginal string was :\r\n" + text + "\r\n";
    //char ch;
    for (char ch : text) {
        encodedStr += huffmanCode[ch];
    }

    //Huff += encodedStr;

    string compressed = "";
    int power = 7, cursor = 0, ascii = 0;
    while (cursor < encodedStr.size())
    {
        for (int i = cursor; i < cursor + 8; i++)
        {
            if (i == encodedStr.size() - 1) {
                break;
            }

            string temp;
            temp = encodedStr[i];
            if (temp == "0")
            {
                power--;
                continue;
            }
            else
            {
                ascii += pow(2, power);
                power--;
            }
        }
        if (ascii <= 31) {
            compressed += char(ascii + 32);
        }
        else if (ascii >= 127 && ascii < 222) {
            compressed += char(ascii - 95);
        }
        else if (ascii >= 222 && ascii < 256) {
            compressed += char(ascii - 190);
        }
        else {
            compressed += char(ascii);
        }
        cursor += 8;
        power = 7;
        ascii = 0;
    }

    Huff = compressed;
    string length = to_string(encodedStr.length());
    Huff = Huff +"\r\nsize of compressed file : "+ length + " bits\r\n";

    return Huff;
}

String^ HuffmanTreeF(string text) 
{
    getCountFreq(text, text.length());
    string N = HuffmanTree(text);
    String^ encoded = gcnew String(N.c_str());

    length2 = 8 * text.length();
    len = to_string(length2);

    return encoded;
}


String^ Decompression() {
    int index = -1;

    string decomp = "";
    decomp = decomp + "\r\nDecoded string is : \r\n";

    int encodedInt = (int)encodedStr.size();

    while (index < encodedInt - 2) {
        decode(root, index, encodedStr);
    }
    
    decomp = decomp + demo + "\r\nSize of original file is: " + len + " bits";
    String^ Final = gcnew String(decomp.c_str());

    return Final;
}





