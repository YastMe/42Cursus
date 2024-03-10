# Alpine Linux with WordPress and PHP
FROM alpine:3.19

# Set environment variables
ENV TERM xterm
ENV WORDPRESS_CLI_VERSION 2.10.0
ENV PHP_VERSION 82

# Update and install packages
RUN apk update && apk upgrade
RUN apk add --no-cache php${PHP_VERSION} \
        php${PHP_VERSION}-phar \
        php${PHP_VERSION}-curl \
        php${PHP_VERSION}-mysqli \
        php${PHP_VERSION}-tokenizer \
        php${PHP_VERSION}-fpm \
        php${PHP_VERSION}-iconv \
        php${PHP_VERSION}-mbstring \
        php${PHP_VERSION}-openssl \
        php${PHP_VERSION}-xml \
        php${PHP_VERSION}-opcache \
        php${PHP_VERSION}-json \
        mariadb-client \
        curl
    
# Install WordPress CLI
RUN curl -o /usr/local/bin/wp -fL "https://github.com/wp-cli/wp-cli/releases/download/v${WORDPRESS_CLI_VERSION}/wp-cli-${WORDPRESS_CLI_VERSION}.phar" && \
    chmod +x /usr/local/bin/wp

# Configure PHP-FPM
RUN adduser -D -H -S -G www-data www-data && \
    sed -i 's/^listen = .*/listen = 0.0.0.0:9000/' /etc/php${PHP_VERSION}/php-fpm.d/www.conf && \
    sed -i "s/user = nobody/user = www-data/" /etc/php${PHP_VERSION}/php-fpm.d/www.conf && \
    sed -i "s/group = nobody/group = www-data/" /etc/php${PHP_VERSION}/php-fpm.d/www.conf && \
    sed -i "s/memory_limit = 128M/memory_limit = 256M/" /etc/php${PHP_VERSION}/php.ini && \
    ln -fs /usr/bin/php${PHP_VERSION} /usr/bin/php && \
    ln -s /usr/sbin/php-fpm${PHP_VERSION} /usr/sbin/php-fpm

# Copy the configuration script and make it executable
COPY config.sh .
COPY home.html .
RUN chmod +x config.sh

# Clean up
RUN rm -f /var/cache/apk/*

# Expose the port
EXPOSE 9000

# Start the service
ENTRYPOINT [ "./config.sh" ]
