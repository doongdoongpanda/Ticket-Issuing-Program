#include <stdio.h>

int main()
{
	FILE *fp = fopen("report.csv", "r");
	const int MAX = 100;
	int index = 0;
	int sumTypeAll = 0;
	int sumTypeLand = 0;
	int todayYear[MAX], todayMonth[MAX], todayDate[MAX];
	int recordingType[MAX], recordingTime[MAX], recordingCount[MAX], recordingDiscount[MAX], recordingTotalPrice[MAX];
		
	while( fscanf(fp, "%d, %d, %d, %d, %d, %d", &todayYear[index], &todayMonth[index], &todayDate[index],
			 &recordingType[index], &recordingTime[index], &recordingCount[index], &recordingDiscount[index], &recordingTotalPrice[index]) != -1){
			 	index++;
		}
	fclose(fp);
	printf("\n==========================%s==========================\n","report.csv"); 
	printf("%7s %6s %9s %6s %7s %10s", "날짜", "권종", "이용시간","수량","우대사항","가격\n");
	for(int i = 0; i < index; i++){
		printf("%6d %6d %9d %6d %7d %10d\n", todayYear[i], todayMonth[i], todayDate[i], recordingType[i], recordingTime[i],
	 	recordingCount[i], recordingDiscount[i], recordingTotalPrice[i]);
	}
	for(int j = 0; j < index; j++){
		switch(recordingType[j]) {
			case 1:
				sumTypeAll += recordingCount[j];
				break;
			case 2:
				sumTypeLand += recordingCount[j];
				break;
				}
		}	
	printf("\n=======================%s=======================\n","권종 별 판매현황"); 
	printf("종합이용권 총 %d매\n",sumTypeAll);
	printf("랜드이용권 총 %d매",sumTypeLand);
	printf("\n==============================================================\n");
	 
return 0;
}
