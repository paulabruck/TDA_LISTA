*Un Readme.txt donde explique el TDA implementado. Explique qué es una lista y qué tipos diferentes de lista
conoce.

El TDA implementado es el de lista simplemente enlazada. Este tipo junto a las pilas, colas , listas circulares y listas 
doblemente enlazadas son de la gran cantidad de tdas que existen el grupo mas comun. Una pila es una estructura de datos usada para
apilar elementos y los agrupa con una politica particular denominada LIFO que significa Last in , first out que vendria a ser que 
el ultimo elemento apilado es el primero en ser desapilado esto en el caso de las pilas es lo que actua como contrato, quien
programa puede ver el tope de la pila , puede apilar o desapilar cosas,puede craer o destruir el elemento pila y chequear si esta 
se encuentra vacia. Otro tipo de dato abstracto es el de cola donde sus elementos se manejan con la estructura FIFO First in first out
que quiere decir que se elimina por el final y se inserta por el frente. El conjunto minimo de operaciones que tiene este tipo 
de dato son crear, encolar para insertar un elemento , desencolar para eliminar un elemento, destruir, primero (indica el 
primer elemento de la cola) y vacio para verificar si la cola esta vacia. también existen las listas que son un tda cuyo objectivo 
es agrupar elementos cada uno va a tener un sucesor menos el ulitmo elemento y un predecedor excepto el primer elemento- Dentro de sus
operaciones podemos encontrar insertar y eliminar un elemento , crear o destruir una lista, ver el elemento y vacio para chequear si
la lista esta vacia. Las listas se dividen a su vez en listas simplemente enlazadas, doblemente enlazas o circulares. En las listas
simplemente enlazadas cada nodo conoce al nodo siguiente, de forma tal que es unidireccional su recorrido. La lista mantiene 
referencia al primer nodo ,Las operaciones basicas de una lista simplemente enlazada son:
crear,insertar,insertar en posicion,borrar,borrar de posicion,elemento en posicion,ultimo,vacia,elementos,destruir. En las listas
doblemente enlazadas se mantiene una referencia a su predecedor y otra referencia al sucesor. El primer nodo apunta a NULL ya que no tiene
antecesor y a su vez el ultimo nodo apunta a NULL ya que no tiene predecedor. En las listas circulares la diferencia con los otros
tipos de listas es que al ultimo nodo que en los casos anteriores haciamos apuntar a NULL ahora reapunta al primer nodo haciendo que
nunca se llegue a una posición en la que ya no sea posible desplazarse. Cuando  llegue al último elemento, el desplazamiento
vuelve a comenzar desde el primer elemento. 


*El Readme.txt deberá contener también una explicación de la solución implementada. Este archivo le sirve a
su corrector para saber si entendió o no el tema. Explique la implementación como si se lo estuviese explicando
a alguien que no sabe del tema. Explique las decisiones que tomó al implementar las primitivas. Si hizo alguna
suposición para resolver el TP (ya sea por enunciado poco claro o cualquier otro motivo) también explı́quela.

