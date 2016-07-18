  /*******************************************************************************************
程序名： 矩阵按键
编写人： 花花雪
编写时间： 2016 年 7月6 日
硬件支持：AT89S52 
接口说明：
修改日志：
NO.1
/*******************************************************************************************
//说明 ：矩阵按键控制LED灯亮灭
			
*******************************************************************************************/
  //[单片机常用SFR头文件]
  # include <REG52.h> 
 // [常用定义声明]
  # define uint unsigned int 
  # define uchar unsigned char
  sbit led1=P1^0;
  sbit led2=P1^1;
  sbit led3=P1^2;
  sbit led4=P1^3;
  sbit led5=P1^4;
  sbit led6=P1^5;
  sbit led7=P1^6;
  sbit led8=P1^7;
  /*******************************************************************************************
函数名：delay_ms
调  用：delay_ms(x)
参  数：uint x
返回值：无
结  果：
注  释：延时程序
*******************************************************************************************/
 void delay_ms(uint x)
  {
  		uint i,j;
		for(i=x;i>0;i--)
			for(j=110;j>0;j--);

  }
 /*******************************************************************************************
函数名：matrixscan
调  用：keyscan()
参  数：
返回值：无
结  果：
注  释：键盘扫描程序
*******************************************************************************************/
void matrixscan()
{
 	uchar temp;
	P0=0xfe;
	temp=P0;
	temp=temp&0xf0;
	if(temp!=0xf0) //判断第一行是否有键按下，低四位代表行，高四位代表列，若第一行有键被按下，高四位就会有一位被置零
	{
	 	delay_ms(10);//去抖
		temp=P0;
		temp=temp&0xf0;	//
		if(temp!=0xf0)
		{
		 	temp=P0;
			switch(temp)
			{
			 	case 0xee:	 //	 1110 1110 第一行 第一列
				led1=0;
				break;
				case 0xde:	 //	 1101 1110 第一行 第二列
				led2=0;
				break;
				case 0xbe:	 //	 1011 1110 第一行 第三列
				led3=0;
				break;
				case 0x7e:	 //	 0111 1110 第一行 第四列
				led4=0;
				break;
			}
			while(temp!=0xf0)
			{
				temp=P0;
				temp=temp&0xf0;	
			}
			P1=0xff;
		}

	
	}
	P0=0xfd;
	temp=P0;
	temp=temp&0xf0;
	if(temp!=0xf0) //判断第一行是否有键按下，低四位代表行，高四位代表列，若第二行有键被按下，高四位就会有一位被置零
	{
	 	delay_ms(10);//去抖
		temp=P0;
		temp=temp&0xf0;	//
		if(temp!=0xf0)
		{
		 	temp=P0;
			switch(temp)
			{
			 	case 0xed:	 //	 1110 1101 第二行 第一列
				led5=0;
				break;
				case 0xdd:	 //	 1101 1101 第二行 第二列
				led6=0;
				break;
				case 0xbd:	 //	 1011 1101 第二行 第三列
				led7=0;
				break;
				case 0x7d:	 //	 0111 1101第二行 第四列
				led8=0;
				break;
			}
			while(temp!=0xf0)
			{
				temp=P0;
				temp=temp&0xf0;	
			}
			P1=0xff;
		}
	}
    P0=0xfb;
	temp=P0;
	temp=temp&0xf0;
	if(temp!=0xf0) //判断第三行是否有键按下，低四位代表行，高四位代表列，若第三行有键被按下，高四位就会有一位被置零
	{
	 	delay_ms(10);//去抖
		temp=P0;
		temp=temp&0xf0;	//
		if(temp!=0xf0)
		{
		 	temp=P0;
			switch(temp)
			{
			 	case 0xeb:	 //	 1011 1011 第三行 第一列
				led1=0;
				break;
				case 0xdb:	 //	 1101 1011 第三行 第二列
				led2=0;
				break;
				case 0xbb:	 //	 1011 1011 第三行 第三列
				led3=0;
				break;
				case 0x7b:	 //	 0111 1011 第三行 第四列
				led4=0;
				break;
			}
			while(temp!=0xf0)
			{
				temp=P0;
				temp=temp&0xf0;	
			}
			P1=0xff;
		}
	}
 	P0=0xf7;
	temp=P0;
	temp=temp&0xf0;
	if(temp!=0xf0) //判断第四行是否有键按下，低四位代表行，高四位代表列，若第四行有键被按下，高四位就会有一位被置零
	{
	 	delay_ms(10);//去抖
		temp=P0;
		temp=temp&0xf0;	//
		if(temp!=0xf0)
		{
		 	temp=P0;
			switch(temp)
			{
			 	case 0xe7:	 //	 1110 0111 第四行 第一列
				led5=0;
				break;
				case 0xd7:	 //	 1101 0111 第四行 第二列
				led6=0;
				break;
				case 0xb7:	 //	 1011 0111 第四行 第三列
				led7=0;
				break;
				case 0x77:	 //	 0111 0111 第四行 第四列
				led8=0;
				break;
			}
			while(temp!=0xf0)
			{
				temp=P0;
				temp=temp&0xf0;	
			}
			P1=0xff;
		}
	}
}
/*******************************************************************************************
函数名：主函数
调  用：main()
参  数：
返回值：无
结  果：
注  释：
*******************************************************************************************/
void main()
{
	while(1)
	{
	 	matrixscan();
	}

}