#include<stdio.h>
#include<time.h>
#include<string.h>

int main()
{
	time_t timer;
	struct tm *t;
  	timer = time(NULL); // 현재 시각을 초 단위로 얻기
	t = localtime(&timer); // 초 단위의 시간을 분리하여 구조체에 넣기
	
	//상수정리 
	const int END_1 = 31, END_2=28, END_3 = 31, END_4 = 30, END_5 = 31, END_6 = 30, END_7 = 31, END_8 = 31;
	const int END_9 = 30, END_10= 31, END_11 = 30, END_12 = 31;
	const int FREE = 0, PRICE_LESS_3YEAR = 15000;
	int birthYear, birthMonth, birthDate, globalBirth, priceEnter, days, tdays, issue, continueOrder, index = 0;
	int tm_year, tm_mon, tm_mday;//today
	long long int id;
	float discountRate;
	int time[10]={0}, type[10]={0}, count[10]={0}, discount[10]={0}, totalPrice[10]={0};
	int todayYear[10], todayMonth[10], todayDate[10];//오늘날짜 그룹 

for(index; index<=10;)//반복 
{
	do
	{
	printf("권종을 선택하세요\n");
	printf("1. 종합이용권(이용범위:판다랜드+민속박물관)\n2. 파크이용권(이용범위:판다랜드)\n");
	scanf("%d",&type[index]);
		if ( !(type[index] ==1 || type[index] ==2)){
			printf("잘못 입력하였습니다.\n\n");
		}
	}
	while( !(type[index] ==1 || type[index] ==2));
	do
	{
	printf("\n이용시간을 선택하세요\n");
	printf("1.1DAY\n2.After4(오후4시부터 입장)\n");
	scanf("%d",&time[index]);
		if ( !(time[index] ==1 || time[index] ==2)){
		printf("잘못 입력하였습니다.\n\n");
		}
	}
	while(!(time[index] ==1 || time[index] ==2));
	
	do
	{
	printf("\n주민번호를 입력하세요(6자리))\n");//주민번호 6자리 
	scanf("%d",&id); 
		if ( id >= 1000000){
		printf("잘못 입력하였습니다.\n\n");
		}
	}
	while ( id >= 1000000);
	do
	{
	printf("\n갯수를 선택하세요\n");
	scanf("%d",&count[index]);
		if ( count[index] > 10){
		printf("잘못 입력하였습니다.\n\n");}
	}
	while( count[index] > 10);
	do
	{
	printf("\n우대사항을 선택하세요\n");
	printf("1.없음\n2.장애인\n3.국가유공자\n4.휴가장병\n5.임산부\n6.다자녀\n");
	scanf("%d",&discount[index]);		
		if(!(discount[index] ==1 || discount[index] ==2 || discount[index] ==3 || discount[index] ==4 || discount[index] ==5 || discount[index] ==6)){
		printf("잘못 입력하였습니다.\n\n");	
		}
	}
	while(!(discount[index] ==1 || discount[index] ==2 || discount[index] ==3 || discount[index] ==4 || discount[index] ==5 || discount[index] ==6));
	
//생년월일로 자르기
	birthYear= (id/10000);
    birthMonth= (id-birthYear*10000)/100;
    birthDate=id-birthYear*10000-birthMonth*100;
//기준시간 (현재시간) 
	todayYear[index] = t->tm_year + 1900;
	todayMonth[index] = t->tm_mon + 1;
	todayDate[index] = t->tm_mday;
// 만나이계산 
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
		globalBirth= (birthYear+2000)*365 + days + birthDate;//태어나서 현재까지  날짜(2000년생이하) 
		}
	else{
		globalBirth= (birthYear+1900)*365 + days + birthDate;//태어나서 현재까지  날짜(2000년생이상) 
		}	
	int totalDate= todayYear[index]*365+tdays+todayDate[index]; //현재까지 날짜 
	int globalAge=(totalDate-globalBirth)/365;//만 나이 = 현재까지 날짜-내가태어난날짜	
	//나이 기준 티켓 가격 결정	
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
	//할인율 적용하기//
	if	(discount[index] == 1){//일반인 
		discountRate= 1;
		totalPrice[index]= priceEnter*discountRate*count[index];	
	}
	if	(discount[index] == 2){//장애인 
		discountRate= 0.5;
		if(count[index] == 1){
			totalPrice[index]= priceEnter*discountRate;
		}
		else{ //2명이상일때 2명까지 혜택적용 
			totalPrice[index]=(priceEnter*2*discountRate)+(priceEnter*(count[index]-2));}
		}
	if	(discount[index] == 3){//국가유공자 
		discountRate=0.5;
		if (count[index] == 1)
			totalPrice[index]= priceEnter*discountRate;
		else{//2명이상일때 2명까지 혜택적용 
			totalPrice[index]= (priceEnter*2*discountRate)+(priceEnter*(count[index]-2));}
		}
	if	(discount[index] == 4){//휴가장병 
		discountRate=0.51;
		totalPrice[index]= priceEnter*discountRate*1+priceEnter*(count[index]-1);
		}
	if	(discount[index] == 5){//임산부 
		discountRate=0.5;
		totalPrice[index]= priceEnter*discountRate*1+priceEnter*(count[index]-1);
		}
	if	(discount[index] == 6){//다둥이 
		discountRate= 0.7;
		totalPrice[index]= priceEnter*discountRate*count[index];
		}	 
	
printf("\n만나이 %d살,가격은 %d원입니다.\n감사합니다.\n\n",globalAge, totalPrice[index]);
	printf("계속발권하시겠습니까?\n1.YES\n2.NO.\n");//추가발권여부 묻기
	scanf("%d", &issue);
	if(issue == 1)//발권으로 돌아가기 
		{ 
		printf("----------------- 발권을 시작합니다. -----------------\n");
		index++;
		continue;
	}
	else if(issue == 2){//종료하기 
		printf("\n프로그램을 종료합니다. 감사합니다\n");
		FILE*fp = fopen("report.csv", "a");
		printf("======================%s========================\n","판다랜드");
	
		for(int i=0; i<=index; i++){
		fprintf(fp, "%d, %d, %d, %d, %d\n",  type[i], time[i], count[i], discount[i], totalPrice[i]);//csv파일 생성 add모드 
			if(type[i] == 1){printf("종합이용권\n");//권종인쇄 
		} 
			else {printf("파크이용권\n");}
		if(time[i] == 1){printf("%s\t", "1Day");//원데이, 오후타임인지 
		} 
			else {printf("%s\t", "After4");}
	printf("X\t%d개\t",count[i]);//개수 인쇄 
	printf("%5d원\t", totalPrice[i]);//금액인쇄 

	//우대사항 문구 인쇄 
	if	(discount[i] == 1){//일반 
		printf("%20s\n","*우대적용없음");
	}
	if	(discount[i] == 2){//장애인 
		printf("%20s\n","*장애인우대적용");
	}
	if	(discount[i] == 3){//국가유공자 
		printf("%20s\n","*국가유공자우대적용");
	}
	if	(discount[i] == 4){//휴가장병 
		printf("%20s\n","*휴가장병우대적용");
		}
	if	(discount[i] == 5){//임산부 
		printf("%20s\n","*임산부우대적용");
		}	
	if	(discount[i] == 6){//다둥이 
		printf("%20s\n","*다둥이우대적용");
		
		}
		
	}
	printf("------------------------------------------------------\n");
		int sumTotal=0;
		for(int i=0; i<=index; i++){
	sumTotal+=totalPrice[i];
		}
		
	printf("%3d년%3d월%3d일\n", todayYear[index],todayMonth[index],todayDate[index]);
	printf("입장료 총액은 %4d원 입니다.\n", sumTotal);
	printf("======================================================\n");

	printf("계속 진행(1: 새로운 주문, 2: 프로그램 종료) :");
	scanf("%d", &continueOrder);
	if(continueOrder == 1){
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

