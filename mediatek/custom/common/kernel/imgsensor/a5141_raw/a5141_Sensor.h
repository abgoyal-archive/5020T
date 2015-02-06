
#ifndef _A5141_SENSOR_H
#define _A5141_SENSOR_H

typedef enum group_enum {
    PRE_GAIN=0,
    CMMCLK_CURRENT,
    FRAME_RATE_LIMITATION,
    REGISTER_EDITOR,
    GROUP_TOTAL_NUMS
} FACTORY_GROUP_ENUM;


#define ENGINEER_START_ADDR 10
#define FACTORY_START_ADDR 0


typedef enum register_index
{
	SENSOR_BASEGAIN=FACTORY_START_ADDR,
	PRE_GAIN_R_INDEX,
	PRE_GAIN_Gr_INDEX,
	PRE_GAIN_Gb_INDEX,
	PRE_GAIN_B_INDEX,
	FACTORY_END_ADDR
} FACTORY_REGISTER_INDEX;

typedef enum engineer_index
{
    CMMCLK_CURRENT_INDEX=ENGINEER_START_ADDR,
    ENGINEER_END
} FACTORY_ENGINEER_INDEX;



typedef struct
{
    SENSOR_REG_STRUCT	Reg[ENGINEER_END];
    SENSOR_REG_STRUCT	CCT[FACTORY_END_ADDR];
} SENSOR_DATA_STRUCT, *PSENSOR_DATA_STRUCT;



#define CURRENT_MAIN_SENSOR                A5141_MICRON



#define A5141_WRITE_ID_1	0x20
#define A5141_READ_ID_1	0x21
#define A5141_WRITE_ID_2	0x30
#define A5141_READ_ID_2	0x31



#define A5141_IMAGE_SENSOR_FULL_HACTIVE		2592
#define A5141_IMAGE_SENSOR_FULL_VACTIVE		1944
#define A5141_IMAGE_SENSOR_PV_HACTIVE			1296
#define A5141_IMAGE_SENSOR_PV_VACTIVE			972

#define A5141_FULL_START_X					4
#define A5141_FULL_START_Y					2
#define A5141_IMAGE_SENSOR_FULL_WIDTH			(A5141_IMAGE_SENSOR_FULL_HACTIVE - 32)  //2592-32 2560
#define A5141_IMAGE_SENSOR_FULL_HEIGHT		(A5141_IMAGE_SENSOR_FULL_VACTIVE - 24)  //1944 -24 1920

#define A5141_PV_START_X						2
#define A5141_PV_START_Y						2
#define A5141_IMAGE_SENSOR_PV_WIDTH			(A5141_IMAGE_SENSOR_PV_HACTIVE - 16)	//1296 -16 1280
#define A5141_IMAGE_SENSOR_PV_HEIGHT			(A5141_IMAGE_SENSOR_PV_VACTIVE - 12)	//972 -12 960

#define	A5141_IMAGE_SENSOR_FULL_HBLANKING		200
#define A5141_IMAGE_SENSOR_FULL_VBLANKING		150
#define	A5141_IMAGE_SENSOR_PV_HBLANKING		279
#define A5141_IMAGE_SENSOR_PV_VBLANKING		128


#define A5141_PV_PERIOD_PIXEL_NUMS			0x095E		//0x095E=2398		
#define A5141_PV_PERIOD_LINE_NUMS			0x0419		//0x0419=1049
#define A5141_FULL_PERIOD_PIXEL_NUMS		0x0E70 //0x0AE8		//0x0AE8=2792		//0x0E70=3696
#define A5141_FULL_PERIOD_LINE_NUMS			0x07E5 //0x082E		//0x082E=2094	//0x07E5=2021

//#define A5141_FULL_PERIOD_PIXEL_NUMS_TEST		0x0E70 	//0x0AE8 	//0x0E70=3696
//#define A5141_FULL_PERIOD_LINE_NUMS_TEST		0x07E5 	//0x082E 	//0x07E5=2021


#define A5141_FRAME_RATE_UNIT		10
#define A5141_set_frame_rate(a) 	(a * A5141_FRAME_RATE_UNIT)
#define A5141_1X_ZOOM_IN_CAPTURE_FRAME	9

typedef enum
{
  A5141_MODE_PREVIEW,  
  A5141_MODE_VIDEO_AUTO,
  A5141_MODE_VIDEO_NIGHT,
  A5141_MODE_PV_END,
  A5141_MODE_CAPTURE,
  A5141_MODE_ZSD_PREVIEW,
  A5141_MODE_CAP_END
} A5141_MODE;

/* SENSOR PRIVATE STRUCT */
struct A5141_SENSOR_STRUCT
{
	kal_uint8 i2c_write_id;
	kal_uint8 i2c_read_id;
	kal_uint16 preview_vt_clk;
	kal_uint16 capture_vt_clk;
};

/* FRAME RATE */
#define A5141_FPS(x)                          ((kal_uint32)(10 * (x)))

#endif /* _A5141_SENSOR_H */
