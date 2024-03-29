; /*************************  ZW_PATCHTABLE_HEADER.A51  ***********************
;  *           #######
;  *           ##  ##
;  *           #  ##    ####   #####    #####  ##  ##   #####
;  *             ##    ##  ##  ##  ##  ##      ##  ##  ##
;  *            ##  #  ######  ##  ##   ####   ##  ##   ####
;  *           ##  ##  ##      ##  ##      ##   #####      ##
;  *          #######   ####   ##  ##  #####       ##  #####
;  *                                           #####
;  *          Z-Wave, the wireless language.
;  *
;  *              Copyright (c) 2001
;  *              Zensys A/S
;  *              Denmark
;  *
;  *              All Rights Reserved
;  *
;  *    This source file is subject to the terms and conditions of the
;  *    Zensys Software License Agreement which restricts the manner
;  *    in which it may be used.
;  *
;  *---------------------------------------------------------------------------
;  *
;  * Description: Z-Wave tableOfPatchedFunctions:
;  *    This table contains a NULL terminated list of pointer pairs for the
;  *    functions in ROM, for which we have a patch.
;  *    The table is immediatly followed by a footer of a fixed format and
;  *    which shall be located at a fixed address in the top of memory.
;  *
;  *    This module contains the header for the tableOfPatchedFunctions,
;  *    and it has to be linked in as the very first module during linking
;  *    of the program under development, and to be loaded in executable RAM.
;  *    Linking in this header before anything else assures that every entry
;  *    for the patchTable generated by the program compilation will be included
;  *    in the final patchTable during linking.
;  *
;  * Author:   Erik Friis Harck
;  *
;  * Last Changed By:  $Author: efh $
;  * Revision:         $Revision: 9763 $
;  * Last Changed:     $Date: 2008-01-10 11:28:42 +0100 (Thu, 10 Jan 2008) $
;  *
;  ****************************************************************************/
;

$NOMOD51

NAME	ZW_PATCHTABLE_HEADER

?CO?ZW_PATCHTABLE    SEGMENT CODE

	PUBLIC	tableOfPatchedFunctions

	RSEG  ?CO?ZW_PATCHTABLE

tableOfPatchedFunctions:

	END
