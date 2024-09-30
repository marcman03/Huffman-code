#include <iostream>

using namespace std;

template <typename T>
class Queue {

private:
  struct Item {
    T value;
    Item *next;
  };

  Item *first;
  Item *last;
  int _size;

  void copyItems(const Item *item, Item *(&first), Item *(&last), int &_size)
  {
    if (item == NULL) {
      first = NULL;
      last = NULL;
      _size = 0;
      return;
    }
    first = new Item();
    first->value = item->value;
    last = first;
    _size = 1;
    while (item->next != NULL) {
      last->next = new Item();
      last = last->next;
      item = item->next;
      last->value = item->value;
      _size++;
    }
    last->next = NULL;
  }


  void deleteItems(Item *item) {
    while (item != NULL) {
      Item *aux = item;
      item = item->next;
      delete aux;
    }
  }
  
public:

  Queue() {
    first = last = NULL;
    _size = 0;
  }

  Queue(Queue &q)
  {
    copyItems(q.first, first, last, _size);
  }

  ~Queue() {
    deleteItems(first);
    _size = 0;
  }

  Queue &operator=(const Queue &q) {
    if (this != &q) {
      deleteItems(first);
      copyItems(q.first, first, last, _size);
    }
    return *this;
  }

  T front() {
    if (first == NULL) {
      cerr << "Error: front on empty queue" << endl;
      exit(0);
    }
    return first->value;
  }

  void pop() {
    if (first == NULL) {
      cerr << "Error: pop on empty queue" << endl;
      exit(0);
    }
    Item *aux = first;
    first = first-> next;
    delete aux;
    _size--;
    if (first == NULL) last = NULL;
  }

  
  void push(T value) {
    // PROGRAM THIS METHOD
  Item *pitem=new Item;
  Item *aux= first;
  pitem->value=value;
if(_size<2){
  if (first == NULL) {
	  first = last = pitem;
	  
  }

 else if((first->value)<(pitem->value)){
	  last->next=pitem;
	  last=pitem;
	  }
	
 else if((pitem->value)<(first->value)){
	 pitem->next=first;
	 first=pitem;
	
}
 }
else{
	bool trobat=false;
  while(not(aux->next==NULL) and not trobat){
	  if ((pitem->value)<(first->value)){
		  trobat=true;
		pitem->next=first;
		first=pitem;
	
		  
		  }
	  else if((pitem->value)<(aux->next->value)){
		  trobat=true;
		  pitem->next=aux->next;
		  aux->next=pitem;
		  }
	  aux=aux->next;
	  
	  
	  }
	if (not trobat){
		last->next=pitem;
		last=pitem;
		}
  }
++_size;
  }
	
  
  
  int size() {
    return _size;
  }

  template<typename U> friend ostream &operator<<(ostream &os, Queue<U> &q);

  template<typename U> friend istream &operator>>(istream &is, Queue<U> &q);
 
};


template<typename U>
ostream &operator<<(ostream &os, Queue<U> &q)
{
  os << q._size;
  for (typename Queue<U>::Item *item = q.first; item != NULL; item = item->next)
    os << " " << item->value;
  return os;
}

template<typename U>
istream &operator>>(istream &is, Queue<U> &q)
{
  int size;
  is >> size;
  if (size == 0) {
    q = Queue<U> ();
    return is;
  }
  for (int i = 0; i < size; ++i) {
    U x;
    cin >> x;
    q.push(x);
  }
  return is;
}

