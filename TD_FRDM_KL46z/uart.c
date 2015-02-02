void uart_init(){
  //activer l'horloge du port série
  SIM_SOPT2|=0x0C000000;//clock source P209
  SIM_SCGC4|=0x00000400; 
  //configurer l'oversampling à la valeur la plus grande possible(on prend 16 ce qui revient à 15)
  UART0_C4 |= 0x0F;
  UART0_C4 &= 0x0D;
  //configurer la vitesse du port série à 115200 bauds
  UART0_BDH = 0x00;
  UART0_BDL = 0x0D;
  //configurer l'UART0 en 8 N 1
  UART0_C4 &= ~0x10;
  UART0_C1 &= ~0x10;
  //passer les broches RX et TX du port A (à vous de trouver lesquelles) en mode UART
  PORTA_PCR1 |= 0x200;
  PORTA_PCR2 |= 0x200;
  SIM_SCGC5 |= 0x00000200;
  //activer le transmetteur et le récepteur(P752)
  UART0_C2 |= 0x04;

}


// qui attend que l'UART soit prêt à transmettre quelque chose, puis lui demande de l'envoyer (registres UART0_S1 et UART0_D)
void uart_putchar(char c){
  while(UARTx_S1[7]!=1);
  UART0_D = c;


}



// qui attend que l'UART ait reçu un caractère puis le retourne (registres UART0_S1 et UART0_D)
unsigned char uart_getchar(){
  while(UARTx_S1[7]==1);
  return UART0_D;

} 


// qui fait la même chose que puts sous Linux
void uart_puts(const char *s){
  putchar(s);
}



// qui fait la même chose que fgets sous Linux
void uart_gets(char *s, int size){
  fgets(s, size);
}
