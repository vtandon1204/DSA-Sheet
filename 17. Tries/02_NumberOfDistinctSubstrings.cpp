class Node
{
public:
    Node *links[26];

    bool containsChar(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void putChar(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *getChar(char ch)
    {
        return links[ch - 'a'];
    }
};
class Solution
{
public:
    int countSubs(string &s)
    {
        // set<string> st;

        // for(int i=0;i<s.size();i++){
        //     string str = "";
        //     for(int j=i;j<s.size();j++){
        //         str += s[j];
        //         st.insert(str);
        //     }
        // }

        // return st.size();

        int cnt = 0;
        Node *root = new Node();

        for (int i = 0; i < s.size(); i++)
        {
            Node *node = root;
            for (int j = i; j < s.size(); j++)
            {
                if (!node->containsChar(s[j]))
                {
                    node->putChar(s[j], new Node());
                    cnt++;
                }
                node = node->getChar(s[j]);
            }
        }

        return cnt;
    }
};
