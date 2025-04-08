// Gabriel Cotua HW 11


// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function Declarations
int GetNumSets();
int GetNumStartEndPts();
int GetNumPts();
double * CreateDataset(int elemNum);
double Average(double arr[], int elemNum);

// Running Function
int main(void) {
  srand(time(NULL));

  int numsPts = 0;
  int nSets = GetNumSets();
  double * DataSet = malloc(nSets * sizeof(double*)); // creates a array of pointers ( will be used to host more arrays )

  printf("Number of Sets: %d\n", nSets);

  double * ptr = DataSet;
  for ( int i = 0; i < nSets; i++, ptr++) {
    numsPts = GetNumPts();
    ptr = CreateDataset(numsPts);
    printf("%lf\n", Average(ptr, numsPts));
  }

/*
  int nPts = GetNumPts();
  printf("Number of Points: %d\n", nPts);
*/
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

  for (int i = 0; i < elemNum - 1; i++, ptr++) {
      *ptr = ((double)rand() / RAND_MAX) * 10.0;
  }

  *ptr = -1.0;  // Setting last item as 'NULL' this will be our flag
                // This value was the chosen one since there is no way
                // of getting a negative number.
   // printf("\nlocation [%p] = %d\n", ptr, arr[elemNum-1] == -1.0);

  return arr;
}

double Average(double arr[], int elemNum) {
  double totalSum = 0;

  double * ptr = arr;
  for (int i  = 0; i < elemNum; i++, ptr++) {
    totalSum += *ptr;
  }

  return totalSum / elemNum;
}

