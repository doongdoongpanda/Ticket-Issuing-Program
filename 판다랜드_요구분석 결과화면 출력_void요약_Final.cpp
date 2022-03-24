#include <stdio.h>

const int MAX = 100;
int index = 0;
int recordingToday[MAX];
int recordingType[MAX], recordingTime[MAX], recordingCount[MAX], recordingDiscount[MAX], recordingTotalPrice[MAX], recordingAgeGroup[MAX];
int priceFree1 =0, priceBaby1=0, priceChild1=0, priceTeen1=0, priceAdult1=0, priceOlder1=0;
int priceFree2 =0, priceBaby2=0, priceChild2=0, priceTeen2=0, priceAdult2=0, priceOlder2=0;
int sumTypeAll=0; 
int sumTypeLand=0;
int  priceAll=0;
int  priceLand=0;
int typeAllOneday=0;
int typeAllAfter4=0;
int typeLandOneday=0;
int typeLandAfter4=0;

void fileScan(){//���� �ҷ����� 
	FILE *fp = fopen("report.csv", "r");
	
while( fscanf(fp, "%d, %d, %d, %d, %d, %d, %d", &recordingToday[index], 
		 &recordingType[index], &recordingTime[index], &recordingCount[index], &recordingDiscount[index], &recordingTotalPrice[index], &recordingAgeGroup[index])!= -1){
		 	index++;
	}
	
fclose(fp);

printf("\n==============================%s==============================\n","report.csv"); 
printf("%8s %6s %12s %6s %7s %15s %7s\n", "��¥", "����", "�̿�ð�","����","������","����","����");

for(int i = 0; i < index; i++){
	printf("%8d %6d %12d %6d %7d %15d %7d\n", recordingToday[i], recordingType[i], recordingTime[i],
 	recordingCount[i], recordingDiscount[i], recordingTotalPrice[i], recordingAgeGroup[i]);
}
}

void typeCalculate(){//������ �Ǹ���Ȳ 
	
	
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
	
	
		
		for(int i = 0; i < index; i++){
			switch(recordingAgeGroup[i]){
			case 1:
				if(recordingType[i]==1){
					priceFree1 = recordingCount[i];}
				else {
				priceFree2 = recordingCount[i];	
				}
				break;
			case 2:if(recordingType[i]==1){
				priceBaby1 = recordingCount[i];}
				else {
				priceBaby2 = recordingCount[i];	
				}
				break;
			case 3:if(recordingType[i]==1)
				{priceChild1 = recordingCount[i];}
				else {
				priceChild2 = recordingCount[i];	
				}
				break;
			case 4:
				if(recordingType[i]==1){
				priceTeen1 = recordingCount[i];}
				else {
				priceTeen2 = recordingCount[i];	
				}
				break;
			case 5:
				if(recordingType[i]==1){
				priceAdult1 = recordingCount[i];}
				else {
				priceAdult2 = recordingCount[i];	
				}
				break;
			case 6:
				if(recordingType[i]==1){
				priceOlder1 = recordingCount[i];}
				else {
				priceOlder2 = recordingCount[i];	
				}
				break;
					}
			}
	printf("\n�����̿�� �� %3d��\n",sumTypeAll);
	printf("�����̿�_����  �� %3d��\n",typeAllOneday);
	printf("�����̿�_����  �� %3d��\n\n",typeAllAfter4);	
	printf("�����̿�� ���� %5d��\n\n",priceAll);
	printf("12���� �̸� %3d��, ���� %d��, ��� %d��, û�ҳ� %d��, � %d��, ���� %d��\n\n",
	priceFree1, priceBaby1, priceChild1, priceTeen1, priceAdult1, priceOlder1);
	printf("�����̿�� �� %3d��\n",sumTypeLand);
	printf("�����̿�_����  �� %3d��\n",typeLandOneday);
	printf("�����̿�_����  �� %3d��\n",typeLandAfter4);
	printf("�����̿�� �� %5d��\n\n",priceLand);	
	printf("12���� �̸� %d��, ���� %d��, ��� %d��, û�ҳ� %d��, � %d��, ���� %d��\n",
	priceFree2, priceBaby2, priceChild2, priceTeen2, priceAdult2, priceOlder2);	
			
}

void dateCalculate(){//���ں� �Ǹ���Ȳ 
	int turn, count, countDate= 0 ;
	int datePriceArr[MAX][2] = {0};

	for(turn =0; turn < index; turn++)
	{
		if(turn == 0)
		{
			datePriceArr[countDate][0] = recordingToday[turn];
			datePriceArr[countDate][1] += recordingTotalPrice[turn];
		}
		else if (recordingToday[turn] == recordingToday[turn-1])
			{
			datePriceArr[countDate][1] += recordingTotalPrice[turn];
			}		
		else {
			countDate++;
		datePriceArr[countDate][0] = recordingToday[turn];
		datePriceArr[countDate][1] += recordingTotalPrice[turn];
		}
		if(recordingToday[turn] == recordingToday[turn+1])
		{
		continue;
		}
		else
		{ 
		int year[MAX] ={0};
		int month[MAX] = {0};
		int date[MAX] ={0};
		
		year[countDate]= (datePriceArr[countDate][0]/1000);
		month[countDate]= (recordingToday[countDate]-year[countDate]*1000)/100;
		date[countDate]= recordingToday[countDate] - year[countDate]*1000 - month[countDate]*100;
		printf("%15d�� %4d�� %4d�� :    �� ����  %8d��\n",
			year[countDate], month[countDate], date[countDate],  datePriceArr[countDate][1]);
		}
	}
} 

void line(){//���м� 
	printf("\n======================================================================\n\n");		
}

void discountCalculate(){//�����׺� �Ǹ���Ȳ 
	
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
	printf("%33s","���Ǹ�Ƽ�ϼ�:");
	printf("%10d��\n",total);
	printf("%33s","������:");
	printf("%10d��\n", discount1);	
	printf("%33s","�����:");
	printf("%10d��\n", discount2);
	printf("%33s","����������:");	
	printf("%10d��\n", discount3);	
	printf("%33s","�ް��庴:");	
	printf("%10d��\n", discount4);
	printf("%33s","�ӻ��:");
	printf("%10d��\n",discount5);
	printf("%33s","���ڳ�:");
	printf("%10d��\n",discount6);
}

int main()//���κ��� 
{
fileScan();
printf("\n===========================%s===========================\n","���� �� �Ǹ���Ȳ"); 
typeCalculate();//������, ���ɺ�
line();
printf("\n============================%s===========================\n","���ں����� ��Ȳ");
dateCalculate();//��¥�� �Ǹ� 
printf("\n===========================%s===========================\n","���� �Ǹ� ��Ȳ");
discountCalculate();	//���� �Ǹ�
line();
return 0;
}
