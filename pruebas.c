#include "lista.h"
#include "pa2mm.h"
#include <string.h>

void dadaunalistainexistente_siinsertounelemento_nologroinsertarnada(){
  lista_t* lista_ =NULL ;
  int estado_insercion=0;
 
  estado_insercion= lista_insertar(lista_, (void*)1 );
  pa2m_afirmar(estado_insercion == -1, "La lista no existe por lo tanto no se puede insertar elementos");
  lista_destruir(lista_);    
}
void dadaUnaLista_SiInsertoElementos_SeAgrandaLaLista(){
  lista_t* lista_= lista_crear();
  int estado_insercion= lista_insertar(lista_, (void*)1 );
  pa2m_afirmar(estado_insercion == 0 && lista_elementos(lista_)==1, "Se inserta un elemento a la lista por lo tanto no es nula");
  pa2m_afirmar(lista_ultimo(lista_)==(void*)1, "EL elemento insertado es 1 y se inserta al final");
  estado_insercion= lista_insertar(lista_, (void*)2);
  pa2m_afirmar(estado_insercion==0 && lista_elementos(lista_)==2, "La lista tiene 2 elementos");
  pa2m_afirmar(lista_ultimo(lista_)==(void*)2, "EL elemento insertado es 2 y se inserta al final");

  estado_insercion= lista_insertar(lista_, (void*)3);
  pa2m_afirmar(estado_insercion==0 && lista_elementos(lista_)==3, "La lista tiene 3 elementos");
  pa2m_afirmar(lista_ultimo(lista_)==(void*)3, "EL elemento insertado es 3 y se inserta al final")

  estado_insercion= lista_insertar(lista_, (void*)4);
  pa2m_afirmar(estado_insercion==0 && lista_elementos(lista_)==4, "La lista tiene 4 elementos");
  pa2m_afirmar(lista_ultimo(lista_)==(void*)4, "EL elemento insertado es 4 y se inserta al final")

  estado_insercion= lista_insertar(lista_, (void*)5);
  pa2m_afirmar(estado_insercion==0 && lista_elementos(lista_)==5, "La lista tiene 5 elementos");
  pa2m_afirmar(lista_ultimo(lista_)==(void*)5, "EL elemento insertado es 5 y se inserta al final")
  lista_destruir(lista_);
}
void dadaunalistainexistente_siinsertounelementoEnUnaPosicionEspecifica_nologroConcretarLaInsercion(){
  lista_t* lista_ =NULL ;
  int estado_insercion=0;
 
  estado_insercion= lista_insertar_en_posicion(lista_, (void*)1,0 );
  pa2m_afirmar(estado_insercion == -1, "La lista no existe por lo tanto no se puede insertar el elemento en la posicion solicitada");
  lista_destruir(lista_); 
}
void dadaUnaLista_SiInsertoUnElementoEnUnaPosicionEspecifica_ElElementoSeInsertaEnLaPosicionEsperada(){
  lista_t* lista_= lista_crear();
  int estado_insercion=0;
  estado_insercion= lista_insertar_en_posicion(lista_, (void*)1,0 );
  pa2m_afirmar(estado_insercion == 0, "El primer elemento ha sido insertado en la posicion 0");
  pa2m_afirmar(lista_elemento_en_posicion(lista_,0)==(void*)1, "El elemento insertado es 1");

  estado_insercion= lista_insertar_en_posicion(lista_, (void*)1,1 );
  pa2m_afirmar(estado_insercion == 0, "El segundo elemento ha sido insertado en la posicion 1");
  pa2m_afirmar(lista_elemento_en_posicion(lista_,1)==(void*)1, "El elemento insertado es 1");
  
  lista_destruir(lista_); 
}
void dadaUnaLista_SiInsertoUnElementoEnUnaPosicionQueNoExiste_ElElementoSeInsertaAlFinal(){
  lista_t* lista_= lista_crear();
  int estado_insercion=0;
  estado_insercion= lista_insertar_en_posicion(lista_, (void*)1, 0);
  pa2m_afirmar(estado_insercion == 0 && lista_ultimo(lista_)==(void*)1 , "AL estar vacia la lista el elemento se inserta al final");

  estado_insercion= lista_insertar_en_posicion(lista_, (void*)2, 3);
  pa2m_afirmar(estado_insercion == 0 && lista_ultimo(lista_)==(void*)2 , "La posicion solicitada es inexistente por lo tanto el elemento se inserta al final");
  
  lista_destruir(lista_); 

}
void dadaUnaListaInexistente_SiBorroUnElemento_ElElementoNoSeBorra(){
  lista_t* lista_ = NULL;
  int estado_insercion=0;
 
  estado_insercion= lista_borrar(lista_);
  pa2m_afirmar(estado_insercion == -1, "La lista no existe por lo tanto no se puede borrar un elemento");

  lista_destruir(lista_); 

}
void dadaUnaLista_SiBorroUnElemento_ElElementoSeBorra(){
  lista_t* lista_ = lista_crear();
  int estado_eliminacion=0;
  int estado_insercion= lista_insertar(lista_, (void*)1 );
  
  estado_eliminacion= lista_borrar(lista_);
  pa2m_afirmar(estado_eliminacion == 0 && estado_insercion==0 && lista_elementos(lista_)==0, "Puedo borrar un elemento de una lista de 1 elemento ");
  
  estado_insercion= lista_insertar(lista_, (void*)1 );
  estado_insercion= lista_insertar(lista_, (void*)2 );
  estado_eliminacion= lista_borrar(lista_);
  pa2m_afirmar(estado_insercion==0 && estado_eliminacion==0 && lista_elementos(lista_)==1, "Puedo borrar un elemento de una lista de 2 elementos");

  estado_insercion= lista_insertar(lista_, (void*)2 );
  estado_insercion= lista_insertar(lista_, (void*)3 );
  estado_eliminacion= lista_borrar(lista_);
  pa2m_afirmar(estado_insercion==0 && estado_eliminacion==0 && lista_elementos(lista_)==2, "Puedo borrar un elemento de una lista de 3 elementos");

  estado_insercion= lista_insertar(lista_, (void*)3 );
  estado_insercion= lista_insertar(lista_, (void*)4 );
  estado_eliminacion= lista_borrar(lista_);
  pa2m_afirmar(estado_insercion==0 && estado_eliminacion==0 && lista_elementos(lista_)==3, "Puedo borrar un elemento de una lista de 4 elementos");

  estado_insercion= lista_insertar(lista_, (void*)4 );
  estado_insercion= lista_insertar(lista_, (void*)5 );
  estado_eliminacion= lista_borrar(lista_);
  pa2m_afirmar(estado_insercion==0 && estado_eliminacion==0 && lista_elementos(lista_)==4, "Puedo borrar un elemento de una lista de 5 elementos");
  lista_destruir(lista_); 
  
}
void dadaUnaListaInexistente_SiIntentoBorrarUnElementoDeUnaPosicionEspecifica_NoPuedoConcretarLaEliminacion(){
  lista_t* lista_ = NULL;
  int estado_eliminacion=0;
 
  estado_eliminacion= lista_borrar_de_posicion(lista_, 2);
  pa2m_afirmar(estado_eliminacion == -1, "La lista no existe por lo tanto no se puede borrar un elemento en la posicion indicada");

  lista_destruir(lista_); 

}
void dadaUnaLista_SiBorroUnElementoEnUnaPosicionEspecifica_SeBorraElElemento(){
  lista_t* lista_= lista_crear();
  int estado_eliminacion=0;
  int estado_insercion=0;
  estado_insercion= lista_insertar_en_posicion(lista_, (void*)1,0 );
  estado_eliminacion= lista_borrar_de_posicion(lista_,0);
  pa2m_afirmar(estado_insercion == 0 && estado_eliminacion==0 && lista_elementos(lista_)==0, "Se puede borrar un elemento de la posicion 0 siendo esta el final de la lista");

  estado_insercion= lista_insertar_en_posicion(lista_, (void*)1,0 );
  estado_insercion= lista_insertar_en_posicion(lista_, (void*)1,1 );
  estado_eliminacion=lista_borrar_de_posicion(lista_, 1);
  pa2m_afirmar(estado_insercion == 0 && estado_eliminacion==0 && lista_elementos(lista_)==1, "Se puede borrar un elemento de la posicion 1 siendo esta el final de las lista");

  estado_insercion= lista_insertar_en_posicion(lista_, (void*)1,1 );
  estado_insercion= lista_insertar_en_posicion(lista_, (void*)1,2 );
  estado_eliminacion= lista_borrar_de_posicion(lista_, 2);
  pa2m_afirmar(estado_insercion == 0 && estado_eliminacion==0 && lista_elementos(lista_)==2, "Se puede borrar el elemento en la posicion esperada");

  estado_insercion=lista_insertar_en_posicion(lista_, (void*)1, 3);
  estado_eliminacion= lista_borrar_de_posicion(lista_, 4);
  pa2m_afirmar(estado_insercion== 0 && estado_eliminacion ==0 && lista_elementos(lista_)==2, "Si no existe la posicion solicitada se elimina el ultimo elemento");

  lista_destruir(lista_);  
}
void dadaUnaListaInexistente_AlCrearUnIterador_ResultaEnUnIteradorNull(){
  lista_t* lista_=NULL;
	lista_iterador_t* iterador=lista_iterador_crear(lista_);
  pa2m_afirmar(iterador==NULL, "Si no existe la lista el iterador creado es Null");
  pa2m_afirmar(!lista_iterador_tiene_siguiente(iterador), "El iterador no tiene siguiente");
  pa2m_afirmar(!lista_iterador_avanzar(iterador) , "El iterador no puede avanzar ");
  lista_destruir(lista_);
}
void dadaUnaLista_AlCrearUnIterador_ResultaEnUnIteradorNoNulo(){
  lista_t* lista_ = lista_crear();
    
  lista_iterador_t* iterador=lista_iterador_crear(lista_);
  pa2m_afirmar(!lista_iterador_tiene_siguiente(iterador), "El iterador no tiene siguiente si no se le han cargado elementos");
  pa2m_afirmar(!lista_iterador_avanzar(iterador), "El iterador no puede avanzar no se le han cargado elementos");
  lista_iterador_destruir(iterador);

  lista_insertar(lista_, (void*)1);
  lista_insertar(lista_, (void*)2);
  lista_iterador_t* iterador_=lista_iterador_crear(lista_);
  pa2m_afirmar(lista_iterador_tiene_siguiente(iterador_) , "El iterador tiene siguiente se le han cargado elementos");
  pa2m_afirmar(lista_iterador_avanzar(iterador_) , "El iterador puede avanzar al siguiente ");
  
  lista_iterador_destruir(iterador_);
  lista_destruir(lista_);
}
void dadaUnaLista_AlCrearUnIterador_PrueboElIterador(){
  lista_t* lista_=lista_crear();
  char* frase="hola";
  int estado_insercion=lista_insertar(lista_, frase);
  lista_insertar(lista_, (void*)1);
  lista_iterador_t* iterador= lista_iterador_crear(lista_);
  pa2m_afirmar(lista_iterador_elemento_actual(iterador)==frase, "El elemento actual del iterador es el esperado");
  pa2m_afirmar(lista_iterador_tiene_siguiente(iterador)&& estado_insercion==0, "El iterador tiene siguiente");
  pa2m_afirmar(lista_iterador_avanzar(iterador), "El iterador puede avanzar");
  pa2m_afirmar(lista_iterador_elemento_actual(iterador)==(void*)1, "El elemento actual del iterador es el esperado");
  pa2m_afirmar(lista_iterador_tiene_siguiente(iterador)&& estado_insercion==0, "El iterador  tiene siguiente");
  pa2m_afirmar(!lista_iterador_avanzar(iterador), "El iterador no puede avanzar");
  pa2m_afirmar(lista_iterador_elemento_actual(iterador)==NULL, "El elemento actual del iterador es el esperado");
  pa2m_afirmar(!lista_iterador_tiene_siguiente(iterador)&& estado_insercion==0, "El iterador no tiene siguiente");
  
  
  lista_iterador_destruir(iterador);
  lista_destruir(lista_);

}
void dadaUnaListaInexistente_AlVerSiLaListaEstaVacia_VemosQueSiLoEsta(){
  lista_t* lista_=NULL;
  pa2m_afirmar(lista_vacia(lista_), "La lista no existe por lo tanto esta vacia");
  lista_destruir(lista_);
}
void dadaUnaListaInexistente_SiQuieroVerElUltimoElemento_MeDevueleveNUll(){
  lista_t* lista_=NULL;
  pa2m_afirmar(lista_ultimo(lista_)==NULL, "La lista no existe por lo tanto devuelve Null");
  lista_destruir(lista_);
}
void dadaUnaListaInexistente_SiQuieroVerLaCantidadDeElementosQueTiene_MeDevuelveQueNoTieneElementos(){
  lista_t* lista_=NULL;
  pa2m_afirmar(lista_elementos(lista_)==0, "La lista no existe por lo tanto devuelve que no tiene elementos ");
  lista_destruir(lista_);

}
void dadaUnaListaInexistente_SiQuieroVerElElementoQueHayEnUnaPosicion_MeDevuelveNull(){
  lista_t* lista_=NULL;
  void* estado= lista_elemento_en_posicion(lista_, 3);
  pa2m_afirmar(estado==NULL, "La lista no existe por lo tanto devuelve NULL ");
  lista_destruir(lista_);
  
}
void dadaUnaLista_SiQuieroVerCuantosElementosHay_MeDevuelveLaCantidad(){
  lista_t* lista_= lista_crear();
  int estado_insercion= lista_insertar(lista_, (void*)1);
  pa2m_afirmar(estado_insercion==0 && lista_elementos(lista_), "Si tengo una lista con 1 elemento me devuelve que la cantidad es 1");
  
  estado_insercion= lista_insertar(lista_, (void*)2);
  pa2m_afirmar(estado_insercion==0 && lista_elementos(lista_)==2, "Si tengo una lista de 2 elementos me devuelve que la cantidad es 2");
  
  estado_insercion= lista_insertar(lista_, (void*)3);
  pa2m_afirmar(estado_insercion==0 && lista_elementos(lista_)==3, "Si tengo una lista de 3 elementos me devuelve que la cantidad es 3");
  
  estado_insercion= lista_insertar(lista_, (void*)4);
  pa2m_afirmar(estado_insercion==0 && lista_elementos(lista_)==4, "Si tengo una lista de 4 elementos me devuelve que la cantidad es 4");
  
  estado_insercion= lista_insertar(lista_, (void*)5);
  pa2m_afirmar(estado_insercion==0 && lista_elementos(lista_)==5, "Si tengo una lista de 5 elementos me devuelve que la cantidad es 5");
  lista_destruir(lista_);
}
void dadaUnaLista_SiQuieroVerSiEstaVAcia_MeDevuelveQueNoEstaVaciaSiTieneElementos(){
  lista_t* lista_= lista_crear();
  pa2m_afirmar(lista_vacia(lista_),"La lista existe pero esta vacia porque no se le han incertado elementos");
  int estado_insercion= lista_insertar(lista_, (void*)1);
  pa2m_afirmar( estado_insercion==0 &&!lista_vacia(lista_),"La lista existe y no esta vacia  porque  se le ha incertado 1 elemento");

  estado_insercion= lista_insertar(lista_, (void*)2);
  pa2m_afirmar( estado_insercion==0 &&!lista_vacia(lista_),"La lista existe y no esta vacia  porque  se le ha incertado 2 elementos");

  estado_insercion= lista_insertar(lista_, (void*)3);
  pa2m_afirmar( estado_insercion==0 &&!lista_vacia(lista_),"La lista existe y no esta vacia  porque  se le ha incertado 3 elementos");  

  estado_insercion= lista_insertar(lista_, (void*)4);
  pa2m_afirmar( estado_insercion==0 &&!lista_vacia(lista_),"La lista existe y no esta vacia  porque  se le ha incertado 4 elementos");

  estado_insercion= lista_insertar(lista_, (void*)5);
  pa2m_afirmar( estado_insercion==0 &&!lista_vacia(lista_),"La lista existe y no esta vacia  porque  se le ha incertado 5 elementos");
  lista_destruir(lista_);

}
void dadaUnaLIsta_SiQuieroVerELElementoQueHayEnUnaPosicionSiEStaNoExiste_MeDevuelveNull(){
  lista_t* lista_= lista_crear();
  void* estado=lista_elemento_en_posicion(lista_,3);
  pa2m_afirmar(estado==NULL, "La lista existe pero no tiene elementos en la posicion solicitada");

  int estado_insercion= lista_insertar(lista_, (void*)1);
  estado= lista_elemento_en_posicion(lista_, 0);
  pa2m_afirmar(estado_insercion==0 && estado!= NULL, "La lista existe y tiene elementos en la posicion solicitada");  
  lista_destruir(lista_);

}
void dadUnaLista_SiQuieroVerElUltimoELemento_MeDevuelveELUltimoElemento(){
  lista_t* lista_= lista_crear();
  int estado_insercion= lista_insertar(lista_, (void*)1);
  pa2m_afirmar(estado_insercion==0 && lista_elementos(lista_)==1 &&lista_ultimo(lista_)==(void*)1,"En una lista de 1 elemento me devuelve el elemento");

  estado_insercion= lista_insertar(lista_, (void*)2);
  pa2m_afirmar(estado_insercion==0 && lista_elementos(lista_)==2 &&lista_ultimo(lista_)==(void*)2,"En una lista de 2 elementos me devuelve el elemento ultimo");

  estado_insercion= lista_insertar(lista_, (void*)3);
  pa2m_afirmar(estado_insercion==0 && lista_elementos(lista_)==3 &&lista_ultimo(lista_)==(void*)3,"En una lista de 3 elementos me devuelve el elemento ultimo");

  estado_insercion= lista_insertar(lista_, (void*)4);
  pa2m_afirmar(estado_insercion==0 && lista_elementos(lista_)==4 &&lista_ultimo(lista_)==(void*)4,"En una lista de 4 elementos me devuelve el elemento ultimo");

  estado_insercion= lista_insertar(lista_, (void*)5);
  pa2m_afirmar(estado_insercion==0 && lista_elementos(lista_)==5 &&lista_ultimo(lista_)==(void*)5,"En una lista de 5 elementos me devuelve el elemento ultimo");
  lista_destruir(lista_);
}
void dadaUnaListaInexistente_SiQuieroApilarUnElemento_NoPuedoApilarlo(){
  lista_t* lista_= NULL;
  int estado_apilamiento= lista_apilar(lista_, (void*)1);
  pa2m_afirmar(estado_apilamiento==-1, "La lista no existe por lo tanto no se pueden apilar elementos");
  lista_destruir(lista_);
}
void dadaUnaLista_SiQuieroApilarElementos_SeAgrandaLaLista(){
  lista_t* lista_= lista_crear();
  int estado_encolar= lista_apilar(lista_, (void*)1);
  pa2m_afirmar(estado_encolar==0 && lista_elementos(lista_)==1, "La lista existe por lo tanto se puede encolar un elemento");
  pa2m_afirmar( lista_ultimo(lista_)== (void*)1, "El elemento apilado se ha apilado al final ");
  
  estado_encolar= lista_apilar(lista_, (void*)2);
  pa2m_afirmar(estado_encolar==0 && lista_elementos(lista_)==2, "Se pueden apilar dos elementos ");

  estado_encolar= lista_apilar(lista_, (void*)3);
  pa2m_afirmar(estado_encolar==0 && lista_elementos(lista_)==3, "Se pueden apilar tres elementos ");

  estado_encolar= lista_apilar(lista_, (void*)4);
  pa2m_afirmar(estado_encolar==0 && lista_elementos(lista_)==4, "Se pueden apilar cuatro elementos ");

  estado_encolar= lista_apilar(lista_, (void*)5);
  pa2m_afirmar(estado_encolar==0 && lista_elementos(lista_)==5, "Se pueden apilar cinco elementos ");

  lista_destruir(lista_);
}
void dadaUnaListaInexistente_SiQuieroDesapilarUnElemento_NoPuedoDesapilarlo(){
  lista_t* lista_= NULL;
  int estado_desapilamiento= lista_desapilar(lista_);
  pa2m_afirmar(estado_desapilamiento==-1, "La lista no existe por lo tanto no se puede desapilar un elemento");
  lista_destruir(lista_);

}
void dadaUnaLIsta_SiQuieroDesapilar_MientrasHallanElementosPuedoHacerlo(){
  lista_t* lista_= lista_crear();
  int estado_desapilamiento= lista_desapilar(lista_);
  pa2m_afirmar(estado_desapilamiento==-1, "La lista existe pero no se pueden desapilar elementos ya que no se han apilado elementos");

  int estado_insercion= lista_apilar(lista_, (void*)1);
  estado_desapilamiento= lista_desapilar(lista_);
  pa2m_afirmar(estado_insercion==0 && estado_desapilamiento==0 && lista_elementos(lista_)==0, "La lista existe y al tener 1 elemento se lo puede desapilar");

  estado_insercion= lista_apilar(lista_, (void*)1);
  estado_insercion= lista_apilar(lista_, (void*)2);
  estado_desapilamiento= lista_desapilar(lista_);
  pa2m_afirmar(estado_insercion==0 && estado_desapilamiento==0 && lista_elementos(lista_)==1, "La lista existe y al tener 2 elementos se  puede desapilar 1 elemento");
  
  estado_insercion= lista_apilar(lista_, (void*)2);
  estado_insercion= lista_apilar(lista_, (void*)3);
  estado_desapilamiento= lista_desapilar(lista_);
  pa2m_afirmar(estado_insercion==0 && estado_desapilamiento==0 && lista_elementos(lista_)==2, "La lista existe y al tener 3 elementos se  puede desapilar 1 elemento");

  estado_insercion= lista_apilar(lista_, (void*)3);
  estado_insercion= lista_apilar(lista_, (void*)4);
  estado_desapilamiento= lista_desapilar(lista_);
  pa2m_afirmar(estado_insercion==0 && estado_desapilamiento==0 && lista_elementos(lista_)==3, "La lista existe y al tener 4 elementos se  puede desapilar 1 elemento");
  
  estado_insercion= lista_apilar(lista_, (void*)4);
  estado_insercion= lista_apilar(lista_, (void*)5);
  estado_desapilamiento= lista_desapilar(lista_);
  pa2m_afirmar(estado_insercion==0 && estado_desapilamiento==0 && lista_elementos(lista_)==4, "La lista existe y al tener 5 elementos se  puede desapilar 1 elemento");
  lista_destruir(lista_);
}
void dadaUnaListaVacia_SiQuieroVerElTope_MeDevuelveNULL(){
  lista_t* lista_=lista_crear();
  pa2m_afirmar(lista_tope(lista_)==NULL, "La lista esta vacia por lo tanto me devulve NUll");
  lista_destruir(lista_);
}
void dadaUnaLista_SiQuieroVerELTope_MeDevuelveElTope(){
  lista_t* lista_= lista_crear();
  int estado_insercion= lista_apilar(lista_, (void*)1);
  pa2m_afirmar(estado_insercion==0 && lista_tope(lista_)==(void*)1,"En una lista de 1 elemento me devuelve que  el tope es 1 ");

  estado_insercion= lista_apilar(lista_, (void*)2);
  pa2m_afirmar(estado_insercion==0 && lista_tope(lista_)==(void*)2,"En una lista de 2 elementos me devuelve que el tope es 2");

  estado_insercion= lista_apilar(lista_, (void*)3);
  pa2m_afirmar(estado_insercion==0 && lista_tope(lista_)==(void*)3,"En una lista de 3 elementos me devuelve que el tope es 3");

  estado_insercion= lista_apilar(lista_, (void*)4);
  pa2m_afirmar(estado_insercion==0 && lista_tope(lista_)==(void*)4,"En una lista de 4 elementos me devuelve que el tope es 4");

  estado_insercion= lista_apilar(lista_, (void*)5);
  pa2m_afirmar(estado_insercion==0 && lista_tope(lista_)==(void*)5,"En una lista de 5 elementos me devuelve que el tope es 5");
  lista_destruir(lista_);
}
void dadaUnaListaInexistente_SiQuieroEncolarUnElemento_NoPuedoHacerlo(){
  lista_t* lista_= NULL;
  int estado_encolar= lista_encolar(lista_, (void*)1);
  pa2m_afirmar(estado_encolar==-1, "La lista es inexistente por lo tanto no se puede encolar un elemento");
  lista_destruir(lista_);
}
void dadUnaLIsta_SiQUieroEncolarElementos_PuedoHacerlo(){
  lista_t* lista_= lista_crear();
  int estado_apilamiento= lista_encolar(lista_, (void*)1);
  pa2m_afirmar(estado_apilamiento==0 && lista_elementos(lista_)==1, "La lista existe por lo tanto se puede apilar un elemento");
  pa2m_afirmar( lista_ultimo(lista_)== (void*)1, "El elemento se puede encolar al final ");
  
  estado_apilamiento= lista_encolar(lista_, (void*)2);
  pa2m_afirmar(estado_apilamiento==0 && lista_elementos(lista_)==2, "Se pueden encolar dos elementos ");

  estado_apilamiento= lista_encolar(lista_, (void*)3);
  pa2m_afirmar(estado_apilamiento==0 && lista_elementos(lista_)==3, "Se pueden encolar tres elementos ");

  estado_apilamiento= lista_encolar(lista_, (void*)4);
  pa2m_afirmar(estado_apilamiento==0 && lista_elementos(lista_)==4, "Se pueden encolar cuatro elementos ");

  estado_apilamiento= lista_encolar(lista_, (void*)5);
  pa2m_afirmar(estado_apilamiento==0 && lista_elementos(lista_)==5, "Se pueden encolar cinco elementos ");

  lista_destruir(lista_);
}
void dadaUnaLIstaInexistente_SiQuieroDesencolarElementos_NoPuedoHacerlo(){
  lista_t* lista_= NULL;
  int estado_desencolar= lista_desencolar(lista_);
  pa2m_afirmar(estado_desencolar==-1, "La lista es inexistente por lo tanto no puedo desencolar elementos");
  lista_destruir(lista_);
}
void dadaUnaLista_SiQuieroDesencolarElementos_PuedoHacerlo(){
  lista_t* lista_ = lista_crear();
  int estado_desencolar= lista_desencolar(lista_);
  pa2m_afirmar(estado_desencolar==-1, "La lista existe pero no se pueden desencolar elementos ya que no se han encolado elementos");

  int estado_insercion= lista_encolar(lista_, (void*)1);
  estado_desencolar= lista_desencolar(lista_);
  pa2m_afirmar(estado_insercion==0 && estado_desencolar==0 && lista_elementos(lista_)==0, "La lista existe y al tener 1 elemento se lo puede desencolar");

  estado_insercion= lista_encolar(lista_, (void*)1);
  estado_insercion= lista_encolar(lista_, (void*)2);
  estado_desencolar= lista_desencolar(lista_);
  pa2m_afirmar(estado_insercion==0 && estado_desencolar==0 && lista_elementos(lista_)==1, "La lista existe y al tener 2 elementos se  puede desencolar 1 elemento");
  
  estado_insercion= lista_encolar(lista_, (void*)2);
  estado_insercion= lista_encolar(lista_, (void*)3);
  estado_desencolar= lista_desencolar(lista_);
  pa2m_afirmar(estado_insercion==0 && estado_desencolar==0 && lista_elementos(lista_)==2, "La lista existe y al tener 3 elementos se  puede desencolar 1 elemento");

  estado_insercion= lista_encolar(lista_, (void*)3);
  estado_insercion= lista_encolar(lista_, (void*)4);
  estado_desencolar= lista_desencolar(lista_);
  pa2m_afirmar(estado_insercion==0 && estado_desencolar==0 && lista_elementos(lista_)==3, "La lista existe y al tener 4 elementos se  puede desencolar 1 elemento");
  
  estado_insercion= lista_encolar(lista_, (void*)4);
  estado_insercion= lista_encolar(lista_, (void*)5);
  estado_desencolar= lista_desencolar(lista_);
  pa2m_afirmar(estado_insercion==0 && estado_desencolar==0 && lista_elementos(lista_)==4, "La lista existe y al tener 5 elementos se  puede desencolar 1 elemento");

  lista_destruir(lista_);
}
void dadaUnaLista_SiQuieroVerElPrimerElemento_SiempreQueHayanElemetosMeDevolveraElPrimerELemento(){
  lista_t* lista_=lista_crear();
  
  pa2m_afirmar(lista_primero(lista_)==NULL, "La lista existe pero al no tener elementos devuelve NULL");
  int estado_encolar= lista_encolar(lista_, (void*)1);
  pa2m_afirmar(estado_encolar==0 && lista_primero(lista_)==(void*)1, "El primer elemento es 1");
  lista_desencolar(lista_);
  estado_encolar= lista_encolar(lista_, (void*)2);
  pa2m_afirmar(estado_encolar==0 && lista_primero(lista_)==(void*)2, "El primer elemento es 2");
  lista_desencolar(lista_);
  estado_encolar= lista_encolar(lista_, (void*)3);
  pa2m_afirmar(estado_encolar==0 && lista_primero(lista_)==(void*)3, "El primer elemento es 3");
  lista_desencolar(lista_);
  estado_encolar= lista_encolar(lista_, (void*)4);
  pa2m_afirmar(estado_encolar==0 && lista_primero(lista_)==(void*)4, "El primer elemento es 4");
  lista_desencolar(lista_);
  estado_encolar= lista_encolar(lista_, (void*)5);
  pa2m_afirmar(estado_encolar==0 && lista_primero(lista_)==(void*)5, "El primer elemento es 5");
  lista_destruir(lista_);
}
bool funcion_de_prueba(void* lista,void* frase){
  return frase;
}
void dadaUnaLista_AlCrearUnIteradorInterno_SeCreaElIterador(){
  lista_t* lista_= lista_crear();
  char* frase="hola";
  lista_insertar(lista_, frase);
  lista_con_cada_elemento(lista_,funcion_de_prueba , frase);
  char* frase_devuelta= (char*)lista_ultimo(lista_);
  pa2m_afirmar(strcmp(frase_devuelta,frase)==0, "La frase insertada no se modifica");
  pa2m_afirmar(lista_con_cada_elemento(lista_,funcion_de_prueba,frase)==1, "Se itera sobre 1 elemento");
  pa2m_afirmar(lista_elemento_en_posicion(lista_, 0)==(void*)"hola", "El elemento iterado es el esperado");
  lista_borrar(lista_);
  pa2m_afirmar(lista_con_cada_elemento(lista_,funcion_de_prueba,frase)==0, "Al no haber elementos  devuelve 0 iteraciones ");
  
  frase= "como";
  lista_insertar(lista_, frase);
  pa2m_afirmar(lista_con_cada_elemento(lista_,funcion_de_prueba,frase)==1, "Se itera sobre 1 elemento ");
  pa2m_afirmar(lista_elemento_en_posicion(lista_, 0)==(void*)"como", "El elemento iterado en la posicion 0 es el esperado");
  frase="estas";
  lista_insertar(lista_, frase);
  pa2m_afirmar(lista_con_cada_elemento(lista_,funcion_de_prueba,frase)==2, "Se itera sobre 2 elementos ");
  pa2m_afirmar(lista_elemento_en_posicion(lista_, 1)==(void*)"estas", "El elemento iterado en la posicion 1 es el esperado");
  frase="yo";
  lista_insertar(lista_, frase);
  pa2m_afirmar(lista_con_cada_elemento(lista_,funcion_de_prueba,frase)==3, "Se itera sobre 3 elementos ");
  pa2m_afirmar(lista_elemento_en_posicion(lista_, 2)==(void*)"yo", "El elemento iterado en la posicion 2 es el esperado");
  frase="bien";
  lista_insertar(lista_, frase);
  pa2m_afirmar(lista_con_cada_elemento(lista_,funcion_de_prueba,frase)==4, "Se itera sobre 4 elementos ");
  pa2m_afirmar(lista_elemento_en_posicion(lista_, 3)==(void*)"bien", "El elemento iterado en la posicion 3 es el esperado");
  lista_borrar(lista_);
  lista_borrar(lista_);
  lista_borrar(lista_);
  lista_borrar(lista_);
  pa2m_afirmar(lista_con_cada_elemento(lista_,funcion_de_prueba,frase)==0, "Al no haber elementos  devuelve 0 iteraciones ");
  
  lista_destruir(lista_);
}

int main() {
  pa2m_nuevo_grupo("Pruebas LISTA:");
 
  pa2m_nuevo_grupo("Pruebas de insertar: ");
  dadaunalistainexistente_siinsertounelemento_nologroinsertarnada();
  dadaUnaLista_SiInsertoElementos_SeAgrandaLaLista();

  pa2m_nuevo_grupo("Pruebas de insertar en una posicion: ");
  dadaunalistainexistente_siinsertounelementoEnUnaPosicionEspecifica_nologroConcretarLaInsercion();
  dadaUnaLista_SiInsertoUnElementoEnUnaPosicionEspecifica_ElElementoSeInsertaEnLaPosicionEsperada();
  dadaUnaLista_SiInsertoUnElementoEnUnaPosicionQueNoExiste_ElElementoSeInsertaAlFinal();

  pa2m_nuevo_grupo("Pruebas de borrar: ");
  dadaUnaListaInexistente_SiBorroUnElemento_ElElementoNoSeBorra();
  dadaUnaLista_SiBorroUnElemento_ElElementoSeBorra();

  pa2m_nuevo_grupo("Pruebas de borrar en una posicion: ");
  dadaUnaListaInexistente_SiIntentoBorrarUnElementoDeUnaPosicionEspecifica_NoPuedoConcretarLaEliminacion();
  dadaUnaLista_SiBorroUnElementoEnUnaPosicionEspecifica_SeBorraElElemento();

  pa2m_nuevo_grupo("Pruebas de lista elemento en posicion: ");
  dadaUnaListaInexistente_SiQuieroVerElElementoQueHayEnUnaPosicion_MeDevuelveNull();
  dadaUnaLIsta_SiQuieroVerELElementoQueHayEnUnaPosicionSiEStaNoExiste_MeDevuelveNull();

  pa2m_nuevo_grupo("Pruebas de lista ultimo: ");
  dadaUnaListaInexistente_SiQuieroVerElUltimoElemento_MeDevueleveNUll();
  dadUnaLista_SiQuieroVerElUltimoELemento_MeDevuelveELUltimoElemento();

  pa2m_nuevo_grupo("Pruebas de lista vacia: ");
  dadaUnaListaInexistente_AlVerSiLaListaEstaVacia_VemosQueSiLoEsta();
  dadaUnaLista_SiQuieroVerSiEstaVAcia_MeDevuelveQueNoEstaVaciaSiTieneElementos();

  pa2m_nuevo_grupo("Pruebas de lista elementos: ");
  dadaUnaListaInexistente_SiQuieroVerLaCantidadDeElementosQueTiene_MeDevuelveQueNoTieneElementos();
  dadaUnaLista_SiQuieroVerCuantosElementosHay_MeDevuelveLaCantidad(); 

  pa2m_nuevo_grupo("Pruebas del Iterador externo: ");
  dadaUnaListaInexistente_AlCrearUnIterador_ResultaEnUnIteradorNull();
  dadaUnaLista_AlCrearUnIterador_ResultaEnUnIteradorNoNulo();
  dadaUnaLista_AlCrearUnIterador_PrueboElIterador();

  pa2m_nuevo_grupo("Pruebas del Iterador interno: ");
  dadaUnaLista_AlCrearUnIteradorInterno_SeCreaElIterador();

  pa2m_nuevo_grupo("Pruebas de apilar: "); 
  dadaUnaListaInexistente_SiQuieroApilarUnElemento_NoPuedoApilarlo();
  dadaUnaLista_SiQuieroApilarElementos_SeAgrandaLaLista();

  pa2m_nuevo_grupo("Pruebas de desapilar: ");
  dadaUnaListaInexistente_SiQuieroDesapilarUnElemento_NoPuedoDesapilarlo();
  dadaUnaLIsta_SiQuieroDesapilar_MientrasHallanElementosPuedoHacerlo();

  pa2m_nuevo_grupo("Pruebas de tope: ");
  dadaUnaListaVacia_SiQuieroVerElTope_MeDevuelveNULL();
  dadaUnaLista_SiQuieroVerELTope_MeDevuelveElTope();

  pa2m_nuevo_grupo("Pruebas de encolar: ");
  dadaUnaListaInexistente_SiQuieroEncolarUnElemento_NoPuedoHacerlo();
  dadUnaLIsta_SiQUieroEncolarElementos_PuedoHacerlo();

  pa2m_nuevo_grupo("Pruebas de desencolar: ");
  dadaUnaLIstaInexistente_SiQuieroDesencolarElementos_NoPuedoHacerlo();
  dadaUnaLista_SiQuieroDesencolarElementos_PuedoHacerlo();

  pa2m_nuevo_grupo("Pruebas de primero: ");
  dadaUnaLista_SiQuieroVerElPrimerElemento_SiempreQueHayanElemetosMeDevolveraElPrimerELemento();

  return pa2m_mostrar_reporte();
}
