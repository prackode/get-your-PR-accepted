// C++ program for Huffman Coding with STL
#include <bits/stdc++.h>
using namespace std;

//Huffman tree node
struct Node
{

    char data; // One of the input characters

    unsigned freq; // Frequency of the character

    // Left and right child of the given node
    Node *left, *right;

    Node(char data, unsigned freq, Node *l = NULL, Node *r = NULL)

    {

        this->left = l;
        this->right = r;
        this->data = data;
        this->freq = freq;
    }
};

//We will make a structure for the comparison of two heap nodes
struct Compare
{

    bool operator()(Node *l, Node *r)

    {
        return (l->freq > r->freq);
    }
};

//
//Below function will print huffman codes from the root of the Huffman Tree.
void PrintHuffman(struct Node *root, string str)
{

    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << ": " << str << "\n";

    PrintHuffman(root->left, str + "0");
    PrintHuffman(root->right, str + "1");
}

// Below  function builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void printHcodes(char arr[], int freq[], int size)
{

    // Create a min heap & inserts all characters of data[]
    priority_queue<Node *, vector<Node *>, Compare> h;

    for (int i = 0; i < size; ++i)
        h.push(new Node(arr[i], freq[i]));

    // Iterate while size of heap doesn't become 1
    while (h.size() > 1)
    {

        // Extract the two minimum
        // freq items from min heap
        Node *l = h.top();
        h.pop();

        Node *r = h.top();
        h.pop();

        // Now create a new internal node with
        // frequency equal to the sum of the
        // two nodes frequencies. Make the
        // two extracted node as left and right children
        // of this new node. Add this node
        // to the min heap '$' is a special value
        // for internal nodes, not used
        Node *top = new Node('$', l->freq + r->freq, l, r);

        h.push(top);
    }

    // Lets print Huffman codes using the Huffman tree we built above
    PrintHuffman(h.top(), "");
}

int main()
{

    char arr[] = {'a', 'b', 'y', 'z'};
    int freq[] = {30, 40, 80, 60};

    int size = sizeof(arr) / sizeof(arr[0]);

    printHcodes(arr, freq, size);

    return 0;
}
