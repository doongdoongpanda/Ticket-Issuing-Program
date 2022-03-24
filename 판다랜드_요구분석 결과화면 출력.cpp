#include <stdio.h>

int main()
{
FILE *fp = fopen("report.csv", "r");
const int MAX = 100;
int index = 0;
int recordingToday[MAX];
int recordingType[MAX], recordingTime[MAX], recordingCount[MAX], recordingDiscount[MAX], recordingTotalPrice[MAX], recordingAgeGroup[MAX];
int sumTypeAll=0; 
int sumTypeLand=0;
int  priceAll=0;
int  priceLand=0;
int typeAllOneday=0;
int typeAllAfter4=0;
int typeLandOneday=0;
int typeLandAfter4=0;
	
while( fscanf(fp, "%d, %d, %d, %d, %d, %d", &recordingToday[index], 
		 &recordingType[index], &recordingTime[index], &recordingCount[index], &recordingDiscount[index], &recordingTotalPrice[index], &recordingAgeGroup[index])!= -1){
		 	index++;
	}
	
fclose(fp);

printf("\n==========================%s==========================\n","report.csv"); 
printf("%7s %6s %9s %6s %7s %10s", "��¥", "����", "�̿�ð�","����","������","����\n");

for(int i = 0; i < index; i++){
	printf("%6d %6d %9d %6d %7d %10d, %5d\n", recordingToday[i], recordingType[i], recordingTime[i],
 	recordingCount[i], recordingDiscount[i], recordingTotalPrice[i], recordingAgeGroup[i]);
}

for(int j = 0; j < index; j++){
			switch(recordingType[j]){
			case 1:
				sumTypeAll += recordingCount[j];
				priceAll += recordingTotalPrice[j];
				if(recordingTime[j]==1){
					typeAllOneday += recordingCount[j];
				} else {
				typeAllAfter4 += recordingCount[j];}
				break;
			case 2:
				sumTypeLand += recordingCount[j];
				priceLand += recordingTotalPrice[j];
				if(recordingTime[j]==1){
				typeLandOneday += recordingCount[j];
				} else {
				typeLandAfter4 += recordingCount[j];}		
				
				break;}
			}

printf("\n=======================%s=======================\n","���� �� �Ǹ���Ȳ"); 
	printf("�����̿�� �� %d��\n",sumTypeAll);
	printf("�����̿�_����  �� %d��\n",typeAllOneday);
	printf("�����̿�_����  �� %d��\n",typeAllAfter4);	
	printf("�����̿�� ���� %d��\n",priceAll);
	printf("�����̿�� �� %d��\n",sumTypeLand);
	printf("�����̿�_����  �� %d��\n",typeLandOneday);
	printf("�����̿�_����  �� %d��\n",typeLandAfter4);
	printf("�����̿�� �� %d��\n",priceLand);
	
	
printf("\n==============================================================\n\n");
printf("\n=======================%s=======================\n","���ں����� ��Ȳ");
	int year[MAX] ={0};
	int month[MAX] = {0};
	int date[MAX] ={0};
	
	int i, j;
	for(i = 0; i < index; i++){
		  for(j =i; j<=i; j++){
		  
	//��¥ �и��ϱ� 
	year[j]= (recordingToday[j]/1000);	//��¥�� �Ѹ��� 
	month[j]= (recordingToday[j]-year*1000)/100;
	date[j]= recordingToday[j] - year*1000 - month*100;
		}
	}
		printf("%d�� %d�� %d�� : ", year[j], month[j], date[j]);	
		printf("%10s","�Ѹ���");
		printf("%15d��", totalPrice);
printf("\n=======================%s=======================\n","���� �Ǹ� ��Ȳ");
	//���� �Ǹ���Ȳ 
int discount1 = 0, discount2 =0, discount3 =0, discount4 =0, discount5 = 0, discount6 = 0, total = 0;

	for(int i = 0; i < index; i++){
			total += recordingCount[i]; 
			
			switch(recordingDiscount[i]){
			case 1:
				discount1 += recordingCount[i];
				break;
			case 2:
				discount2 += recordingCount[i];
				break;
			case 3:
				discount3 += recordingCount[i];
				break;
			case 4:
				discount4 += recordingCount[i];
				break;
			case 5:
				discount5 += recordingCount[i];
				break;
			case 6:
				discount6 += recordingCount[i];
				break;
					}
			}
	
	
	printf("%10s","���Ǹ�Ƽ�ϼ�:");
	printf("%10d��\n",total);
	printf("%10s","������:");
	printf("%10d��\n", discount1);	
	printf("%10s","�����:");
	printf("%10d��\n", discount2);
	printf("%10s","����������:");	
	printf("%10d��\n", discount3);	
	printf("%10s","�ް��庴:");	
	printf("%10d��\n", discount4);
	printf("%10s","�ӻ��:");
	printf("%10d��\n",discount5);
	printf("%10s","���ڳ�:");
	printf("%10d��\n",discount6);
printf("\n==============================================================\n\n");	
return 0;
}
