#include <iostream>

using namespace std;

template <class T>
class GenDoublyLinkedList
{
  public:
    ListNode *front;
    ListNode *back;
    unsigned int size;

    GenDoublyLinkedList();
    ~GenDoublyLinkedList();

    void insertFront(int d);
    void insertBack(int d);
    T removeFront();
    T deletePos(int pos);
    T find(int d);

    bool isEmpty();
    void printList();
    unsigned int getSize();
};
//default
template <class T>
GenDoublyLinkedList<T>::GenDoublyLinkedList()
{
  size = 0;
  front = NULL;
  back = NULL;
}
//destructor
template <class T>
GenDoublyLinkedList<T>::~GenDoublyLinkedList()
{
  //will need to iterate through the list
}
template <class T>
void DoublyLinkedList<T>::insertFront(T elem)
{
  ListNode *node = new ListNode(elem);
  //check if is empty
  if(isEmpty()) //if size == 0
  {
    //we have an empty list
    back = node;
  }
  else
  {
    //not an empty list
    node->next = front;
    front->prev = node;
  }
  front = node;
  size++;
}
template <class T>
T DoublyLinkedList<T>::removeFront()
{
  //check if empty
  //front temp
  ListNode *ft = front;
  //check if there is only one element
  if(front->next == NULL)
  {
    back = NULL;

  }
  else
  {
    //more than one element in the list
    front->next->prev = NULL;
  }
  //update where the front is
  front = front->next;
  //get data from temp
  T temp = ft->data;
  //null out the next link
  ft->next = NULL;
  //decrement size
  size--;
  //delete the original front (what we are removing)
  delete ft;
  //return temp
  return temp;
}
template <class T>
void DoublyLinkedList<T>::insertBack(T elem)
{
  ListNode *node = new ListNode(elem);
  //check if is empty
  if(isEmpty()) //if size == 0
  {
    //we have an empty list
    front = node;
  }
  else
  {
    //not an empty list
    back->next = node;
    node->prev = node;
  }
  back = node;
  size++;
}
template <class T>
ListNode* DoublyLinkedList<T>::remove(T elem)
{
  //returning pointer to node
  //not returning the data because it won't always be an int

  //first check if empty

  //iterate through list
  ListNode *curr = front;
  //run loop until data is the data we are looking for
  while(curr->data != elem)
  {
    curr = curr->next;

    if(curr == NULL)//value doesn't exist
    {
      return NULL;
    }
  }
  //found the node that contains the data 'd'
  //check if front, back, or in the middle of the linkedlist
  if(curr == front)
  {
    front = curr->next;
  }
  else if(curr == back)
  {
    //its the back
    back = curr->prev;
  }
  //it's not the front
  else
  {
    //update pointers
    //this skips over curr
    curr->prev->next = curr->next;
    //same thing
    curr->next->prev = curr->prev;
  }

  curr->next = NULL;
  curr->prev = NULL;
  size--;

  return curr;
}