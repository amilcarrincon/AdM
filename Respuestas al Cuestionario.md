- Arquitectura de Microprocesadores.
- Carrera de Especialización en Sistemas Embebidos.
- Universidad de Buenos Aires. 
- Amilcar Alejandro Rincon Charris

# Preguntas orientadoras
> 1. Describa brevemente los diferentes perfiles de familias de microprocesadores/microcontroladores de ARM. Explique alguna de sus diferencias características.

ARM significa Maquina Avanzada de Conjunto de Instrucciones Reducido (Advanced RISC Machine).
**Cortex A (Application)**
Procesadores de alto rendimiento orientados a la implementación de sistemas operativos en sistemas embebidos de alta performance. 
**Cortex R (Real time)**
Procesadores orientados sistemas de tiempo real donde prima la necesidad de implementar soluciones de baja latencia y alta capacidad de procesamiento. 
**La familia Cortex-M** es una serie de microprocesadores diseñados para bajo consumo de energía. Procesadores orientados a dispositivos de consumo masivo y sistemas embebidos compactos(diseñados para alta densidad de código y programación en C).
## Cortex M
> 2. Describa brevemente las diferencias entre las familias de procesadores Cortex M0, M3 y M4.

M0, M0 +: son las versiones más basicas de los cortex, por lo que no se pueden producir microcontroladores STM32 de alto rendimiento;
M3: Actualmente, la selección de núcleo de diseño más convencional, con una amplia gama de aplicaciones;
M4: Al comparar el núcleo M3, el procesador M4 agrega instrucciones para procesar datos DSP por lo que se pueden considerar como números de punto flotant.

 
> 3. ¿Por qué se dice que el set de instrucciones Thumb permite mayor densidad de código? Explique

En el estado ARM, el procesador ejecuta instrucciones ARM alineadas con palabras de 32 bits, y en el estado Thumb, el procesador ejecuta instrucciones THUMB alineadas con media palabra de 16 bits.

> 4. ¿Qué entiende por arquitectura load-store? ¿Qué tipo de instrucciones no posee este tipo de arquitectura?

Las unidades Load/Store son las encargadas de ejecutar las instrucciones relativas al acceso a la memoria RAM del sistema, ya sean de lectura como de escritura. No existe una unidad L/S, sino que son dos tipos de unidades que funcionan en paralelo y que gestionan el acceso a los datos.

> 5. ¿Cómo es el mapa de memoria de la familia?

El mapa de memoria de la familia es de 4GB y tiene 32 bits de direccionamiento. Basicamente esta dividido en stack, periféricos, sram, y flash. Además, permite el uso de bit-banding, que son regiones de memoria de 8bits mapeadas a un bit de la memoria. 

> 6. ¿Qué ventajas presenta el uso de los “shadowed pointers” del PSP y el MSP?

La principal diferencia entre el (PSP) puntero de pila y el (MSP) contador de programa es que el puntero de pila es un registro que almacena la dirección de la última solicitud de programa en una pila, mientras que el contador de programa es un registro que almacena la dirección de la siguiente instrucción que se ejecutará desde la memoria. El hecho de que el sistema operativo y los controladores de excepciones utilicen una pila diferente a la de la aplicación significa que el sistema operativo puede proteger su pila y evitar que las aplicaciones accedan a ella o la corrompan.

> 7. Describa los diferentes modos de privilegio y operación del Cortex M, sus relaciones y como se conmuta de uno al otro. Describa un ejemplo en el que se pasa del modo privilegiado a no priviligiado y nuevamente a privilegiado.

En el modo privilegiado, los usuarios pueden acceder y configurar los registros de control del sistema, como los controladores de interrupción NVIC.
En el modo no privilegiado, el registro de control del sistema no está permitido acceder, una vez que el acceso resultará en anomalías de hardware. 
Todos los registros periféricos cuyo SPI, USART, USB, incluidos los registros de SPI, USART, USB y otros registros periféricos se pueden acceder bajo niveles no privilegiados. 

> 8. ¿Qué se entiende por modelo de registros ortogonal? Dé un ejemplo

En general, una instrucción codifica una operación básica que el computador realiza sobre unos datos ubicados en la memoria o en los registros de la máquina y a los que accede utilizando un modo de direccionamiento. Diremos que un modelo de registro es ortogonal cuando las instrucciones puedan combinar los
valores de los tres factores anteriores sin ninguna restricción. Ejemplo: ISA Instruction Set Architecture.

> 9. ¿Qué ventajas presenta el uso de intrucciones de ejecución condicional (IT)? Dé un ejemplo

Una de las ventajas del uso de instrucciones de ejecución condicional es que se evita la ejecución de una instrucción al darse una determinada condición. Las instrucciones de salto condicional comprueban ciertos indicadores del registro CCR para decidir si se debe saltar o no. 

> 10. Describa brevemente las excepciones más prioritarias (reset, NMI, Hardfault).

Excepción RESET: Detiene la ejecución del procesador. 
Excepción NMI: Es utilizada por el watchdog y el brown-out detector.
Excepción HARDFAULT: Se presenta cuando hay un error de respuesta en el acceso a memoria, o error en el bus de comunicación.
 
> 11. Describa las funciones principales de la pila. ¿Cómo resuelve la arquitectura el llamado a funciones y su retorno?

