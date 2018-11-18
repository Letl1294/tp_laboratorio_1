#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList)); //la pasa una posicion de memoria
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{

    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = this->size; //cantidad de nodo en la lista.
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */

static Node* getNode(LinkedList* this, int nodeIndex)
{
    int i;
    Node* pNode = NULL;
    if(this!=NULL && ll_len(this) > 0 && nodeIndex < ll_len(this) && nodeIndex >= 0) //validamos la linkedList y que el indice
    {                                                                                //sea menor y igual o mayo al size.
        pNode = this->pFirstNode; //Asigno en el nodo auxiliar el primer nodo.
        for(i=0;i<nodeIndex;i++) //recorro para llegar al indice solicitado.
        {
            pNode =  pNode->pNextNode;
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNode = malloc(sizeof(Node));
    pNode->pElement = pElement;
    Node* auxNodeFirst; //declaro 3 punteros auxiliares de nodo.
    Node* auxNodePrevious;
    Node* auxNodeLast;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        if(this->pFirstNode == NULL && nodeIndex == 0) //Si el primer nodo esta vacio y quiere guardar en el indice 0.
        {
            this->pFirstNode = pNode; //asigno el nuevo nodo en el indice 0.
            this->size++; //aumento el tamaño el la linkedList.
            returnAux = 0;
        }
        else if(this->pFirstNode != NULL && nodeIndex==0) //si el pirmer nodo esta cargado y indice es 0.
        {
            auxNodeFirst = this->pFirstNode; //el nodo que habia en el indice 0 lo paso a un puntero de nodo(auxiliar).
            this->pFirstNode = pNode; //en el indice 0 cargo el nuevo nodo.
            pNode->pNextNode = auxNodeFirst; //en el indice 1 cargo el auxiliar del anterior indice 0.
            this->size++;
            returnAux = 0;
        }
        else if(this->pFirstNode != NULL && nodeIndex>0 && nodeIndex<ll_len(this)) //si el primer nodo esta cargado y el indice
        {                                                                          //es mayor a 0 y menor al len.
            auxNodeFirst = getNode(this,nodeIndex); //hago getNode para obtener el nodo en el indice solicitado.
            pNode->pNextNode = auxNodeFirst; //el nodo del indice solicitado se lo paso a siguiente del nuevo nodo.
            auxNodePrevious = getNode(this,nodeIndex-1); //obtengo al nodo del indice anterior al solicitado.
            auxNodePrevious->pNextNode = pNode; //al nodo siguiente al anterior le cargo el nuevo nodo.
            this->size++;
            returnAux = 0;
        }
        else if(this->pFirstNode != NULL && nodeIndex == ll_len(this)) //Si esta cargado y es igual al len
        {
            auxNodeLast = getNode(this,nodeIndex -1); //obtengo el anteultimo nodo.
            auxNodeLast->pNextNode = pNode; //al siguiente de este(que sera el ultimo) le paso el nuevo nodo.
            this->size++;
            returnAux = 0;
        }
    }
return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */

int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        addNode(this,ll_len(this),pElement); //llamo a la funcion addNode y le paso un indice y un elemento.
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        auxNode = getNode(this,index);
        returnAux = auxNode->pElement; //le paso al puntero de Node el elemento del nodo.
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode;

    if(this!=NULL && index>=0 && index <ll_len(this))
    {
        auxNode = getNode(this,index); //Usamos funcion getNode para obtener el nodo solicitado y se lo pasamos a un auxiliar.
        auxNode->pElement = pElement;  //le pasamos el nuevo elemento a el auxiliar.
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int nodeIndex)
{
    int returnAux = -1;
    Node* auxNodeFirst;
    Node* auxNodePrevious;
    Node* auxNodeLast;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        if(this->pFirstNode == NULL && nodeIndex == 0) //Si el primer nodo esta vacio y el indice 0.
        {
            returnAux = 0;
        }
        else if(this->pFirstNode != NULL && nodeIndex==0) //si el pirmer nodo esta cargado y indice es 0.
        {
            auxNodeFirst = this->pFirstNode; //el nodo que habia en el indice 0 lo paso a un puntero de nodo(auxiliar).
            this->pFirstNode = auxNodeFirst->pNextNode;
            free(auxNodeFirst); //Borra el nodo en el indice 0.
            this->size--;
            returnAux = 0;
        }
        else if(this->pFirstNode != NULL && nodeIndex>0 && nodeIndex<ll_len(this)) //si el primer nodo esta cargado y el indice
        {                                                                          //es mayor a 0 y menor al len.
            auxNodeFirst = getNode(this,nodeIndex); //hago getNode para obtener el nodo en el indice solicitado.
            free(auxNodeFirst); //el nodo del indice solicitado se lo paso a siguiente del nuevo nodo.
            auxNodePrevious = getNode(this,nodeIndex-1); //obtengo al nodo del indice anterior al solicitado.
            auxNodePrevious->pNextNode = getNode(this,nodeIndex+1); //al nodo siguiente al anterior le cargo el nuevo nodo.
            this->size--;
            returnAux = 0;
        }
        else if(this->pFirstNode != NULL && nodeIndex == ll_len(this)-1) //Si esta cargado y es igual al len -1
        {
            auxNodeLast = getNode(this,nodeIndex); //obtengo el anteultimo nodo.
            auxNodePrevious = getNode(this,nodeIndex -1); //obtengo el anterior al anteultimo nodo.
            auxNodePrevious = auxNodeLast->pNextNode; //le pasamos el siguiente del anteultimo(es decir el ultimo)a otro auxiliar.
            free(auxNodeLast);
            this->size--;
            returnAux = 0;
        }
    }
return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int i;
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        for(i=ll_len(this)-1;i>=0;i--)
        {
            ll_remove(this,i);
        }
    }
    return retorno;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */

int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        free(this);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */

int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* nodeAux;
    if(this!=NULL)
    {
        for(i=0;i<ll_len(this);i++) //recorro la linkedList
        {
            nodeAux = getNode(this,i); //le voy pasando al nodo auxiliar el nodo desde el indice 0 en adelante.
            if(nodeAux->pElement == pElement) //valido que si elemento sea igual al elemento que le paso a la funcion.
            {
                returnAux = i;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */

int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = 1;
        if(this->pFirstNode!=NULL)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && index>=0 && index<=ll_len(this))
    {
        returnAux = 0;
        addNode(this,index,pElement);
    }
    return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */

void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* auxNode;
    if(this!=NULL && index>=0 && index<=ll_len(this))
    {
        auxNode = ll_get(this,index);
        returnAux = auxNode;
        ll_remove(this,index);
    }
    return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/

int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = 0;
        if(ll_indexOf(this,pElement)!=-1) //Utilizamos la funcion ll_indexOf para buscar sea igual con el elemento que pasamos.
        {                                 //si es -1 es porque no esta si esta la funcion devuelve 0 o mas.
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    Node* nodeAux;
    if(this!=NULL && this2!=NULL)
    {
        returnAux = 1;
        for(i=0;i<ll_len(this2);i++) //Recorro la segunda linkedList.
        {
           nodeAux = ll_get(this2,i); //voy pasando al nodo auxiliar lo nodos a partir del indice 0.
           if(!ll_contains(this,nodeAux)) //con el if y la funcion ll_contains, validamos que el elemento este presente en
           {                              //la otra linkedList.
                returnAux = 0;
           }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL; //declaro un auxiliar de linkedList
    Node* auxNode;
    int i;
    int j = to;
    if(this!=NULL && from>=0 && to<=ll_len(this))
    {
        cloneArray = ll_newLinkedList(); //utilizo la funcion para crear una nueva linkedList.
        for(i=from;i<j;i++)
        {
            auxNode = ll_get(this,i);
            ll_add(cloneArray,auxNode);
        }
    }
    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    Node* auxNode;
    int i;
    if(this!=NULL)
    {
        cloneArray = ll_newLinkedList();
        for(i=0;i<ll_len(this);i++)
        {
            auxNode = ll_get(this,i);
            ll_add(cloneArray,auxNode);
        }
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
// */

int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order) //le pasamos una linkedlist, un puntero a funcion, y un int.
{
    int returnAux = -1;
    int i;
    Node* auxNode; //nodo auxiliar
    void* elementA; //elemento auxiliar
    void* elementB; //elemento auxiliar
    int flagSwap;
    int criterio;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0)) //validamos
    {
        do
        {
            flagSwap = 0;

            for(i=0;i<ll_len(this)-1;i++) //recorro la linkedList, a la funcion ll_len se le resta 1 porque sino nos pasamos.
            {
                auxNode = getNode(this,i); //asignamos en un auxiliar el nodo de la primera posicion.
                elementA = auxNode->pElement; //el elemento de ese nodo lo pasamos a elementA.
                auxNode = auxNode->pNextNode; //el siguiente nodo se lo pasamos al auxiliar anterior.
                elementB = auxNode->pElement; //el elemento de este nuevo nodo se lo paso a elementoB.

                if(elementA != NULL && elementB != NULL) //Valido que elementA y B sean distintos a NULL.
                {
                    criterio = pFunc(elementA,elementB); //llamo a la funcion que compara y se la asigno a criterio.

                    if((order == 0 && criterio == -1) || //dependiendo de criterio y orden lo validamos en el if.
                        (order == 1 && criterio == 1))
                    {
                        flagSwap = 1; //se le pasa un 1 para saber que entro a ordenar.
                        ll_set(this,i,elementB); //setea los elementos en la posicion de i.
                        ll_set(this,i+1,elementA);
                    }
                }
            }
        }while(flagSwap == 1); //cuando sea 0 sale porque ya no entra a ordenar.
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Hace una copia de la linkedList segun el criterio.
 * \param le pasamos un puntero de LinkedList y un puntero a funcion.
 * \param con un if validamos, recorremos con un for y si cumple el criterio agrega el elemento a la nueva lista.
 * \return retorna una copia de linkedList.
 */

LinkedList* ll_filter(LinkedList* this,int (*pFunc)(void*))
{
    LinkedList* cloneArray = NULL; //declaro un auxiliar de linkedList
    Node* auxNode;
    int i;
    if(this!=NULL && pFunc!=NULL)
    {
        cloneArray = ll_newLinkedList(); //utilizo la funcion para crear una nueva linkedList.
        for(i=0;i<ll_len(this);i++)
        {
            auxNode = ll_get(this,i);
            if(!pFunc(auxNode))
            {
                ll_add(cloneArray,auxNode);
            }
        }
    }
    return cloneArray;
}

/** \brief Modificamos los elementos de la linkedList segun un criterio.
 * \param le pasamos un puntero de LinkedList y un puntero a funcion.
 * \param con un if validamos, recorremos con un for y el elemento a la funcion criterio.
 * \return retorna 1 si se pudo realizar la modificacion.
 */

int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int retorno = -1;
    int i;
    void* auxElement;

    if(this!=NULL && pFunc!=NULL)
    {
        retorno = 0;
        for(i=0;i<ll_len(this);i++)
        {
            auxElement =  ll_get(this,i);
            if(auxElement!=NULL)
            {
                if(!pFunc(auxElement))
                {
                    retorno = 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return retorno;
}
