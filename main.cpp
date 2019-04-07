#include "structhead.h"
using namespace std;

node *root=NULL;


int main()
{
    l:
    cout<<"**************AVL_TREE***************"<<endl;
    cout<<"       PRESS 1.INSERTION"<<endl;
    cout<<"       PRESS 2.TRAVERSE"<<endl;
    cout<<"       PRESS 3.DELETION"<<endl;
    cout<<"Enter ur choice..."<<endl;
    int ch;
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            cout<<"Enter the no. of element u want to insert"<<endl;
            int n;
            cin>>n;
            while(n--)
            {
                int val;
                cin>>val;
                root=insert(root,val);
            }
            cout<<"Data Sucessfully inserted"<<endl;
            break;
        }
        case 2:
        {
            l1:
            cout<<"     1.PREORDER"<<endl;
            cout<<"     2.INORDER"<<endl;
            cout<<"     3.POSTORDER"<<endl;
            cout<<"choose ur option..."<<endl;
            int op;
            cin>>op;
            switch(op)
            {
                case 1:
                {
                    cout<<" NODE "<<"   BALANCE_FACTOR"<<endl;
                    preorder(root);
                    break;
                } 
                case 2:
                {
                    cout<<" NODE "<<"   BALANCE_FACTOR"<<endl;
                    inorder(root);
                    break;
                }
                case 3:
                {
                    cout<<" NODE "<<"   BALANCE_FACTOR"<<endl;
                    postorder(root);
                    break;
                }
                
            }
            cout<<"press 0 to continue or any other key to exit"<<endl;
            int ch;
            cin>>ch;
            if(ch==0)
            goto l1;
            break;
        }
        case 3:
        {
            cout<<"Enter data which u want to delete"<<endl;
            int val;
            cin>>val;
            root=remove(root,val);
            cout<<"Data Sucessfully deleted"<<endl;
            break;
        }
        default:
        return 0;
    }
    goto l;
}