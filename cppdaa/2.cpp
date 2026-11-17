#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    char ch; int freq; Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare { 
    bool operator()(Node* a, Node* b) { return a->freq > b->freq; } 
};

void makeCodes(Node* root, string code, unordered_map<char, string>& codes) {
    if (!root) return;
    if (!root->left && !root->right) codes[root->ch] = code.empty() ? "0" : code;
    makeCodes(root->left, code + "0", codes);
    makeCodes(root->right, code + "1", codes);
}

void freeTree(Node* n) { 
    if (n) { freeTree(n->left); freeTree(n->right); delete n; } 
}

int main() {
    string s; 
    cout << "Enter text: "; 
    getline(cin, s);
    if (s.empty()) { cout << "Empty input.\n"; return 0; }

    unordered_map<char, int> freq; 
    for (char c : s) freq[c]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto [c, f] : freq) pq.push(new Node(c, f));

    while (pq.size() > 1) {
        Node *a = pq.top(); pq.pop(); 
        Node *b = pq.top(); pq.pop();
        Node *p = new Node('\0', a->freq + b->freq); 
        p->left = a; p->right = b; 
        pq.push(p);
    }

    Node* root = pq.top(); 
    unordered_map<char, string> codes; 
    makeCodes(root, "", codes);

    cout << "Huffman codes:\n"; 
    for (auto [c, code] : codes) cout << c << " : " << code << '\n';

    cout << "Encoded text: "; 
    for (char c : s) cout << codes[c]; 
    cout << '\n';

    freeTree(root);
}
