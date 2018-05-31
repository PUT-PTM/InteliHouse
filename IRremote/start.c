#include "main.h"


void init_USB()
{
	USBD_Init(&USB_OTG_dev,
	            USB_OTG_FS_CORE_ID,
	            &USR_desc,
	            &USBD_CDC_cb,
	            &USR_cb);

	return;
}
void TIMER_init(uint16_t a){

 	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
 	TIM_TimeBaseInitTypeDef str;
 	str.TIM_Period = 2099;
 	str.TIM_Prescaler = a;
 	str.TIM_ClockDivision = TIM_CKD_DIV1;

 	str.TIM_CounterMode=TIM_CounterMode_Up;
 	TIM_TimeBaseInit(TIM3,&str);
 	TIM_Cmd(TIM3, ENABLE);
 	NVIC_InitTypeDef str;
 	str.NVIC_IRQChannel = TIM3_IRQn ;
 	str.NVIC_IRQChannelPreemptionPriority = 0x00;
 	str.NVIC_IRQChannelSubPriority = 0x00;
 	str.NVIC_IRQChannelCmd = ENABLE ;
 	NVIC_Init(&str);
 	TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
 	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE );
}
int global =0;
void TIM3_IRQHandler(void)
 {
 	if(TIM_GetITStatus(TIM3,TIM_IT_Update) != RESET)
	{
 				    if(UB_IRMP_Read(&myIRData)==TRUE) {

 				    	global=global+1;
 				      if(myIRData.address==65280) {
 							if(myIRData.command==8)
 									LED_GREEN_ON;
 							if(myIRData.command==24)
 									LED_ORANGE_ON;
 							if(myIRData.command==90)
 									LED_RED_ON;
 							if(myIRData.command==82)
 									LED_BLUE_ON;
 							if(myIRData.command==28)
 									ALL_OFF;

 				      }
 		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
 	}

}}

