#include<stdio.h>
#include<vector>
using namespace std;

#define MAX 1123

typedef struct { double x, y; }ponto;
typedef vector<double>vd;

void calcula_difs(int n, vector<vd> &difs, ponto p[]) {
  int i, j; double newdif;
  for (i = 0; i < n; i++)
    difs[i].push_back(p[i].y);
  for (i = 1; i < n; i++)
    for (j = 0; j < n - i; j++) {
      newdif = (difs[j + 1][i - 1] - difs[j][i - 1]) /
        (p[j + i].x - p[j].x);
      difs[j].push_back(newdif);
    }}

int main(void) {
  int n, i, j; ponto p[MAX];
  double ip, resp, ac;
   printf("Informe o numero de pontos: ");
  scanf("%d", &n);
  vector<vd>difdiv(n);
  printf("Informe os pontos:\n");
  for (i = 0; i < n; i++) {
    printf("Ponto %d: ", i);
    scanf("%lf %lf", &p[i].x, &p[i].y);
  }
   printf("Informe o valor a interpolar: ");
  scanf("%lf", &ip);
  calcula_difs(n, difdiv, p); resp = p[0].y;
  for (i = 1; i < n; i++) {
    ac = difdiv[0][i];
    for (j = 0; j < i; j++)
      ac *= (ip - p[j].x);
    resp += ac;
  }
  printf("Divididas: %.6lf\n", resp);
  return 0;
}
