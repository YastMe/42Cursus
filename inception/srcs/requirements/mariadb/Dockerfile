# Alpine Linux with MariaDB
FROM alpine:3.19

# Set environment variables
ENV TERM xterm

# Update and install packages
RUN apk update && apk upgrade && apk add --no-cache mariadb \
        mariadb-common \
        mariadb-client \
        openrc

# Allow remote connections
RUN sed -i 's/#bind-address/bind-address/' /etc/my.cnf.d/mariadb-server.cnf && \
        sed -i 's/skip-networking/#skip-networking/' /etc/my.cnf.d/mariadb-server.cnf

# Start service maganer
RUN openrc && touch /run/openrc/softlevel

# Create a directory for the database and set its owner to the mysql user
RUN mkdir -p /run/mysqld && \
        chown -R mysql /run/mysqld && \
        /etc/init.d/mariadb setup && \
        chown -R mysql /var/lib/mysql

# Copy the configuration script and make it executable
COPY tools/config.sh .
RUN chmod +x config.sh

# Clean up
RUN rm -f /var/cache/apk/*

# Expose the port
EXPOSE 3306

# Start the service
ENTRYPOINT [ "./config.sh" ]