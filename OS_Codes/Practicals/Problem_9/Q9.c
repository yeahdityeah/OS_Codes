#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>


#define NUM_THREADS 5

void *PrintHello(void *threadid) {
   long tid;
   tid = (long)threadid;
   printf("Hello World! Thread ID, %ld\n", tid);
   pthread_exit(NULL);
}

int main () {
   printf("Considering 5 threads\n");
   pthread_t threads[NUM_THREADS];
   int rc;
   int i;
   for( i = 0; i < NUM_THREADS; i++ ) {
      printf("main() : creating thread, %d\n", i);
      rc = pthread_create(&threads[i], NULL, PrintHello,(void * restrict)i);
      if (rc) {
         printf("Error:unable to create thread, %d\n", rc);
         exit(-1);
      }
   }
   pthread_exit(NULL);
}
