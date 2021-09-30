/*******************************************************************************
* File Name: COLUMNAS.h  
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

#if !defined(CY_PINS_COLUMNAS_H) /* Pins COLUMNAS_H */
#define CY_PINS_COLUMNAS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "COLUMNAS_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 COLUMNAS__PORT == 15 && ((COLUMNAS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    COLUMNAS_Write(uint8 value);
void    COLUMNAS_SetDriveMode(uint8 mode);
uint8   COLUMNAS_ReadDataReg(void);
uint8   COLUMNAS_Read(void);
void    COLUMNAS_SetInterruptMode(uint16 position, uint16 mode);
uint8   COLUMNAS_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the COLUMNAS_SetDriveMode() function.
     *  @{
     */
        #define COLUMNAS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define COLUMNAS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define COLUMNAS_DM_RES_UP          PIN_DM_RES_UP
        #define COLUMNAS_DM_RES_DWN         PIN_DM_RES_DWN
        #define COLUMNAS_DM_OD_LO           PIN_DM_OD_LO
        #define COLUMNAS_DM_OD_HI           PIN_DM_OD_HI
        #define COLUMNAS_DM_STRONG          PIN_DM_STRONG
        #define COLUMNAS_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define COLUMNAS_MASK               COLUMNAS__MASK
#define COLUMNAS_SHIFT              COLUMNAS__SHIFT
#define COLUMNAS_WIDTH              4u

/* Interrupt constants */
#if defined(COLUMNAS__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in COLUMNAS_SetInterruptMode() function.
     *  @{
     */
        #define COLUMNAS_INTR_NONE      (uint16)(0x0000u)
        #define COLUMNAS_INTR_RISING    (uint16)(0x0001u)
        #define COLUMNAS_INTR_FALLING   (uint16)(0x0002u)
        #define COLUMNAS_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define COLUMNAS_INTR_MASK      (0x01u) 
#endif /* (COLUMNAS__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define COLUMNAS_PS                     (* (reg8 *) COLUMNAS__PS)
/* Data Register */
#define COLUMNAS_DR                     (* (reg8 *) COLUMNAS__DR)
/* Port Number */
#define COLUMNAS_PRT_NUM                (* (reg8 *) COLUMNAS__PRT) 
/* Connect to Analog Globals */                                                  
#define COLUMNAS_AG                     (* (reg8 *) COLUMNAS__AG)                       
/* Analog MUX bux enable */
#define COLUMNAS_AMUX                   (* (reg8 *) COLUMNAS__AMUX) 
/* Bidirectional Enable */                                                        
#define COLUMNAS_BIE                    (* (reg8 *) COLUMNAS__BIE)
/* Bit-mask for Aliased Register Access */
#define COLUMNAS_BIT_MASK               (* (reg8 *) COLUMNAS__BIT_MASK)
/* Bypass Enable */
#define COLUMNAS_BYP                    (* (reg8 *) COLUMNAS__BYP)
/* Port wide control signals */                                                   
#define COLUMNAS_CTL                    (* (reg8 *) COLUMNAS__CTL)
/* Drive Modes */
#define COLUMNAS_DM0                    (* (reg8 *) COLUMNAS__DM0) 
#define COLUMNAS_DM1                    (* (reg8 *) COLUMNAS__DM1)
#define COLUMNAS_DM2                    (* (reg8 *) COLUMNAS__DM2) 
/* Input Buffer Disable Override */
#define COLUMNAS_INP_DIS                (* (reg8 *) COLUMNAS__INP_DIS)
/* LCD Common or Segment Drive */
#define COLUMNAS_LCD_COM_SEG            (* (reg8 *) COLUMNAS__LCD_COM_SEG)
/* Enable Segment LCD */
#define COLUMNAS_LCD_EN                 (* (reg8 *) COLUMNAS__LCD_EN)
/* Slew Rate Control */
#define COLUMNAS_SLW                    (* (reg8 *) COLUMNAS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define COLUMNAS_PRTDSI__CAPS_SEL       (* (reg8 *) COLUMNAS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define COLUMNAS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) COLUMNAS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define COLUMNAS_PRTDSI__OE_SEL0        (* (reg8 *) COLUMNAS__PRTDSI__OE_SEL0) 
#define COLUMNAS_PRTDSI__OE_SEL1        (* (reg8 *) COLUMNAS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define COLUMNAS_PRTDSI__OUT_SEL0       (* (reg8 *) COLUMNAS__PRTDSI__OUT_SEL0) 
#define COLUMNAS_PRTDSI__OUT_SEL1       (* (reg8 *) COLUMNAS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define COLUMNAS_PRTDSI__SYNC_OUT       (* (reg8 *) COLUMNAS__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(COLUMNAS__SIO_CFG)
    #define COLUMNAS_SIO_HYST_EN        (* (reg8 *) COLUMNAS__SIO_HYST_EN)
    #define COLUMNAS_SIO_REG_HIFREQ     (* (reg8 *) COLUMNAS__SIO_REG_HIFREQ)
    #define COLUMNAS_SIO_CFG            (* (reg8 *) COLUMNAS__SIO_CFG)
    #define COLUMNAS_SIO_DIFF           (* (reg8 *) COLUMNAS__SIO_DIFF)
#endif /* (COLUMNAS__SIO_CFG) */

/* Interrupt Registers */
#if defined(COLUMNAS__INTSTAT)
    #define COLUMNAS_INTSTAT            (* (reg8 *) COLUMNAS__INTSTAT)
    #define COLUMNAS_SNAP               (* (reg8 *) COLUMNAS__SNAP)
    
	#define COLUMNAS_0_INTTYPE_REG 		(* (reg8 *) COLUMNAS__0__INTTYPE)
	#define COLUMNAS_1_INTTYPE_REG 		(* (reg8 *) COLUMNAS__1__INTTYPE)
	#define COLUMNAS_2_INTTYPE_REG 		(* (reg8 *) COLUMNAS__2__INTTYPE)
	#define COLUMNAS_3_INTTYPE_REG 		(* (reg8 *) COLUMNAS__3__INTTYPE)
#endif /* (COLUMNAS__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_COLUMNAS_H */


/* [] END OF FILE */
