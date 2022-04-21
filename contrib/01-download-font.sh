#!/bin/sh

set -x

curl -L https://github.com/adobe-fonts/source-code-pro/releases/download/2.038R-ro%2F1.058R-it%2F1.018R-VAR/TTF-source-code-pro-2.038R-ro-1.058R-it.zip -o TTF-source-code-pro-2.038R-ro-1.058R-it.zip

sudo mkdir -p /usr/local/share/fonts/SourceCodePro

sudo unzip TTF-source-code-pro-2.038R-ro-1.058R-it.zip -d /usr/local/share/fonts/SourceCodePro
