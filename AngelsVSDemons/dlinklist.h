#ifndef DLINKLIST_H
#define DLINKLIST_H

//TEMPLATE DE NODO
template <typename T>
struct Node{
    //Attr.
    Node<T> *nxt,*prv;
    T*data;
    //Constr.
    Node<T>(){
        this->nxt = this->prv = nullptr;
        this->data = nullptr;
    }
    Node<T>(T* data){
        this->nxt = nullptr;
        this->prv = nullptr;
        this->data = data;
    }
};

//TEMPLATE DE LISTA DOBLEMENTE ENLAZADA
template <typename T>
struct DLinkList{
    //Attr.
    Node<T> *first,*last;
    //Constr.
    DLinkList(){
        this->last = this->first = nullptr;
    }
    //////////////////////////////////////////////////////////////////////////
    //Methods
    //Verifica si la lista esta vacia
    bool isEmpty(){
        return first == nullptr;
    }
    /*
     * (INSERTAR AL FINAL)
     * E: Una persona
     * S: No tiene
     * D: Agrega un OBJETO en la lista
     */
    void append(T* data){
        if (isEmpty())
            first = last = new Node<T>(data);
        else{
            Node<T> *nuevo = new Node<T>(data);
            last->nxt = nuevo;
            nuevo->prv = last;
            last = nuevo;
        }
    }

    /*LENTGH
     * E: No tiene
     * S: Int
     * D: Da la cantidad de elem de la lista
     */

    int length(){
        int i = 0;
        Node<T> *tmp = first;
        while (tmp != nullptr) {
            ++i;
            tmp = tmp->nxt;
        }
        return i;
    }





};

#endif // DLINKLIST_H
