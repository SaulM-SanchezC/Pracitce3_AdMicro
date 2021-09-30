/*******************************************************************************
* File Name: Alarm.h  
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

#if !defined(CY_PINS_Alarm_H) /* Pins Alarm_H */
#define CY_PINS_Alarm_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Alarm_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Alarm__PORT == 15 && ((Alarm__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Alarm_Write(uint8 value);
void    Alarm_SetDriveMode(uint8 mode);
uint8   Alarm_ReadDataReg(void);
uint8   Alarm_Read(void);
void    Alarm_SetInterruptMode(uint16 position, uint16 mode);
uint8   Alarm_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Alarm_SetDriveMode() function.
     *  @{
     */
        #define Alarm_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Alarm_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Alarm_DM_RES_UP          PIN_DM_RES_UP
        #define Alarm_DM_RES_DWN         PIN_DM_RES_DWN
        #define Alarm_DM_OD_LO           PIN_DM_OD_LO
        #define Alarm_DM_OD_HI           PIN_DM_OD_HI
        #define Alarm_DM_STRONG          PIN_DM_STRONG
        #define Alarm_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Alarm_MASK               Alarm__MASK
#define Alarm_SHIFT              Alarm__SHIFT
#define Alarm_WIDTH              1u

/* Interrupt constants */
#if defined(Alarm__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Alarm_SetInterruptMode() function.
     *  @{
     */
        #define Alarm_INTR_NONE      (uint16)(0x0000u)
        #define Alarm_INTR_RISING    (uint16)(0x0001u)
        #define Alarm_INTR_FALLING   (uint16)(0x0002u)
        #define Alarm_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Alarm_INTR_MASK      (0x01u) 
#endif /* (Alarm__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Alarm_PS                     (* (reg8 *) Alarm__PS)
/* Data Register */
#define Alarm_DR                     (* (reg8 *) Alarm__DR)
/* Port Number */
#define Alarm_PRT_NUM                (* (reg8 *) Alarm__PRT) 
/* Connect to Analog Globals */                                                  
#define Alarm_AG                     (* (reg8 *) Alarm__AG)                       
/* Analog MUX bux enable */
#define Alarm_AMUX                   (* (reg8 *) Alarm__AMUX) 
/* Bidirectional Enable */                                                        
#define Alarm_BIE                    (* (reg8 *) Alarm__BIE)
/* Bit-mask for Aliased Register Access */
#define Alarm_BIT_MASK               (* (reg8 *) Alarm__BIT_MASK)
/* Bypass Enable */
#define Alarm_BYP                    (* (reg8 *) Alarm__BYP)
/* Port wide control signals */                                                   
#define Alarm_CTL                    (* (reg8 *) Alarm__CTL)
/* Drive Modes */
#define Alarm_DM0                    (* (reg8 *) Alarm__DM0) 
#define Alarm_DM1                    (* (reg8 *) Alarm__DM1)
#define Alarm_DM2                    (* (reg8 *) Alarm__DM2) 
/* Input Buffer Disable Override */
#define Alarm_INP_DIS                (* (reg8 *) Alarm__INP_DIS)
/* LCD Common or Segment Drive */
#define Alarm_LCD_COM_SEG            (* (reg8 *) Alarm__LCD_COM_SEG)
/* Enable Segment LCD */
#define Alarm_LCD_EN                 (* (reg8 *) Alarm__LCD_EN)
/* Slew Rate Control */
#define Alarm_SLW                    (* (reg8 *) Alarm__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Alarm_PRTDSI__CAPS_SEL       (* (reg8 *) Alarm__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Alarm_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Alarm__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Alarm_PRTDSI__OE_SEL0        (* (reg8 *) Alarm__PRTDSI__OE_SEL0) 
#define Alarm_PRTDSI__OE_SEL1        (* (reg8 *) Alarm__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Alarm_PRTDSI__OUT_SEL0       (* (reg8 *) Alarm__PRTDSI__OUT_SEL0) 
#define Alarm_PRTDSI__OUT_SEL1       (* (reg8 *) Alarm__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Alarm_PRTDSI__SYNC_OUT       (* (reg8 *) Alarm__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Alarm__SIO_CFG)
    #define Alarm_SIO_HYST_EN        (* (reg8 *) Alarm__SIO_HYST_EN)
    #define Alarm_SIO_REG_HIFREQ     (* (reg8 *) Alarm__SIO_REG_HIFREQ)
    #define Alarm_SIO_CFG            (* (reg8 *) Alarm__SIO_CFG)
    #define Alarm_SIO_DIFF           (* (reg8 *) Alarm__SIO_DIFF)
#endif /* (Alarm__SIO_CFG) */

/* Interrupt Registers */
#if defined(Alarm__INTSTAT)
    #define Alarm_INTSTAT            (* (reg8 *) Alarm__INTSTAT)
    #define Alarm_SNAP               (* (reg8 *) Alarm__SNAP)
    
	#define Alarm_0_INTTYPE_REG 		(* (reg8 *) Alarm__0__INTTYPE)
#endif /* (Alarm__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Alarm_H */


/* [] END OF FILE */
