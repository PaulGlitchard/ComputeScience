#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <map>

volatile size_t counter = 0;
ssize_t array[16];
ssize_t empty_elements_in_array = 16;
ssize_t full_elements_in_array = 0;
size_t run = 1;

void producer(size_t x)
{
  for (size_t i = 0; i < 100000ULL; ++i)
  {
    while (1)
    {
      for (size_t j = 0; j < 16; ++j)
      {
        if (array[j] == -1)
        {
          array[j] = x;
          usleep(1);
          empty_elements_in_array--;
          full_elements_in_array++;
          goto next_one;
        }
      }
    }
    next_one: ;
  }
}

void consumer(size_t x)
{
  while (run || full_elements_in_array > 0)
  {
    for (size_t i = 0; i < 16; ++i)
    {
      if (array[i] != -1)
      {
        counter += array[i];
        array[i] = -1;
        empty_elements_in_array++;
        full_elements_in_array--;
      }
    }
  }
}

int main()
{
  memset(array,-1,16*sizeof(ssize_t));
  pthread_t producers[10];
  for (size_t i = 0; i < 3; ++i)
    pthread_create(producers+i,0,(void*(*)(void*))&producer,(void *)1);
  pthread_t consumers[10];
  for (size_t i = 0; i < 3; ++i)
    pthread_create(consumers+i,0,(void*(*)(void*))&consumer,(void *)1);
  for (size_t i = 0; i < 3; ++i)
    pthread_join(producers[i],0);
  printf("all producers are done\n");
  run = 0;
  for (size_t i = 0; i < 3; ++i)
    pthread_join(consumers[i],0);
  printf("counter = %zu\n", counter);
  return 0;
}