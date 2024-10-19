# Tarea_1_S.O

Contenido del codigo y funcionamiento:
El archivo adjunto contiene ademas de este archivo readme trae el codigo que simula la carrera con las respectivas librerias solicitadas como la libreria thread que son para cada auto o autos, trae un Mutex para evitar que las hebras se escriban al mismo tiempo para que asi los mensajes de salida no se mezclen entre si, trae en su primera funcion el comportamiento de cada auto con las siguientes funciones: id (identificador de cada auto unico), distanciaTotal (distancia que recorrera el auto), posiciones (vector que guarda el lugar de cada auto) y lugar (orden de llegada de cada auto) dentro de esta funcion se generan los numeros aleatorios los cuales determinan cuanto avanzara dicho auto (entre 1 a 10 metros de distancia) ademas de imprimir un mensaje cada vez que este avanze con los metros totales ya recorridos y el mensaje de finalizacion de carrera.

Ejecucion del codigo:
para compilar el codigo debe seguir los siguientes pasos en su respectiva consola de comandos, para iniciar copie la url de este programa en la pestaña "Code" y dirigase a su consola donde colocara "git clone (url)", tras esto se descargara el archivo "Tarea_1_S.O", se ubicara en el con "cd Tarea_1_S.O/", ejecutelo con el comando "make", ya activado el archivo escribira lo siguiente para iniciar la carrera: "./carrera (largo de la carrera) (numero de autos)" o como ejemplo de prueba "./carrera 20 3".

Que aparecera en pantalla:
tras ejecutar y colocar las especificaciones de la carrera se imprimiran mensajes continuos de la simulacion de la carrera tanto cuantos metros avanzados y los metros totales recorridos por cada respectivo auto, tras alcanzar la distancia ya especificada de la carrera se imprimiran los mensajes de las posiciones en las cuales llegaron cada uno de los autos finalizando la ejecucion del programa.
