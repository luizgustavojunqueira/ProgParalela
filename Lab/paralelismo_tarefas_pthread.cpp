#include <pthread.h>
#include <stdio.h>

#define n 1000000

void* soma_func(void* args){
  
  int v1[n], v2[n], v3[n];

  for(int i = 0; i < n; i++){
    printf("Thread 1 -> v1[%d]:%d, v2[%d]:%d\n", i, v1[i], i, v2[i]);
  } 

  for(int i = 0; i < n; i++){
    v3[i] = v1[i] + v2[i];
    v3[i] = v1[i] + v2[i];
    v3[i] = v1[i] + v2[i];
  }

  return NULL;
}

void* multiplicacao_func(void* args){
  
  int v1[n], v2[n], v3[n];

  for(int i = 0; i < n; i++){
    printf("Thread 2 -> v1[%d]:%d, v2[%d]:%d\n", i, v1[i], i, v2[i]);
  }

  for(int i = 0; i < n; i++){
    v3[i] = v1[i] * v2[i];
    v3[i] = v1[i] * v2[i];
    v3[i] = v1[i] * v2[i];
  }

  return NULL;
}

int main(int argc, char** argv){

  pthread_t soma, multiplicacao;

  pthread_create(&soma, NULL, soma_func, NULL);
  pthread_create(&multiplicacao, NULL, multiplicacao_func, NULL);

  pthread_exit(NULL);
}
