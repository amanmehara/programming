// Copyright 2020 Anjali Soni
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    // For user
    void insertWord(string word)
    {
        if (insertWord(root, word))
        {
            this->count++;
        }
    }

    void print(TrieNode *root, string s)
    {
        if (root == NULL)
            return;

        if (root->isTerminal)
            cout << s << endl;

        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {

                print(root->children[i], s + root->children[i]->data);
            }
        }
    }

    void helper(TrieNode *root, string pattern, string output)
    {
        if (root == NULL)
            return;
        if (pattern.size() == 0)
        {
            if (root->isTerminal)
            {
                cout << output << "\n";
            }

            for (int i = 0; i < 26; i++)
            {
                if (root->children[i] != NULL)
                {
                    print(root->children[i], output + root->children[i]->data);
                }
            }
            return;
        }
        int idx = pattern[0] - 'a';
        output += pattern[0];
        helper(root->children[idx], pattern.substr(1), output);
    }
    void autoComplete(vector<string> input, string pattern)
    {

        for (string s : input)
        {
            insertWord(s);
        }

        string out = "";
        helper(root, pattern, out);
    }
};

int main()
{
    Trie t;
    int N;
    cin >> N;
    string pattern;
    vector<string> vect;
    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;
    t.autoComplete(vect, pattern);
}
