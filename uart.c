#include <reg51.h>
void init();
void send(char*data);

void init(){
    // Set Modes
    TMOD = 0x20; //Set timer to mode-2, 8bit auto-reload mode
    SCON = 0x50; //Set serial control to mode-1, reception enable.

    // Set baud rate to 9600
    TH1 = 0xFD;

    // Start timer-1
    TR1 = 1; 
}

void transmit(char data){
    SBUF = data; //Load data on SBUF register

    while(TI == 0);

    TI=0; //Reset Transmit interrupt flag to 0 for next transmission.
}

void send(char*data){
    unsigned int i;

    for(i = 0; data[i] != 0; i++)
        transmit(data[i]);

    transmit(0x0D); //Send carriage return
    
}

void main(){
    init();

    while(1){

        while(RI == 0);
        temp_data = SBUF;
        RI = 0;

        
    }
}