#include<stdio.h>
#include<time.h>
#include<string.h>

int main()
{
	time_t timer;
	struct tm *t;
  	timer = time(NULL); // ���� �ð��� �� ������ ���
	
   	t = localtime(&timer); // �� ������ �ð��� �и��Ͽ� ����ü�� �ֱ�

	int type, time, count, number;
	long long int id;
	while(1)
{
	do
	{
	printf("������ �����ϼ���\n");
	printf("1. �����̿��(�̿����:�Ե�����+�μӹڹ���)\n2. ��ũ�̿��(�̿����:�Ե�����))\n");
	scanf("%d",&type);
		if ( !(type ==1 || type ==2)){
			printf("�߸� �Է��Ͽ����ϴ�.\n\n");
		}
	}
	while( !(type ==1 || type ==2));
	do
	{
	printf("�̿�ð��� �����ϼ���\n");
	printf("1.1DAY\n2.After4(����4�ú��� ����)\n");
	scanf("%d",&time);
		if ( !(time ==1 || time ==2)){
		printf("�߸� �Է��Ͽ����ϴ�.\n\n");
		}
	}
	while(!(time ==1 || time ==2));
	
	do
	{
	printf("�ֹι�ȣ�� �Է��ϼ���(6�ڸ�))\n");//�ֹι�ȣ 6�ڸ� 
	scanf("%d",&id); 
		if ( id >= 1000000){
		printf("�߸� �Է��Ͽ����ϴ�.\n\n");
		}
	}
	while ( id >= 1000000);
	
	printf("������ �����ϼ���\n");
	scanf("%d",&count);
	printf("�������� �����ϼ���\n");
	printf("1.����\n2.�����\n3.����������\n4.�ް��庴\n5.�ӻ��\n6.���ڳ�\n");
	scanf("%d",&number);		
//���� �ľ� 
	const int END_1 = 31, END_3 = 31, END_4 = 30, END_5 = 31, END_6 = 30, END_7 = 31, END_8 = 31;
	const int END_9 = 30, END_10= 31, END_11 = 30, END_12 = 31;
	int END_2=28;
	const int FREE=0, PRICE_LESS_3YEAR=15000;
	int birthYear, birthMonth, birthDate, globalBirth, priceEnter;
	float discountRate;
	
//������Ϸ� �ڸ���
	birthYear= (id/10000);
    birthMonth= (id-birthYear*10000)/100;
    birthDate=id-birthYear*10000-birthMonth*100;
    
//���ؽð� (����ð�) 
	int tm_year;//todayYear
	int tm_mon;//
	int tm_mday;//
	
	int todayYear =t->tm_year + 1900;
	int todayMonth=t->tm_mon + 1;
	int todayDate= t->tm_mday;
// �����̰�� 
	int days;
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
		int tdays;
		switch(todayMonth) {
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

	if(birthYear<=(todayYear-2000)){
		globalBirth= (birthYear+2000)*365 + days + birthDate;//�¾�� �������  ��¥(2000�������) 
		}
	else
		{
		globalBirth= (birthYear+1900)*365 + days + birthDate;//�¾�� �������  ��¥(2000����̻�) 
		}	
	int totalDate= todayYear*365+tdays+todayDate; //������� ��¥ 
	int globalAge=(totalDate-globalBirth)/365;//������� ��¥-�����¾��¥=������ 
	//���̺� ���� å���ϱ�		
	
	//���� ���� Ƽ�� ���� ����	
	if (globalAge <1){	
		priceEnter = FREE;}
	if (globalAge >= 1 && globalAge <3){
		priceEnter = PRICE_LESS_3YEAR;}
	if ((globalAge>= 3 && globalAge <12) || globalAge >=65){
		if(type == 1){
			if(time == 1){
			priceEnter = 47000;}
			else{
			priceEnter = 36000;}
		}
		else{
			if(time == 1){
				priceEnter =46000;}
			else {
				priceEnter =35000;}
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
 	int totalPrice;
	if
	(number == 1){//�Ϲ��� 
		discountRate= 1;
		totalPrice= priceEnter*discountRate*count;	
	}
	if
	(number == 2){//����� 
		discountRate= 0.5;
		totalPrice= priceEnter*discountRate*count;
		if(count >= 2){
			totalPrice=(priceEnter*2*discountRate)+(priceEnter*(count-2));}
			}
	if
	(number == 3){//���������� 
		discountRate=0.5;
		totalPrice= priceEnter*discountRate*count;
		if(count >= 2){
		totalPrice= (priceEnter*2*discountRate)+(priceEnter*(count-2));}
		}
	
	if
	(number == 4){//�ް��庴 
		discountRate=0.51;
		totalPrice= priceEnter*discountRate*1+priceEnter*(count-1);
		}
	if
	(number == 5){//�ӻ�� 
		discountRate=0.5;
		totalPrice= priceEnter*discountRate*1+priceEnter*(count-1);
		}
	if
	(number == 6){//�ٵ��� 
		discountRate= 0.7;
		totalPrice= priceEnter*discountRate*count;}	 
	
printf("������ %d��,������ %d���Դϴ�.\n�����մϴ�.\n\n",globalAge, totalPrice);
}

return 0;
}

