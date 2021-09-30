/*******************************************************************************
* File Name: COLUMNAS.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_COLUMNAS_ALIASES_H) /* Pins COLUMNAS_ALIASES_H */
#define CY_PINS_COLUMNAS_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define COLUMNAS_0			(COLUMNAS__0__PC)
#define COLUMNAS_0_INTR	((uint16)((uint16)0x0001u << COLUMNAS__0__SHIFT))

#define COLUMNAS_1			(COLUMNAS__1__PC)
#define COLUMNAS_1_INTR	((uint16)((uint16)0x0001u << COLUMNAS__1__SHIFT))

#define COLUMNAS_2			(COLUMNAS__2__PC)
#define COLUMNAS_2_INTR	((uint16)((uint16)0x0001u << COLUMNAS__2__SHIFT))

#define COLUMNAS_3			(COLUMNAS__3__PC)
#define COLUMNAS_3_INTR	((uint16)((uint16)0x0001u << COLUMNAS__3__SHIFT))

#define COLUMNAS_INTR_ALL	 ((uint16)(COLUMNAS_0_INTR| COLUMNAS_1_INTR| COLUMNAS_2_INTR| COLUMNAS_3_INTR))

#endif /* End Pins COLUMNAS_ALIASES_H */


/* [] END OF FILE */
