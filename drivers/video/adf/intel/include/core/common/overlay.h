/*
 * overlay.h
 *
 *  Created on: Jul 9, 2014
 *      Author: root
 */

#ifndef OVERLAY_H_
#define OVERLAY_H_

/*Polyphase filter coefficients*/
#define N_HORIZ_Y_TAPS			5
#define N_VERT_Y_TAPS			3
#define N_HORIZ_UV_TAPS			3
#define N_VERT_UV_TAPS			3
#define N_PHASES			17
#define MAX_TAPS			5

/*Filter cutoff frequency limits*/
#define MIN_CUTOFF_FREQ			1.0
#define MAX_CUTOFF_FREQ			3.0

/*Overlay init micros*/
#define OVERLAY_INIT_CONTRAST		0x4b
#define OVERLAY_INIT_BRIGHTNESS		-19
#define OVERLAY_INIT_SATURATION		0x92
#define OVERLAY_INIT_GAMMA0		0x080808
#define OVERLAY_INIT_GAMMA1		0x101010
#define OVERLAY_INIT_GAMMA2		0x202020
#define OVERLAY_INIT_GAMMA3		0x404040
#define OVERLAY_INIT_GAMMA4		0x808080
#define OVERLAY_INIT_GAMMA5		0xc0c0c0
#define OVERLAY_INIT_COLORKEY		0
#define OVERLAY_INIT_COLORKEYMASK	((0x0 << 31) | (0X0 << 30))
#define OVERLAY_INIT_CONFIG		((0x1 << 18) | (0x1 << 3))

/*overlay register values*/
#define OVERLAY_FORMAT_MASK		(0xf << 10)
#define OVERLAY_FORMAT_PACKED_YUV422	(0x8 << 10)
#define OVERLAY_FORMAT_PLANAR_NV12_1	(0x7 << 10)
#define OVERLAY_FORMAT_PLANAR_NV12_2	(0xb << 10)
#define OVERLAY_FORMAT_PLANAR_YUV420	(0xc << 10)
#define OVERLAY_FORMAT_PLANAR_YUV422	(0xd << 10)
#define OVERLAY_FORMAT_PLANAR_YUV41X	(0xe << 10)

#define OVERLAY_PACKED_ORDER_YUYV	(0x0 << 14)
#define OVERLAY_PACKED_ORDER_YVYU	(0x1 << 14)
#define OVERLAY_PACKED_ORDER_UYVY	(0x2 << 14)
#define OVERLAY_PACKED_ORDER_VYUY	(0x3 << 14)
#define OVERLAY_PACKED_ORDER_MASK	(0x3 << 14)

#define OVERLAY_MEMORY_LAYOUT_TILED	(0x1 << 19)
#define OVERLAY_MEMORY_LAYOUT_LINEAR	(0x0 << 19)

#define OVERLAY_MIRRORING_NORMAL	(0x0 << 17)
#define OVERLAY_MIRRORING_HORIZONTAL	(0x1 << 17)
#define OVERLAY_MIRRORING_VERTIACAL	(0x2 << 17)
#define OVERLAY_MIRRORING_BOTH		(0x3 << 17)

#define BUF_TYPE			(0x1<<5)
#define BUF_TYPE_FRAME			(0x0<<5)
#define BUF_TYPE_FIELD			(0x1<<5)
#define TEST_MODE			(0x1<<4)
#define BUFFER_SELECT			(0x3<<2)
#define BUFFER0				(0x0<<2)
#define BUFFER1				(0x1<<2)
#define FIELD_SELECT			(0x1<<1)
#define FIELD0				(0x0<<1)
#define FIELD1				(0x1<<1)
#define OVERLAY_ENABLE			0x1

struct overlay_back_buffer {
	u32 OBUF_0Y;
	u32 OBUF_1Y;
	u32 OBUF_0U;
	u32 OBUF_0V;
	u32 OBUF_1U;
	u32 OBUF_1V;
	u32 OSTRIDE;
	u32 YRGB_VPH;
	u32 UV_VPH;
	u32 HORZ_PH;
	u32 INIT_PHS;
	u32 DWINPOS;
	u32 DWINSZ;
	u32 SWIDTH;
	u32 SWIDTHSW;
	u32 SHEIGHT;
	u32 YRGBSCALE;
	u32 UVSCALE;
	u32 OCLRC0;
	u32 OCLRC1;
	u32 DCLRKV;
	u32 DCLRKM;
	u32 SCHRKVH;
	u32 SCHRKVL;
	u32 SCHRKEN;
	u32 OCONFIG;
	u32 OCMD;
	u32 RESERVED1;
	u32 OSTART_0Y;
	u32 OSTART_1Y;
	u32 OSTART_0U;
	u32 OSTART_0V;
	u32 OSTART_1U;
	u32 OSTART_1V;
	u32 OTILEOFF_0Y;
	u32 OTILEOFF_1Y;
	u32 OTILEOFF_0U;
	u32 OTILEOFF_0V;
	u32 OTILEOFF_1U;
	u32 OTILEOFF_1V;
	u32 FASTHSCALE;
	u32 UVSCALEV;

	u32 RESERVEDC[(0x200 - 0xA8) / 4];
	u16 Y_VCOEFS[N_VERT_Y_TAPS * N_PHASES];
	u16 RESERVEDD[0x100 / 2 - N_VERT_Y_TAPS * N_PHASES];
	u16 Y_HCOEFS[N_HORIZ_Y_TAPS * N_PHASES];
	u16 RESERVEDE[0x200 / 2 - N_HORIZ_Y_TAPS * N_PHASES];
	u16 UV_VCOEFS[N_VERT_UV_TAPS * N_PHASES];
	u16 RESERVEDF[0x100 / 2 - N_VERT_UV_TAPS * N_PHASES];
	u16 UV_HCOEFS[N_HORIZ_UV_TAPS * N_PHASES];
	u16 RESERVEDG[0x100 / 2 - N_HORIZ_UV_TAPS * N_PHASES];
};

typedef struct {
	u8 sign;
	u16 mantissa;
	u8 exponent;
} coeffRec, *coeffPtr;

#endif /* OVERLAY_H_ */
