// #include "TrieNode.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
  public:
    char data;
    TrieNode** children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode*[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode* root;

  public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode* root, string word)
    {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            }
            else {
                return false;
            }
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    // For user
    void insertWord(string word)
    {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

    bool search(TrieNode* root, string word)
    {

        // Base case
        if (word.length() == 0) {

            return true;
        }

        int index = word[0] - 'a';
        if (root->children[index] == NULL) {
            return false;
        }
        else {
            TrieNode* child = root->children[index];
            return search(child, word.substr(1));
        }
    }

    bool search(string word)
    {
        // Write your code here

        return search(root, word);
    }

    bool patternMatching(vector<string> vect, string pattern)
    {
        // Complete this function
        // Return true or false
        string temp;
        for (int i = 0; i < vect.size(); i++) {

            temp = vect[i];
            while (temp.size() != 0) {
                insertWord(temp);
                temp = temp.substr(1);
            }
        }

        return search(pattern);
    }
};
int main()
{
    Trie t;
    int N;
    cin >> N;
    string pattern;
    vector<string> vect;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;
    if (t.patternMatching(vect, pattern)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
