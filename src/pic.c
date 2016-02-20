#include "pic.h"
#include "ioport.h"
#include "interrupt.h"

void pic_setup(){
	out8(PIC_MASTER_COMMAND_REGISTER_PORT, PIC_FIRST_COMMAND_WORD);
	out8(PIC_SLAVE_COMMAND_REGISTER_PORT, PIC_FIRST_COMMAND_WORD);

	out8(PIC_MASTER_DATA_REGISTER_PORT , PIC_BOUND_MASTER);
	out8(PIC_SLAVE_DATA_REGISTER_PORT, PIC_BOUND_SLAVE);

	out8(PIC_MASTER_DATA_REGISTER_PORT, PIC_MASTER_SLAVE_PORT);
	out8(PIC_SLAVE_DATA_REGISTER_PORT, PIC_SLAVE_MASTER_PORT);

	out8(PIC_MASTER_DATA_REGISTER_PORT, PIC_FOURTH_COMMAND_WORD);
	out8(PIC_SLAVE_DATA_REGISTER_PORT, PIC_FOURTH_COMMAND_WORD);

	out8(PIC_MASTER_DATA_REGISTER_PORT, PIC_INTERRUPT_MASK);
	out8(PIC_SLAVE_DATA_REGISTER_PORT, PIC_INTERRUPT_MASK);
}

void pic_eoi(int master){
	if(!master){
		out8(PIC_SLAVE_COMMAND_REGISTER_PORT, PIC_EOI);
	}
	out8(PIC_MASTER_COMMAND_REGISTER_PORT, PIC_EOI);

}
