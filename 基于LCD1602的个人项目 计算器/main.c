#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Matrix.h"
unsigned int KeyNum;
unsigned int _1602Num;
unsigned int _1602wei;
unsigned int Date;
unsigned int Yunsuan1=0;
unsigned int Yunsuan2=1;
void main(){
	LCD_Init();
	
	while (1){
		//KeyNum的获取及译码
		
		KeyNum = Matrix();
		if (KeyNum){
			if(KeyNum==1){
				_1602Num= 1;
				_1602wei++;
				Date*=10;
				Date+=_1602Num%10;
			}
			if(KeyNum==2){
				_1602Num= 2;
				_1602wei++;
				Date*=10;
				Date+=_1602Num%10;
			}
			if(KeyNum==3){
				_1602Num= 3;
				_1602wei++;
				Date*=10;
				Date+=_1602Num%10;
			}
			if(KeyNum==5){
				_1602Num= 4;
				_1602wei++;
				Date*=10;
				Date+=_1602Num%10;
			}
			if(KeyNum==6){
				_1602Num=5;
				_1602wei++;
				Date*=10;
				Date+=_1602Num%10;
			}
			if(KeyNum==7){
				_1602Num=6;
				_1602wei++;
				Date*=10;
				Date+=_1602Num%10;
			}
			if(KeyNum==9){
				_1602Num = 7;
				_1602wei++;
				Date*=10;
				Date+=_1602Num%10;
			}
			if(KeyNum==10){
				_1602Num = 8;
				_1602wei++;
				Date*=10;
				Date+=_1602Num%10;
			}
			if(KeyNum==11){
				_1602Num = 9;
				_1602wei++;
				Date*=10;
				Date+=_1602Num%10;
			}
			if(KeyNum==14){
				_1602Num = 0;
				_1602wei++;
				Date*=10;
				Date+=_1602Num%10;
			}
			if(KeyNum==4){
				LCD_ShowChar(1,1,'+');
				LCD_ShowNum(1,3,Yunsuan2,6);
				Yunsuan1=Date;
				Yunsuan2=Yunsuan1+Yunsuan2;
				Delay(20);
				Date=0;
				_1602wei=0;
				LCD_ShowString(2,1,"                ");//提醒：这句代码不能放在这里
			}
			if(KeyNum==8){
				LCD_ShowChar(1,1,'-');
				LCD_ShowNum(1,3,Yunsuan2,6);
				Yunsuan1=Date;
				Yunsuan2=Yunsuan1-Yunsuan2;
				Date=0;
				_1602wei=0;
				LCD_ShowString(2,1,"                ");
			}
			if(KeyNum==12){
				LCD_ShowChar(1,1,'*');
				Yunsuan1=Date;
				Yunsuan2*=Yunsuan1;
				LCD_ShowNum(1,3,Yunsuan2,6);
				Date=0;
				_1602wei=0;
				LCD_ShowString(2,1,"                ");
			}
			if(KeyNum==16){
				LCD_ShowChar(1,1,'/');
				Yunsuan1=Date;
				Yunsuan2=Yunsuan2/Yunsuan1;
				LCD_ShowNum(1,3,Yunsuan2,6);
				Date=0;
				_1602wei=0;
				LCD_ShowString(2,1,"                ");
			}
			if(KeyNum==15){
				LCD_ShowChar(1,1,'=');
				Date=0;
				LCD_ShowNum(2,1,Yunsuan2,6);
			}
			if(Date==8007){
				LCD_ShowString(1,1,"Y");
			
			}
			if(Yunsuan2==2333){
				LCD_ShowString(1,1,"S");
			}
			LCD_ShowNum(2,_1602wei,_1602Num,1	);
		}
		
		
	}

	
}

