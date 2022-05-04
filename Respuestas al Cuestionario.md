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

 
> 3. ¿Por qué se dice que el set de instrucciones Thumb permite mayor densidad de código? Explique

En el estado ARM, el procesador ejecuta instrucciones ARM alineadas con palabras de 32 bits, y en el estado Thumb, el procesador ejecuta instrucciones THUMB alineadas con media palabra de 16 bits.

> 4. ¿Qué entiende por arquitectura load-store? ¿Qué tipo de instrucciones no posee este tipo de arquitectura?

> 5. ¿Cómo es el mapa de memoria de la familia?

> 6. ¿Qué ventajas presenta el uso de los “shadowed pointers” del PSP y el MSP?

> 7. Describa los diferentes modos de privilegio y operación del Cortex M, sus relaciones y como se conmuta de uno al otro. Describa un ejemplo en el que se pasa del modo privilegiado a no priviligiado y nuevamente a privilegiado.

> 8. ¿Qué se entiende por modelo de registros ortogonal? Dé un ejemplo
 
> 9. ¿Qué ventajas presenta el uso de intrucciones de ejecución condicional (IT)? Dé un ejemplo

> 10. Describa brevemente las excepciones más prioritarias (reset, NMI, Hardfault).
 
> 11. Describa las funciones principales de la pila. ¿Cómo resuelve la arquitectura el llamado a funciones y su retorno?

> 12. Describa la secuencia de reset del microprocesador.
 
> 13. ¿Qué entiende por “core peripherals”? ¿Qué diferencia existe entre estos y el resto de los periféricos?

> 14. ¿Cómo se implementan las prioridades de las interrupciones? Dé un ejemplo

> 15. ¿Qué es el CMSIS? ¿Qué función cumple? ¿Quién lo provee? ¿Qué ventajas aporta?

> 16. Cuando ocurre una interrupción, asumiendo que está habilitada ¿Cómo opera el microprocesador para atender a la subrutina correspondiente? Explique con un ejemplo
 
> 17. ¿Cómo cambia la operación de stacking al utilizar la unidad de punto flotante?
