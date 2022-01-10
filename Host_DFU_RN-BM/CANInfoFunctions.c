#include <xc.h>
#if defined(_CAN1) || defined(_CAN2)

#include "CANTypes.h"
#include <peripheral/CAN.h>


UINT CANTotalModules(void)

{

	/* This function returns the total number

	 * of modules on the device. */



	return(CAN_NUMBER_OF_MODULES);

}



UINT CANTotalChannels(void)

{

	/* This function returns the total number

	 * of channels per CAN module. */



	return(CAN_ALL_CHANNELS);

}



UINT CANTotalFilters(void)

{

	/* This function returns the total number

	 * of filter available per CAN module. */



	return(CAN_NUMBER_OF_FILTERS);

}

	

UINT CANTotalMasks(void)

{

	/* This function returns the total number

	 * of filter masks available per CAN module. */



	return(CAN_NUMBER_OF_FILTER_MASKS);

}




#endif /* defined(_CAN1) || defined(_CAN2) */

