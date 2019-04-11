#include<iostream>
#include<cstdlib>
#include<cstring>
#include<stack>
using namespace std;

struct node
{
    char data;
    node *child[128];
    node()
    {
        for (int i = 0; i < 128; i++)
            child[i] = NULL;
    }
};

/*
 * trie class Declaration
 */
class trie
{
    private:
        node *root;
    public:
        trie()
        {
            root = new_node(0);
        }

        node *new_node(int data)
        {
            node *Q = new node;
            Q->data = data;
            return Q;
        }

        void add(string S)
        {
            node *cur = root;
            for (int i = 0; i < S.length(); i++)
            {
                if (!cur->child[S[i] - 'A'])
                    cur->child[S[i] - 'A'] = new_node(S[i]);
                cur = cur->child[S[i] - 'A'];
            }
        }

        void check(node *cur, string S, int i)
        {
            if (cur)
            {
                cout<<cur->data;
                if (i < S.length())
                    check(cur->child[S[i] - 'A'], S, i + 1);
            }
        }

        void checkroot(string S)
        {
            if (root && S.length() > 0 && S[0] > 'A')
                check(root->child[S[0] - 'A'],S,1);
            else
                cout<<"\nEmpty root \n";
        }
};

/*
 * Main
 */
int main()
{
    trie dict;
    dict.add("are");
    dict.add("area");
    dict.add("base");
    dict.add("cat");
    dict.add("cater");
    dict.add("basement");
    dict.add("sagar");
    dict.add("hello");
    dict.add("tree");
    string input;
    while(true){
        cout<<" (?) Enter the Words : ";
        cin>>input;
        cout<<" --> "<<input << ":   ";
        dict.checkroot(input);
        cout<<endl;
        cout<<endl;
    }
    return 0;
}
