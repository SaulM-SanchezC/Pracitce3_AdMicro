/*******************************************************************************
* File Name: FILAS.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_FILAS_H) /* Pins FILAS_H */
#define CY_PINS_FILAS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "FILAS_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 FILAS__PORT == 15 && ((FILAS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    FILAS_Write(uint8 value);
void    FILAS_SetDriveMode(uint8 mode);
uint8   FILAS_ReadDataReg(void);
uint8   FILAS_Read(void);
void    FILAS_SetInterruptMode(uint16 position, uint16 mode);
uint8   FILAS_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the FILAS_SetDriveMode() function.
     *  @{
     */
        #define FILAS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define FILAS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define FILAS_DM_RES_UP          PIN_DM_RES_UP
        #define FILAS_DM_RES_DWN         PIN_DM_RES_DWN
        #define FILAS_DM_OD_LO           PIN_DM_OD_LO
        #define FILAS_DM_OD_HI           PIN_DM_OD_HI
        #define FILAS_DM_STRONG          PIN_DM_STRONG
        #define FILAS_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define FILAS_MASK               FILAS__MASK
#define FILAS_SHIFT              FILAS__SHIFT
#define FILAS_WIDTH              4u

/* Interrupt constants */
#if defined(FILAS__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in FILAS_SetInterruptMode() function.
     *  @{
     */
        #define FILAS_INTR_NONE      (uint16)(0x0000u)
        #define FILAS_INTR_RISING    (uint16)(0x0001u)
        #define FILAS_INTR_FALLING   (uint16)(0x0002u)
        #define FILAS_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define FILAS_INTR_MASK      (0x01u) 
#endif /* (FILAS__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define FILAS_PS                     (* (reg8 *) FILAS__PS)
/* Data Register */
#define FILAS_DR                     (* (reg8 *) FILAS__DR)
/* Port Number */
#define FILAS_PRT_NUM                (* (reg8 *) FILAS__PRT) 
/* Connect to Analog Globals */                                                  
#define FILAS_AG                     (* (reg8 *) FILAS__AG)                       
/* Analog MUX bux enable */
#define FILAS_AMUX                   (* (reg8 *) FILAS__AMUX) 
/* Bidirectional Enable */                                                        
#define FILAS_BIE                    (* (reg8 *) FILAS__BIE)
/* Bit-mask for Aliased Register Access */
#define FILAS_BIT_MASK               (* (reg8 *) FILAS__BIT_MASK)
/* Bypass Enable */
#define FILAS_BYP                    (* (reg8 *) FILAS__BYP)
/* Port wide control signals */                                                   
#define FILAS_CTL                    (* (reg8 *) FILAS__CTL)
/* Drive Modes */
#define FILAS_DM0                    (* (reg8 *) FILAS__DM0) 
#define FILAS_DM1                    (* (reg8 *) FILAS__DM1)
#define FILAS_DM2                    (* (reg8 *) FILAS__DM2) 
/* Input Buffer Disable Override */
#define FILAS_INP_DIS                (* (reg8 *) FILAS__INP_DIS)
/* LCD Common or Segment Drive */
#define FILAS_LCD_COM_SEG            (* (reg8 *) FILAS__LCD_COM_SEG)
/* Enable Segment LCD */
#define FILAS_LCD_EN                 (* (reg8 *) FILAS__LCD_EN)
/* Slew Rate Control */
#define FILAS_SLW                    (* (reg8 *) FILAS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define FILAS_PRTDSI__CAPS_SEL       (* (reg8 *) FILAS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define FILAS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) FILAS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define FILAS_PRTDSI__OE_SEL0        (* (reg8 *) FILAS__PRTDSI__OE_SEL0) 
#define FILAS_PRTDSI__OE_SEL1        (* (reg8 *) FILAS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define FILAS_PRTDSI__OUT_SEL0       (* (reg8 *) FILAS__PRTDSI__OUT_SEL0) 
#define FILAS_PRTDSI__OUT_SEL1       (* (reg8 *) FILAS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define FILAS_PRTDSI__SYNC_OUT       (* (reg8 *) FILAS__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(FILAS__SIO_CFG)
    #define FILAS_SIO_HYST_EN        (* (reg8 *) FILAS__SIO_HYST_EN)
    #define FILAS_SIO_REG_HIFREQ     (* (reg8 *) FILAS__SIO_REG_HIFREQ)
    #define FILAS_SIO_CFG            (* (reg8 *) FILAS__SIO_CFG)
    #define FILAS_SIO_DIFF           (* (reg8 *) FILAS__SIO_DIFF)
#endif /* (FILAS__SIO_CFG) */

/* Interrupt Registers */
#if defined(FILAS__INTSTAT)
    #define FILAS_INTSTAT            (* (reg8 *) FILAS__INTSTAT)
    #define FILAS_SNAP               (* (reg8 *) FILAS__SNAP)
    
	#define FILAS_0_INTTYPE_REG 		(* (reg8 *) FILAS__0__INTTYPE)
	#define FILAS_1_INTTYPE_REG 		(* (reg8 *) FILAS__1__INTTYPE)
	#define FILAS_2_INTTYPE_REG 		(* (reg8 *) FILAS__2__INTTYPE)
	#define FILAS_3_INTTYPE_REG 		(* (reg8 *) FILAS__3__INTTYPE)
#endif /* (FILAS__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_FILAS_H */


/* [] END OF FILE */