Bueno para la implementación de este TDA lo primero que hice fue resolver la pregunta teórica sobre la lista y
los otros tipos de datos abstractos que habíamos visto para así tener bien claro que era lo que iba a tener que hacer.
Ahi realicé los dibujos de cómo funcionaría cada primitiva para tener visualizado que iban a hacer cada una. 
Después de eso usando lista.h como ejemplo de que primitivas tenía que implementar empecé con lista crear.
Una vez hecha está primitiva pase a hacer lista insertar. Lo primero que hice fue hacer una prueba donde no se pueda insertar un elemento en una lista que no exista,
tambien hice pruebas que verificaran que se iban agregando los elementos e insertando al final como corresponde si es que existe la lista .
Para poder hacer estas pruebas complete la primitiva de lista elementos, que me devuelve la cantidad de elementos almacenados en la lista,
para poder corroborar que una vez que insertaba elementos en la lista esten esa cantidad que habia insertado , a su vez realicé la primitiva de lista último para poder ver
cada vez que insertaba un elemento que  este se insertara al final y luego hice lista destruir para asi poder liberar la lista y no tener errores de memoria.
Una vez que tenía estas pruebas pasé a hacer la primitiva tratando de cubrir todos los casos que había puesto en las pruebas. Una vez que me funcionó sin pérdida de memoria
pasé a hacer lista insertar en posición. Nuevamente fui a las pruebas y trate de insertar un elemento en una posición en una lista que no existía después también traté de insertar
en una posición habiendo creado una lista y cree la primitiva de lista elementos en posición que me devuelve el elemento en la posición que yo le indico, para asi corroborar que una
vez que inserte en una posición en ella esté el elemento insertado. Otra prueba que realicé fue fijarme que si quería insertar un elemento en una posición que no existía el elemento
se insertará al final de la lista.Después de escribir el código y que pasen las pruebas pasé a hacer lista borrar ,para corroborar esta primitiva hice la prueba de borrar en una lista
que no existe y después traté de borrar en una lista que si existía y que se le habían agregado elementos. Una vez que estas pruebas pasaban pasé a borrar en una posición específica.
Para esto probé el caso en que la lista no existía entonces no se podía borrar y después cuando la lista si estaba creada después de haber insertado intentaba eliminar y me fijaba si 
se había eliminado . Otra prueba que hice fue que si no existía la posición que me pedían  eliminará el último elemento que estaba en la lista . Una vez que esto funcionaba pase a hacer
las funciones de pila de apilar y desapilar . Primero fui a hacer las pruebas y me fijé que si no existía la lista que no me pudiera apilar y después que si si existía la lista me 
apilara elementos cumpliendo la política que tienen estas lo mismo hice para desapilar .Cómo En la pila se apilan los elementos de manera que el último elemento apilado es el primero
en ser desapilado lo que hice fue en lista apilar llamar a lista insertar en posición para que se inserte en la posición cero y en lista desapilar llame a lista borrar de posición para
que se borre de la posición cero entonces el último elemento apilado va a ser el primero en ser desapilado. Elegí hacerlo de esta manera y no con lista insertar en el final y 
lista borrar en el final porque la complejidad de insertar y borrar en posición es o (1) y si optaba por la otra implementación insertar al final si era o(1) pero borrar al final 
era o(n) . Lo mismo me paso con lista destruir, al usar dentro del while lista borrar de posición me quedo una complejidad en esa función de o(n) en cambio si hubiera usado lista borrar
 en su lugar hubiera quedado o(n^2). Junto con las funciones de pila hice lista Tope que me devuelve el elemento que se encuentra en el tope de la pila . Hice pruebas para probar a 
 medida que apilaba cuáles iban siendo los topes y que coincidiera con la política de la pila . Una vez que todo esto funcionaba pase a  hacer encolar y desencolar. En este caso  
 Como las colas tienen la política de qué El primer elemento insertado es a su vez el primero en ser  eliminado en lista encolar llame a lista insertar que es de complejidad o(1) 
 que me inserte por el final y en lista desencolar llame a lista borrar de posición cero que también es o(1) y entonces que borre por el inicio. De esta manera se respeta el
 comportamiento de una cola y optimizamos el nivel de complejidad. Luego cree lista primero que me devuelve el primer elemento de la cola, una vez que me pasaron las pruebas de
 esto pase hacer el itirador externo. Primero hice las pruebas, probé que si quería crear un interador en una lista que no existía me cree un iterador nulo por ende que el iterador
  no tenga siguiente, que no pueda avanzar. Después pense en el caso que haya un interador en una lista que si existía y entonces me fijé que el iterador no tenga siguiente Y que no 
puede avanzar porque no se habian insertado elementos en la lista y por la tanto no tenía  sobre que  iterar. Después agregué elementos y comprobé que tenga siguiente y que pueda avanzar
e hice una prueba donde le inserte  una frase y me fijé que el elemento actual sea el esperado, que pueda avanzar y que cuando se quede sin elementos no pueda avanzar . 
Y una vez que todo esto funcionó pase al iterador interno. Como prueba  hice una función de prueba que me devolviera una frase y dándole una lista creada inserte la frase, luego llamaba
 al iterador interno y corroboraba que una frase que me devuelva siga siendo la misma que habia insertado , que  a su vez  itere sobre un elemento y que el elemento en la  posición cero
sea la frase que había insertado. Lo mismo hice con varios casos y  probé que si no hubieran elementos me devolviera cero interacciones. Luego pasé a la implementación del código.
Creo que lo que más me costo hacer fueron las pruebas y tener en cuenta todos los casos bordes sin dejar ninguno afuera. 