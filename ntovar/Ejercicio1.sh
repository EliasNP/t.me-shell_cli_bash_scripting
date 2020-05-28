#!/usr/bin/env bash 
#
# Hecho por : Nelo R. Tovar
#
# Ejercicio nro 1 :
# Crear 3 funciones :
# - Una que cree 40 archivos .txt en una carpeta de tu escritorio (usa touch # para crearlos)
# - Otra que comprima con gzip sólo los archivos 23 y 29.
# - La última que cambie la extensión de los ficheros que contengan un 3 en su
# nombre de .txt a .md.)

function crear_archivos() {
# Funcion para crear n archivos
# Parametros de entrada :
#   $1 : Cantidad de archivos a crear
#   $2 : Prefijo del nombre de los archivos
#   $3 : Extension de los archivos

    for (( i = 1; i <= $1; i++ )); do
        touch "$2_$i.$3"
    done
}

function comprimir_archivo() {
# Funcion para comprimir un archivo
# Parametros de entrada :
#   $1 : Nombre del archivo a comprimir

    if [ -e $1 ]; then
        # Si el archivo existe, entonces comprimirlo
        gzip $1
    fi
}

function cambiar_extension() {
# Funcion para cambiar la extension a un grupo de archivos
# Parametros de entrada :
#   $1 : Patron del nombre de los archivos a cambiarle la extension
#   $2 : Extension original de los archivos
#   $3 : Nueva extension de los archivos
    
    for i in `ls -1 | grep $1` ; do
        echo $i | grep ".${2}$"
        if [ $? -eq 0 ]; then
            nombre=$(echo $i | cut -d'.' -f 1)
            mv $i "$nombre.$3"
        fi
    done

}

#
# Parametros de entrada del script
#

# Crear 40 archivos de forma predeterminada
cant=40

# Prefijo predertminado del nombre de los archivos
prefix='file'

# Extension predeterminada de los archivos
ext='txt'

# Procesar los parametros pasados al script
if [ $# -ne 0 ]; then
    # Actualizar la cantidad de archivos a crear
    cant=$1

    # Si existe $2, entonces actualizar el prefijo del nombre de los archivos
    if [ -n "$2" ]; then
        prefix=$2

        # Si existe $3, entonces actualizar la extendion de los archivos
        if [ -n "$3" ]; then
            ext=$3
        fi
    fi
fi

crear_archivos $cant $prefix $ext
echo 'Crear archivos' > salida.txt
ls -1 | grep -v sh >> salida.txt
comprimir_archivo "${prefix}_23.$ext"
comprimir_archivo "${prefix}_29.$ext"

echo ' ' >> salida.txt
echo 'Comprimir archivos' >> salida.txt
ls -1 *gz >> salida.txt

cambiar_extension '3' $ext 'md'
echo ' ' >> salida.txt
echo 'Cambiar extension de los archivos' >> salida.txt
ls -1 *.md | grep -v salida | grep -v sh >> salida.txt

echo ' ' >> salida.txt
cat ejercicio01.sh >> salida.txt

#pastebinit -b pastebin.com -i salida.txt
