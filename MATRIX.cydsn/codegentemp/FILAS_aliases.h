/*******************************************************************************
* File Name: FILAS.h  
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

#if !defined(CY_PINS_FILAS_ALIASES_H) /* Pins FILAS_ALIASES_H */
#define CY_PINS_FILAS_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define FILAS_0			(FILAS__0__PC)
#define FILAS_0_INTR	((uint16)((uint16)0x0001u << FILAS__0__SHIFT))

#define FILAS_1			(FILAS__1__PC)
#define FILAS_1_INTR	((uint16)((uint16)0x0001u << FILAS__1__SHIFT))

#define FILAS_2			(FILAS__2__PC)
#define FILAS_2_INTR	((uint16)((uint16)0x0001u << FILAS__2__SHIFT))

#define FILAS_3			(FILAS__3__PC)
#define FILAS_3_INTR	((uint16)((uint16)0x0001u << FILAS__3__SHIFT))

#define FILAS_INTR_ALL	 ((uint16)(FILAS_0_INTR| FILAS_1_INTR| FILAS_2_INTR| FILAS_3_INTR))

#endif /* End Pins FILAS_ALIASES_H */


/* [] END OF FILE */
