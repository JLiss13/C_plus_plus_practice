// Make a linked_list using a C++
//

#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class LinkedList {
public:
    LinkedList(int value) : head(nullptr) , tail(nullptr)
    {
        Node* temp = new Node(value);
        head = temp;
        length=1;
    }

    void appendDoublely(int value) 
    {
        Node* newNode = new Node(value);
        if (!head) 
        {
            head = newNode;
            tail = newNode;
        } 
        else
        {
            newNode->prev = tail;
            tail->next =  newNode;
            tail = newNode;
            length++;
        }
    }

    void append(int value) 
    {
        Node* newNode = new Node(value);
        if (!head) 
        {
            head = newNode;
            tail = newNode;
        } 
        else
        {
            Node* current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newNode;
            tail = newNode;
            length++;
        }
    }

    void prepend(int value) 
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void prependDoublely(int value) 
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        length++;
    }

    void insertion(int index, int value) // O(n)
    {
        // First while loop through the node list and adjust the pointers at the index section
        Node* current  = head;
        Node* insertionNode = new Node(value);
        int index_cnt=0;
        while(current)
        {
            if (index == index_cnt)
            {
                insertionNode-> next = current; // Current node is the insertionNode
                prev_node->next = insertionNode; // Set the previous node next pointer to the insertionNode
                length++;
            }
            else
            {
                prev_node = current; // Save the previous node 
                current = current->next;
            }

            index_cnt++;
            
        }
    }

    Node* lookup(int index) // O(n)
    {
        if (!head)
        {
            return nullptr;
        }

        Node* current  = head;
        int index_cnt=0;
        while(current)
        {
            if (index == index_cnt)
            {
                break;
            }
            else
            {
                current = current->next;
            }
            index_cnt++;
        }

        return current;
    }

    void deletion(int index) //O(n)
    {
        // First while loop through the node list and adjust the pointers at the index section
        Node* current  = head;
        Node* deletionNode = nullptr;
        int index_cnt=0;
        while(current)
        {
            
            if (index == 0)
            {
                head = current->next;
                length--;
                break;
            }
            else if (index == index_cnt)
            {
                prev_node->next = current->next; // Set the previous node next pointer to the insertionNode
                length--;
                break;
            }
            else
            {
                prev_node = current; // Save the previous node 
                current = current->next;
            }
            index_cnt++;
        }
    }

    void reverse() //O(n)
    {
        // Make the tail the head and take the tail as the current and work my way backwards with the ptr assignments
        Node* newHead = head;
        append(newHead->data);
        deletion(0);
        display();
        for(int i=1;i<length-1;i++)
        {
            Node* newHead = head;
            insertion(length-i,newHead->data);
            deletion(0);
            display();
        }

    }
    void reverseCleaner() //O(n)
    {
        // Have placeholders for first, second, and third items
        // Check if the length of the linked list is 1 then don't reverse
        if(length<2)
        {
            std::cout << "No need to reverse order of the linked list" << std::endl;
        }
        else
        {
            Node* prevNode = nullptr;
            Node* current = head;
            Node* nextNode = nullptr;
            while (current != nullptr) {
                //tranverses through the linked list and changes all the pointers to have the previous element be the next node
                //steps through the re-referencing from head to tail
                nextNode = current->next;
                current->next = prevNode;
                prevNode = current;
                current = nextNode;
            }
            // then the last node to re-referenced becomes the head
            head = prevNode;
            display();
        }
    }
    void display() 
    {
        Node* current = head;
        while (current) 
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    ~LinkedList() 
    {
        while (head) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

private:
    Node* head;
    Node* prev_node;
    Node* tail;
    int length;
};

int main() 
{
    LinkedList myList(14);

    myList.append(1);
    myList.append(99);
    myList.appendDoublely(55);
    myList.append(300);
    myList.prepend(100);
    myList.insertion(2,22);
    myList.display();

    // myList.reverse();
    myList.reverseCleaner();

    myList.deletion(3);
    myList.display();

    return 0;
}