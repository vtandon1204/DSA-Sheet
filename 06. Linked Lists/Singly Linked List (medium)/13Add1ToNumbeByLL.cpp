struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *reverse(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    while (curr)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node *addOne(Node *head)
{
    head = reverse(head);

    Node *curr = head;
    int carry = 1;

    while (curr)
    {
        int sum = curr->data + carry;
        curr->data = sum % 10;
        carry = sum / 10;

        if (!curr->next && carry)
        {
            curr->next = new Node(carry);
            carry = 0;
            break;
        }
        curr = curr->next;
    }

    return reverse(head);
}