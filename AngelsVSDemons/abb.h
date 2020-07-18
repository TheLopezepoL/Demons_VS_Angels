#ifndef ABB_H
#define ABB_H
//PREGUNTAR FISH TEMPLATE PARA HACER UN SOLO ABB
template <typename T>
struct NodeABB{
  NodeABB<T> *leftSon,*rightSon;
  T *data;
  //Attribute
  NodeABB(T * data){
      leftSon = rightSon = nullptr;
      this->data = data;
  }
};

template <typename T>
struct ABB{
    NodeABB<T> *root;
    ABB(){
        root = nullptr;
    }
    void insertar(T *data){
        root = insertarAux(data,root);
    };

};

#endif // ABB_H
