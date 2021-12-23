
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
//void countFreq(std::string c);
int CharctersFreq[95];
string str = "";
string finalDecoded;

struct node {
    
            char character;
            int frequency;
            node* left;
            node* right;
    
    
}; 
node* root;
node* makeNode(char c, int f, node* l, node*r)
{
    node * n = new node();
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
			unordered_map<char, string> &huffmanCode)
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
void decode(node* root, int &index, string str)
{
	if (root == nullptr) {
		return;
	}
    
	// found a leaf node
	if (!root->left && !root->right)
	{
		finalDecoded += root->character;
		return;
	}

	index++;

	if (str[index] =='0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}
void HuffmanTree(string text){
    priority_queue<node*, vector<node*>, comp> pq;
    for(int i=0;i<95;i++)
    {
        if (CharctersFreq[i]==0) continue;
        else
        pq.push(makeNode(char(i + ' '), CharctersFreq[i], nullptr, nullptr));
            
    }
    while (pq.size() != 1)
	{
		// Remove the two nodes of highest priority
		// (lowest frequency) from the queue
		node *left = pq.top(); pq.pop();
		node *right = pq.top();	pq.pop();

		/* Create a new internal node with these two nodes
		   as children and with frequency equal to the sum
		   of the two nodes' frequencies. Add the new node
		   to the priority queue.*/
		int sum = left->frequency + right->frequency;
		pq.push(makeNode('\0', sum, left, right));
	}
	 root = pq.top();
	////////////////////////////////////////////////////
	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);

	cout << "Huffman Codes are :\n" << '\n';
	for (auto pair: huffmanCode) {
		cout << pair.first << " " << pair.second << '\n';
	}

	cout << "\nOriginal string was :\n" << text << '\n';

	// print encoded string
	//string str = "";
	for (char ch: text) {
		str += huffmanCode[ch];
	}

	cout << "\nEncoded string is :\n" << str << '\n';
	cout<< "size of compressed file: "<<str.length()<<" bits"<<endl;

	// traverse the Huffman Tree again and this time
	// decode the encoded string
	int index = -1;
	/*cout << "\nDecoded string is: \n";
	while (index < (int)str.size() - 2) {
		decode(root, index, str);
	}*/
//	return root;

}


void countFreq(std::string c)
{
    int j;
    char ch[1];
    strcpy(ch,c.c_str());
    j = ch[0] - ' ';
    CharctersFreq[j]++;
}

void getCountFreq(string s,int size)
{
    for (int i=0;i<size;i++)
    {
        string character,check;
        character=s[i];
        if(character==" "){
            check = s[i+1];
            if(character==check) continue;
        }
        countFreq(character);
    }
}


int main()
{
    string s ="<user>\
                    <id>1</id>\
                    <name>Ahmed Ali</name>\
                    <posts>\
                        <post>\
                            <body>\
                                Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\
                            </body>\
                            <topics>\
                                <topic>\
                                    economy\
                                </topic>\
                                <topic>\
                                    finance\
                                </topic>\
                            </topics>\
                        </post>\
                        <post>\
                            <body>\
                                Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\
                            </body>\
                            <topics>\
                                <topic>\
                                    solar_energy\
                                </topic>\
                            </topics>\
                        </post>\
                    </posts>\
                    <followers>\
                        <follower>\
                            <id>2</id>\
                        </follower>\
                        <follower>\
                            <id>3</id>\
                        </follower>\
                    </followers>\
                </user>";//"my name is Haidy Wael & my id is $1802310";

    	getCountFreq(s,s.length());
    	/*for(int i=0;i<95;i++){
            cout<<char(i + ' ')<<"\t"<<CharctersFreq[i]<<endl;
        }*/
    	HuffmanTree(s);
    	int index = -1;
    	cout << "\nDecoded string is: \n";
    	while (index < (int)str.size() - 2) {
    		decode(root, index, str);
    	}
    	cout<<finalDecoded;

    cout<<endl;
    cout<< "size of original file: "<<s.length()*8<<" bits"<<endl;
    return 0;
}



