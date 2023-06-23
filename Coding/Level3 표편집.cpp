#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *pre, *post;
};

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'X');
    struct node *add = new struct node, *piv, *s;
    vector<struct node*> del;
    int bet;
    add->data = 0; add->post = add->pre = NULL;
    for(int i = 1; i < n; i++){
        struct node* nod = new struct node;
        nod -> data = i;
        nod -> post = NULL;
        if(i == k) piv = nod;
        add->post = nod;
        nod->pre = add;
        add = nod;
    }
    for(int i = 0; i < cmd.size(); i++){
        switch(cmd[i][0]){
            case 'U':
                bet = stoi(string(cmd[i].begin() + 2, cmd[i].end()));
                while(piv->pre != NULL && bet--) piv = piv->pre;
                break;
            case 'D':
                bet = stoi(string(cmd[i].begin() + 2, cmd[i].end()));
                while(piv->post != NULL && bet--) piv = piv->post;
                break;
            case 'C':
                del.push_back(piv);
                if(piv -> pre != NULL) (piv->pre)->post = piv->post;
                if(piv -> post != NULL) {
                    (piv->post)->pre = piv->pre;
                    piv = piv->post;
                }
                else piv = piv->pre;
                break;
            case 'Z':
                add = del.back();
                del.pop_back();
                if(add->post != NULL) (add->post)->pre = add;
                if(add->pre != NULL) (add->pre)->post = add;
                break;
        }
    }
    while(piv->pre != NULL) piv = piv->pre;
    while(piv != NULL){
        answer[piv->data] = 'O';
        piv = piv->post;
    }
    return answer;
}
