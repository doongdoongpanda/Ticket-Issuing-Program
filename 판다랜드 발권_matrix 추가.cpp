#include<stdio.h>
#include<time.h>
#include<string.h>

int main()
{

	time_t timer;
	struct tm *t;
  	timer = time(NULL); // ���� �ð��� �� ������ ���
	t = localtime(&timer); // �� ������ �ð��� �и��Ͽ� ����ü�� �ֱ�
	//������� 
	const int END_1 = 31, END_2=28, END_3 = 31, END_4 = 30, END_5 = 31, END_6 = 30, END_7 = 31, END_8 = 31;
	const int END_9 = 30, END_10= 31, END_11 = 30, END_12 = 31;
	const int FREE = 0, PRICE_LESS_3YEAR = 15000;
	int birthYear, birthMonth, birthDate, globalBirth, priceEnter, days, tdays;
	float discountRate;
	int index =0;
	int time[10]={0}; 
	int type[10]={0};
	int count[10]={0};
	int number[10]={0};
	int totalPrice[10]={0};
	int issue;
	long long int id;
for(index; index<=10;)//�ݺ� 
{
	do
	{
	printf("������ �����ϼ���\n");
	printf("1. �����̿��(�̿����:�Ե�����+�μӹڹ���)\n2. ��ũ�̿��(�̿����:�Ե�����))\n");
	scanf("%d",&type[index]);
		if ( !(type[index] ==1 || type[index] ==2)){
			printf("�߸� �Է��Ͽ����ϴ�.\n\n");
		}
	}
	while( !(type[index] ==1 || type[index] ==2));
	do
	{
	printf("�̿�ð��� �����ϼ���\n");
	printf("1.1DAY\n2.After4(����4�ú��� ����)\n");
	scanf("%d",&time[index]);
		if ( !(time[index] ==1 || time[index] ==2)){
		printf("�߸� �Է��Ͽ����ϴ�.\n\n");
		}
	}
	while(!(time[index] ==1 || time[index] ==2));
	
	do
	{
	printf("�ֹι�ȣ�� �Է��ϼ���(6�ڸ�))\n");//�ֹι�ȣ 6�ڸ� 
	scanf("%d",&id); 
		if ( id >= 1000000){
		printf("�߸� �Է��Ͽ����ϴ�.\n\n");
		}
	}
	while ( id >= 1000000);
	do
	{
	printf("������ �����ϼ���\n");
	scanf("%d",&count[index]);
		if ( count[index] > 10){
		printf("�߸� �Է��Ͽ����ϴ�.\n\n");}
	}
	while( count[index] > 10);
	do
	{
	printf("�������� �����ϼ���\n");
	printf("1.����\n2.�����\n3.����������\n4.�ް��庴\n5.�ӻ��\n6.���ڳ�\n");
	scanf("%d",&number[index]);		
		if(!(number[index] ==1 || number[index] ==2 || number[index] ==3 || number[index] ==4 || number[index] ==5 || number[index] ==6)){
		printf("�߸� �Է��Ͽ����ϴ�.\n\n");	
		}
	}
	while(!(number[index] ==1 || number[index] ==2 || number[index] ==3 || number[index] ==4 || number[index] ==5 || number[index] ==6));
	
//������Ϸ� �ڸ���
	birthYear= (id/10000);
    birthMonth= (id-birthYear*10000)/100;
    birthDate=id-birthYear*10000-birthMonth*100;
//���ؽð� (����ð�) 
	int tm_year;//todayYear
	int tm_mon;//todaymonth
	int tm_mday;//today
	int todayYear[10];
	int todayMonth[10];
	int todayDate[10];
	todayYear[index] = t->tm_year + 1900;
	todayMonth[index] = t->tm_mon + 1;
	todayDate[index] = t->tm_mday;
// �����̰�� 
	switch(birthMonth-1) {
			case 12:
				days += END_11;
			case 11:
				days += END_10;
			case 10:
				days += END_9;
			case 9:
				days += END_8;
			case 8:
				days += END_7;
			case 7:
				days += END_6;
			case 6:
				days += END_5;
			case 5:
				days += END_4;
			case 4:
				days += END_3;
			case 3:
				days += END_2;
			case 2:
				days += END_1;
		}
		switch(todayMonth[index]) {
			case 12:
				tdays += END_11;
			case 11:
				tdays += END_10;
			case 10:
				tdays += END_9;
			case 9:
				tdays += END_8;
			case 8:
				tdays += END_7;
			case 7:
				tdays += END_6;
			case 6:
				tdays += END_5;
			case 5:
				tdays += END_4;
			case 4:
				tdays += END_3;
			case 3:
				tdays += END_2;
			case 2:
				tdays += END_1;
		}	
	if(birthYear<=(todayYear[index]-2000)){
		globalBirth= (birthYear+2000)*365 + days + birthDate;//�¾�� �������  ��¥(2000�������) 
		}
	else{
		globalBirth= (birthYear+1900)*365 + days + birthDate;//�¾�� �������  ��¥(2000����̻�) 
		}	
	int totalDate= todayYear[index]*365+tdays+todayDate[index]; //������� ��¥ 
	int globalAge=(totalDate-globalBirth)/365;//�� ���� = ������� ��¥-�����¾��¥	
	//���� ���� Ƽ�� ���� ����	
	if (globalAge < 1){	
		priceEnter = FREE;}
	if (globalAge >= 1 && globalAge <3){
		priceEnter = PRICE_LESS_3YEAR;}
	if ((globalAge >= 3 && globalAge <12) || globalAge >=65){
		if(type[index] == 1){
			if(time[index] == 1){
			priceEnter = 47000;}
			else{
			priceEnter = 36000;}
		}
		else{
			if(time[index] == 1){
				priceEnter = 46000;}
			else {
				priceEnter = 35000;}
		}
	}
	if (globalAge>= 12 && globalAge <18){
		if(type[index] == 1){
			if(time[index] == 1){
			priceEnter = 52000;}
			else{
			priceEnter = 42000;}
		}
		else{
			if(time[index] == 1){
				priceEnter =50000;}
			else {
				priceEnter =40000;}
		}		
	}
	if (globalAge>= 18 && globalAge <65){
		if(type[index] == 1){
			if(time[index] == 1){
			priceEnter = 59000;}
			else{
			priceEnter = 48000;}
		}
		else{
			if(time[index] == 1){
				priceEnter =56000;}
			else {
				priceEnter =45000;}
		}
	}	
	//������ �����ϱ�//
	if	(number[index] == 1){//�Ϲ��� 
		discountRate= 1;
		totalPrice[index]= priceEnter*discountRate*count[index];	
	}
	if	(number[index] == 2){//����� 
		discountRate= 0.5;
		if(count[index] == 1){
			totalPrice[index]= priceEnter*discountRate;
		}
		else{ //2���̻��϶� 2����� �������� 
			totalPrice[index]=(priceEnter*2*discountRate)+(priceEnter*(count[index]-2));}
		}
	if	(number[index] == 3){//���������� 
		discountRate=0.5;
		if (count[index] == 1)
			totalPrice[index]= priceEnter*discountRate;
		else{//2���̻��϶� 2����� �������� 
			totalPrice[index]= (priceEnter*2*discountRate)+(priceEnter*(count[index]-2));}
		}
	if	(number[index] == 4){//�ް��庴 
		discountRate=0.51;
		totalPrice[index]= priceEnter*discountRate*1+priceEnter*(count[index]-1);
		}
	if	(number[index] == 5){//�ӻ�� 
		discountRate=0.5;
		totalPrice[index]= priceEnter*discountRate*1+priceEnter*(count[index]-1);
		}
	if	(number[index] == 6){//�ٵ��� 
		discountRate= 0.7;
		totalPrice[index]= priceEnter*discountRate*count[index];
		}	 
	
printf("������ %d��,������ %d���Դϴ�.\n�����մϴ�.\n\n",globalAge, totalPrice[index]);
	printf("��ӹ߱��Ͻðڽ��ϱ�?\n1.YES\n2.NO.\n");//�߰��߱ǿ��� ����
	scanf("%d", &issue);
	if(issue == 1)//�߱����� ���ư��� 
		{ 
		printf("------- �߱��� �����մϴ�. -------\n");
		index++;
		continue;
		}
	else if(issue == 2){//�����ϱ� 
		printf("���α׷��� �����մϴ�. �����մϴ�\n");
		printf("==================�Ǵٷ���==================\n");
	
		for(int i=0; i<=index; i++){
			if(type[i] == 1){printf("�����̿��\n");//�����μ� 
		} 
			else {printf("��ũ�̿��\n");}
		if(time[i] == 1){printf("1Day ");//������, ����Ÿ������ 
		} 
			else {printf("After4 ");}
	printf("x\t%d��\t",count[i]);//���� �μ� 
	printf("%d��\t", totalPrice[i]);//�ݾ��μ� 

	//������ ���� �μ� 
	if	(number[i] == 1){//�Ϲ� 
		printf("*����������\n");
	}
	if	(number[i] == 2){//����� 
		printf("*����ο������\n");
	}
	if	(number[i] == 3){//���������� 
		printf("*���������ڿ������\n");
	}
	if	(number[i] == 4){//�ް��庴 
		printf("*�ް��庴�������\n");
		}
	if	(number[i] == 5){//�ӻ�� 
		printf("*�ӻ�ο������\n");
		}	
	if	(number[i] == 6){//�ٵ��� 
		printf("*�ٵ��̿������\n");
		}
	
	}
	printf("--------------------------------------------\n");
		int sumTotal=0;
		for(int i=0; i<=index; i++){
	sumTotal+=totalPrice[i];
		}
	printf("%d��%d��%d��\n", todayYear[index],todayMonth[index],todayDate[index]);
	printf("����� �Ѿ��� %d�� �Դϴ�.\n", sumTotal);
	
}
		break;
}
return 0;
}

