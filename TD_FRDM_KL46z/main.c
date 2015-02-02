void r_led_off(void);
void  led_init(void);
void clocks_init(void); 
void r_led_toggle(void);
void v_led_toggle(void);  
int main(){
  clocks_init();
  led_init();    
   for (int i=0; i<100000000; i++){
    asm volatile("nop");
    r_led_toggle();
    v_led_toggle();
   }
}
 
