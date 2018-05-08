void scan(struct person *x){
		printf("请输入姓名：");
		scanf("%s",x->name);

get_sex:	printf("请输入性别（man/women）：");
		scanf("%s",x->sex);
		if(strcmp(x->sex,"man")&&strcmp(x->sex,"woman")){
			printf("请输入正确的性别！\n");
			goto get_sex;
		}
		
		printf("请输入年龄：");
		scanf("%d",&x->age);
		printf("请输入电话号码：");
		scanf("%s",x->num);
		printf("请输入电子邮件地址：");
		scanf("%s",x->e_mail);
}
void add(){
	char ch;
	FILE *fp=fopen("通讯录.txt","at+");
	if(fp==NULL){
		printf("打开文件失败！");exit(0);
	}
	else{
		struct person p;
		do{
			scan(&p);
			fwrite(&p,sizeof(struct person),1,fp);
			printf("写入信息成功!继续输入？(y/n)");
			getchar();
		}while(ch=getchar()=='y');
		fclose(fp);
	}
}
