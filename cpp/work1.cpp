template <typename Key,typename E>
BSTNode<Key,E>* BST<Key,E>::removehelp(BSTNode<key,E>* rt,const Key &k)
{
    BSTNode<Key,E>* pn = rt;
    BSTNode<Key,E>* pre;
    bool le=false;
    while(pn!=NULL)
    {
        if(pn < pn->key())
        {
            pn = pn->left();
            pre=pn;
            le=true;
            continue;
        }else if(pn > pn->right())
        {
            pn = pn->right();
            pre=pn;
            le=false;
            continue;
        }else
        {
            BSTNode<Key,E>* temp=pn;
            if(pn->right()==NULL)
            {
                pn=pn->left();
                delete temp;
            }else if(pn->left()==NULL)
            {
                pn=pn->right();
                delete temp;
            }else
            {
                temp = getmin(pn->right());
                pn->setElement(temp->element());
                pn->setKey(temp->key());
                pn->setRight(deletmin(pn->right()));
                delete temp;
            }
        }
    }
    return rt;
}