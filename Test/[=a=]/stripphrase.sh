#!/bin/bash

echo "Plase insert any phrase"
read var_phrase

#2.
var_words=`echo "$var_phrase" | wc -w `
var_letters=`echo ${var_phrase} | tr -d '[[:space:]]'`
var_letters=`echo ${#var_letters}`

echo "The Phrase ($var_phrase) have:"
echo " ----------- "
echo "$var_letters leters"
echo "$var_words words"
echo " ----------- "
counter=1
while [ $counter -le $var_words ]
do
var_only=`echo ${var_phrase} |cut -d " " -f ${counter}`
var_numwor=`echo  ${var_only} | wc -c `
echo "${var_only} have ${var_numwor} letter"

((counter++))
done
