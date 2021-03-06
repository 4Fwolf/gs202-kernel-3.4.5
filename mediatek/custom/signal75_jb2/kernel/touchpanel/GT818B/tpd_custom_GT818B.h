#ifndef TOUCHPANEL_H__
#define TOUCHPANEL_H__

#ifndef MT6575
#define MT6575
#endif

#define TPD_TYPE_CAPACITIVE
#define TPD_TYPE_RESISTIVE
#define TPD_POWER_SOURCE         MT6575_POWER_VGP2
#define TPD_I2C_NUMBER           0
#define TPD_WAKEUP_TRIAL         60
#define TPD_WAKEUP_DELAY         100

#define TPD_DELAY                (2*HZ/100)
#define TPD_CALIBRATION_MATRIX   {962,0,0,0, 1600,0,0,0};
#define TPD_HAVE_CALIBRATION
#define TPD_HAVE_TREMBLE_ELIMINATION

#define TPD_NO_GPIO
#define TPD_RESET_PIN_ADDR       (PERICFG_BASE + 0xC000)
//#define TPD_DITO_SENSOR
#define TPD_CONDITION_SWITCH
#define TPD_RESET_ISSUE_WORKAROUND
#define TPD_X_RES                (480)
#define TPD_Y_RES                (800)
#define TPD_WARP_X(x) ( x )
#define TPD_WARP_Y(y) ( y )
#define TPD_BUTTON_HEIGHT        (480)

// lower key on phone
#define TPD_HAVE_BUTTON
#define HAVE_TOUCH_KEY
#define TPD_KEY_COUNT            (4)

#define TPD_KEYS                 {KEY_MENU,       KEY_HOMEPAGE,    KEY_BACK,        KEY_SEARCH}
#define TPD_KEYS_DIM             {{20,830,54,32}, {210,830,54,32}, {430,830,54,32}, {480, 840, 0,0}}
//                               key_0             key_1            key_2           key_3(not found, not use)

#define TPD_MAX_RESET_COUNT      TPD_KEY_COUNT

#ifdef TPD_DITO_SENSOR

static u8 cfg_data_version_d[] =
{
0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,
0x10,0x12,0x80,0x00,0x90,0x00,0xA0,0x00,
0xB0,0x00,0xC0,0x00,0xD0,0x00,0xE0,0x00,
0xF0,0x00,0x00,0x00,0x10,0x00,0x20,0x00,
0x30,0x00,0x40,0x00,0x50,0x00,0x60,0x00,
0x70,0x00,0x07,0x03,0x10,0x10,0x10,0x38,
0x38,0x38,0x10,0x0F,0x0A,0x40,0x30,0x0F,
0x03,0x00,0x05,0xE0,0x01,0x34,0x03,0x00,
0x00,0x5B,0x4F,0x55,0x4A,0x00,0x00,0x25,
0x14,0x05,0x08,0x00,0x00,0x00,0x00,0x00,
0x14,0x10,0x8E,0x03,0x00,0x00,0x00,0x00,
0x00,0x00,0x1C,0x57,0x93,0x00,0x0B,0x45,
0x35,0x3C,0x28,0x00,0x00,0x00,0x00,0x00,
0x00,0x01
};

static u8 cfg_data_with_charger_version_d[] =
{
0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,
0x10,0x12,0x80,0x00,0x90,0x00,0xA0,0x00,
0xB0,0x00,0xC0,0x00,0xD0,0x00,0xE0,0x00,
0xF0,0x00,0x00,0x00,0x10,0x00,0x20,0x00,
0x30,0x00,0x40,0x00,0x50,0x00,0x60,0x00,
0x70,0x00,0x07,0x03,0x10,0x10,0x10,0x38,
0x38,0x38,0x10,0x0F,0x0A,0x40,0x30,0x0F,
0x03,0x00,0x05,0xE0,0x01,0x34,0x03,0x00,
0x00,0x5B,0x4F,0x55,0x4A,0x00,0x00,0x25,
0x14,0x05,0x08,0x00,0x00,0x00,0x00,0x00,
0x14,0x10,0x8E,0x03,0x00,0x00,0x00,0x00,
0x00,0x00,0x1C,0x57,0x93,0x00,0x0B,0x45,
0x35,0x3C,0x28,0x00,0x00,0x00,0x00,0x00,
0x00,0x01
};

