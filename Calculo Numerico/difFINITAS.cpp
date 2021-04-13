#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;

#define MAX 1123

typedef struct { double x, y; }ponto;
typedef vector<double>vd;
typedef unsigned long long ull;

ull fat(int n) { return (n == 0) ? 1 : n * fat(n - 1); }

void calcula_difs_fin(int n, vector<vd> &difs, ponto p[]) {
  int i, j; double newdif;
  for (i = 0; i < n; i++)
    difs[i].push_back(p[i].y);
  for (i = 1; i < n; i++)
    for (j = 0; j < n - i; j++) {
      newdif = difs[j + 1][i - 1] - difs[j][i - 1];
      difs[j].push_back(newdif);
    }}

int main(void) {
  int n, i, j; ponto p[MAX];
  double ip, resp, ac, z;
   printf("Informe o numero de pontos: ");
  scanf("%d", &n);
  vector<vd>diffin(n);
   printf("Informe os pontos:\n");
  for (i = 0; i < n; i++) {
    printf("Ponto %d: ", i);
    scanf("%lf %lf", &p[i].x, &p[i].y);
  }
  printf("Informe o valor a interpolar: ");
  scanf("%lf", &ip);
  z = (ip - p[0].x) / (fabs(p[1].x - p[0].x));
  calcula_difs_fin(n, diffin, p); resp = p[0].y;
  for (i = 1; i < n; i++) {
    ac = diffin[0][i] / fat(i);
    for (j = 0; j < i; j++)
      ac *= (z - j);
    resp += ac;
  }
  printf("Finita: %.6lf\n", resp);
  return 0;
}
