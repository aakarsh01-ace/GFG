//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
public:
    Node* removeAllDuplicates(Node* head) {
        if (!head || !head->next) return head; // If the list is empty or has only one element, return it as is.

        Node* dummy = new Node(0); // Dummy node to handle edge cases.
        dummy->next = head;
        
        Node* prev = dummy; // This will always point to the last node in the result list that is guaranteed to have no duplicates.
        Node* current = head; // Used to explore the list.

        while (current) {
            // Check if current node is a start of a sequence of duplicates
            bool isDuplicate = false;
            while (current->next && current->data == current->next->data) {
                isDuplicate = true;
                current = current->next; // Skip all duplicates
            }

            if (isDuplicate) {
                // Skip the last duplicate
                current = current->next;
                continue;
            }

            // No duplicates were found for the current node
            prev->next = current;
            prev = prev->next;
            current = current->next;
        }

        prev->next = nullptr; // Terminate the list
        Node* newHead = dummy->next; // The head of the modified list
        delete dummy; // Clean up dummy node
        return newHead;
    }
};


//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends