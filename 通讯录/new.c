void scan(struct person *x){
		printf("������������");
		scanf("%s",x->name);

get_sex:	printf("�������Ա�man/women����");
		scanf("%s",x->sex);
		if(strcmp(x->sex,"man")&&strcmp(x->sex,"woman")){
			printf("��������ȷ���Ա�\n");
			goto get_sex;
		}
		
		printf("���������䣺");
		scanf("%d",&x->age);
		printf("������绰���룺");
		scanf("%s",x->num);
		printf("����������ʼ���ַ��");
		scanf("%s",x->e_mail);
}
void add(){
	char ch;
	FILE *fp=fopen("ͨѶ¼.txt","at+");
	if(fp==NULL){
		printf("���ļ�ʧ�ܣ�");exit(0);
	}
	else{
		struct person p;
		do{
			scan(&p);
			fwrite(&p,sizeof(struct person),1,fp);
			printf("д����Ϣ�ɹ�!�������룿(y/n)");
			getchar();
		}while(ch=getchar()=='y');
		fclose(fp);
	}
}
