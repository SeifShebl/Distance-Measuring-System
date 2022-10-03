/*
 * ultrasonic.h
 *
 *  Created on: Mar 3, 2022
 *      Author: hends
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"

/*   FUNCTIONS PROTOTYPES   */

 void Ultrasonic_init(void);
 void Ultrasonic_Trigger(void);
 uint16 Ultrasonic_readDistance(void);
 void Ultrasonic_edgeProcessing(void);



#endif /* ULTRASONIC_H_ */
