void find(){
	int n,num,i,flag=0;
	char m[10],x;
	struct person p;
	FILE *fp=fopen("ͨѶ¼.txt","r+");
	if(fp==NULL){
		printf("���ļ�ʧ�ܣ�");exit(0);
	}
	else{
		printf("1.�����\t2.������\t3.�������˵�\n");
		scanf("%d",&n);
		num=get_lenth(fp);
		switch(n){
			case 1: printf("����%d����Ϣ,������Ҫ���ҵ����(����'0'�˳�):",num);
					while(1){
						scanf("%d",&i); 
						if(i>0&&i<=num){
							fseek(fp,(i-1)*sizeof(struct person),SEEK_SET);
							fread(&p,sizeof(struct person),1,fp);
							printf("��%dλ��ϢΪ:\n",i);
							print(p);
							del_change(fp,i,num); /*ɾ�����޸�*/
							printf("\n������ż�����ѯ(����'0'�˳�)");
						}
						else if(i==0)	break; 
						else printf("��Ų�׼ȷ,����������,������'0'�˳�:");
					}
					break;
			case 2: 
					while(1){
						printf("\n\n����������:");
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
						if(flag==0)	printf("δ�ҵ���Ӧ��Ϣ\n"); 
						
						getchar();
						printf("������ѯ?(y/n):");
						x=getchar();
						if(x!='y')	break;
					}
					break;
		}
	}
	fclose(fp);
}
