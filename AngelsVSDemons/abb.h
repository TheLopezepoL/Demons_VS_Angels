#ifndef ABB_H
#define ABB_H
//PREGUNTAR FISH TEMPLATE PARA HACER UN SOLO ABB
struct NodeABB{
  NodeABB *leftSon,*rightSon;
  //Attribute
  NodeABB(){
      leftSon = rightSon = nullptr;
  }
};


struct ABB{
    NodeABB *root;
    ABB(){
        root = nullptr;
    }
    void insertar();

};

#endif // ABB_H
