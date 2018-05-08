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
	printf("\n姓名：%s\n",x.name);
	printf("性别：%s\n",x.sex);
	printf("年龄：%d\n",x.age);
	printf("联系方式：%s\n",x.num);
	printf("电子邮箱：%s\n\n",x.e_mail);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 

}
void show_all(){
	int i,num;
	FILE *fp=fopen("通讯录.txt","rt");
	if(fp==NULL){
		printf("读取通讯录失败,是否还未输入过信息?");
	}
	else{
		struct person *p;
		num=get_lenth(fp);
		p=(struct person *)malloc(sizeof(struct person)*num);
		fseek(fp,0,SEEK_SET);
		for(i=0;i<num;i++){
			fread(&p[i],sizeof(struct person),1,fp);
			printf("序号:%d\n",i); 
			print(p[i]);
			
		}
		fclose(fp);
	}
}
