/******************************************************************************
* File Name:   main.c
*
* Description: This is the source code for the
*              mtb-example-cyw43907-uart-tx-rx Code Example
*              for ModusToolbox.
*
* Related Document: See README.md
*
*
*******************************************************************************
* $ Copyright 2021-2023 Cypress Semiconductor $
*******************************************************************************/

#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
#include "cy_utils.h"

/*******************************************************************************
* Macros
********************************************************************************/
#define UART_DELAY 10u


/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
* This is the main function for CYW43907 CPU. It does
*    1. UART initialization.
*    2. Gets and prints a character.
*
* Parameters:
*  void
*
* Return:
*  int
*
*******************************************************************************/
int main(void)
{
    uint8_t read_data;

    /* Initialize retarget-io to use the debug UART port */
    cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, CY_RETARGET_IO_BAUDRATE);

    /* \x1b[2J\x1b[;H - ANSI ESC sequence for clear screen */
    printf("\x1b[2J\x1b[;H");

    printf("****************** \r\n"
           "CYW43907 UART Transmit and Receive \r\n"
           "mtb-example-cyw43907-uart-tx-rx \r\n"
           "****************** \r\n\n");

    /* Get a character from user and print the same on console*/
    printf("Type a character and the same is displayed\r\n\n");

    for (;;)
    {
        /* Get a character from user. */
        if (CY_RSLT_SUCCESS == cyhal_uart_getc(&cy_retarget_io_uart_obj,
                                               &read_data, 0))
        {
            /* Put the character that user given as input */
            if (CY_RSLT_SUCCESS != cyhal_uart_putc(&cy_retarget_io_uart_obj,
                                                   read_data))
            {
                CY_ASSERT(0);
            }
        }
        else
        {
            CY_ASSERT(0);
        }

        cyhal_system_delay_ms(UART_DELAY);
    }
}

/* [] END OF FILE */
