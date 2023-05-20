// HEADERFILE
#include <bits/stdc++.h>
using namespace std;

// DECLARATIONS ---------------------------------------------------------------------------------------------
namespace dsa
{
    template <typename type>
    class Node
    {
    public:
        // PROPERTIES
        type data;
        Node<type> *next;

        // CONSTRUCTOR
        Node() : data(NULL), next(NULL){};
        Node(type x) : data(x), next(NULL){};

    };

    template <typename type>
    class LinkedList
    {
    public:
        // PROPERTIES
        dsa::Node<type> *head;
        dsa::Node<type> *tail;
        int size;

        // CONSTRUCTORS
        LinkedList() : head(NULL), tail(NULL), size(0){};

        // FUNCTIONS
        void beginInsert(type data);

        void lastInsert(type data);

        void locInsert(type data, int loc);

        void beginDelete();

        void lastDelete();

        void locDelete(int loc);

        void display();

        void makeCycle(int pos);

        bool isCycle();

        void removeCycle();

        int Size();

        void reverse();

        bool isKey(type key);

        bool isSorted();

        Node<type> getHead();

        void intersect(dsa::Node<type> head1, int pos);

        bool isConnected(dsa::Node<type> head1);

        void sort();
    };
};

// IMPLEMENATIONS -----------------------------------------------------------------------------------

// CLASS FUNCTIONS
template <typename type>
void dsa::Node<type>::setData(type data)
{
    this->data = data;
}

template <typename type>
type dsa::Node<type>::getData()
{
    return this->data;
}

template <typename type>
void dsa::Node<type>::setNext(Node<type> *node)
{
    this->next = node;
}

template <typename type>
dsa::Node<type> dsa::Node<type>::getNext()
{
    return this->next;
}

// Insert at Beginning
template <typename type>
void dsa::LinkedList<type>::beginInsert(type data)
{
    // MAKING A NEW NODE FROM DATA
    dsa::Node<type> *newNode = new dsa::Node<type>(data);

    // LIST IS EMPTY
    if (this->size == 0)
    {
        this->head = newNode;
        this->tail = newNode;
        this->size++;
        return;
    }
    else
    {
        // LIST IS NOT EMPTY
        newNode->next = this->head;
        this->head = newNode;
        this->size++;
        return;
    }
}

// Insert at End
template <typename type>
void dsa::LinkedList<type>::lastInsert(type data)
{
    // MAKING A NEW NODE FROM DATA
    dsa::Node<type> *newNode = new dsa::Node<type>(data);

    // // LIST IS EMPTY
    if (this->size == 0)
    {
        this->head = newNode;
        this->tail = newNode;
        this->size++;
        return;
    }
    else
    {
        this->tail->next = newNode;
        this->tail = this->tail->next;
        this->size++;
    }
}

