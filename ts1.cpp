#include<stdio.h>
struct gride{
	float g1;
	float g2;
	float g3;
	float g4;
	float aver;
};
void i(struct gride *x){
	scanf("%f%f%f%f%f",&x->g1,&x->g2,&x->g3,&x->g3,&x->aver);
}
int main(){
	struct gride g;
	i(&g);
	printf("%f\t%f\t%f\t%f\t%f",g.g1,g.g2,g.g3,g.g3,g.aver);
	

}
