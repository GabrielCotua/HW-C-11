// Gabriel Cotua HW 11

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function Declarations
int GetNumSets();
int GetNumStartEndPts();
int GetNumPts();
double * CreateDataset(int elemNum);
double Average();

// Running Function
int main(void) {
  srand(time(NULL));

  int sets = GetNumSets();
  printf("Number of Sets: %d\n", sets);

  double * DataSet[sets];

  int points = GetNumPts();
  printf("Number of Points: %d\n", points);



  free(DataSet);
  return 0;
}

// Function Definitions
int GetNumSets() {
  return rand() % 6 + 5;
}

int GetNumStartEndPts() {
  return rand() % 3 + 2;
} 

int GetNumPts() {
  return 1000 * (rand() % 8 + 4);
}

double * CreateDataset(int elemNum) {
  double * arr = malloc(elemNum * sizeof(double));

  if (arr == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }

  double * ptr = arr;

  for (int i = 0; i < elemNum-1; ++i, ++ptr) {

    *ptr = ((double)rand() / RAND_MAX) * 10.0;
    //  printf("%lf", *ptr);
  } 
  ++ptr;
  ptr = NULL;



  return arr;
}

//  using arr[i] {580, 564, 555}
//  using *ptr {535, 526, 543}