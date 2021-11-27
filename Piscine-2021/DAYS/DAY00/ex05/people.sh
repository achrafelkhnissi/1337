#!/bin/sh
ldapsearch -LLL -Q "objectclass=apple-user" uid | grep uid: | cut -c6- | sort -r
