//
// Created by Artem Martus on 10/7/19.
//

#ifndef CORE_DEFINES_H
#define CORE_DEFINES_H

// defines whether lib_print will print to the console
#define PRINT_TO_STDOUT 1

#define ATN_TYPE_EQUATION       0x0
#define ATN_TYPE_ADDITION       0x0
#define ATN_TYPE_SUBSTITUTION   0x0
#define ATN_TYPE_NUMBER         0x0
#define ATN_TYPE_NOT_A_NUMBER   0x0

#define FAIL_RETURN(retVal) {lib_print("FAILURE EXITING FUNCTION"); return retVal;}

#define SAFETY(x) if(!x) FAIL_RETURN(0)
#define SAFETY2(x,y) if(!x) {free(y);FAIL_RETURN(0)}
#define SAFETY3(x,y,z) if(!x) {free(y);free(z);FAIL_RETURN(0)}

#define SAFETY_RET(x,ret) if(!x) FAIL_RETURN(ret)

#endif //CORE_DEFINES_H
