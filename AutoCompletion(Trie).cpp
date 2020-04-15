#include<bits/stdc++.h>
using namespace std;
const int size = 26;
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct TrieNode{
    struct TrieNode* child[size];
    bool isword;
};
typedef TrieNode* node;
node getNode(void){
    node pNode =    new TrieNode();
    pNode->isword = false;
    for(int i=0;i<size;++i)
        pNode->child[i] = NULL;
    return pNode;
}
void insert(node root,const string key){
    node pCrawl = root;
    for(int l = 0;l < key.length();++l){
        int index = CHAR_TO_INDEX(key[l]);
        if(!pCrawl->child[index])
            pCrawl->child[index] = getNode();
        pCrawl = pCrawl->child[index];

    }
    pCrawl->isword = true;
}
bool search(node root, const string key)
{
    int length = key.length();
    node pCrawl = root;
    for (int level = 0; level < length; level++)
    {
        int index = CHAR_TO_INDEX(key[level]);

        if (!pCrawl->child[index])
            return false;

        pCrawl = pCrawl->child[index];
    }

    return (pCrawl != NULL && pCrawl->isword);
}
bool isLastNode(node root)
{
    for (int i = 0; i < size; i++)
        if (root->child[i])
            return 0;
    return 1;
}
void suggestionsRec(struct TrieNode* root, string currPrefix)
{
    if (root->isword)
    {
        cout << currPrefix;
        cout << endl;
    }

    if (isLastNode(root))
        return;

    for (int i = 0; i < size; i++)
    {
        if (root->child[i])
        {
            currPrefix.push_back(97 + i);

            suggestionsRec(root->child[i], currPrefix);
            currPrefix.pop_back();
        }
    }
}

int printAutoSuggestions(node root, const string query)
{
    node pCrawl = root;

    int level;
    int n = query.length();
    for (level = 0; level < n; level++)
    {
        int index = CHAR_TO_INDEX(query[level]);

        if (!pCrawl->child[index])
            return 0;

        pCrawl = pCrawl->child[index];
    }

    bool isWord = (pCrawl->isword == true);

    bool isLast = isLastNode(pCrawl);

      if (isWord && isLast)
    {
        cout << query << endl;
        return -1;
    }

    if (!isLast)
    {
        string prefix = query;
        suggestionsRec(pCrawl, prefix);
        return 1;
    }
}
