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

void fileScan(){//파일 불러오기 
	FILE *fp = fopen("report.csv", "r");
	
while( fscanf(fp, "%d, %d, %d, %d, %d, %d, %d", &recordingToday[index], 
		 &recordingType[index], &recordingTime[index], &recordingCount[index], &recordingDiscount[index], &recordingTotalPrice[index], &recordingAgeGroup[index])!= -1){
		 	index++;
	}
	
fclose(fp);

printf("\n==============================%s==============================\n","report.csv"); 
printf("%8s %6s %12s %6s %7s %15s %7s\n", "날짜", "권종", "이용시간","수량","우대사항","가격","연령");

for(int i = 0; i < index; i++){
	printf("%8d %6d %12d %6d %7d %15d %7d\n", recordingToday[i], recordingType[i], recordingTime[i],
 	recordingCount[i], recordingDiscount[i], recordingTotalPrice[i], recordingAgeGroup[i]);
}
}

void typeCalculate(){//권종별 판매현황 
	
	
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
	printf("\n종합이용권 총 %3d매\n",sumTypeAll);
	printf("종합이용_종일  총 %3d매\n",typeAllOneday);
	printf("종합이용_오후  총 %3d매\n\n",typeAllAfter4);	
	printf("종합이용권 매출 %5d원\n\n",priceAll);
	printf("12개월 미만 %3d매, 유아 %d매, 어린이 %d매, 청소년 %d매, 어른 %d매, 노인 %d매\n\n",
	priceFree1, priceBaby1, priceChild1, priceTeen1, priceAdult1, priceOlder1);
	printf("랜드이용권 총 %3d매\n",sumTypeLand);
	printf("랜드이용_종일  총 %3d매\n",typeLandOneday);
	printf("랜드이용_오후  총 %3d매\n",typeLandAfter4);
	printf("랜드이용권 총 %5d원\n\n",priceLand);	
	printf("12개월 미만 %d매, 유아 %d매, 어린이 %d매, 청소년 %d매, 어른 %d매, 노인 %d매\n",
	priceFree2, priceBaby2, priceChild2, priceTeen2, priceAdult2, priceOlder2);	
			
}

void dateCalculate(){//일자별 판매현황 
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
		printf("%15d년 %4d월 %4d일 :    총 매출  %8d원\n",
			year[countDate], month[countDate], date[countDate],  datePriceArr[countDate][1]);
		}
	}
} 

void line(){//구분선 
	printf("\n======================================================================\n\n");		
}

void discountCalculate(){//우대사항별 판매현황 
	
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
	printf("%33s","총판매티켓수:");
	printf("%10d매\n",total);
	printf("%33s","우대없음:");
	printf("%10d매\n", discount1);	
	printf("%33s","장애인:");
	printf("%10d매\n", discount2);
	printf("%33s","국가유공자:");	
	printf("%10d매\n", discount3);	
	printf("%33s","휴가장병:");	
	printf("%10d매\n", discount4);
	printf("%33s","임산부:");
	printf("%10d매\n",discount5);
	printf("%33s","다자녀:");
	printf("%10d매\n",discount6);
}

int main()//메인보드 
{
fileScan();
printf("\n===========================%s===========================\n","권종 별 판매현황"); 
typeCalculate();//권종별, 연령별
line();
printf("\n============================%s===========================\n","일자별매출 현황");
dateCalculate();//날짜별 판매 
printf("\n===========================%s===========================\n","우대권 판매 현황");
discountCalculate();	//우대권 판매
line();
return 0;
}
