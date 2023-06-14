#!/bin/bash

# Dato un file in input txt(esistente), restituisce il numero di occorrenze presenti nel file
[ $# -ne 2 ] && echo Usage: $0 \<pathname\> \<string\> && exit 1  
[ -z "$1" ] && exit 1
[ -z "$2" ] && exit 1

file=$1
word=$2
count=$(grep "$word" "$file" | wc -l)

echo "Il numero di occorrenze nel file $file è di $count"

# ~$ bash es2.sh Lorem
