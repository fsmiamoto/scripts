#!/bin/bash
#
# ino - Script simples para compilar e fazer o upload do sketch usando
# a arduino-cli
#
#

# Parâmetros
porta=/dev/ttyACM0
placa=arduino:avr:uno

# Compila e, se não houver erros, faz o upload
arduino-cli compile --fqbn "$placa" "$1" && arduino-cli upload -p "$porta" --fqbn "$placa" "$1"
