/*
 * ejercicios.c
 *
 *  Created on: Mayo 23, 2022
 *      Author: Amilcar Rincon Charris
 */

#include "ejercicios.h"


/* Ejercicio 1 - Realizar una función que inicialice un vector con ceros.
La función debe tener el siguiente prototipo: void zeros (uint32_t *vector, uint32_t longitud);
*/
void zeros (uint32_t *vector, uint32_t longitud)
{
	uint32_t i = 0;
	for(i = 0; i < longitud; i++){
		vector[i] = vector[i]*0;
	}
}

/* Ejercicio 2 - Realizar una función que realice el producto de un vector y un escalar (por ejemplo, podría servir
para cambiar el nivel de amplitud de una señal).
void productoEscalar32 (uint32_t *vectorIn, uint32_t *vectorOut uint32_t longitud, uint32_t escalar);
*/
void productoEscalar32 (uint32_t *vectorIn, uint32_t *vectorOut, uint32_t longitud, uint32_t escalar)
{
	uint32_t i = 0;
	for(i = 0; i < longitud; i++){
		vectorOut[i] = vectorIn[i]*escalar;
	}
}


/* Ejercicio 3 - Adapte la función del ejercicio 2 para realizar operaciones sobre vectores de 16 bits:
void productoEscalar16 (uint16_t *vectorIn, uint16_t *vectorOut, uint32_t longitud, uint16_t escalar);
*/
void productoEscalar16 (uint16_t *vectorIn, uint16_t *vectorOut, uint32_t longitud, uint16_t escalar)
{
	uint32_t i = 0;
	for(i = 0; i < longitud; i++){
		vectorOut[i] = vectorIn[i]*escalar;
	}
}


/* Ejercicio 4 - Adapte la función del ejercicio 3 para saturar el resultado del producto a 12 bits:
void productoEscalar12 (uint16_t * vectorIn, uint16_t * vectorOut, uint32_t longitud, uint16_t escalar);
*/
void productoEscalar12 (uint16_t *vectorIn, uint16_t *vectorOut, uint32_t longitud, uint16_t escalar)
{
	uint32_t i = 0;
	for(i = 0; i < longitud; i++){
		vectorOut[i] = vectorIn[i]*escalar;
		if(vectorOut[i] >= 4095) vectorOut[i] = 4095;
	}
}



/* Ejercicio 5 - Realice una función que implemente un filtro de ventana móvil de 10 valores sobre un vector de
muestras.
void filtroVentana10(uint16_t *vectorIn, uint16_t *vectorOut, uint32_t longitudVectorIn);
*/
void filtroVentana10(uint16_t *vectorIn, uint16_t *vectorOut, uint32_t longitudVectorIn)
{
	uint32_t offsetVentana = 0;


	for(uint32_t i = 0 ; i < longitudVectorIn ; i++){
		vectorOut[i] = 0;
	}

	for( offsetVentana = 0 ; offsetVentana < (longitudVectorIn - 10 + 1) ; offsetVentana++)	// Muevo la ventana
	{
		for( uint32_t j = 0; j < 10 ; j++ ) //acumulo la ventana
		{
			vectorOut[offsetVentana] += vectorIn[offsetVentana + j];
		}
		vectorOut[offsetVentana] /= 10;
	}
}


/* Ejercicio 6 - Realizar una función que reciba un vector de números signados de 32 bits y los “empaquete” en
otro vector de 16 bits. La función deberá adecuar los valores de entrada a la nueva precisión.
void pack32to16 (int32_t *vectorIn, int16_t *vectorOut, uint32_t longitud);
*/
void pack32to16 (int32_t *vectorIn, int16_t *vectorOut, uint32_t longitud)
{
	uint32_t i = 0;

	for(uint32_t i = 0 ; i < longitud ; i++){
		vectorOut[i] = vectorIn[i]>>16;
	}
}


/* Ejercicio 7 - Realizar una función que reciba un vector de números signados de 32 bits y devuelva la posición
del máximo del vector. int32_t max (int32_t *vectorIn, uint32_t longitud);
*/
int32_t max_c(int32_t *vectorIn, uint32_t longitud)
{
	uint32_t i = 0;
	uint32_t max = 0;

	for(uint32_t i = 0 ; i < longitud ; i++)
	{
		if(vectorIn[i] > max)
		{
			max = vectorIn[i];
		}
	}
	return max;
}



/* Ejercicio 8 - Realizar una función que reciba un vector de muestras signadas de 32 bits y lo decime
descartando una cada N muestras.
void downsampleM (int32_t *vectorIn, int32_t *vectorOut, uint32_t longitud, uint32_t N);
*/
void downsampleM (int32_t *vectorIn, int32_t *vectorOut, uint32_t longitud, uint32_t N)
{
	volatile uint32_t i, k = 0;

	for( i = 0 ; i < longitud ; i++){
		if(i%N == 0){
			vectorOut[k] = vectorIn[i];
			k++;
		}
		else {
			vectorOut[i] = 0;
		}
	}
	return;
}

/* Ejericio 9 - Realizar una función que reciba un vector de muestras no signadas de 16 bits e invierta su orden.
void invertir (uint16_t *vector, uint32_t longitud);
*/
void invertir (uint16_t *vector, uint32_t longitud)
{
	volatile uint32_t i, j = 0;
	volatile uint16_t vec[10];

	for( i = 0 ; i < longitud ; i++){
		vec[j] = vector[i];
		j++;
	}
	j = 0;
	for(i = 0;i < longitud; i++){
		vector[longitud-1-i] = vec[j];
		j++;
	}

	return;
}


/* Ejercicio 10 - Realizar una función que calcule la correlación entre dos vectores. Luego optimice utilizando
instrucciones SIMD.
void corr (int16_t *vectorX, int16_t *vectorY, int16_t vectorCorr, uint32_t longitud)
*/

void corr (int16_t *vectorX, int16_t *vectorY, int16_t *vectorCorr, uint32_t longitud){
	uint16_t index_corr = 0 ;
	uint16_t acum = 0 ;
	uint16_t index_vector_input = 0 ;
	uint16_t aux_calc ;
	for (index_corr = 0 ; index_corr<longitud ; index_corr++){
		for (index_vector_input = 0;index_vector_input<longitud;index_vector_input++ ){
			aux_calc = (index_vector_input-index_corr)<0 ?0 \
			:vectorX[index_vector_input]*vectorY[(index_vector_input-index_corr)] ;
			acum = acum +aux_calc ;
		}
		vectorCorr[index_corr] = acum  ;
		acum = 0 ;
		aux_calc = 0 ;
	}


}





