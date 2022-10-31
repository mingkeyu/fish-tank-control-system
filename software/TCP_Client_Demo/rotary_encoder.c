#include "rotary_encoder.h"
#define PICO_ECA_PIN 10
#define PICO_ECB_PIN 11
#define PICO_ECD_PIN 12

const uint ECA_PIN = PICO_ECA_PIN;
const uint ECB_PIN = PICO_ECB_PIN;
const uint ECD_PIN = PICO_ECD_PIN;
 
#define EC11_PHB_LEVEL  gpio_get(ECB_PIN)
#define EC11_PHA_LEVEL  gpio_get(ECA_PIN)
#define EC11_TAG_LEVEL  gpio_get(ECD_PIN)//按键

#define TAG_KEY_ACTION      (0x01)
#define LEFT_KEY_ACTION     (0x02)
#define RIGHT_KEY_ACTION    (0x03)
#define QUIT_KEY_ACTION     (0x04)
#pragma pack(1)
//旋转编码器信息
typedef struct
{
    unsigned char a_last;      //A相上一次状态
    unsigned char b_last;      //B相上一次的状态
    unsigned char type;        //类型，0：一定位一脉冲，1：两定位一脉冲
}ec11_info_t;
#pragma pack()

static ec11_info_t ec11;

//按键初始化函数
void key_scan_init(void) //IO初始化
{
    gpio_init(ECA_PIN);
    gpio_set_dir(ECA_PIN, GPIO_IN);

    gpio_init(ECB_PIN);
    gpio_set_dir(ECB_PIN, GPIO_IN);

    gpio_init(ECD_PIN);
    gpio_set_dir(ECD_PIN, GPIO_IN);
}

/*
*\读取旋转编码器按键动作
*\return:键值
*/
static unsigned char ec11_tag_scan(void)
{
	static unsigned int key_tag = 0x01,press_cnt = 0;
	unsigned char key = 0,tag = 0;
	
	key = EC11_TAG_LEVEL;
	if(!key)
	{
		if(key_tag != key)
		{
				key_tag = key;
				press_cnt = 0;
		}
		press_cnt++;
		if(press_cnt >= 200)
				press_cnt = 201;
	}    
	else
	{
		if(press_cnt >= 2)
				tag = TAG_KEY_ACTION;
		press_cnt = 0;
		key_tag = 0x01;
	}

	return tag;
}

/*
*\一定位一脉冲类型旋转编码器解析
*/
static unsigned char ec11_single_scan(void)
{
	unsigned char result = 0;
	
	if(EC11_PHA_LEVEL != ec11.a_last)
	{
		if(EC11_PHA_LEVEL == 0)
		{
			if(EC11_PHB_LEVEL != 0)
				result = LEFT_KEY_ACTION;
			else
				result = RIGHT_KEY_ACTION;
		}
		ec11.a_last = EC11_PHA_LEVEL;
		ec11.b_last = EC11_PHB_LEVEL;
	}
	
	return result;
}

/*
*\两定位一脉冲类型旋转编码器计息
*/
static unsigned char ec11_double_scan(void)
{
	unsigned char result = 0;
	
	if(EC11_PHA_LEVEL != ec11.a_last)
	{
		if(EC11_PHA_LEVEL != 0)
		{
			if((ec11.b_last != 0)&&(EC11_PHB_LEVEL == 0))
					result = LEFT_KEY_ACTION;
			if((ec11.b_last == 0)&&(EC11_PHB_LEVEL != 0))
					result = RIGHT_KEY_ACTION;
			if((ec11.b_last == EC11_PHB_LEVEL)&&(EC11_PHB_LEVEL == 0))
					result = LEFT_KEY_ACTION;
			
			if((ec11.b_last == EC11_PHB_LEVEL)&&(EC11_PHB_LEVEL != 0))
					result = RIGHT_KEY_ACTION;
		}
		else
		{
			if((ec11.b_last != 0)&&(EC11_PHB_LEVEL == 0))
					result = RIGHT_KEY_ACTION;
			if((ec11.b_last == 0)&&(EC11_PHB_LEVEL != 0))
					result = LEFT_KEY_ACTION;
			
			if((ec11.b_last == EC11_PHB_LEVEL)&&(EC11_PHB_LEVEL == 0))
					result = RIGHT_KEY_ACTION;
			
			if((ec11.b_last == EC11_PHB_LEVEL)&&(EC11_PHB_LEVEL != 0))
					result = LEFT_KEY_ACTION;
		}        
		ec11.a_last = EC11_PHA_LEVEL;
		ec11.b_last = EC11_PHB_LEVEL;
	}

	return result;
}

/*
*\旋转编码器动作解析
*/
unsigned char ec11_action_analysis(void)
{
	unsigned char result = 0;
	
	if(ec11.type == 0)
	{
		result = ec11_single_scan();
		if(result != 0)
			return result;
	}
	else
	{
		result = ec11_double_scan();
		if(result != 0)
			return result;
	}
	result = ec11_tag_scan();
	return result;
}


