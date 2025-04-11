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
  double * avg = malloc(nSets * sizeof(double));
  printf("Number of Sets: %d\n", nSets);
  int numStartEndPts = GetNumStartEndPts();
  int * arrNtps = malloc(nSets * sizeof(int));

  double * ptr = DataSet;
  double * ptrAvg = avg;
  int * ptrNtps = arrNtps;
  for ( int i = 0; i < nSets; i++, ptr++, ptrAvg++, ptrNtps++) {
    numsPts = GetNumPts();
    *ptrNtps = numsPts;
    ptr = CreateDataset(numsPts);
    *ptrAvg = Average(ptr, numsPts);
    //printf("%lf\n", Average(ptr, numsPts));
  }

  // depending on the size to show at the end and start, the output will be modified
  switch (numStartEndPts)
  {
    case 2:
      printf("%7s %8s %10s %20s %10s\n", "Set #", "Npts", "Average", "First_Data_Pts", "Last_Data_Pts_");
      break;
    case 3:
      printf("%7s %8s %10s %24s %10s\n", "Set #", "Npts", "Average", "____First_Data_Pts____", "____Last_Data_Pts____");
      break;
    case 4:
      printf("%7s %8s %10s %35s %30s\n", "Set #", "Npts", "Average", "_________First_Data_Pts_________", "_________Last_Data_Pts_________");
      break;
  }

  
  ptr = DataSet;
  ptrAvg = avg;
  ptrNtps = arrNtps;
  for (int i = 0; i < nSets; i++, ptrAvg++, ptrNtps++) {
    printf("%5d %10d %3s %2.4lf %3s", i, *ptrNtps, " ",*ptrAvg, " ");
      for (int k = 0; k < numStartEndPts; k++, ptr++) {
        printf("%3.4lf", *(ptr));
      }
      putchar('\n');
  }

/*
  int nPts = GetNumPts();
  printf("Number of Points: %d\n", nPts);
*/
  free(DataSet);
  free(avg);
  free(arrNtps);
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

