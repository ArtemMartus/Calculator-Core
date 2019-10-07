//
// Created by Artem Martus on 10/7/19.
//

#ifndef CORE_DEFINES_H
#define CORE_DEFINES_H

/// @brief defines whether lib_print will print to the console stdout
#define PRINT_TO_STDOUT 1

/// @brief String type define with struct
#define String struct __tag_string*
/// @brief temporary string name used in construction S_TEMP('hello'); printf(TEMP_STR); _S_TEMP;
#define TEMP_STR __temp_string_name_
/// @brief temporary string creation macro used in construction S_TEMP('hello'); printf(TEMP_STR); _S_TEMP;
#define S_TEMP(x) {String TEMP_STR = S(x)
/// @brief temporary string deletion macro used in construction S_TEMP('hello'); printf(TEMP_STR); _S_TEMP;
#define _S_TEMP _S(TEMP_STR);}
/// @brief messaged fired when SAFETY fails via lib_print
#define SAFETY_FAILURE_MESSAGE "FAILURE EXITING FUNCTION"
/// @brief creates string structure from const char* str
#define S(str) createStr(str,lib_strlen(str)+1)
/// @brief returns const char* from str String
#define CS(str) toCString(str)
/// @brief release String str
#define _S(str) freeString(str)
/// @brief create String from existing String
#define S_COPY(str) copyString(str)

/// @brief SAFETY helper macro that fires lib_print SAFETY_FAILURE_MESSAGE
#define FAIL_RETURN(retVal) {\
		String __str_ptr = S(SAFETY_FAILURE_MESSAGE);\
		lib_print(__str_ptr);\
		_S(__str_ptr);\
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
