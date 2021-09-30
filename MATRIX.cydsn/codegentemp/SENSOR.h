/*******************************************************************************
* File Name: SENSOR.h  
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

#if !defined(CY_PINS_SENSOR_H) /* Pins SENSOR_H */
#define CY_PINS_SENSOR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SENSOR_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SENSOR__PORT == 15 && ((SENSOR__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SENSOR_Write(uint8 value);
void    SENSOR_SetDriveMode(uint8 mode);
uint8   SENSOR_ReadDataReg(void);
uint8   SENSOR_Read(void);
void    SENSOR_SetInterruptMode(uint16 position, uint16 mode);
uint8   SENSOR_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SENSOR_SetDriveMode() function.
     *  @{
     */
        #define SENSOR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SENSOR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SENSOR_DM_RES_UP          PIN_DM_RES_UP
        #define SENSOR_DM_RES_DWN         PIN_DM_RES_DWN
        #define SENSOR_DM_OD_LO           PIN_DM_OD_LO
        #define SENSOR_DM_OD_HI           PIN_DM_OD_HI
        #define SENSOR_DM_STRONG          PIN_DM_STRONG
        #define SENSOR_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SENSOR_MASK               SENSOR__MASK
#define SENSOR_SHIFT              SENSOR__SHIFT
#define SENSOR_WIDTH              1u

/* Interrupt constants */
#if defined(SENSOR__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SENSOR_SetInterruptMode() function.
     *  @{
     */
        #define SENSOR_INTR_NONE      (uint16)(0x0000u)
        #define SENSOR_INTR_RISING    (uint16)(0x0001u)
        #define SENSOR_INTR_FALLING   (uint16)(0x0002u)
        #define SENSOR_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SENSOR_INTR_MASK      (0x01u) 
#endif /* (SENSOR__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SENSOR_PS                     (* (reg8 *) SENSOR__PS)
/* Data Register */
#define SENSOR_DR                     (* (reg8 *) SENSOR__DR)
/* Port Number */
#define SENSOR_PRT_NUM                (* (reg8 *) SENSOR__PRT) 
/* Connect to Analog Globals */                                                  
#define SENSOR_AG                     (* (reg8 *) SENSOR__AG)                       
/* Analog MUX bux enable */
#define SENSOR_AMUX                   (* (reg8 *) SENSOR__AMUX) 
/* Bidirectional Enable */                                                        
#define SENSOR_BIE                    (* (reg8 *) SENSOR__BIE)
/* Bit-mask for Aliased Register Access */
#define SENSOR_BIT_MASK               (* (reg8 *) SENSOR__BIT_MASK)
/* Bypass Enable */
#define SENSOR_BYP                    (* (reg8 *) SENSOR__BYP)
/* Port wide control signals */                                                   
#define SENSOR_CTL                    (* (reg8 *) SENSOR__CTL)
/* Drive Modes */
#define SENSOR_DM0                    (* (reg8 *) SENSOR__DM0) 
#define SENSOR_DM1                    (* (reg8 *) SENSOR__DM1)
#define SENSOR_DM2                    (* (reg8 *) SENSOR__DM2) 
/* Input Buffer Disable Override */
#define SENSOR_INP_DIS                (* (reg8 *) SENSOR__INP_DIS)
/* LCD Common or Segment Drive */
#define SENSOR_LCD_COM_SEG            (* (reg8 *) SENSOR__LCD_COM_SEG)
/* Enable Segment LCD */
#define SENSOR_LCD_EN                 (* (reg8 *) SENSOR__LCD_EN)
/* Slew Rate Control */
#define SENSOR_SLW                    (* (reg8 *) SENSOR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SENSOR_PRTDSI__CAPS_SEL       (* (reg8 *) SENSOR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SENSOR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SENSOR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SENSOR_PRTDSI__OE_SEL0        (* (reg8 *) SENSOR__PRTDSI__OE_SEL0) 
#define SENSOR_PRTDSI__OE_SEL1        (* (reg8 *) SENSOR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SENSOR_PRTDSI__OUT_SEL0       (* (reg8 *) SENSOR__PRTDSI__OUT_SEL0) 
#define SENSOR_PRTDSI__OUT_SEL1       (* (reg8 *) SENSOR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SENSOR_PRTDSI__SYNC_OUT       (* (reg8 *) SENSOR__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SENSOR__SIO_CFG)
    #define SENSOR_SIO_HYST_EN        (* (reg8 *) SENSOR__SIO_HYST_EN)
    #define SENSOR_SIO_REG_HIFREQ     (* (reg8 *) SENSOR__SIO_REG_HIFREQ)
    #define SENSOR_SIO_CFG            (* (reg8 *) SENSOR__SIO_CFG)
    #define SENSOR_SIO_DIFF           (* (reg8 *) SENSOR__SIO_DIFF)
#endif /* (SENSOR__SIO_CFG) */

/* Interrupt Registers */
#if defined(SENSOR__INTSTAT)
    #define SENSOR_INTSTAT            (* (reg8 *) SENSOR__INTSTAT)
    #define SENSOR_SNAP               (* (reg8 *) SENSOR__SNAP)
    
	#define SENSOR_0_INTTYPE_REG 		(* (reg8 *) SENSOR__0__INTTYPE)
#endif /* (SENSOR__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SENSOR_H */


/* [] END OF FILE */
