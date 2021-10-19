#include <bits/stdc++.h>

class WordDictionary
{
    struct TrieNode
    {
        TrieNode() : isWord_(false), children_(26, nullptr) {}
        bool isWord_;
        std::vector<std::shared_ptr<TrieNode>> children_;
    };

    std::shared_ptr<TrieNode> root_;

    bool find(std::shared_ptr<TrieNode> res, std::string &prefix, int idx)
    {
        if (res != nullptr)
        {
            if (prefix.size() == idx)
            {
                return res->isWord_;
            }

            if (prefix[idx] == '.')
            {
                for (auto child : res->children_)
                {
                    if (find(child, prefix, idx + 1))
                    {
                        return true;
                    }
                }
            }
            else
            {
                return find(res->children_[prefix[idx] - 'a'], prefix, idx + 1);
            }
        }

        return false;
    }

public:
    WordDictionary() : root_(std::make_shared<TrieNode>()) {}

    void addWord(std::string word)
    {
        auto res = root_;
        for (auto c : word)
        {
            if (res->children_[c - 'a'] == nullptr)
            {
                res->children_[c - 'a'] = std::make_shared<TrieNode>();
            }
            res = res->children_[c - 'a'];
        }
        res->isWord_ = true;
    }

    bool search(std::string word)
    {
        return find(root_, word, 0);
    }
};