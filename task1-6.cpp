#include <iostream>

using namespace std;

class node {
 public:
  int data;
  node *next;

  node() {}
  node(int d) : data(d), next(NULL) {}
};

class sll {
 public:
  node *head;
  sll() { head = NULL; }
  sll(node *n) { head = n; }

  void insertatstart(int d) {
    node *temp = new node(d);
    temp->next = head;
    head = temp;
  }

  void insertatend(int d) {
    node *temp = head;
    if (head == NULL) {
      head = new node(d);
      return;
    }
    while (temp->next != NULL) {
      temp = temp->next;
    }

    temp->next = new node(d);
  }

  void insertatpos(int d, int pos) {
    node *temp = head;
    if (pos == 0) {
      insertatstart(d);
    }
    for (int i = 0; i < pos - 1 && temp->next != NULL; i++) {
      temp = temp->next;
    }
    node *newnode = new node(d);
    newnode->next = temp->next;
    temp->next = newnode;
  }

  void print() {
    node *temp = head;

    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << "\n";
  }

  void replacenode(int d, int pos) {
    if (head == NULL) {
      return;
    }
    if (pos == 0) {
      node *newnode = new node(d);
      newnode->next = head->next;
      delete head;
      head = newnode;
      return;
    }

    node *temp = head;
    for (int i = 0; i < pos - 1 && temp->next != NULL; i++) {
      temp = temp->next;
    }

    if (temp->next == NULL) {
      // Position out of range
      return;
    }

    node *newnode = new node(d);
    newnode->next = temp->next->next;
    delete temp->next;
    temp->next = newnode;
  }

  void deleteatstart() {
    node *temp = head;
    delete temp;
    head = head->next;
  }

  void deleteatend() {
    node *temp = head;
    if (head == NULL) {
      return;
    }
    if (temp->next == NULL) {
      deleteatstart();
      return;
    }

    while (temp->next->next != NULL) {
      temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
  }

  void deleteatpos(int pos) {
    node *temp = head;
    if (head == NULL) {
      return;
    }
    if (pos == 0) {
      deleteatstart();
      return;
    }
    for (int i = 0; i < pos - 1 && temp->next != NULL; i++) {
      temp = temp->next;
    }

    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
  }

  ~sll() {
    node *temp;
    while (head != NULL) {
      temp = head;
      head = head->next;
      delete temp;
    }
  }
};

int main() {
  sll list;
  list.insertatend(1);
  list.insertatend(2);
  list.insertatend(3);
  list.print();
  list.insertatstart(0);
  list.print();
  list.insertatpos(5, 4);
  list.print();
  list.insertatpos(6, 5);
  list.print();
  list.deleteatend();
  list.print();
  list.deleteatpos(3);
  list.print();
  list.replacenode(10, 2);
  list.print();
  return 0;
}