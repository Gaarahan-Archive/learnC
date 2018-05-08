void find(){
	int n,num,i,flag=0;
	char m[10],x;
	struct person p;
	FILE *fp=fopen("通讯录.txt","r+");
	if(fp==NULL){
		printf("打开文件失败！");exit(0);
	}
	else{
		printf("1.查序号\t2.搜姓名\t3.返回主菜单\n");
		scanf("%d",&n);
		num=get_lenth(fp);
		switch(n){
			case 1: printf("共有%d条信息,请输入要查找的序号(输入'0'退出):",num);
					while(1){
						scanf("%d",&i); 
						if(i>0&&i<=num){
							fseek(fp,(i-1)*sizeof(struct person),SEEK_SET);
							fread(&p,sizeof(struct person),1,fp);
							printf("第%d位信息为:\n",i);
							print(p);
							del_change(fp,i,num); /*删除或修改*/
							printf("\n输入序号继续查询(输入'0'退出)");
						}
						else if(i==0)	break; 
						else printf("序号不准确,请重新输入,或输入'0'退出:");
					}
					break;
			case 2: 
					while(1){
						printf("\n\n请输入姓名:");
						scanf("%s",m);
						for(i=0;i<num;i++){
							fseek(fp,i*sizeof(struct person),SEEK_SET);
							fread(&p,sizeof(struct person),1,fp);
							if(strcmp(m,p.name)==0){
								print(p);
								del_change(fp,i,num);
								flag=1;
							}
						}
						if(flag==0)	printf("未找到对应信息\n"); 
						
						getchar();
						printf("继续查询?(y/n):");
						x=getchar();
						if(x!='y')	break;
					}
					break;
		}
	}
	fclose(fp);
}
