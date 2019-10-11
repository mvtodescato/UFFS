#include <stdio.h>
int area1(int x1, int y1,int x2,int y2,int x3, int y3){
	int area;
	area = ((x1*y2*1) + (y1* 1*x3) + (1*x2*y3) - ((y1*x2*1) + (x1*1*y3) + (1*y2*x3)));
	return abs(area);
}
int main(void){
	int x1,y1,x2,y2,x3,y3,area,i,j;
	//Fiz um quadrado de 40/40
	printf("Digite x1,y1,x2,y2,x3 e y3 respectivamente:\n");
	scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
	
	
	
	 area = ((x1*y2) + (y1* x3) + (x2*y3) - ((y1*x2) + (x1*y3) + (y2*x3)));
	 area = abs(area);
	 for(i=0;i<40;i++){
		 for(j=0;j<40;j++){
			if((area1(i,j,x2,y2,x3,y3) + area1(x1,y1,i,j,x3,y3) + area1(x1,y1,x2,y2,i,j)) <= area)
				 printf("@");
			else
				printf("#");
			 
		}
		printf("\n");
	}
	return 0;
}