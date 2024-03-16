# Alpine Linux with Nginx
FROM alpine:3.19

# Set environment variables
ENV TERM xterm

# Update and install packages
RUN apk update && apk upgrade
RUN apk add --no-cache nginx \
        openssl \
        envsubst

# Create the SSL directory
RUN mkdir -p /etc/nginx/ssl

# Configure Nginx with www-data user
RUN adduser -D -H -S -G www-data www-data
RUN sed -i 's/user nginx;/user www-data;/' /etc/nginx/nginx.conf
RUN sed -i 's/keepalive_timeout 65;/keepalive_timeout 5;/' /etc/nginx/nginx.conf

# Copy the configuration script and make it executable
COPY tools/config.sh .
RUN chmod +x config.sh

# Copy the Nginx config file
COPY conf/nginx_base.conf .

# Clean up
RUN rm -f /var/cache/apk/*

# Expose the port
EXPOSE 443

# Start the service
ENTRYPOINT [ "./config.sh" ]