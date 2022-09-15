#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


template <class T>
class List{
public:
	List(); 
	~List();
	List(const List<T>& other); 
	const List<T>& operator=(const List<T>& rhs);
private:
	ListNode<T> *Head, *Tail; 
	int count; 
    
//adding to the front (head)
template <class T>
void List<T>::push_front(const T& item){
	Head->Prev = new ListNode(item); 
	Head->Prev->Next = Head; 
	Head = Head->Prev; 
	count++;
}

//adding to the end (tail)
template <class T>
void List<T>::push_back(const T& item)
{
	Tail->Next = new ListNode(item); 
	Tail->Next->Prev = Tail; 
	Tail = Tail->Next; 
	count++; 
}


/*
Defining a node 

Ordinarily data & pointers would be private, but we’re going to be modifying them frequently & getters/setters are more pain than they’re worth
But we want the constructor so the pointers are set automatically
We could also make this a private class within a List template

*/


template <class T>
class ListNode{
public:
	ListNode() {Next = Prev = nullptr;
    }
	ListNode(const T& item) {
        Data = item; 
        Next = Prev = nullptr;
           }
	T Data;
	ListNode<T> *Next, *Prev;
};


ListNode<T> *P, *Q; 
// assume P already points to node that should follow new node 
// assume Q points to new node 
Q->Next = P; 
Q->Prev = P->Prev;
P->Prev->Next = Q; 
P->Prev = Q; 
count++; 

 

/*
Passing note: A full implementation would do things a little differently: 
Move the Node definition inside Queue
Consider making Node a class, and Queue a friend of the class
Rather than holding an item of T, have a Node contain a pointer to T, & dynamically 
allocate the data (makes it easier to move data around with pointer manipulation rather than copying it directly) 
*/


template<class T>
struct Node { 	
    T data;	
    Node<T>* next;
    };
    
    template<class T>
    class Queue { 
        public: // to be added 
        private:	Node<T>* Head, *Tail;
        };


template<class T>
Queue<T>::Queue() {     
    Head = Tail = nullptr;
    } 
template<class T> 
bool Queue<T>::is_empty() const {     
    return (Head == nullptr);
    }

/*
For adding an item, we have to consider 2 states the queue could be in: Empty or not empty 
*/

template<class T>
void Queue<T>::push(const T& item) {    
    if (is_empty()) {        
        Head = new Node<T>;       
        Head->Data = item;        
        Head -> Next = nullptr;       
        Tail = Head; // 1st item also last 	
        }    
        
        else { // already have something in queue	    
        Tail->Next = new Node<T>;	    
        Tail = Tail->Next; // Tail points to last node          
        Tail->data = item;	    
        Tail -> Next = nullptr; // and there’s nothing after     
            }
        }

/*
Getting the front item 
*/ 

template<class T>
T Queue<T>::front() const {    
    if (Head != nullptr)      
     return Head->data;   
     else         
     // throw exception
     }

/*
 Removing an item completely 
*/

template<class T>
void Queue<T>::pop() {     
    Node<T> *p = Head;     
    if (p != nullptr) {        
        Head = Head->next;       
        delete p;	    
        if (Head == nullptr)         
        Tail = nullptr;    
        } 
       }


//Cleanup & destructor  

template<class T>
void Queue<T>::clear() {    
    while (Head != nullptr) {      
        pop();   
        } 
      }
      template<class T>
      Queue<T>::~Queue() {     
          clear();
          }

// Priority Queue uses vector