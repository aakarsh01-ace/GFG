//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends

class Solution
{
public:
    // Function to rotate a linked list to the left by k nodes.
    Node* rotate(Node* head, int k) {
        if (head == nullptr || k == 0) return head;

        // Calculate the length of the linked list
        Node* tail = head;
        int len = 1;
        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }

        // Adjust k to be within the bounds of the list length
        k = k % len;
        if (k == 0) return head;

        // Find the new tail of the rotated list, which is the k-th node
        Node* newTail = head;
        for (int i = 1; i < k; i++) {
            newTail = newTail->next;
        }

        // The new head is the next node of newTail
        Node* newHead = newTail->next;

        // Break the list at newTail
        newTail->next = nullptr;

        // Connect the original tail to the original head
        tail->next = head;

        return newHead;
    }
};

    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends