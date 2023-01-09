#include <stdio.h>
#include <stdlib.h>

/*
  Método que intercambia o contido de dous punteiros a int.
Parámetros de entrada:
 - p1: punteiro a int, recibido por REFERENCIA, é dicir, recibimos a dirección do punteiro. Vale, si, un punteiro é unha dirección, pois ben,
       nosoutros aquí recibimos a DIRECCIÓN do PUNTEIRO a int.
 - p2: idem.
*/
void swap(int **p1, int **p2)
{
  int *tmp = NULL;
  tmp = *p1; //o punteiro "tmp" vai apuntar á misma dirección de memoria que apunta o punteiro "p1"
  *p1 = *p2; //o punteiro "p1" vai apuntar á misma dirección de memoria que apunta o punteiro "p2"
  *p2 = tmp; //o punteiro "p2" vai apuntar á misma dirección de memoria que apunta o punteiro "tmp", que apunta
           //á misma dirección á que apuntaba o punteiro "p1" antes de machacalo.
//  printf("dentro: a = %d, b = %d\n", **a, **b);
}

int main(int argc, char *argv[])
{
  int *a = NULL; //definimos "a" como punteiro a int
  int *b = NULL; //definimos "b" como punteiro a int

//  printf("sizeof int = %lu\n", sizeof(int));
  a = (int *)malloc(1*sizeof(int)); //asigno memoria no punteiro "a" para meter 1 int
  b = (int *)malloc(1*sizeof(int)); //asigno memoria no punteiro "b" para meter 1 int

  *a = 3; //na "caixiña" á que apunta o punteiro "a" imos meter o valor 3
  *b = 5; //na "caixiña" á que apunta o punteiro "b" imos meter o valor 5

  printf("a = %d, b = %d\n", *a, *b); //pintamos o contido/caixiña do punteiro "a" e o punteiro "b"
  swap(&a,&b); //aquí está a chicha: pasamos POR REFERENCIA os punteiros á función que intercambia o contido dos punteiros.
/*
               Na vida en general e na linguaxe C en particular hai dous xeitos de pasarlle parámetros (variables) a unha función:
                    1) Por valor: pasamos o CONTIDO da variable, é dicir, pasamos unha COPIA. Dentro do método podes modificar o parámetro pero sólo estas modificando a copia, é dicir, 
                         sólo afecta ó ámbito do método invocado. Cando o fluxo de execución remate e volvas ó sitio onde chamache a ese método, nesa variable que lle enviache antes ó método vas ter 
                         o mismo valor que tiñas antes de chamar ó método.
                    2) Por referencia: pasamos a DIRECCIÓN da variable. Calquera modificación que faigas dos parámetro de entrada dentro do método vaise manter fóra do ámbito dese método.
*/
  printf("a = %d, b = %d\n", *a, *b);

  free(a); //libero a memoria asignada ó punteiro "a" para evitar memory leaks.
  free(b); //libero a memoria asignada ó punteiro "b" para evitar memory leaks.

  return 0;
}
