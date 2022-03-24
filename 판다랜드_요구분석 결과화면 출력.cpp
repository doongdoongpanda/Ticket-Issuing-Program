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
printf("%7s %6s %9s %6s %7s %10s", "날짜", "권종", "이용시간","수량","우대사항","가격\n");

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

printf("\n=======================%s=======================\n","권종 별 판매현황"); 
	printf("종합이용권 총 %d매\n",sumTypeAll);
	printf("종합이용_종일  총 %d매\n",typeAllOneday);
	printf("종합이용_오후  총 %d매\n",typeAllAfter4);	
	printf("종합이용권 매출 %d원\n",priceAll);
	printf("랜드이용권 총 %d매\n",sumTypeLand);
	printf("랜드이용_종일  총 %d매\n",typeLandOneday);
	printf("랜드이용_오후  총 %d매\n",typeLandAfter4);
	printf("랜드이용권 총 %d원\n",priceLand);
	
	
printf("\n==============================================================\n\n");
printf("\n=======================%s=======================\n","일자별매출 현황");
	int year[MAX] ={0};
	int month[MAX] = {0};
	int date[MAX] ={0};
	
	int i, j;
	for(i = 0; i < index; i++){
		  for(j =i; j<=i; j++){
		  
	//날짜 분리하기 
	year[j]= (recordingToday[j]/1000);	//날짜별 총매출 
	month[j]= (recordingToday[j]-year*1000)/100;
	date[j]= recordingToday[j] - year*1000 - month*100;
		}
	}
		printf("%d년 %d월 %d일 : ", year[j], month[j], date[j]);	
		printf("%10s","총매출");
		printf("%15d원", totalPrice);
printf("\n=======================%s=======================\n","우대권 판매 현황");
	//우대권 판매현황 
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
	
	
	printf("%10s","총판매티켓수:");
	printf("%10d매\n",total);
	printf("%10s","우대없음:");
	printf("%10d매\n", discount1);	
	printf("%10s","장애인:");
	printf("%10d매\n", discount2);
	printf("%10s","국가유공자:");	
	printf("%10d매\n", discount3);	
	printf("%10s","휴가장병:");	
	printf("%10d매\n", discount4);
	printf("%10s","임산부:");
	printf("%10d매\n",discount5);
	printf("%10s","다자녀:");
	printf("%10d매\n",discount6);
printf("\n==============================================================\n\n");	
return 0;
}
