# include <stdint.h>

#define SRAM_START 0X20000000                       /*Inicio da Ram*/
#define SRAM_SIZE (128U * 1024U)                    /*tam. SRAMSTM32F411 128K*/
#define SRAM_END ((SRAM_START) + (SRAM_SIZE))       /*Final da SRAM STM32F411*/

#define STACK_START SRAM_END                   /*Inicio da stack*/

void reset_handler     (void);
void nmi_handler       (void)_attribute_((weak, alias("default_handler")));
void hardfault_handler (void)_attribute_((weak, alias("default_handler")));
void memmanage_handler (void)_attribute_((weak, alias("default_handler")));
void busfault_handler  (void)_attribute_((weak, alias("default_handler")));
void usagefault_handler(void)_attribute_((weak, alias("default_handler")));
void svc_handler       (void)_attribute_((weak, alias("default_handler")));
void debugmon_handler  (void)_attribute_((weak, alias("default_handler")));
void pendsv_handler    (void)_attribute_((weak, alias("default_handler")));
void systick_handler   (void)_attribute_((weak, alias("default_handler")));

/*variaveis exportadas*/


uint32_t vectors[]_attribute_((section(".isr_vectors")))=
{
    STACK_START,                                                     /*0X0000 0000*/
    (uint32_t)reset_handler,                                         /*0x0000 0004*/
    (uint32_t)nmi_handler,                                        /*0x0000 0008*/
    (uint32_t)hardfault_handler,                                     /*0x0000 000c*/
    (uint32_t)memmanage_handler,                                      /*0x0000 0010*/
    (uint32_t)busfault_handler,                                     /*0x0000 0014*/
    (uint32_t)usagefault_handler,                                   /*0x0000 0018*/
    0,                                         /*0x0000 001c*/
    0,                                         /*0x0000 0020*/
    0,                                         /*0x0000 0024*/
    0,                                         /*0x0000 0028*/
    (uint32_t)svc_handler,                                      /*0x0000 002c*/
    (uint32_t)debugmon_handler,                                       /*0x0000 0030*/
    0,                                         /*0x0000 0034*/
    (uint32_t)pendsv_handler,                                         /*0x0000 0038*/
    (uint32_t)systick_handler,                                         /*0x0000 003c*/
}

void reset_handler(void)
{

}

void nmi_handler(void)
{
    while(1){}
}

void default_handler(void)
{
    while(1){}
}
