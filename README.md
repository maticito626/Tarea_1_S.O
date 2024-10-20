# Tarea 1 - Sistemas Operativos: Simulación de Carrera de Autos

Este repositorio contiene el código de la tarea 1 de Sistemas Operativos que simula una carrera de autos utilizando hilos (threads) y sincronización mediante mutex.

## Requisitos:
- Lenguaje: C++ (estandar C++ 11 o superiores).
- Compilador: GNU g++ (makefile).
- Plataforma: Sistema operativo Linux o Putty.

## Funcionamiento:
- Cada auto definido tiene su unico identificador.
- Cada auto avanza y detiene de manera aleatoria.
- Por cada auto y en cada iteracion, calcular un valor aleatorio para la distancia que
avanza (maximo de 10 metros) y cambia la velocidad (entre 100-500 ms).
- Durante la Carrera se muestra el progreso en tiempo real y total de cada auto y se finaliza cuando todos los autos llegan a la meta definida.

## Contenido del Código

El archivo principal incluye las siguientes funcionalidades:

- **Librerías**: Se utiliza la librería thread para gestionar los hilos, donde cada hilo representa un auto en la carrera.
- **Mutex**: Se utiliza un mutex para asegurar que los mensajes de salida no se mezclen entre sí, ya que varios autos pueden avanzar simultáneamente.
- **Funciones principales**:
  - id: Identificador único para cada auto.
  - distanciaTotal: Define la distancia total que cada auto debe recorrer.
  - posiciones: Vector que guarda el lugar de cada auto al finalizar la carrera.
  - lugar: Registra el orden de llegada de los autos.

Dentro de la función principal de cada auto, se generan números aleatorios para determinar el avance en metros (entre 1 y 10). En cada avance, se imprime un mensaje que muestra los metros recorridos y un mensaje final al concluir la carrera.

## Ejecución del Código

Para ejecutar el código, sigue los siguientes pasos en tu consola de comandos:

1. Clona este repositorio:
   ```bash
   git clone <URL_DEL_REPOSITORIO>
2. Accede al directorio del proyecto:
   cd Tarea_1_S.O/
3. Compila el programa utilizando make:
   make
4. Ejecuta el programa con el siguiente comando:
   ./carrera <distancia_de_la_carrera> <numero_de_autos>
Ejemplo:
./carrera 20 3
En este ejemplo, la carrera será de 20 metros y participarán 3 autos.

Salida en Pantalla
Durante la ejecución del programa, se imprimen mensajes continuos que muestran el progreso de cada auto, incluyendo:

Los metros avanzados en cada iteración.
Los metros totales recorridos por cada auto.
Mensajes indicando el final de la carrera para cada auto.
Una vez que todos los autos terminan la carrera, se imprimen las posiciones finales de llegada.
Requisitos
Sistema operativo Linux (o compatible con pthread).
Compilador con soporte para make y pthread.
