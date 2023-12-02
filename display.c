#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "file.txt"

void displayDataFromFile() {
  FILE *file = fopen(FILENAME, "r");

  if (file == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  char line[256];
  while (fgets(line, sizeof(line), file) != NULL) {
    printf("%s", line);
  }

  fclose(file);
}

int main() {
  sem_t *semaphore;
  int sval;
  semaphore = sem_open("/semaphore", O_RDWR);

  if (semaphore == NULL) // SEM_FAILED == NULL
  {
    perror("sem_open fail\n");
    return -1;
  } else {
    printf("\n sem_open success");
  }
  sem_getvalue(semaphore, &sval);
  printf("\n semaphore val =(%d)\n", sval);
  sem_wait(semaphore);
  sem_getvalue(semaphore, &sval);
  printf("\n semaphore val =(%d) in section \n", sval);
  printf("Displaying data from file:\n");
  displayDataFromFile();
  sem_post(semaphore);

  return 0;
}
