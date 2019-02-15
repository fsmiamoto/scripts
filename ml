#!/bin/bash
#
# ml - Select a folder from Machine Learning directory with fzf
#
#

# Selects the folder with fzf
pasta=$(ls -l ~/ML/MachineLearningCoursera/ | grep "^d" | sed -nE "s/^.*[0-9] (.*)$/\1/p" | sed -n "s/^.*$/&\//p" | fzf)

# Opens VS Code
exec code $(echo "/home/shigueo/ML/MachineLearningCoursera/$pasta")


