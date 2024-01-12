/* 7-seg LED driver routines and defines */

/* Defines To Be Changed According To The Current Schematic */

// Comment following line if common cathode (non inverted), and uncomment if common cathode (inverted).
//#define LED_INVERT 1

// Digits positions

#ifndef LED_SEG_POS_A

#define LED_SEG_POS_A   0
#define LED_SEG_POS_B   1
#define LED_SEG_POS_C   2
#define LED_SEG_POS_D   3
#define LED_SEG_POS_E   4
#define LED_SEG_POS_F   5
#define LED_SEG_POS_G   6
#define LED_SEG_POS_H   7

#endif

/* Non-changeable Defines */

#ifndef LED_INVERT
#define LED_INVERT 0
#endif

#if LED_INVERT
#define LED_OPER	   &
#define LED_INV            ~
#define LED_INIT_VAL       0xFF
#define LED_SEG_VAL(seg_pos)  (0xFF & ~(1 << seg_pos))
#else
#define LED_OPER	   |
#define LED_INV
#define LED_INIT_VAL       0x00
#define LED_SEG_VAL(seg_pos)  (1 << seg_pos)
#endif


#define LED_SEG_A	LED_SEG_VAL(LED_SEG_POS_A)
#define LED_SEG_B	LED_SEG_VAL(LED_SEG_POS_B)
#define LED_SEG_C	LED_SEG_VAL(LED_SEG_POS_C)
#define LED_SEG_D	LED_SEG_VAL(LED_SEG_POS_D)
#define LED_SEG_E	LED_SEG_VAL(LED_SEG_POS_E)
#define LED_SEG_F	LED_SEG_VAL(LED_SEG_POS_F)
#define LED_SEG_G	LED_SEG_VAL(LED_SEG_POS_G)
#define LED_SEG_H	LED_SEG_VAL(LED_SEG_POS_H)

/* Output bytes for diffirent numbers */

#define LED_SIGN_0	(LED_INIT_VAL LED_OPER LED_SEG_A LED_OPER LED_SEG_B LED_OPER LED_SEG_C LED_OPER LED_SEG_D LED_OPER LED_SEG_E LED_OPER LED_SEG_F)
#define LED_SIGN_1	(LED_INIT_VAL LED_OPER LED_SEG_B LED_OPER LED_SEG_C)
#define LED_SIGN_2	(LED_INIT_VAL LED_OPER LED_SEG_A LED_OPER LED_SEG_B LED_OPER LED_SEG_D LED_OPER LED_SEG_E LED_OPER LED_SEG_G)
#define LED_SIGN_3	(LED_INIT_VAL LED_OPER LED_SEG_A LED_OPER LED_SEG_B LED_OPER LED_SEG_C LED_OPER LED_SEG_D LED_OPER LED_SEG_G)
#define LED_SIGN_4	(LED_INIT_VAL LED_OPER LED_SEG_B LED_OPER LED_SEG_C LED_OPER LED_SEG_F LED_OPER LED_SEG_G)
#define LED_SIGN_5	(LED_INIT_VAL LED_OPER LED_SEG_A LED_OPER LED_SEG_C LED_OPER LED_SEG_D LED_OPER LED_SEG_F LED_OPER LED_SEG_G)
#define LED_SIGN_6	(LED_INIT_VAL LED_OPER LED_SEG_A LED_OPER LED_SEG_C LED_OPER LED_SEG_D LED_OPER LED_SEG_E LED_OPER LED_SEG_F LED_OPER LED_SEG_G)
#define LED_SIGN_7	(LED_INIT_VAL LED_OPER LED_SEG_A LED_OPER LED_SEG_B LED_OPER LED_SEG_C)
#define LED_SIGN_8	(LED_INIT_VAL LED_OPER LED_SEG_A LED_OPER LED_SEG_B LED_OPER LED_SEG_C LED_OPER LED_SEG_D LED_OPER LED_SEG_E LED_OPER LED_SEG_F LED_OPER LED_SEG_G)
#define LED_SIGN_9	(LED_INIT_VAL LED_OPER LED_SEG_A LED_OPER LED_SEG_B LED_OPER LED_SEG_C LED_OPER LED_SEG_D LED_OPER LED_SEG_F LED_OPER LED_SEG_G)
#define LED_SIGN_A	(LED_INIT_VAL LED_OPER LED_SEG_A LED_OPER LED_SEG_B LED_OPER LED_SEG_C LED_OPER LED_SEG_E LED_OPER LED_SEG_F LED_OPER LED_SEG_G)
#define LED_SIGN_B	(LED_INIT_VAL LED_OPER LED_SEG_C LED_OPER LED_SEG_D LED_OPER LED_SEG_E LED_OPER LED_SEG_F LED_OPER LED_SEG_G)
#define LED_SIGN_C	(LED_INIT_VAL LED_OPER LED_SEG_A LED_OPER LED_SEG_D LED_OPER LED_SEG_E LED_OPER LED_SEG_F)
#define LED_SIGN_D	(LED_INIT_VAL LED_OPER LED_SEG_B LED_OPER LED_SEG_C LED_OPER LED_SEG_D LED_OPER LED_SEG_E LED_OPER LED_SEG_G)
#define LED_SIGN_E	(LED_INIT_VAL LED_OPER LED_SEG_A LED_OPER LED_SEG_D LED_OPER LED_SEG_E LED_OPER LED_SEG_F LED_OPER LED_SEG_G)
#define LED_SIGN_F	(LED_INIT_VAL LED_OPER LED_SEG_A LED_OPER LED_SEG_E LED_OPER LED_SEG_F LED_OPER LED_SEG_G)

/* Encode one digit number into the output byte */

#define LED_ENCODE(value)  \
 (value & 0x08)?           \
    ((value & 0x04)?       \
       ((value & 0x02)?    \
          ((value & 0x01)? \
             (LED_SIGN_F): \
             (LED_SIGN_E)  \
          ):               \
          ((value & 0x01)? \
             (LED_SIGN_D): \
             (LED_SIGN_C)  \
          )                \
       ):                  \
       ((value & 0x02)?    \
          ((value & 0x01)? \
             (LED_SIGN_B): \
             (LED_SIGN_A)  \
          ):               \
          ((value & 0x01)? \
             (LED_SIGN_9): \
             (LED_SIGN_8)  \
          )                \
       )                   \
    ):                     \
    ((value & 0x04)?       \
       ((value & 0x02)?    \
          ((value & 0x01)? \
             (LED_SIGN_7): \
             (LED_SIGN_6)  \
          ):               \
          ((value & 0x01)? \
             (LED_SIGN_5): \
             (LED_SIGN_4)  \
          )                \
       ):                  \
       ((value & 0x02)?    \
          ((value & 0x01)? \
             (LED_SIGN_3): \
             (LED_SIGN_2)  \
          ):               \
          ((value & 0x01)? \
             (LED_SIGN_1): \
             (LED_SIGN_0)  \
          )                \
       )                   \
    )
