#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED


/** \brief suma dos números
 *
 * \param float primer numero ingresado
 * \param float segundo nuemro ingresado
 * \return float suma de los dos numeros ingresados
 *
 */
float sumar(float,float);


/** \brief resta dos números
 *
 * \param float primer numero ingresado
 * \param float segundo numero ingresado
 * \return float resultado de la resta de los dos numeros
 *
 */
float restar(float,float);


/** \brief divide dos numeros
 *
 * \param float primer numero ingresado
 * \param float segundo nuemero ingresado
 * \return float resultado de la division entre los dos numeros
 *
 */
float dividir(float,float);


/** \brief multiplica dos numeros
 *
 * \param float primer numero ingresado
 * \param float segundo nuemero ingresado
 * \return float resultado de la multiplicacion entre los dos numeros
 *
 */
float multiplicar(float,float);



/** \brief calcula el factorial de un numero
 *
 * \param int numero al que se le quiere calcular el factorial
 * \return long long int factorial del numero ingresado
 *
 */
long long int factorial(int);



/** \brief muestra resultado
 *
 * \param char texto[] texto que se quiere mostrar junto con el resultado
 * \param float resultado a mostrar
 *
 */
void mostrarResultado(char texto[],float);


/** \brief valida un divisor distinto a 0
 *
 * \param float divisor a validar
 * \return int 0 si el divisor es 0 y 1 si el divisor es otro numero
 *
 */
int validarDivisor(float);


/** \brief valida un numero al que se le pueda calcular el factorial(que sea positivo y entero), y calcula el factorial de 0
 *
 * \param float numero a validar
 * \return int 1 si NO se puede calcular el factorial(y un printf que explica por qué en cada caso)
 *
 */
int validarFactorial(float);


/** \brief calcula suma, resta, multiplicación y división de dos numeros, y el factorial del primer numero ingresado
 *
 * \param float primer numero para calcular
 * \param float segundo numero para calcular
 *
 */
void calcularTodasOperaciones(float,float);


