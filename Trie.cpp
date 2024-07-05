#include <bits/stdc++.h>
class Node{
    public:
    // char data;
    vector<Node*>child;
    bool terminal;
    int countprefix=0;
    int countendwith=0;
    Node(){
        // data=c;
        child.resize(26);
        for(auto &i:child)i=nullptr;
        terminal=0;
        countprefix=1;
        countendwith=0;
    }
    bool containsKey(char ch)
    {
        return child[ch-'a']!=nullptr;
    }
    void put(char ch,Node * node){
        child[ch-'a']=node;
    }

    Node * get(char ch){
        return child[ch-'a'];
    }
    void setend(){
        terminal=1;
    }

};
class Trie
{   

public:
    Node*root;
        Trie(){
            root=new Node();
        }
        void insert(string word){
            Node* node = root;
           for(int i=0;i<word.size();i++){
                char ch=word[i];
                // if their is no child 
                // of node then create it and move towards it
                if(!node->child[ch-'a']){
                    node->put(ch,new Node());
                }
                else{
                    node->countprefix++;
                }
                // move to the child node
                node=node->get(ch);
           } 
        //  at last please set the node as terminal node;
                 node->setend(); // ==== node->terminal=1;
                 node->countendwith++;
        }
        bool search(string s){
            Node*node=root;
            for(int i=0;i<s.size();i++){
                if(node->containsKey(s[i]))node=node->get(s[i]);
                else return 0;
            }
            if(node->terminal)return 1;
            return 0;
        }

        bool startsWith(string s){
            Node*node=root;
            for(int i=0;i<s.size();i++){
                if(!node->containsKey(s[i])){
                    return 0;
                }
                node=node->get(s[i]);
            }
            return 1;
        }
        int countWordsStartsWith(string s){
            Node *node=new Node;
            for(int i=0;i<s.size();i++){
                if(!node->containsKey(s[i]))return 0;
                node=node->get(s[i]);
            }
            return node->countprefix;

        }
        int countWordEqualTo(string s){
            Node *node=new Node;
            for(int i=0;i<s.size();i++){
                if(!node->containsKey(s[i]))return 0;
                node=node->get(s[i]);
            }
            return node->countendwith;
        }
        void erase(string s){
            Node *node =root;
            for(int i=0;i<s.size();i++){
                    node->countprefix--;
                    node=node->get(s[i]);
            }
            node->countendwith--;
        }

};

 