Se entiende como pila, a un almacenamiento donde los elementos están apilados verticalmente, de manera que solo la cima de la pila es accesible, siendo solo el elemento último en poner en la pila, el único que puede ser sacado. Los demás elementos (aunque visibles) no pueden ser sacados de la pila, mientras encima de ellos haya otros elementos. La principal característica de la pila, es que tiene dos índices (punteros) que sirven para llevar un control de cómo está siendo utilizada esta pila. 
> 12. Describa la secuencia de reset del microprocesador.

En un microprocesador, la señal de reset se genera manualmente al pulsar un botón(reset manual) o cuando se pone en marcha el sistema(reset por encendido). En un  microprocesador hay otras posibles fuentes de reset como son el reset por fallo de alimentación y el rest por desbordamiento del watch Dog.

> 13. ¿Qué entiende por “core peripherals”? ¿Qué diferencia existe entre estos y el resto de los periféricos?

Son perifericos que impactan directamente en el comportamiento de la arquitectura. Ej: NVIC, SysTick,SCB y MPU. Se diferencian de los demás perifericos en que requeridos y no opcionales.

> 14. ¿Cómo se implementan las prioridades de las interrupciones? Dé un ejemplo

Las interrupciones son generadas por los dispositivos periféricos habilitando una señal del CPU (llamada IRQ "interrupt request") para solicitar atención del mismo. Por ejemplo. cuando un disco duro completa una lectura solicita atención al igual que cada vez que se presiona una tecla o se mueve el mouse.

> 15. ¿Qué es el CMSIS? ¿Qué función cumple? ¿Quién lo provee? ¿Qué ventajas aporta?

(CMSIS) es una capa de abstracción de hardware independiente del proveedor de la serie de procesadores Cortex-M. El propósito de CMSIS es permitir que las MCU Cortex M de diferentes fabricantes logren un cierto grado de consistencia al menos en el nivel central, y mejorar la eficiencia de la migración de software.

> 16. Cuando ocurre una interrupción, asumiendo que está habilitada ¿Cómo opera el microprocesador para atender a la subrutina correspondiente? Explique con un ejemplo

Una petición de interrupción o más conocida como IRQ, siglas que significan Interrupt ReQuest, es un mecanismo indispensable en toda CPU para poder interactuar con ella a todos los niveles, tanto por parte de los usuarios como el resto del hardware. Para gestionar una petición de interrupción la CPU ha de parar en seco el ciclo de instrucción, cada vez que una instrucción es completada la propia CPU va a comprobar si existe una petición de interrupción. En el caso de que no exista ejecutará la siguiente línea de código del programa. Si existe lo que hará será almacenar el estado del programa en un registro especial. Siendo el estado el valor de la siguiente instrucción en el contador de programa. Dependiendo del cual sea el tipo de instrucción, la CPU cargará en el contador de programa una dirección de memoria especial que apunta a la ROM de instrucciones, un programa en una memoria aparte del procesador que tiene codificado como la CPU tiene que gestionar dicha instrucción.

> 17. ¿Cómo cambia la operación de stacking al utilizar la unidad de punto flotante?

Si el procesador no tiene unidad de punto flotante, el stack frame es siempre de 8 palabras. Para cortex M4 con unidad de punto flotante, el frame va de 8 o 26 palabras. 
> 18. ¿Qué es el systick? ¿Por qué puede afirmarse que su implementación favorece la portabilidad de los sistemas operativos embebidos?

Se trata de un temporizador de 24 bits de cuenta descendente, que produce una interrupción cuando el registro interno llega a cero desde el valor de recarga inicial.
Es completamente portable, porque pertenece al core de la arquitectura. 
> 19. ¿Qué funciones cumple la unidad de protección de memoria (MPU)?

Entre las funciones de este dispositivo se encuentran la traducción de las direcciones lógicas (o virtuales) a direcciones físicas (o reales), la protección de la memoria, el control de caché y, en arquitecturas de computadoras más simples (especialmente en sistemas de 8 bits), bank switching.

> 20. ¿Cuántas regiones pueden configurarse como máximo? ¿Qué ocurre en caso de haber solapamientos de las regiones? ¿Qué ocurre con las zonas de memoria no cubiertas por las regiones definidas?

En la MPU se pueden definir hasta 8 regiones programables. Si se accede a una zona de memoria no permitida, entonces ocurre una excepción de falla. Si hay regiones superpuestas, entonces el permiso se basará en la región con el numero mas alto.

> 21.  ¿Para qué se suele utilizar la excepción PendSV? ¿Cómo se relaciona su uso con el resto

> 22.  ¿Para qué se suele utilizar la excepción SVC? Expliquelo dentro de un marco de un sistema operativo embebido.

**ISA**
> 1.  ¿Qué son los sufijos y para qué se los utiliza? Dé un ejemplo
> 2.  ¿Para qué se utiliza el sufijo ‘s’? Dé un ejemplo
> 3.  ¿Qué utilidad tiene la implementación de instrucciones de aritmética saturada? Dé un ejemplo con operaciones con datos de 8 bits.
> 4.  Describa brevemente la interfaz entre assembler y C ¿Cómo se reciben los argumentos 	de las funciones? ¿Cómo se devuelve el resultado? ¿Qué registros deben guardarse en la 	pila antes de ser modificados?
> 5. ¿Qué es una instrucción SIMD? ¿En qué se aplican y que ventajas reporta su uso? Dé un ejemplo.
