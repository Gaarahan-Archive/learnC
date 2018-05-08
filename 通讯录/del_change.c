void del_change(FILE *x,int y,int num){/*删除第y个结构体*/
	int n,i,j; 
	FILE *Ftemp; 
	struct person p; 
	struct person p0={"\0"};
	printf("是否对该信息进行删改(输入序号)? 1.删除 2.修改 0.不删改\n");
	scanf("%d",&n);
	switch(n){
		case 0: break;
		case 1: {
					printf("删除中\n");
					if(rename("通讯录.txt","temp.txt")<0){
						printf("重命名失败");
						break; 
					} 
					Ftemp=fopen("通讯录.txt","wt");
					if(Ftemp==NULL){
						printf("打开缓存文件失败");
						break; 
					}
					for(i=0;i<=num;i++){
						if(i!=y) {
							fread(&p,sizeof(struct person),1,x);
							fwrite(&p,sizeof(struct person),1,Ftemp);
						} 
					}
					fclose(Ftemp);
					remove("temp.txt");
				}
				
	}

}
