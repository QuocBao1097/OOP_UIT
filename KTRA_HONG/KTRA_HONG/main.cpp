
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
struct List {
    Node* head;
    List()
    {
        head = NULL;
    }
    void reverse()//dao nguoc
    {
        Node* current = head;
        Node *prev = NULL, *next = NULL;
        
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};
void toList(int x,List& l) {
    while (x != 0) {
        l.push(x % 10);
        x /= 10;
    }
    l.print();
}
void addTwoLists(List l1,List l2,List& l3)
{
    int s1 = 0; int s2 = 0;
    l1.reverse();
    l2.reverse();
    Node* p1=l1.head;
    Node* p2 = l2.head;
    
    while (p1 != NULL)
    {
        s1 = s1*10+p1->data;
        cout << p1->data << endl;
        p1 = p1->next;
    }
    cout << s1<<endl;
    while (p2 != NULL)
    {
        s2 = s2*10+p2->data;
        p2 = p2->next;
    }
    cout << s2 << endl;
    int s = s1 + s2;
    while (s != 0) {
        l3.push(s % 10);
        s/= 10;
    }
    l3.print();
}
void tinh(int a, int b, List& l)
{
    int x = a + b;
    while (x != 0) {
        l.push(x % 10);
        x /= 10;
    }
    l.reverse();
    l.print();
}
int main()
{
    List l2,l3;
    List l1;
    l2.push(2);
    l2.push(3);
    l1.push(1);
    l1.push(4);
    cout<<l1.head->data;
    addTwoLists(l1,l2,l3);
    cout<<endl;
    List l4;
    tinh(3, 45, l4);
    return 0;
}
