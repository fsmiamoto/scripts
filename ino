#!/bin/bash
#
# ino - Script para compilar e fazer o upload do sketch usando
# a arduino-cli
#
# Versão 1.0 - Funcionalidade básica
# Versão 1.1 - Adicionado flag de parar limpeza do código

mensagem_ajuda="
$(basename $0) [-h | -v] - Compila e faz upload do sketch 
"
# Parâmetros
porta=/dev/ttyACM0
placa=arduino:avr:uno

limparArquivo=0

while test -n "$1"
do
    case "$1" in
        -p | --prod)
            limparArquivo=1
            shift
            ;;
        -h | --help)
            echo $mensagem_ajuda
            exit 0
            ;;
        -v | --version)
            echo -n "$(basename $0): "
            # Pega versão do cabeçalho do código
            grep "^# Versão" $0 | tail -1 | cut -d : -f 1 | sed "s/^# // g"
            exit 0
            ;;
        *)
            break
            ;;
    esac
done

# Remove possíveis / do nome
name=$(echo "$1" | sed "s/\///g")

if test "$limparArquivo" = "1"
then
   cp "$name/$name.ino" "$name/backup.ino"
   sed -i "/Serial/d" "$name/$name.ino"
fi

# Compila e, se não houver erros, faz o upload
arduino-cli compile --fqbn "$placa" "$name" && arduino-cli upload -p "$porta" --fqbn "$placa" "$name"

# Remove arquivos elf e hex
rm "$name/"*.elf
rm "$name/"*.hex

if test "$limparArquivo" = "1"
then
    cat "$name/backup.ino" > "$name/$name.ino"
    rm "$name/backup.ino"
fi

