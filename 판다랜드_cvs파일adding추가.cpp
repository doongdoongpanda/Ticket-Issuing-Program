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
	int recordingTime[10], recordingType[10], recordingCount[10], recordingDiscount[10], recordingTotalPrice[10];//�׷켳���Լ� 
	int todayYear[10], todayMonth[10], todayDate[10];//���ó�¥ �׷� 
	int birthYear, birthMonth, birthDate, globalBirth, priceEnter, days, tdays, issue, continueOrder, index = 0;
	int time, type, count, discount, totalPrice;
	int tm_year, tm_mon, tm_mday;//today
	long long int id;
	float discountRate;

for(index; index<=10;)//�ݺ� 
{
	do
	{
	printf("������ �����ϼ���\n");
	printf("1. �����̿��(�̿����:�Ǵٷ���+�μӹڹ���)\n2. ��ũ�̿��(�̿����:�Ǵٷ���)\n");
	scanf("%d",&type);
		if ( !(type ==1 || type ==2)){
			printf("�߸� �Է��Ͽ����ϴ�.\n\n");
		}
	}
	while( !(type ==1 || type ==2));
	do
	{
	printf("\n�̿�ð��� �����ϼ���\n");
	printf("1.1DAY\n2.After4(����4�ú��� ����)\n");
	scanf("%d",&time);
		if ( !(time ==1 || time ==2)){
		printf("�߸� �Է��Ͽ����ϴ�.\n\n");
		}
	}
	while(!(time ==1 || time ==2));
	
	do
	{
	printf("\n�ֹι�ȣ�� �Է��ϼ���(6�ڸ�))\n");//�ֹι�ȣ 6�ڸ� 
	scanf("%d",&id); 
		if ( id >= 1000000){
		printf("�߸� �Է��Ͽ����ϴ�.\n\n");
		}
	}
	while ( id >= 1000000);
	do
	{
	printf("\n������ �����ϼ���\n");
	scanf("%d",&count);
		if ( count > 10){
		printf("�߸� �Է��Ͽ����ϴ�.\n\n");}
	}
	while( count > 10);
	do
	{
	printf("\n�������� �����ϼ���\n");
	printf("1.����\n2.�����\n3.����������\n4.�ް��庴\n5.�ӻ��\n6.���ڳ�\n");
	scanf("%d",&discount);		
		if(!(discount ==1 || discount ==2 || discount ==3 || discount ==4 || discount ==5 || discount ==6)){
		printf("�߸� �Է��Ͽ����ϴ�.\n\n");	
		}
	}
	while(!(discount ==1 || discount ==2 || discount ==3 || discount ==4 || discount ==5 || discount ==6));
	
//������Ϸ� �ڸ���
	birthYear= (id/10000);
    birthMonth= (id-birthYear*10000)/100;
    birthDate=id-birthYear*10000-birthMonth*100;
//���ؽð� (����ð�) 
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
		if(type == 1){
			if(time == 1){
			priceEnter = 47000;}
			else{
			priceEnter = 36000;}
		}
		else{
			if(time == 1){
				priceEnter = 46000;}
			else {
				priceEnter = 35000;}
		}
	}
	if (globalAge>= 12 && globalAge <18){
		if(type == 1){
			if(time == 1){
			priceEnter = 52000;}
			else{
			priceEnter = 42000;}
		}
		else{
			if(time == 1){
				priceEnter =50000;}
			else {
				priceEnter =40000;}
		}		
	}
	if (globalAge>= 18 && globalAge <65){
		if(type == 1){
			if(time == 1){
			priceEnter = 59000;}
			else{
			priceEnter = 48000;}
		}
		else{
			if(time == 1){
				priceEnter =56000;}
			else {
				priceEnter =45000;}
		}
	}	
	//������ �����ϱ�//
	if	(discount == 1){//�Ϲ��� 
		discountRate= 1;
		totalPrice= priceEnter*discountRate*count;	
		}
	if	(discount == 2){//����� 
		discountRate= 0.5;
		if(count == 1){
			totalPrice= priceEnter*discountRate;
		}
		else{ //2���̻��϶� 2����� �������� 
			totalPrice=(priceEnter*2*discountRate)+(priceEnter*(count-2));}
		}
	if	(discount == 3){//���������� 
		discountRate=0.5;
		if (count == 1)
			totalPrice= priceEnter*discountRate;
		else{//2���̻��϶� 2����� �������� 
			totalPrice= (priceEnter*2*discountRate)+(priceEnter*(count-2));}
		}
	if	(discount == 4){//�ް��庴 
		discountRate=0.51;
		totalPrice= priceEnter*discountRate*1+priceEnter*(count-1);
		}
	if	(discount == 5){//�ӻ�� 
		discountRate=0.5;
		totalPrice= priceEnter*discountRate*1+priceEnter*(count-1);
		}
	if	(discount == 6){//�ٵ��� 
		discountRate= 0.7;
		totalPrice= priceEnter*discountRate*count;
		}	 
	printf("\n������ %d��,������ %d���Դϴ�.\n�����մϴ�.\n\n",globalAge, totalPrice);

	recordingTime[index] = time;
	recordingType[index] = type;
	recordingCount[index] = count;
	recordingDiscount[index] = discount;
	recordingTotalPrice[index] = totalPrice;
	
	printf("��ӹ߱��Ͻðڽ��ϱ�?\n1.YES\n2.NO.\n");//�߰��߱ǿ��� ����
	scanf("%d", &issue);
	if(issue == 1)//�߱����� ���ư��� 
		{ 
		printf("----------------- �߱��� �����մϴ�. -----------------\n");
		index++;
		continue;
	}
	else if(issue == 2){//�����ϱ� 
		printf("\n���α׷��� �����մϴ�. �����մϴ�.\n\n");
		FILE*fp = fopen("report.csv", "a");
		printf("======================%s========================\n","�Ǵٷ���");
	
		for(int i=0; i<=index; i++){
		fprintf(fp, "%d, %d, %d, %d, %d\n",  recordingType[i], recordingTime[i], recordingCount[i], recordingDiscount[i], recordingTotalPrice[i]);//csv���� ���� add��� 
			if(recordingType[i] == 1){printf("�����̿��\n");//�����μ� 
		} 
			else {printf("��ũ�̿��\n");}
		if(recordingTime[i] == 1){printf("%s\t", "1Day");//������, ����Ÿ������ 
		} 
			else {printf("%s\t", "After4");}
	printf("X\t%d��\t",recordingCount[i]);//���� �μ� 
	printf("%5d��\t", recordingTotalPrice[i]);//�ݾ��μ� 

	//������ ���� �μ� 
	if	(recordingDiscount[i] == 1){//�Ϲ� 
		printf("%20s\n","*����������");
	}
	if	(recordingDiscount[i] == 2){//����� 
		printf("%20s\n","*����ο������");
	}
	if	(recordingDiscount[i] == 3){//���������� 
		printf("%20s\n","*���������ڿ������");
	}
	if	(recordingDiscount[i] == 4){//�ް��庴 
		printf("%20s\n","*�ް��庴�������");
		}
	if	(recordingDiscount[i] == 5){//�ӻ�� 
		printf("%20s\n","*�ӻ�ο������");
		}	
	if	(recordingDiscount[i] == 6){//�ٵ��� 
		printf("%20s\n","*�ٵ��̿������");
		}
	}
	printf("------------------------------------------------------\n");
	int sumTotal=0;
	for(int i=0; i<=index; i++){
	sumTotal+=recordingTotalPrice[i];
	}
		
	printf("%3d��%3d��%3d��\n", todayYear[index],todayMonth[index],todayDate[index]);
	printf("����� �Ѿ��� %4d�� �Դϴ�.\n", sumTotal);
	printf("======================================================\n");
	printf("��� ����(1: ���ο� �ֹ�, 2: ���α׷� ����) :");
	scanf("%d", &continueOrder);
	if(continueOrder == 1){
		printf("\n");
		continue;
	}
	if (continueOrder == 2){
		break;
	}	
	fclose(fp);
	}	
}
return 0;
}
