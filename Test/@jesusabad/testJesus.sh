#!/bin/bash

# your code goes here

echo "Prueba de Jesus (@jesusabad)"
echo "Voy a ahcer un \"du * -ah\" y lo voy a Guardar en un Archivo1.sh "
echo "Pulsa \"ENTER\" para Continuar"
read P
#Comando a Ejecutar du la variable * busca en todo el directorio actual las opccion -a lista todo y la opcion -h cambia el formato de la salida a algo entendible por humanos.
du * -ah > "Archivo1.sh"

echo "Se ha guardado el resultado en Archivo 1.sh"
cat "Archivo1.sh"
