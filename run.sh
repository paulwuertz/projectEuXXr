#!/bin/bash
pp=""
if [[ $1 -lt 10 ]]; then
    pp="0"$pp
fi
if [[ $1 -lt 100 ]]; then
    pp="0"$pp
fi

echo bin/$pp$1 `cat params.txt | grep -e "^$1:.*$" | sed "s@$1:@@"`
bin/$pp$1 `cat params.txt | grep -e "^$1:.*$" | sed "s@$1:@@"`