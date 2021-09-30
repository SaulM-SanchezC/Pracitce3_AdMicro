/*******************************************************************************
* File Name: isr_FILA.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_isr_FILA_H)
#define CY_ISR_isr_FILA_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isr_FILA_Start(void);
void isr_FILA_StartEx(cyisraddress address);
void isr_FILA_Stop(void);

CY_ISR_PROTO(isr_FILA_Interrupt);

void isr_FILA_SetVector(cyisraddress address);
cyisraddress isr_FILA_GetVector(void);

void isr_FILA_SetPriority(uint8 priority);
uint8 isr_FILA_GetPriority(void);

void isr_FILA_Enable(void);
uint8 isr_FILA_GetState(void);
void isr_FILA_Disable(void);

void isr_FILA_SetPending(void);
void isr_FILA_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isr_FILA ISR. */
#define isr_FILA_INTC_VECTOR            ((reg32 *) isr_FILA__INTC_VECT)

/* Address of the isr_FILA ISR priority. */
#define isr_FILA_INTC_PRIOR             ((reg8 *) isr_FILA__INTC_PRIOR_REG)

/* Priority of the isr_FILA interrupt. */
#define isr_FILA_INTC_PRIOR_NUMBER      isr_FILA__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isr_FILA interrupt. */
#define isr_FILA_INTC_SET_EN            ((reg32 *) isr_FILA__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isr_FILA interrupt. */
#define isr_FILA_INTC_CLR_EN            ((reg32 *) isr_FILA__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isr_FILA interrupt state to pending. */
#define isr_FILA_INTC_SET_PD            ((reg32 *) isr_FILA__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isr_FILA interrupt. */
#define isr_FILA_INTC_CLR_PD            ((reg32 *) isr_FILA__INTC_CLR_PD_REG)


#endif /* CY_ISR_isr_FILA_H */


/* [] END OF FILE */
