//
// Created by Artem Martus on 10/7/19.
//

#ifndef CORE_DEFINES_H
#define CORE_DEFINES_H

/// @brief defines whether lib_print will print to the console stdout
#define PRINT_TO_STDOUT 1

/// @brief messaged fired when SAFETY fails via lib_print
#define SAFETY_FAILURE_MESSAGE "FAILURE EXITING FUNCTION"

/// @brief SAFETY helper macro that fires lib_print SAFETY_FAILURE_MESSAGE
#define FAIL_RETURN(retVal) {\
		lib_print(SAFETY_FAILURE_MESSAGE);\
		return retVal;\
	}
/// @brief used for checking if pointer equals to 0, returns 0
#define SAFETY(x) if(!x) FAIL_RETURN(0)
/// @brief same as SAFETY(x) but frees y if failed, returns 0
#define SAFETY2(x,y) if(!x) {if(y)free(y);FAIL_RETURN(0)}
/// @brief same as SAFETY(x,y) but frees y and z if failed, returns 0
#define SAFETY3(x,y,z) if(!x) {if(y)free(y);if(z)free(z);FAIL_RETURN(0)}

/// @brief regular SAFETY check but with return type used, returns ret
#define SAFETY_RET(x,ret) if(!x) FAIL_RETURN(ret)

/// @brief enum Used as type code for abstract tree node
enum TreeNodeType{
	Letter,
	Number,
	Addition,
	Equation
};

#endif //CORE_DEFINES_H