// Insert at location
template <typename type>
void dsa::LinkedList<type>::locInsert(type data, int loc)
{
    dsa::Node<type> *newNode = new dsa::Node<type>(data);
    dsa::Node<type> *temp = this->head;
    if (this->size == 0)
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else if (loc > this->size)
    {
        this->tail->next = newNode;
        this->tail = this->tail->next;
    }
    else
    {
        if (loc == 1)
        {
            newNode->next = temp;
            temp = newNode;
        }
        else
        {
            for (int i = 1; i < loc - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    this->size++;
}

// Begin delete
template <typename type>
void dsa::LinkedList<type>::beginDelete()
{
    dsa::Node<type> *temp = this->head;
    if (this->head != NULL)
    {
        this->head = this->head->next;
        this->size--;
    }
    else
    {
        cout << "List is empty\n";
    }
    free(temp);
}

template <typename type>
void dsa::LinkedList<type>::lastDelete()
{
    dsa::Node<type> *temp = this->head;
    dsa::Node<type> *temp1 = this->head;
    if (temp == NULL)
    {
        cout << "List is empty\n";
        this->size = 0;
        return;
    }
    else if (this->head->next == NULL)
    {
        temp = this->head;
        this->head = NULL;
        this->tail = NULL;
        this->size--;
        free(temp);
        return;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = NULL;
        this->tail = temp1;
        this->size--;
        free(temp);
        return;
    }
}

template <typename type>
void dsa::LinkedList<type>::locDelete(int loc)
{
    dsa::Node<type> *temp = this->head;
    dsa::Node<type> *temp1 = this->head;

    if (loc != 0)
    {
        if (this->size == 0)
        {
            cout << "List is Empty\n";
        }
        else if (loc > this->size)
        {
            if (temp->next == NULL)
            {
                this->head = NULL;
                this->tail == NULL;
                this->size = 0;
                free(temp);
            }
            else
            {
                while (temp->next != NULL)
                {
                    temp1 = temp;
                    temp = temp->next;
                }
                temp1->next = NULL;
                this->tail = temp1;
                this->size--;
                free(temp);
            }
        }
        else
        {
            if (loc == 1)
            {
                this->head = this->head->next;
            }
            else
            {
                for (int i = 1; i < loc; i++)
                {
                    temp1 = temp;
                    temp = temp->next;
                }
                temp1->next = temp->next;
                free(temp);
            }
            this->size--;
        }
    }
}

template <typename type>
void dsa::LinkedList<type>::display()
{
    dsa::Node<type> *traverseNode = this->head;

    while (traverseNode != NULL)
    {
        cout << traverseNode->data << " -> ";
        traverseNode = traverseNode->next;
    }
    cout << "NULL\n";
}

// Make Cycle
template <typename type>
void dsa::LinkedList<type>::makeCycle(int pos)
{
    dsa::Node<type> *temp = this->head;
    dsa::Node<type> *start;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            start = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = start;
}

template <typename type>
bool dsa::LinkedList<type>::isCycle()
{
    dsa::Node<type> *tortoise = this->head;
    dsa::Node<type> *rabbit = this->head;
    while (rabbit != NULL && rabbit->next != NULL)
    {
        tortoise = tortoise->next;
        rabbit = rabbit->next->next;

        if (tortoise == rabbit)
        {
            return true;
        }
    }
    return false;
}

template <typename type>
bool dsa::LinkedList<type>::isSorted()
{
    bool flag = 1;
    dsa::Node<type> *temp = this->head;
    if (temp == NULL || temp->next == NULL)
    {
        flag = 1;
    }
    else
    {
        if (temp->next != NULL)
        {
            if (temp->data < temp->next->data)
            {
                while (temp->next != NULL)
                {
                    if (temp->data > temp->next->data)
                    {
                        flag = 0;
                        break;
                    }
                    temp = temp->next;
                }
            }
            else
            {
                while (temp->next != NULL)
                {
                    if (temp->data < temp->next->data)
                    {
                        flag = 0;
                        break;
                    }
                    temp = temp->next;
                }
            }
        }
    }
    return flag;
}

template <typename type>
void dsa::LinkedList<type>::removeCycle()
{
    dsa::Node<type> *tortoise = this->head;
    dsa::Node<type> *rabbit = this->head;
    if (head != NULL && head->next != NULL && head->next->next != NULL)
    {
        do
        {
            tortoise = tortoise->next;
            rabbit = rabbit->next->next;
        } while (rabbit != tortoise);
        rabbit = head;
        while (tortoise->next != rabbit->next)
        {
            tortoise = tortoise->next;
            rabbit = rabbit->next;
        }
        tortoise->next = NULL;
    }
}

template <typename type>
int dsa::LinkedList<type>::Size()
{
    return this->size;
}

template <typename type>
void dsa::LinkedList<type>::intersect(dsa::Node<type> head1, int pos)
{
    dsa::Node<type> *temp1 = this->head;
    dsa::Node<type> *temp2 = &head1;
    pos--;
    while (pos--)
    {
        if (temp1 != NULL)
            temp1 = temp1->next;
    }
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

template <typename type>
void dsa::LinkedList<type>::reverse()
{
    dsa::Node<type> *prev = NULL;
    dsa::Node<type> *current = this->head;
    dsa::Node<type> *nextNode;
    if (this->head == NULL || this->head->next == NULL)
    {
        return;
    }
    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    this->head = prev;
}

template <typename type>
bool dsa::LinkedList<type>::isKey(type key)
{
    dsa::Node<type> *temp = this->head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <typename type>
dsa::Node<type> dsa::LinkedList<type>::getHead()
{
    return *this->head;
}

template <typename type>
bool dsa::LinkedList<type>::isConnected(dsa::Node<type> head1)
{
    dsa::Node<type> *temp1 = this->head;
    dsa::Node<type> *temp2 = &head1;
    int l1 = 0, l2 = 0;
    while (temp1 != NULL)
    {
        l1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        l2++;
        temp2 = temp2->next;
    }
    temp1 = this->head;
    temp2 = &head1;
    int len;
    if (l1 < l2)
    {
        len = l2 - l1;
        while (len--)
        {
            temp2 = temp2->next;
        }
    }
    else
    {
        len = l1 - l2;
        while (len > 0)
        {
            temp1 = temp1->next;
            len--;
        }
    }
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 == temp2)
        {
            return true;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return false;
}

template <typename type>
void dsa::LinkedList<type>::sort()
{
    dsa::Node<type> *current = this->head;
    dsa::Node<type> *index = NULL;
    int temp;
    if (this->head == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            // index points to the node next to current
            index = current->next;

            while (index != NULL)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}