static u8 cfg_data_version_b[] =
{
0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,
0x10,0x12,0x80,0x00,0x90,0x00,0xA0,0x00,
0xB0,0x00,0xC0,0x00,0xD0,0x00,0xE0,0x00,
0xF0,0x00,0x00,0x00,0x10,0x00,0x20,0x00,
0x30,0x00,0x40,0x00,0x50,0x00,0x60,0x00,
0x70,0x00,0x07,0x03,0x10,0x10,0x10,0x38,
0x38,0x38,0x10,0x0F,0x0A,0x40,0x30,0x0F,
0x03,0x00,0x05,0xE0,0x01,0x34,0x03,0x00,
0x00,0x5B,0x4F,0x55,0x4A,0x00,0x00,0x25,
0x14,0x05,0x08,0x00,0x00,0x00,0x00,0x00,
0x14,0x10,0x8E,0x03,0x00,0x00,0x00,0x00,
0x00,0x00,0x1C,0x57,0x93,0x00,0x0B,0x45,
0x35,0x3C,0x28,0x00,0x00,0x00,0x00,0x00,
0x00,0x01
};

static u8 cfg_data_with_charger_version_b[] =
{
0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,
0x10,0x12,0x80,0x00,0x90,0x00,0xA0,0x00,
0xB0,0x00,0xC0,0x00,0xD0,0x00,0xE0,0x00,
0xF0,0x00,0x00,0x00,0x10,0x00,0x20,0x00,
0x30,0x00,0x40,0x00,0x50,0x00,0x60,0x00,
0x70,0x00,0x07,0x03,0x10,0x10,0x10,0x38,
0x38,0x38,0x10,0x0F,0x0A,0x40,0x30,0x0F,
0x03,0x00,0x05,0xE0,0x01,0x34,0x03,0x00,
0x00,0x5B,0x4F,0x55,0x4A,0x00,0x00,0x25,
0x14,0x05,0x08,0x00,0x00,0x00,0x00,0x00,
0x14,0x10,0x8E,0x03,0x00,0x00,0x00,0x00,
0x00,0x00,0x1C,0x57,0x93,0x00,0x0B,0x45,
0x35,0x3C,0x28,0x00,0x00,0x00,0x00,0x00,
0x00,0x01
};

#else  // SITO

static u8 cfg_data_version_b[] =
{
0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,
0x10,0x12,0x80,0x00,0x90,0x00,0xA0,0x00,
0xB0,0x00,0xC0,0x00,0xD0,0x00,0xE0,0x00,
0xF0,0x00,0x00,0x00,0x10,0x00,0x20,0x00,
0x30,0x00,0x40,0x00,0x50,0x00,0x60,0x00,
0x70,0x00,0x07,0x03,0x10,0x10,0x10,0x38,
0x38,0x38,0x10,0x0F,0x0A,0x40,0x30,0x0F,
0x03,0x00,0x05,0xE0,0x01,0x34,0x03,0x00,
0x00,0x5B,0x4F,0x55,0x4A,0x00,0x00,0x25,
0x14,0x05,0x08,0x00,0x00,0x00,0x00,0x00,
0x14,0x10,0x8E,0x03,0x00,0x00,0x00,0x00,
0x00,0x00,0x1C,0x57,0x93,0x00,0x0B,0x45,
0x35,0x3C,0x28,0x00,0x00,0x00,0x00,0x00,
0x00,0x01
};

static u8 cfg_data_with_charger_version_b[] =
{
0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,
0x10,0x12,0x80,0x00,0x90,0x00,0xA0,0x00,
0xB0,0x00,0xC0,0x00,0xD0,0x00,0xE0,0x00,
0xF0,0x00,0x00,0x00,0x10,0x00,0x20,0x00,
0x30,0x00,0x40,0x00,0x50,0x00,0x60,0x00,
0x70,0x00,0x07,0x03,0x10,0x10,0x10,0x38,
0x38,0x38,0x10,0x0F,0x0A,0x40,0x30,0x0F,
0x03,0x00,0x05,0xE0,0x01,0x34,0x03,0x00,
0x00,0x5B,0x4F,0x55,0x4A,0x00,0x00,0x25,
0x14,0x05,0x08,0x00,0x00,0x00,0x00,0x00,
0x14,0x10,0x8E,0x03,0x00,0x00,0x00,0x00,
0x00,0x00,0x1C,0x57,0x93,0x00,0x0B,0x45,
0x35,0x3C,0x28,0x00,0x00,0x00,0x00,0x00,
0x00,0x01
};

#endif
#endif /* TOUCHPANEL_H__ */
