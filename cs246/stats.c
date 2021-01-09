// File: stats.c
// Date: March 20, 2018
// Author: Adam Abad

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void read_doubles(int n, double a[n]) {
  for(int i = 0; i < n; i++)
    scanf("%lf", &a[i]);
}

void max_min(int n, double a[n], double *max, double *min) {
  *max = a[0];
  *min = a[0];
  for(int i = 1; i < n; i++) {
    if(a[i] > *max)
      *max = a[i];
    if(a[i] < *min)
      *min = a[i];
  }  
}

double sum(int n, double a[n]) {
  double total = 0;
  for(int i = 0; i < n; i++) {
    total += a[i];
  }
  return total;
}

double mean(int n, double a[n]) {
  return sum(n,a) / n;
}

int compare(const void *x, const void *y) {
  double xx = * (double *) x;
  double yy = * (double *) y;
  if (xx < yy) return -1;
  else if (xx > yy) return 1;
  else return 0;
}

double median(int n, double a[n]) {
  qsort(a, n, sizeof(double), compare);
  if(n%2 == 0)
    return (a[n / 2] + a[n / 2 - 1]) / 2;
  else
    return (a[n / 2]);
}

double variance(int n, double a[n]) {
  double total = 0;
  double m = mean(n, a);
  for(int i = 0; i < n; i++) {
    double num = pow((a[i] - m), 2);
    total += num;
  }
  return total / n;
}

double stddev(int n, double a[n]) {
  return pow(variance(n,a),.5);
}

int main() {

  int n;
  scanf("%d", &n);
  
  double a[n];
  double max;
  double min;
  double total;
  double med;
  double var;
  double m;
  double dev;
  
  read_doubles(n, a);
  max_min(n, a, &max, &min);

  total = sum(n, a);
  m = mean(n,a);
  med = median(n, a);
  var = variance(n, a);
  dev = stddev(n,a);
  
  printf("count: %33d\n", n);
  printf("min: %35.8f\n", min);
  printf("max: %35.8f\n", max);
  printf("sum: %35.8f\n", total);
  printf("median: %32.8f\n", med);
  printf("mean: %34.8f\n", m);
  printf("variance: %30.8f\n", var);
  printf("stddev: %32.8f\n", dev);
  
}
