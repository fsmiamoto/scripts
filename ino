#!/bin/bash
#
# ino - Script simples para compilar e fazer o upload do sketch usando
# a arduino-cli
#
#

# Parâmetros
porta=/dev/ttyACM0 # Porta serial utilizada
placa=arduino:avr:mega # Placa Arduino

# Compila e, se não houver erros, faz o upload
arduino-cli compile --fqbn "$placa" "$1" && arduino-cli upload -p "$porta" --fqbn "$placa" "$1"
