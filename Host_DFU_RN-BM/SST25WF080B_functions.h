/* 
 * File:   SST25WF080B_functions.h
 * Author: C03009
 *
 * Created on January 26, 2017, 9:55 AM
 */

#ifndef SST25WF080B_FUNCTIONS_H
#define	SST25WF080B_FUNCTIONS_H

unsigned char Read_Status_Register();

void WRSR(char byte);
void WREN();
void PD();
void EPD();
void WRDI();
unsigned char Read_ID(char ID_addr);
void Jedec_ID_Read(int *Manufacturer_Id, int *Device_Type, int *Device_Id);
unsigned char Read(unsigned long Dst); 
void Read_Cont(unsigned long Dst,unsigned long no_bytes, unsigned int *read_data);
unsigned char HighSpeed_Read(unsigned long Dst); 
void HighSpeed_Read_Cont(unsigned long Dst,unsigned long no_bytes, unsigned int *read_data);
void Page_Program(unsigned long Dst, unsigned int *Prog_data);
void Chip_Erase();
void Small_Sector_Erase(unsigned long Dst);
void Sector_Erase(unsigned long Dst);
void Wait_Busy();



#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* SST25WF080B_FUNCTIONS_H */

