#ifndef SYS_CALL
#define SYS_CALL

/*
*   Enable / disable virtual address traslation
*/

extern void v_addr(uint8_t flag);

/*
*   Programs execution
*/

extern void prog_exec_0(void);
extern void prog_exec_1(void);

extern void prog_stop_0(void);
extern void prog_stop_1(void);

#endif