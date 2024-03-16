#!/bin/sh

# Create SSL certificate
if [ ! -f /etc/nginx/ssl/$DOMAIN_NAME.key ]; then
    echo -e "\033[1;33mSSL certificate not found, creating one for $DOMAIN_NAME\033[0m"
    openssl req -x509 -nodes -days 42 -newkey rsa:2048 -keyout /etc/nginx/ssl/$DOMAIN_NAME.key -out /etc/nginx/ssl/$DOMAIN_NAME.crt -subj \
    "/C=ES/ST=Andalucia/L=Malaga/O=42Malaga/OU=alumni/CN=$DOMAIN_NAME"
else
    echo -e "\033[1;32mUsing existing SSL certificate for $DOMAIN_NAME\033[0m"
fi

# Create nginx configuration file
if [ ! -f /etc/nginx/http.d/$DOMAIN_NAME.conf ]; then
    echo -e "\033[1;33mNginx configuration file not found, creating one for $DOMAIN_NAME\033[0m"
    envsubst '$DOMAIN_NAME' < /nginx_base.conf > /etc/nginx/http.d/$DOMAIN_NAME.conf
else
    echo -e "\033[1;32mUsing existing nginx configuration file for $DOMAIN_NAME\033[0m"
fi

# Start nginx
echo -e "\033[1;32mStarting nginx\033[0m"
nginx -g "daemon off;"