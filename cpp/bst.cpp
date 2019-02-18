#include <bits/stdc++.h>

using namespace std;

template <typename Key,typename Value>
class Node
{
private:
    Key key;
    Value val;
    int N;
public:
    Node<Key,Value> * leftC;
    Node<Key,Value> * reightC;
    Node(Key key = NULL,Value val = NULL,int N = 0,Node * leftC = NULL,Node * reightC = NULL)
    :key(key),val(val),N(N),leftC(leftC),reightC(reightC){}
    Key getKey(){return key;}
    void setKey(Key key){this->key=key;}
    Value getVal(){return val;}
    void setVal(Value val){this->val=val;}
    int setN(Node<Key,Value>*root)
    {
        if(root==NULL)return N=0;
        return root->N=setN(root->leftC)+setN(root->reightC)+1;
    }
    int size(){return setN(this);}
};

template <typename Key,typename Value>
class BST
{
private:
    Node<Key,Value> * root;
public:
    BST(Node<Key,Value> * root = NULL)
    :root(root){}
    Value get(const Key &)const;
    Value get(Node<Key,Value> *,const Key &)const;
    void put(const Key &,const Value &);
    void put(Node<Key,Value> *&,const Key &,const Value &);
    void ersea(const Key &);
    void ersea(Node<Key,Value> *,const Key &,Node<Key,Value> ** = NULL);
    void LDR(vector<Key>&ans){LDR(ans,root);}
    void LDR(vector<Key> &,Node<Key,Value>*);
};

template <typename Key,typename Value>
void BST<Key,Value>::LDR(vector<Key> &ans,Node<Key,Value> * root)
{
    if(root == NULL)return;
    LDR(ans,root->leftC);
    ans.push_back(root->getKey());
    LDR(ans,root->reightC);
}

template <typename Key,typename Value>
Value BST<Key,Value>::get(const Key& key)const
{
    return this->get(root,key);
}

template <typename Key,typename Value>
Value BST<Key,Value>::get(Node<Key,Value> * node,const Key& key)const
{
    if(node == NULL) return NULL;
    if(node->getKey()==key)return node->getVal();
    if(key>=node->getKey())return get(node->reightC,key);
    else return get(node->leftC,key);
}

template <typename Key,typename Value>
void BST<Key,Value>::put(const Key&key,const Value & val)
{
    put(root,key,val);
}

template <typename Key,typename Value>
void BST<Key,Value>::put(Node<Key,Value> * &node,const Key&key,const Value & val)
{
    if(node == NULL){node = new Node(key,val,1);return;}
    else if(node->getKey()==key)node->setVal(val);
    else if(key>=node->getKey())put(node->reightC,key,val);
    else put(node->leftC,key,val);
}

template <typename Key,typename Value>
void BST<Key,Value>::ersea(const Key & key)
{
    ersea(root,key);
}

template <typename Key,typename Value>
void BST<Key,Value>::ersea(Node<Key,Value> * node,const Key & key,Node<Key,Value> ** _fr)
{
    if(node==NULL)return;
    if(node->getKey()==key)
    {
        if(node->reightC==NULL)
        {
            if(_fr!=NULL)*_fr=node->leftC;
            else root = node->leftC;
            delete node;
        }
        else
        {
            Node<Key,Value> * temp = node->reightC;
            Node<Key,Value> * fr=NULL;
            while(temp->leftC)
            {
                fr=temp;
                temp=temp->leftC;
            }
            fr->leftC=temp->reightC;
            if(_fr!=NULL)*_fr = temp;
            else root = temp;
            delete node;
        }
        return;
    }
    if(key>=node->getKey()) ersea(node->reightC,key,&node->reightC);
    else ersea(node->leftC,key,&node->leftC);
}

struct pos
{
    int x;
    int y;
    pos(int x=0,int y=0)
    :x(x),y(y){}
};

int main()
{
    int n;
    cin>>n;
    string str;
    int x,y;
    BST<string,pos>tree;
    for (int i=0;i<n;++i)
    {
        cin>>str>>x>>y;
        tree.put(str,pos(x,y));
    }
    while(cin>>n,n!=2)
    {
        switch(n)
        {
            case 0:
                cin>>str;
                tree.ersea(str);
                break;
            case 1:
                cin>>str>>x>>y;
                tree.put(str,pos(x,y));
                break;
        }
    }
    int r;
    cin>>str>>x>>y>>r;
    vector<string>que;
    tree.LDR(que);
    for(int i=0;i<que.size();++i)
        cout<<que[i]<<endl;
    for(int i=0;i<que.size();++i)
    {
        if(str[0]==que[i][0])
            cout<<que[i]<<' '<<tree.get(que[i]).x<<' '<<tree.get(que[i]).y<<endl;
    }
    for(int i=0;i<que.size();++i)
    {
        pos temp = tree.get(que[i]);
        if(sqrt(pow(x-temp.x,2)+pow(y-temp.y,2))<=r)
            cout<<que[i]<<' '<<temp.x<<' '<<temp.y<<endl;
    }
    return 0;
}