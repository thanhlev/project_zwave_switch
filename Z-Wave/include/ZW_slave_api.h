/*******************************  ZW_SLAVE_API.H  *******************************
 *           #######
 *           ##  ##
 *           #  ##    ####   #####    #####  ##  ##   #####
 *             ##    ##  ##  ##  ##  ##      ##  ##  ##
 *            ##  #  ######  ##  ##   ####   ##  ##   ####
 *           ##  ##  ##      ##  ##      ##   #####      ##
 *          #######   ####   ##  ##  #####       ##  #####
 *                                           #####
 *          Z-Wave, the wireless lauguage.
 *
 *              Copyright (c) 2001
 *              Zensys A/S
 *              Denmark
 *
 *              All Rights Reserved
 *
 *    This source file is subject to the terms and conditions of the
 *    Zensys Software License Agreement which restricts the manner
 *    in which it may be used.
 *
 *---------------------------------------------------------------------------
 *
 * Description: Z-Wave Slave node application interface
 *
 * Author:   Ivar Jeppesen
 *
 * Last Changed By:  $Author: jsi $
 * Revision:         $Revision: 22623 $
 * Last Changed:     $Date: 2012-04-26 16:04:19 +0200 (to, 26 apr 2012) $
 *
 ****************************************************************************/
#ifndef _ZW_SLAVE_API_H_
#define _ZW_SLAVE_API_H_

#ifndef ZW_SLAVE
#define ZW_SLAVE
#endif

/****************************************************************************/
/*                              INCLUDE FILES                               */
/****************************************************************************/
#include <ZW_basis_api.h>


/****************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                       */
/****************************************************************************/

/* ApplicationcSlaveUpdate status */
#define UPDATE_STATE_NODE_INFO_RECEIVED     0x84


/* Defines used to handle inclusion and exclusion of node */
#define ASSIGN_COMPLETE           0x00
#define ASSIGN_NODEID_DONE        0x01  /*Node ID have been assigned*/
#define ASSIGN_RANGE_INFO_UPDATE  0x02  /*Node is doing Neighbor discovery*/

/* Mode parameters to ZW_SetLearnMode */
#define ZW_SET_LEARN_MODE_DISABLE           0x00
#define ZW_SET_LEARN_MODE_CLASSIC           0x01
#define ZW_SET_LEARN_MODE_NWI               0x02

/*===========================   ZW_SetLearnMode   ===========================
**    Enable/Disable home/node ID learn mode.
**    When learn mode is enabled, received "Assign ID's Command" are handled:
**    If the current stored ID's are zero, the received ID's will be stored.
**    If the received ID's are zero the stored ID's will be set to zero.
**
**    The learnFunc is called when the received assign command has been handled.
**    The returned parameter is the learned Node ID.
**
** void           RET  Nothing
** ZW_SetLearnMode(
** BYTE mode,                IN  learnMode bitmask
** void (*learnFunc)(BYTE)); IN  Node learn call back function.
**--------------------------------------------------------------------------*/
#define ZW_SET_LEARN_MODE(mode, func) ZW_SetLearnMode(mode, func)


/*===========================   ZW_SetDefault   ================================
**    Remove all Nodes and timers from the EEPROM memory.
**    Reset the homeID and nodeID
**    Side effects:
**
**--------------------------------------------------------------------------*/
#define ZW_SET_DEFAULT     ZW_SetDefault


/****************************************************************************/
/*                              EXPORTED DATA                               */
/****************************************************************************/

/****************************************************************************/
/*                           EXPORTED FUNCTIONS                             */
/*                 Implemented within the application moduls                */
/****************************************************************************/

/*============================   ZW_SUPPORT9600_ONLY   ======================
**    Function description
**     If ZW_SUPPORT9600ONLY(TRUE) node will report as 9600 baud only.
**      This function should only be called from ApplicationInitSW
**      RETURNS TRUE if successfull, FALSE if not.
**    Side effects:
**      If TRUE communication to this node will always be 9.6kbit
**--------------------------------------------------------------------------*/
#define ZW_SUPPORT9600_ONLY(val) ZW_Support9600Only(val)

/*==========================   ZW_Support9600Only   =========================
**    Function description
**      If bValue is TRUE this node will only support 9600 Baud RF
**
**
**--------------------------------------------------------------------------*/
BOOL                   /*RET  TRUE if succesfull, FALSE if node is Listening*/
ZW_Support9600Only(
  BOOL bValue);         /*IN TRUE enable 9600 only*/


/****************************************************************************/
/*                           EXPORTED FUNCTIONS                             */
/*                 Implemented within the Z-Wave slave modules              */
/****************************************************************************/


/*===========================   ZW_SetLearnMode   ===========================
**    Enable/Disable home/node ID learn mode.
**    When learn mode is enabled, received "Assign ID's Command" are handled:
**    If the current stored ID's are zero, the received ID's will be stored.
**    If the received ID's are zero the stored ID's will be set to zero.
**
**    The learnFunc is called when the received assign command has been handled.
**
**--------------------------------------------------------------------------*/
extern void         /*RET  Nothing        */
ZW_SetLearnMode(
  BYTE mode,                                       /* IN  learnMode bitmask */
  VOID_CALLBACKFUNC(learnFunc)(BYTE bStatus, BYTE nodeID));  /*IN  Node learn call back function. */


/*===========================   ZW_SetDefault   ================================
**    Reset the slave to its default state.
**    Delete all routes in routing slave
**    Reset the homeID and nodeID
**    Side effects:
**
**--------------------------------------------------------------------------*/
void           /*RET  Nothing        */
ZW_SetDefault(void);

#endif /* _ZW_SLAVE_API_H_ */

