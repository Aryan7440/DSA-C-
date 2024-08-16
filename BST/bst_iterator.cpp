#include "bst.h"

class BSTiterator
{
public:
    stack<bst *> st;
    bool Reverse;

    BSTiterator(bst *root, bool isReverse=false)
    {
        Reverse = isReverse;
        pushall(root);
    }

    bool has_next()
    {
        return !st.empty();
    }

    int next()
    {
        if (has_next() == false)
            return INT16_MIN;
        bst *temp = st.top();
        st.pop();
        if (Reverse)
        {
            if (temp->left)
                pushall(temp->left);
        }
        else
        {
            if (temp->right)
                pushall(temp->right);
        }

        return temp->val;
    }

private:
    void pushall(bst *root)
    {
        if (Reverse)
        {
            while (root)
            {
                st.push(root);
                root = root->right;
            }
        }
        else
        {
            while (root)
            {
                st.push(root);
                root = root->left;
            }
        }
    }
};


bool twoSum_bst(bst* root,int k)
{
    if(root==NULL)return false;
    BSTiterator* l=new BSTiterator(root);
    BSTiterator* r=new BSTiterator(root,true);

    int i=l->next();
    int j=r->next();
    while (i<j)
    {
        if(i+j==k)return true;
        if(i+j<k)i=l->next();
        else j=r->next();
    }
    return false;
    

}
int main()
{
    bst *root = create_bst({4,2,6,1,3,5,7,9,10,11,12});
    printBST(root);
    BSTiterator *it=new BSTiterator(root);
    // cout<<it->has_next()<<endl;
    // cout<<it->next()<<endl;
    // cout<<it->next()<<endl;
   
    BSTiterator *itr=new BSTiterator(root,true);

    cout<<twoSum_bst(root,200);


    
}