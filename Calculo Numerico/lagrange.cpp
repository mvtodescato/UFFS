#include<stdio.h>

#define MAX 1123

typedef struct { double x, y; }ponto;

int main(void) {
  int n, i, j;
  double ip, resp, ac;
  ponto p[MAX];
    printf("Informe o numero de pontos: ");
  scanf("%d", &n);
   printf("Informe os pontos:\n");
  for (i = 0; i < n; i++) {
     printf("Ponto %d: ", i);
    scanf("%lf %lf", &p[i].x, &p[i].y);
  }
   printf("Informe o valor a interpolar: ");
  scanf("%lf", &ip);
  for (ac = 1, resp = i = 0; i < n; i++, ac = 1) {
    for (j = 0; j < n; j++)
      if (i != j) ac *= (ip - p[j].x) / (p[i].x - p[j].x);
    resp += ac * p[i].y;
  }
  printf("Lagrange: %.6lf\n", resp);
  return 0;
}
