/* 
 * File:   sender.h
 * Author: Dan
 *
 * Created on May 3, 2020, 9:31 PM
 */

#ifndef SENDER_H
#define	SENDER_H

#ifdef	__cplusplus
extern "C" {
#endif

void pwm_out();
void high_bit();
void low_bit();
void send_reader();
void send_data(uint8_t *data, uint8_t size);
void send_data_ch(char *data, uint8_t size);


#ifdef	__cplusplus
}
#endif

#endif	/* SENDER_H */

