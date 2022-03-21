#include<stdio.h>
#include<time.h>
#include<string.h>

int main()
{
	time_t timer;
	struct tm *t;
  	timer = time(NULL); // 현재 시각을 초 단위로 얻기
	
   	t = localtime(&timer); // 초 단위의 시간을 분리하여 구조체에 넣기

	int type, time, count, number;
	long long int id;
	while(1)
{
	do
	{
	printf("권종을 선택하세요\n");
	printf("1. 종합이용권(이용범위:롯데월드+민속박물관)\n2. 파크이용권(이용범위:롯데월드))\n");
	scanf("%d",&type);
		if ( !(type ==1 || type ==2)){
			printf("잘못 입력하였습니다.\n\n");
		}
	}
	while( !(type ==1 || type ==2));
	do
	{
	printf("이용시간을 선택하세요\n");
	printf("1.1DAY\n2.After4(오후4시부터 입장)\n");
	scanf("%d",&time);
		if ( !(time ==1 || time ==2)){
		printf("잘못 입력하였습니다.\n\n");
		}
	}
	while(!(time ==1 || time ==2));
	
	do
	{
	printf("주민번호를 입력하세요(6자리))\n");//주민번호 6자리 
	scanf("%d",&id); 
		if ( id >= 1000000){
		printf("잘못 입력하였습니다.\n\n");
		}
	}
	while ( id >= 1000000);
	
	printf("권종을 선택하세요\n");
	scanf("%d",&count);
	printf("우대사항을 선택하세요\n");
	printf("1.없음\n2.장애인\n3.국가유공자\n4.휴가장병\n5.임산부\n6.다자녀\n");
	scanf("%d",&number);		
//나이 파악 
	const int END_1 = 31, END_3 = 31, END_4 = 30, END_5 = 31, END_6 = 30, END_7 = 31, END_8 = 31;
	const int END_9 = 30, END_10= 31, END_11 = 30, END_12 = 31;
	int END_2=28;
	const int FREE=0, PRICE_LESS_3YEAR=15000;
	int birthYear, birthMonth, birthDate, globalBirth, priceEnter;
	float discountRate;
	
//생년월일로 자르기
	birthYear= (id/10000);
    birthMonth= (id-birthYear*10000)/100;
    birthDate=id-birthYear*10000-birthMonth*100;
    
//기준시간 (현재시간) 
	int tm_year;//todayYear
	int tm_mon;//
	int tm_mday;//
	
	int todayYear =t->tm_year + 1900;
	int todayMonth=t->tm_mon + 1;
	int todayDate= t->tm_mday;
// 만나이계산 
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
		globalBirth= (birthYear+2000)*365 + days + birthDate;//태어나서 현재까지  날짜(2000년생이하) 
		}
	else
		{
		globalBirth= (birthYear+1900)*365 + days + birthDate;//태어나서 현재까지  날짜(2000년생이상) 
		}	
	int totalDate= todayYear*365+tdays+todayDate; //현재까지 날짜 
	int globalAge=(totalDate-globalBirth)/365;//현재까지 날짜-내가태어난날짜=만나이 
	//나이별 가격 책정하기		
	
	//나에 따른 티켓 가격 결정	
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
	//할인율 적용하기//
 	int totalPrice;
	if
	(number == 1){//일반인 
		discountRate= 1;
		totalPrice= priceEnter*discountRate*count;	
	}
	if
	(number == 2){//장애인 
		discountRate= 0.5;
		totalPrice= priceEnter*discountRate*count;
		if(count >= 2){
			totalPrice=(priceEnter*2*discountRate)+(priceEnter*(count-2));}
			}
	if
	(number == 3){//국가유공자 
		discountRate=0.5;
		totalPrice= priceEnter*discountRate*count;
		if(count >= 2){
		totalPrice= (priceEnter*2*discountRate)+(priceEnter*(count-2));}
		}
	
	if
	(number == 4){//휴가장병 
		discountRate=0.51;
		totalPrice= priceEnter*discountRate*1+priceEnter*(count-1);
		}
	if
	(number == 5){//임산부 
		discountRate=0.5;
		totalPrice= priceEnter*discountRate*1+priceEnter*(count-1);
		}
	if
	(number == 6){//다둥이 
		discountRate= 0.7;
		totalPrice= priceEnter*discountRate*count;}	 
	
printf("만나이 %d살,가격은 %d원입니다.\n감사합니다.\n\n",globalAge, totalPrice);
}

return 0;
}

