void del_change(FILE *x,int y,int num){/*ɾ����y���ṹ��*/
	int n,i,j; 
	FILE *Ftemp; 
	struct person p; 
	struct person p0={"\0"};
	printf("�Ƿ�Ը���Ϣ����ɾ��(�������)? 1.ɾ�� 2.�޸� 0.��ɾ��\n");
	scanf("%d",&n);
	switch(n){
		case 0: break;
		case 1: {
					printf("ɾ����\n");
					if(rename("ͨѶ¼.txt","temp.txt")<0){
						printf("������ʧ��");
						break; 
					} 
					Ftemp=fopen("ͨѶ¼.txt","wt");
					if(Ftemp==NULL){
						printf("�򿪻����ļ�ʧ��");
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
