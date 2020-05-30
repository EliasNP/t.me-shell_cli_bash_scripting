#!/usr/bin/env bash

_filemaker() {
    echo "Creamos 40 archivos de texto..."
    # Usamos la expansión de llaves para crear los archivos
    touch {01..40}.txt
    ls
}

_compressor() {
    echo -e "\nComprimimos en formato gzip los archivos 23 y 29..."
    # $@ toma como valor todos los argumentos que se pasan a la función
    gzip "$@"
    ls ./*.gz
}

_chext() {
    echo -e "\nModificamos la extensión a 'md' a todos los archivos que contienen un 3 en su nombre..."
    # Iteramos sobre todos los elementos del directorio
    for f in *; do
        # Si contiene en núm. 3 en su nombre; stout y sterr se suprime
        if grep '3' <<<"$f" > /dev/null 2>&1 ; then
            # Eliminamos la parte de la extensión para ser sustiduida por .md
            mv "$f" "${f%.*}.md"
            echo "${f%.*}.md"
        fi
    done
}

_filemaker
# Pasamos como argumentos los archivos indicados en el ejercicio
_compressor 23.txt 29.txt
_chext


