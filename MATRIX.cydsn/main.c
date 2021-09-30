#include "project.h"
#include "stdlib.h"
#define ALARM_ON 1u
#define ALARM_OFF 0u
int Counter = 0, Start = 0, Digits = 0, D1, D2, D3, D4, D5, FinalN;

CY_ISR(SENSOR_int)
{
    Counter--;
    CyDelay(250);
    SENSOR_ClearInterrupt();
}

CY_ISR(isr_FILA)
{
    int Temp = 0, Ctrl = 0;
    uint8 tecla, columna;
    tecla=FILAS_Read();
    columna=COLUMNAS_Read();
    tecla=tecla<<4;
    tecla=tecla|columna;
    
    if (Start == 0)
    {
        switch (tecla)
        {
            case 0xD7:
                //B
                Start = 1;
                break;
        }
    }
    else if (Digits < 5 && Start < 2)
    {
        switch(tecla)
        {
            case 0xEE:
                //1
                Temp = 1;
                LCD_PutChar('1');
                Digits++;
                Ctrl = 1;
                break;
            case 0xED:
                //2
                Temp = 2;
                LCD_PutChar('2');
                Digits++;
                Ctrl = 1;
                break;
            case 0xEB:
                //3
                Temp = 3;
                LCD_PutChar('3');
                Digits++;
                Ctrl = 1;
                break;   
            case 0xE7:
                //A
                //Start = 2; 
                break;
            case 0xDE:
                //4
                Temp = 4;
                LCD_PutChar('4');
                Digits++;
                Ctrl = 1;
                break;
            case 0xDD:
                //5
                Temp = 5;
                LCD_PutChar('5');
                Digits++;
                Ctrl = 1;
                break;
            case 0xDB:
                //6
                Temp = 6;
                LCD_PutChar('6');
                Digits++;
                Ctrl = 1;
                break;
            case 0xD7:
                //B
                Start = 2;
                break;
            case 0xBE:
                //7
                Temp = 7;
                LCD_PutChar('7');
                Digits++;
                Ctrl = 1;
                break;
            case 0xBD:
                //8
                Temp = 8;
                LCD_PutChar('8');
                Digits++;
                Ctrl = 1;
                break;
            case 0xBB:
                //9
                Temp = 9;
                LCD_PutChar('9');
                Digits++;
                Ctrl = 1;
                break;
            case 0xB7:
                //C
                break;
            case 0x7E:
                //*
                break;
            case 0x7D:
                //0
                Temp = 0;
                LCD_PutChar('0');
                Digits++;
                Ctrl = 1;
                break;
            case 0x7B:
                //#
                break;
            case 0x77:
                //D
                break;
        }
        
        if (Ctrl == 1)
        {
            switch (Digits)
            {
                case (1):
                    D1 = Temp;
                    break;
                case (2):
                    D2 = Temp;
                    break;
                case (3):
                    D3 = Temp;
                    break;
                case (4):
                    D4 = Temp;
                    break;
                case (5):
                    D5 = Temp;
                    break;
            }
        }
    }
    else if (Digits == 5)
    {
        switch (tecla)
        {
            case 0xD7:
                //B
                Start = 2;
                break;
        }  
    }
    
    LCD_ClearDisplay();
    LCD_Position(0,0);
    LCD_PrintString("Estas presionando");
    LCD_Position(1,0);
    LCD_PrintNumber(Temp);
    while(FILAS_Read()!=0x0F);
    FILAS_ClearInterrupt(); 
}
int main(void)
{
    CyGlobalIntEnable; 
    
    LCD_Start();
    isr_FILA_StartEx(isr_FILA);
    SENSOR_int_StartEx(SENSOR_int);
    

    for(;;)
    {
        Alarm_Write(ALARM_OFF);
        
        COLUMNAS_Write(0b1110);
        
        COLUMNAS_Write(0b1101);

        COLUMNAS_Write(0b1011);

        COLUMNAS_Write(0b0111);
        //CyDelayUs(500);
        
        if (Start == 0)
        {
            LCD_ClearDisplay();
            LCD_Position(0,0);
            LCD_PrintString("Presione B");
            LCD_Position(1,0);
            LCD_PrintString("para empezar.");
            CyDelay(100);
        }
        else if (Start == 1)
            {
                if (Digits == 0)
                {
                    LCD_ClearDisplay();
                    LCD_Position(0,0);
                    LCD_PrintString("Maximo 5 digitos");
                    LCD_Position(1,0);
                    LCD_PrintString("Cantidad: ");
                    CyDelay(100);
                }
                else if (Digits == 1)
                {
                    LCD_ClearDisplay();
                    LCD_Position(0,0);
                    LCD_PrintString("Maximo 5 digitos");
                    LCD_Position(1,0);
                    LCD_PrintString("Cantidad: ");
                    LCD_PrintNumber(D1);
                    CyDelay(100);
                }
                else if (Digits == 2)
                {
                    LCD_ClearDisplay();
                    LCD_Position(0,0);
                    LCD_PrintString("Maximo 5 digitos");
                    LCD_Position(1,0);
                    LCD_PrintString("Cantidad: ");
                    LCD_PrintNumber(D1);
                    LCD_PrintNumber(D2);
                    CyDelay(100);
                }
                else if (Digits == 3)
                {
                    LCD_ClearDisplay();
                    LCD_Position(0,0);
                    LCD_PrintString("Maximo 5 digitos");
                    LCD_Position(1,0);
                    LCD_PrintString("Cantidad: ");
                    LCD_PrintNumber(D1);
                    LCD_PrintNumber(D2);
                    LCD_PrintNumber(D3);
                    CyDelay(100);
                }
                else if (Digits == 4)
                {
                    LCD_ClearDisplay();
                    LCD_Position(0,0);
                    LCD_PrintString("Maximo 5 digitos");
                    LCD_Position(1,0);
                    LCD_PrintString("Cantidad: ");
                    LCD_PrintNumber(D1);
                    LCD_PrintNumber(D2);
                    LCD_PrintNumber(D3);
                    LCD_PrintNumber(D4);
                    CyDelay(100);
                }
                else if (Digits == 5)
                {
                    LCD_ClearDisplay();
                    LCD_Position(0,0);
                    LCD_PrintString("Maximo 5 digitos");
                    LCD_Position(1,0);
                    LCD_PrintString("Cantidad: ");
                    LCD_PrintNumber(D1);
                    LCD_PrintNumber(D2);
                    LCD_PrintNumber(D3);
                    LCD_PrintNumber(D4);
                    LCD_PrintNumber(D5);
                    CyDelay(100);
                }
                
            }
            else if (Start == 2)
                {
                    switch (Digits)
                    {
                        case (1):
                            FinalN = (D1 * 1);
                            break;
                        case (2):
                            FinalN = (D1 * 10) + D2;
                            break;
                        case (3):
                            FinalN = (D3 * 100) + (D2 * 10) + D3;
                            break;
                        case (4):
                            FinalN = (D1 * 1000) + (D2 * 100) + (D3 * 10) + D4;
                            break;
                        case (5):
                            FinalN = (D1 * 10000) + (D2 * 1000) + (D3 * 100) + (D4 * 10) + D5;
                            break;
                    }
                    
                    while (Counter > 0)
                    {
                        CyDelay(250);
                        LCD_ClearDisplay();
                        LCD_Position(0,0);
                        LCD_PrintString("Max: ");
                        LCD_PrintDecUint16(FinalN);
                        LCD_Position(1,0);
                        LCD_PrintString("Actual: ");
                        int NCount = FinalN - Counter;
                        LCD_PrintDecUint16(NCount);
                    }
                    
                    Alarm_Write(ALARM_ON);
                    CyDelay(3500);
                    
                    Start = 0;
                    Digits = 0;
                    Counter = 0;
                }  
        
    }
}

