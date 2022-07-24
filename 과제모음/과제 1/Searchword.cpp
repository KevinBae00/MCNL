#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

const int Alphabets = 26;
int toNumber(char ch) {
    if(ch>'a')return ch - 'a';
    else return ch - 'A';
    }
struct Trie
{
    /* data */
    int count;
    Trie* children[Alphabets];
    bool terminal;
    Trie() : terminal(false){
        memset(children, 0, sizeof(children));
        count=-1;
    }
    ~Trie () {
        for(int i = 0; i < Alphabets; i++)
            if(children[i]) delete children[i];
    }
    void insert(const char* key, int num){
        if(*key == 0){
            number=num;
            terminal=true;
        }
        else{
            int next=toNumber(*key);
            if(children[next]==NULL)
                children[next]=new Trie();
            children[next]->insert(key+1);
        }
    }

    Trie* find(const char* key){
        if(*key == 0)return this;
        int next = toNumber(*key);
        if(children[next] == NULL) return NULL;
        return children[next]->find(key+1);
    }

};

int main(void){
    Trie* root = new Trie;

    ifstream ifs;
    ifs.open("words_alpha.txt");
    string str1, str2;
    int num;
    if(ifs.is_open()){
        while (!ifs.eof())
        {
            getline(ifs,str1,',');
            getline(ifs,str2);
            num=toNumber(str2);
            root->insert(str1,num);
        }
        
    }

    string str;
    for(int i=0; i<30; i++)printf("-");
    printf("\n");
    printf("%s Search Word: ", "\033[32m");
    printf("%s \n","\033[0m");
    for(int i=0; i<30; i++)printf("-");
    printf("\n");
}