#!/bin/sh

ifconfig -a | grep ether | awk '{print $2}'

# ifconfig | awk '/ether/ {print $2}'
# ✗ ifconfig -a | grep ether | cut -d ' ' -f 2

