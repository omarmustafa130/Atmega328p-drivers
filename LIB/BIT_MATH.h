/*
 * BIT_MATH.h
 *
 * Created: 9/15/2021 9:11:18 PM
 *  Author: The Warlock & Omar
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define  SET_BIT(VAR,BIT_NUM)	VAR |=(1<<(BIT_NUM))
#define  CLR_BIT(VAR,BIT_NUM)	VAR &= ~(1<<(BIT_NUM))
#define	 TOG_BIT(VAR,BIT_NUM)	VAR ^= (1<<(BIT_NUM))
#define	 GET_BIT(VAR,BIT_NUM)	((VAR>>(BIT_NUM))&1)

#define CLR_REG(VAR)			VAR = 0
#define SET_REG(VAR)			VAR = 255

#endif /* BIT_MATH_H_ */