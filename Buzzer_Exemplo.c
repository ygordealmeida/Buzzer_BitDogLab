#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "Buzzer.h"

int main()
{
    stdio_init_all();
    pwm_init_buzzer(BUZZER_PIN_A);
    float clock = clock_get_hz(clk_sys);
    while (true) {
        check_and_play_next_note(BUZZER_PIN_A);

    }
}
/* É MUITO IMPORTANTE OBSERVAR A RESPOSTA EM FREQUENCIA NO DATASHEET DO BUZZER
ALÉM DISSO TER EM MENTE QUE O BUZZER ADICIONA RUIDO E O RUIDO PODE SER ALTO 
EM FREQUENCIAS COM BAIXO GANHO

NO GERAL O RUIDO É DE ALTA FREQUENCIA E APARECE QUANDO VC TOCA UMA NOTA DE BAIXA FREQUENCIA
*/