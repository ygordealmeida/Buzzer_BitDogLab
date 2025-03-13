<div align="center">
    <img src="https://github.com/user-attachments/assets/337c76d6-a1cc-414f-bd90-866fe408b844" alt="V-CC_Color_Basica_TextoAzul" style="width:50%;"/>
</div>


# Biblioteca para Controle de Buzzer - BitDogLab 

Esta biblioteca (`Buzzer.c`) foi desenvolvida para facilitar a geração de sons utilizando um buzzer passivo com PWM no Raspberry Pi Pico W (RP2040). A implementação permite tocar notas musicais e melodias inteiras definidas em arrays de frequência e duração.

## Buzzers da BitDogLab - MLT8530

Os dois buzzers presentes na BitDogLab são do modelo **MLT8530**. Eles são **buzzers** **passivos**, por isso serão controlados via sinal PWM, além disso é importante se ater as condições de operação do buzzer seguindo o datasheet. É importante mencionar que é comum que buzzers tenham ruído indesejaveis, e o modelo em questão não foge a regra. A seguir se apresenta a resposta em frequência retirada do seu datasheet.

<div align="center">
    <img src="https://github.com/user-attachments/assets/fd74e3ac-7829-4d68-b460-822c257e6f75" alt="V-CC_Color_Basica_TextoAzul" style="width:60%;"/>
</div>

Observe que para valores a baixo de 700 hz o buzzer possui baixo ganho e na prática o som emitido possui ruído de alta frequência em valores consideraveis.

## Recursos da Biblioteca

A biblioteca inclui as seguintes funcionalidades:

- **Inicialização do PWM para o buzzer** (`pwm_init_buzzer(pin)`): Configura o PWM no pino especificado para controlar o buzzer.
- **Reprodução de um tom específico** (`play_tone2(pin, frequency, duration_ms)`): Configura o PWM para tocar uma nota com a frequência e duração especificadas.
- **Sequenciamento de notas para reprodução de músicas** (`check_and_play_next_note(pin)`): Gerencia a reprodução automática de uma sequência de notas musicais, garantindo a temporização correta.

  **Obs: Nenhuma das funções utiliza de delays que param a CPU**
  
## Como Usar a Biblioteca

### Configuração

1. **Inclua a biblioteca no seu projeto:**
   ```c
   #include "Buzzer.h"
   ```
2. **Inicialize o buzzer no pino desejado:**
   ```c
   pwm_init_buzzer(BUZZER_PIN_A);
   ```
3. **Toque uma nota específica:**
   ```c
   play_tone2(BUZZER_PIN_A, 1319, 300); // Toca a nota de 1319 Hz por 300 ms
   ```
4. **Reproduza uma sequência de notas automaticamente:**
   ```c
   while (true) {
       check_and_play_next_note(BUZZER_PIN_A);
   }
   ```

## Exemplo de Uso em um Programa

O código abaixo inicializa o buzzer e executa uma sequência de notas musicais:

```c
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "Buzzer.h"

int main()
{
    stdio_init_all();
    pwm_init_buzzer(BUZZER_PIN_A);
    
    while (true) {
        check_and_play_next_note(BUZZER_PIN_A);
    }
}
```

## Considerações Importantes

- **Verifique a resposta em frequência do buzzer no datasheet**: Algumas frequências podem ser melhor reproduzidas do que outras.
- **O buzzer pode adicionar ruído**: O ruído geralmente aparece em notas de baixa frequência e pode incluir componentes de alta frequência indesejadas.
- **Ajuste os parâmetros conforme necessário**: Dependendo do modelo do buzzer, o volume e a qualidade do som podem variar.

## Conclusão

Esta biblioteca permite controlar um buzzer passivo de maneira eficiente, permitindo a reprodução de tons e melodias. É ideal para projetos que necessitam de feedback sonoro, alarmes ou sinalizações sonoras customizadas.


