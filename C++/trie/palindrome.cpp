#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode {
  public:
    char data;
    TrieNode** children;
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode*[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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
            root->childCount++;
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
            if (root->isTerminal == true) {
                return true;
            }
            else {
                return false;
            }
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

    bool isPalindrome(string check_substr)
    {
        int l = check_substr.length();
        for (int i = 0; i < l / 2; i++) {
            if (check_substr[i] != check_substr[l - i - 1])
                return false;
        }
        return true;
    }

    bool findIfPalindromePair(vector<string> arr)
    {
        for (int i = 0; i < arr.size(); i++) {
            string s = arr[i];
            if (isPalindrome(s)) {
                return true;
            }
            for (int j = i + 1; j < arr.size(); j++) {
                string check_substr;
                check_substr = arr[i] + arr[j];
                if (isPalindrome(check_substr)) {
                    return true;
                }
                check_substr = arr[j] + arr[i];
                if (isPalindrome(check_substr)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Trie t;
    vector<string> vect;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    bool ans = t.findIfPalindromePair(vect);
    if (ans) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
