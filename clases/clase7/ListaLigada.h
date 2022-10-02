#include <iostream>
template <typename T>
class Node{
  private: 
    T data;
    Node<T> * next;
  friend class LinkedList;
  public:
    /**
    * @brief Constructor para un objeto Nodo
    * @param data dato del nodo
    */
    Node(T data){
      this->data=data;
      next = NULL;
    }
    /**
    * @brief Constructor para un objeto Nodo
    * @param data dato del nodo
    * @param next apuntador al siguiente nodo
    */
    Node(T data, Node<T> * next){
      this->data = data;
      this->next = next;
    }
};

template <typename T>
class LinkedList{
  private:
    Node<T> * head;
  public:
    /**
    * @brief Constructor para el objeto LinkedList
    */
    LinkedList(){
      head = NULL;
    }
    LinkedList(Node <T> * head){
      this->head = head;
    }
    void addFirst(T data){
      if(head == NULL){
        Node<T> * ptr = new Node<T>(data);
        head = ptr;
      } else{
        Node<T> * ptr = new Node<T>(data, head);
        head = ptr;
      }
    }

    void print(){
      Node <T> * aux = head;
      while(aux != NULL){
        std::cout << aux->data() << "\n";
        aux++;
      }
    }
};