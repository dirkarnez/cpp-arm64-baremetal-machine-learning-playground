.global _start
_start:
    ldr x30, =stack_top	    /* Retrieve initial stack address */
    mov sp, x30             /* Set stack address */

    mrs    x1, cpacr_el1    /* Enable floating point, copied from https://forums.raspberrypi.com/viewtopic.php?t=259802 */
    mov    x0, #(3 << 20)   /* Enable floating point, copied from https://forums.raspberrypi.com/viewtopic.php?t=259802 */
    orr    x0, x1, x0       /* Enable floating point, copied from https://forums.raspberrypi.com/viewtopic.php?t=259802 */
    msr    cpacr_el1, x0    /* Enable floating point, copied from https://forums.raspberrypi.com/viewtopic.php?t=259802 */

    bl main                 /* Branch to main() */

.global system_off
system_off:
    ldr x0, =0x84000008     /* SYSTEM_OFF function ID */
    hvc #0                  /* Hypervisor call */

sleep:                      /* This point should not be reached */
    wfi                     /* Wait for interrupt */
    b sleep                 /* Endless loop */

