// Gabriel Cotua HW 11

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
  printf("\n\n|#####################|\n|HW #11, Gabriel Cotua|\n|#####################|\n\n");

  int nSets = GetNumSets();
  int numStartEndPts = GetNumStartEndPts();

  double **DataSet = malloc(nSets * sizeof(double*));  // array of double arrays
  double *avg = malloc(nSets * sizeof(double));
  int *arrNtps = malloc(nSets * sizeof(int));

  if (!DataSet || !avg || !arrNtps) {
    printf("Memory allocation failed.\n");
    exit(1);
  }

  printf("Number of Sets: %d\n", nSets);

  // Fill datasets
  for (int i = 0; i < nSets; i++) {
    int numsPts = GetNumPts();
    arrNtps[i] = numsPts;
    DataSet[i] = CreateDataset(numsPts);
    avg[i] = Average(DataSet[i], numsPts);
  }

  // Header depending on numStartEndPts
  switch (numStartEndPts) {
    case 2:
      printf("%7s %8s %10s %17s %16s\n", "Set #", "Npts", "Average", "First_Data_Pts", "Last_Data_Pts_");
      break;
    case 3:
      printf("%7s %8s %10s %24s %22s\n", "Set #", "Npts", "Average", "____First_Data_Pts____", "____Last_Data_Pts_____");
      break;
    case 4:
      printf("%7s %8s %10s %35s %30s\n", "Set #", "Npts", "Average", "_________First_Data_Pts________", "_________Last_Data_Pts_________");
      break;
  }

  // Print Data Summary
  for (int i = 0; i < nSets; i++) {
    printf("%5d %10d    %2.4lf    ", i, arrNtps[i], avg[i]);

    // First Data Points
    for (int j = 0; j < numStartEndPts; j++) {
      printf("%7.4lf ", DataSet[i][j]);
    }
    //printf("%4s", ' ');
    // Last Data Points
    for (int j = arrNtps[i] - numStartEndPts; j < arrNtps[i]; j++) {
      printf("%7.4lf ", DataSet[i][j]);
    }

    putchar('\n');
  }

  // Free memory
  for (int i = 0; i < nSets; i++) {
    free(DataSet[i]);
  }

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
  double *arr = malloc(elemNum * sizeof(double));
  if (!arr) {
    printf("Memory allocation failed.\n");
    exit(1);
  }

  for (int i = 0; i < elemNum; i++) {
    arr[i] = ((double)rand() / RAND_MAX) * 10.0;
  }

  return arr;
}

double Average(double arr[], int elemNum) {
  double totalSum = 0;
  for (int i = 0; i < elemNum; i++) {
    totalSum += arr[i];
  }
  return totalSum / elemNum;
}
