int get_lenth(FILE *p){
	long size;
	int num;
	fseek(p,0,SEEK_END);
	size=ftell(p);
	num=size/sizeof(struct person);
	return num;
}
int print(struct person x){
	if(strcmp(x.name,"\0")==0) return 0;
	printf("\n������%s\n",x.name);
	printf("�Ա�%s\n",x.sex);
	printf("���䣺%d\n",x.age);
	printf("��ϵ��ʽ��%s\n",x.num);
	printf("�������䣺%s\n\n",x.e_mail);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 

}
void show_all(){
	int i,num;
	FILE *fp=fopen("ͨѶ¼.txt","rt");
	if(fp==NULL){
		printf("��ȡͨѶ¼ʧ��,�Ƿ�δ�������Ϣ?");
	}
	else{
		struct person *p;
		num=get_lenth(fp);
		p=(struct person *)malloc(sizeof(struct person)*num);
		fseek(fp,0,SEEK_SET);
		for(i=0;i<num;i++){
			fread(&p[i],sizeof(struct person),1,fp);
			printf("���:%d\n",i); 
			print(p[i]);
			
		}
		fclose(fp);
	}
}
